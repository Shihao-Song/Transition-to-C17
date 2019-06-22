#include "cache.hh"
#include "lambdas.hh"

#include <functional>
#include <vector>

int main()
{
    // Structured bindings can help with the cache-line information extraction
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

    // **************************************************
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
 
    for (auto &&callback : callbacks) { callback(); }

    /*
     * (2) concat functions, f(g(h(...)))
     * */
    std::cout << "\n";
    auto timesFour([](int n){return n * 4;});
    auto timesFive([](int n){return n * 5;});
    auto addMe([](int a, int b){return a + b;});

    // Man! This is F**ing cool.
    auto combined(concat(timesFour, timesFive, addMe));
    std::cout << "(1 + 1) * 4 * 5 = " << combined(1,1) << "\n";

    /*
     * (3) Inherit from lambdas 
     * */
    std::cout << "\n";
    auto oneParam([](int n){return n + 1;});
    auto twoParams([](int a, int b){return a + b;});
    auto test(Visitor(oneParam, twoParams));
    std::cout << test(2) << "\n";
    std::cout << test(2,2) << "\n";

    /*
     * (4) Filter design with lambdas
     * */
    std::cout << "\n";
    auto begin_with_a([](const std::string &str){return str.find("a") == 0;});
    auto end_with_b([](const std::string &str){return str.find("b") == str.length() - 1;});
    auto logi_ands([](auto ... x){return (x & ...);}); // fold expression
    auto f(filter(logi_ands,begin_with_a,end_with_b));
    std::cout << "Does \"acb\" begin with a and end with b? " << f("acb") << "\n";

    /*
     * (5) Multiple functions operating on a single input
     * Tech 1) pack expansion (A programming trick)
     *      Hints: comma operator
     * */
    std::cout << "\n";
    // auto f1([](){std::cout << "f1 was evaluated.\n";});
    // auto f2([](){return 4;});
    // int haha = (f1(), f2()); // f1 is evaluated, but f2 is assigned.
    // std::cout << "My assigned value: " << haha << "\n";
    auto f1([](int n){std::cout << "Original value is: " << n << "\n";});
    auto f2([](int n){std::cout << "Plus one is: " << n + 1 << "\n";});
    auto calls(multicalls(f1,f2));
    forEach(calls, 1, 2, 3, 4);

    /*
     * (6) design a trasform_if with lambda
     *  Tech: std::accumulate 
     * */
    std::cout << "\n";
    // if input is an even integer
    auto even([](int i){return i % 2 == 0;});
    // then double it
    auto twice([](int i){return i * 2;});

    std::vector<int> inputs{1,2,3,4,5};
    std::vector<int> out{1,2,3,4,5};

    std::accumulate(inputs.begin(),inputs.end(),out.begin(),
                    Filter(even)(
                                 Opr(twice)));
    std::cout << out[0] << "\n";
    std::cout << out[1] << "\n";

    /*
     * (7) print out cartesian coordinates 
     * */
    std::cout << "\n";
    constexpr auto call_cart(
    [=](auto x, auto ...y) constexpr{
        (void)std::initializer_list<int>{
            (printCoor(x,y),0)...
        };
    });

    constexpr auto Cartesian(
    [=](auto ...xs) constexpr{
        (void)std::initializer_list<int>{
            (call_cart(xs, xs...),0)...
        };
    });

    Cartesian(1,2,3);
}
