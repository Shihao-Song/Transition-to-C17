#include <any>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct PCM 
{
    PCM() { std::cout << "Hello from PCM! \n"; }
};

struct DRAM
{
    DRAM() { std::cout << "Hello from DRAM! \n"; }
};

class Clocked_Object
{
  public:
    Clocked_Object(){}
};

template<typename T>
class Memory : public Clocked_Object
{
  private:
    std::vector<std::unique_ptr<T>> controllers;

  public:
    Memory() : Clocked_Object()
    {
        controllers.push_back(std::move(std::make_unique<T>()));
    }
};

typedef Memory<DRAM> DRAMSystem;
typedef Memory<PCM> PCMSystem;

class MemorySystemFactory
{
  private:
    std::unordered_map<std::string,
                       std::function<std::unique_ptr<Clocked_Object>()>> factories;

  public:
    MemorySystemFactory()
    {
        factories["DRAM"] = [](){return std::make_unique<DRAMSystem>();};
        factories["PCM"] = [](){return std::make_unique<PCMSystem>();};
    }

    auto createMemorySystem(std::string &type)
    {
        return factories[type]();
    }
};

static MemorySystemFactory MemorySystemFactories;
auto createMemorySystem(std::string &type)
{
    return MemorySystemFactories.createMemorySystem(type);
}

int main()
{
    std::string type = "PCM";
    std::unique_ptr<Clocked_Object> mem_system(createMemorySystem(type)); 
}
