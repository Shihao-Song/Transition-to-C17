#ifndef __LD_HH__
#define __LD_HH__

/*
 * The following coding tasks should be enough for me to understand or apply
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
    if constexpr(sizeof...(ts) > 0)
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


#endif
