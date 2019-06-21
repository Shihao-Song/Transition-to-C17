#ifndef __LD_HH__
#define __LD_HH__

// tmp function to create callbacks
static auto createCallback(auto &mem){return [&](){mem.callme();};}

#endif
