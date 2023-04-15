#include <iostream>

#ifdef DEBUG_FILE
#include <fstream>
std::ofstream debug_file(DEBUG_FILE);
#define DEBUG_STREAM(x) debug_file << x
#else
#define DEBUG_STREAM(x)
#endif

#include "CMakeTemplate/CMakeTemplate.hpp"

void say_hello(){
    std::cout << "Hello, from CMakeTemplate!" << std::endl;
    DEBUG_STREAM("Hello, from CMakeTemplate!" << std::endl);
}
