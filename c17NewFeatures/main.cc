#include "cache.hh"
#include "lambdas.hh"

#include <functional>
#include <vector>

int main()
{
    // Structured bindings can help with the cache-line information extraction
    // Cache<OnChipToOffChip> cache;
    NLC cache;
    LLC eDRAM;

    const auto [found,addr,missing_reason,core_id,when_ready] = cache.getCacheLine(0);

    if (found)
    {
        std::cout << "Block " << addr << "\n"
                  << "Missing Reason: " << missing_reason << "\n"
                  << "Core ID: " << core_id << "\n"
                  << "When Available: " << when_ready << "\n";
    }
    else
    {
        std::cout << "Block " << addr << " not found.\n";
    }
    std::cout << "\n";

    // Play with lambda
    std::cout << "1 + 1 = "
              << [](auto i, auto j){ return i + j; }(1,1)
              << "\n";

    int count = 0;
    auto counter([&count]() {return ++count;});
    /*
    counter();
    counter();
    counter();
    std::cout << count << "\n";
    */
    auto countNTimes([=](int n){for (int i = 0; i < n; i++){ counter(); }});
    countNTimes(10);
    std::cout << "Count 10 times: " << count << "\n";

    /*
     * Possible use of lambdas.
     * (1) Collect all callbacks from all layers.
     * */
    std::vector<std::function<void()>> callbacks{createCallback(cache),
                                                 createCallback(eDRAM)};
    // Looks like lambda is lvalue (object that occupies memory).
    for (auto &&callback : callbacks) { callback(); }
}
