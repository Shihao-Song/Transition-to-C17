# Towards ~~Un~~**Manageable** Architecture

## **Abstract**
My ultimate goal is to make every major class (especially Cache, MMU, and Memory Controller) as generic as possible. I have noticed the following architectural issues of my simulator so far:

+ #include formatting issue:
    + I found that I did a terrible job in maintaining headers, for example, here shows the #include section of Main\_PALP.cpp for CASES 2019:

```c++
...
#include "../Configs/config.hh"
#include "../PCMSim/Memory_System/pcm_sim_memory_system.hh"
#include "../PCMSim/Trace/pcm_sim_trace.hh"

#include "src/cache.hh"
#include "src/tags/fa_tags.hh"
#include "src/tags/set_assoc_tags.hh"
...
```

+ #include formatting solution:
    + [x] Create a root directory, call it **include**
    + [x] Organize and put all the header files there
    + [x] Modify Makefile

+ Request class:
    + Issue (1): I put the definition of Request class into PCMSim, the directory where all the PCM controller implementations locate. This is a bad organization since the Request class, as a memory request abstraction, is used by Processor and cache as well.
    + [x] Solution (1): To create a new directory called Sim, this directory will be used to contain all the classes/functions related to simulation.

+ PCMSimMemorySystem class:
    + Issue (1): The purpose of this class is to simply group number of memory controllers; however, the existing implementation is not flexible since we may have different types of memory controller.
    + [x] Solution (1): Make the class as a template and use Factory technique (one of the most important Design Patterns) to construct different memory systems with different types of memory controllers.

+ SampleController class:
    + [x] Fixed: Added the C++17 constexpr-if feature, so that the scheduling scheme can be determined in compile-time.

+ Cache class:
    + [x] Use lambda functions as callbacks to improve performance.
    + [x] Use constexpr-if expressions to determine Read-Only/Write-Only/Normal cache at compile time.
    + [x] Use Factory technique to create different types of cache.

+ Processor class:
    + [x] Connect all the components and test the entire system.

+ Traces:
    + Issue: The traces that're fed into our simulator are too storage intensive.
    + [x] Solution: Use Google Protocol Buffer.
