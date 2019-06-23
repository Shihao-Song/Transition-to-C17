#ifndef __LD_HH__
#define __LD_HH__

//#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>

/*
 * The following coding tasks should be enough for me to understand and apply
 * advanced lambda techniques.
 * */

// tmp function to create callbacks
// I found this function very interesting, it takes and captures an object, then
// return back a lambda function. 
static auto createCallback(auto &mem){return [&](){mem.callme();};}

// Task 2, achieve something like f(g(h(...)))
// Here also shows how to pass arbitrary number of arguments.
// ...ts or ...params is the parameter pack
// Use ts... or params... to unpack parameters
template<typename T, typename ...Ts>
auto concat(T t, Ts ...ts)
{
    // Check if there are any more lambdas left
    // Won't compile without constexpr
    if constexpr (sizeof...(ts) > 0)
    {
        // what is retured should be a lambda function as well
        return [=](auto ...params)
               {
                   return t(concat(ts...)(params...));
               };
    }
    else
    {
        return t;
    }
}

// Task 3, inherit from lambdas
// We can inherit multiple lambdas by packing parameters
template<typename ...B>
struct Visitor : B...
{
    Visitor(B ...l) : B(l)...
    {
    }

    // This is important
    using B::operator()...;
};

// Task 4, design a filter with lambda
template<typename F, typename ...X>
auto filter(F filt, X ...x)
{
    return [=](auto param)
           {
               return filt(x(param)...);
           };
}

// Task 5, multiple functions operating with the same input
static auto multicalls (auto ...functions)
{
    return [=](auto param)
           {
               // Here is a coding trick, initializer_list is used to expand ...
               // The trick makes use of comma operator.
               (void)std::initializer_list<int>{((void)functions(param), 0)...};
           };
}

static auto forEach(auto functs, auto ...params)
{
    (void)std::initializer_list<int>{((void)functs(params), 0)...};
}

// Task 6, design a transform_if with lambdas, and accumalte
auto Opr(auto trans)
{
    return [=](auto iter, auto val)
           {
               *iter = trans(val);
               return ++iter;
           };
}

auto Filter(auto filt)
{
    return [=](auto opr)
           {
               return [=](auto iter, auto val)
               {
                   if (filt(val))
                   {
                       return opr(iter, val);
                   }
                   else
                   {
                       return iter;
                   }
               };
           };
}

// Task 7, print out cartesian coordinates
static void printCoor(int x, int y)
{
    std::cout << "(" << x << ", " << y << ")\n";
}

#endif
