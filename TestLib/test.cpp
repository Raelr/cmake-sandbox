#include "test.h"
#include <iostream>
#include <cmath>
// #include "ProjectA.h"

void test() {

    // Run specific code if and ONLY if the symbols required actually exist. 
    #if defined(HAVE_LOG) && defined(HAVE_EXP)
        std::cout << "Test with exp and log" << std::endl;
    #else
        std::cout << "Test without exp and log!" << std::endl;
    #endif
}
