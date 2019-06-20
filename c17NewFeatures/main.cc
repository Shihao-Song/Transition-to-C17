#include <iostream>

#include "structured_bindings.hh"

int main()
{
    // Structured bindings can help with the cache-line information extraction
    Cache cache;

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
}
