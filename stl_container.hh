#ifndef __STL_C_HH__
#define __STL_C_HH__

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

// Here shows O(1) complexity way to remove an item from a vector
template<typename T>
auto O_1_remove_at(auto &vec, T idx)
{
    if constexpr(std::is_same<T, std::vector<int>::iterator>::value)
    {
        *idx = std::move(vec.back());
        vec.pop_back();
    }
    else
    {
        // .at does boundary checking automatically
        vec.at(idx) = std::move(vec.back());
        vec.pop_back();
    }
}

void STLContainer()
{
    /*
     * Study on vector
     * */
    std::cout << "\n";
    std::vector<int> v = {1, 2, 3, 4, 5, 2, 2, 8};
    std::cout << "Size of vector: " << v.size() << "; ";
    std::cout << "Capacity: " << v.capacity() << "\n";
    for (auto &val : v)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    const auto new_end(remove(begin(v), end(v), 2));
    std::cout << "Size of vector (removing 2), first: " << v.size() << "; ";
    std::cout << "Capacity: " << v.capacity() << "\n";
    for (auto &val : v)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    v.erase(new_end, end(v));
    std::cout << "Size of vector (removing 2), final: " << v.size() << "; ";
    std::cout << "Capacity: " << v.capacity() << "\n";
    for (auto &val : v)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    auto odd([](int i) {return i % 2 != 0;});
    v.erase(remove_if(begin(v), end(v), odd), end(v));
    std::cout << "Size of vector (removing all odds), final: " << v.size() << "; ";
    std::cout << "Capacity: " << v.capacity() << "\n";
    for (auto &val : v)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    v.shrink_to_fit();
    std::cout << "Shrink to fit (new feature), capacity: " << v.capacity() << "\n";

    /*
     * Cool way to remove item from vector
     * */
    std::cout << "\n";
    std::vector<int> v2{111,222,333};
    for (auto &val : v2)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    O_1_remove_at(v2, 1);
    std::cout << "Removed \"222\": ";
    for (auto &val : v2)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    O_1_remove_at(v2, std::find(begin(v2), end(v2), 333));
    std::cout << "Removed \"333\": ";
    for (auto &val : v2)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";
    v2.shrink_to_fit();
    std::cout << "Size: " << v2.size() << "; capacity: " << v2.capacity() << "\n";

    /*
     * Keep vector sorted
     * */
    std::cout << "\n";
    std::vector<int> v3{1,5,7,3,2,9,10};
    std::sort(begin(v3), end(v3));
    auto insertSorted([](auto &v, auto ele)
                      {
                          auto pos = std::lower_bound(begin(v),end(v),ele);
                          v.insert(pos, ele);
                      });
    insertSorted(v3, 4);
    for (auto &val : v3)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    /*
     * Research on std::map
     * */
    std::cout << "\n";
    // New feature (1): try_emplace() - if the insertion is not successful, the object
    // will not be constructed (copy run-time copying)
    // New feature (2): insert with hints to speedup
    std::map<std::string, int> m;
    for (const auto &s : {"a", "b", "c", "a"})
    {
        if (auto [iter, success] = m.try_emplace(s,1);
            !success)
        {
            ++(iter->second);
        }
    }
    std::cout << "Mapping (character : num_occurs)\n"; 
    for (const auto &[key,value] : m)
    {
        std::cout << key << " : " << value << "\n";
    }

    auto hint(end(m));
    hint = m.insert(hint, {"d",1});
    std::cout << "Inserted \"d\" (with hints): \n"; 
    for (const auto &[key,value] : m)
    {
        std::cout << key << " : " << value << "\n";
    }
}

#endif
