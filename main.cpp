#include <iostream>

class Program
{
public:
  int8_t code[16][2];
  int8_t asigned_mem;
};

class Kernel 
{
public:
  bool still_running = true;
  int8_t memory[128][128];
  int8_t kernel_queue[256][2];
  int8_t cash[8];
  Kernel() 
  {
    std::cout << "booting kernal ... ";
    while (still_running)
    {
        int16_t i = 0;
        while (i < 255)
        {
            int8_t current = kernel_queue[i][2];
            std::cout << std::to_string(i) << ":" << std::to_string(current) << std::endl;
            i += 1;
        }
    }
  }
  int8_t load_program(Program program) 
  {
    program.asigned_mem = 0;
    return 0;
  }
};

int main(int argc, const char * argv[])
{
  
  Program program;
  program.code[0][0] = 1;
  program.code[0][1] = 0;
  
  Kernel ken;
  ken.load_program(program);
  
  
  return 0;
}
