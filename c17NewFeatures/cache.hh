#ifndef __CACHE_HH__
#define __CACHE_HH__

#include <iostream>
#include <string>
#include <unordered_map>

struct CacheLine
{
    std::string missing_reason;
    int core_id;
    unsigned when_ready;
};

// This is used for structure binding
struct CacheLineInfoQuery
{
    bool found;
    unsigned addr;

    // In our real cache, missing_reason should be an enum.
    // Do not forget to initialize.
    std::string missing_reason;
    int core_id;
    unsigned when_ready;
};

// ClockedObject helps to chain all levels of memory.
class ClockedObject
{
  public:
    ClockedObject(){}

    virtual void tick() = 0;
    // TODO, send() should also be required
};

// These two structs help us to determine when to tick next level 
struct OnChipToOffChip{};
struct OnChipToOnChip{};

template<typename pos>
class Cache : public ClockedObject
{
  public:
    Cache()
    {
        // We are also limiting variable scopes
        if (auto [itr, success] = cache.insert({0, {"LOAD", 1, 10}});
            success == false)
        {
            // TODO, I don't think I use cout/cerr appropriately, need to 
            // dig into it as well. Solved!
            // throw std::runtime_error("Already exists.");
            std::cerr << "Already exists.\n";
	}

        // Determine when to tick next level
        // TODO, should use constexpr for everything that can be determined at
        // compile-time.
        if constexpr(std::is_same<OnChipToOffChip,pos>::value)
        {
            std::cout << "This is the last level cache. \n";
            tick_next_level = 15;
        }
        else
        {
            std::cout << "This is a non-LLC cache. \n";
            tick_next_level = 1;
        }
    }
    void tick() override{}
    ClockedObject *next_level;

    std::unordered_map<unsigned,CacheLine> cache;
    auto getCacheLine(unsigned addr)
    {
        if (auto iter = cache.find(addr);
                 iter != cache.end())
        {
            return CacheLineInfoQuery
                   {true,
                    addr,
                    iter->second.missing_reason,
                    iter->second.core_id,
                    iter->second.when_ready};
        }
        else
        {
            return CacheLineInfoQuery{false,addr};
        }
    }
    void callme() {std::cout << tick_next_level << "\n";}

    unsigned tick_next_level;
};

typedef Cache<OnChipToOffChip> LLC; // Last-level cache
typedef Cache<OnChipToOnChip> NLC; // Non last-level cache

#endif
