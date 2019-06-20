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

// These two structs help us to determine when to tick next level 
struct OnChipToOffChip{};
struct OnChipToOnChip{};

// ClockedObject helps to chain all levels of cache
class ClockedObject
{
  public:
    ClockedObject(){}

    virtual void tick() = 0;
};

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
            throw std::runtime_error("Already exists.");
        }

        // Determine when to tick next level 
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

    unsigned tick_next_level;
};
#endif
