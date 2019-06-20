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

    std::string missing_reason;
    int core_id;
    unsigned when_ready;
};

class Cache
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
    }

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
};
