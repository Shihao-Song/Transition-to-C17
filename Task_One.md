# Day one: Towards ~~Un~~**Manageable** Architecture (1)

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
    + [ ] Organize and put all the header files there
    + [x] Modify Makefile

+ Request class:
    + Issue (1): I put the definition of Request class into PCMSim, the directory where all the PCM controller implementations locate. This is a bad organization since the Request class, as a memory request abstraction, is used by Processor and cache as well.
    + [x] Solution (1): To create a new directory called Sim, this directory will be used to contain all the classes/functions related to simulation.

+ PCMSimMemorySystem class:
    + Issue (1): The purpose of this class is to simply group number of memory controllers; however, the existing implementation is not flexible since we may have different types of memory controller.
    + [x] Solution (1): Make the class as a template and use Factory technique (one of the most important Design Patterns) to construct different memory systems with different types of memory controllers.
