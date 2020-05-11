#include <iostream>
#include "ProjectA.h"

#ifdef USE_TEST
    #include "test.h"
#endif

int main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << argv[0] << " version " << CMAKETest_VERSION_MAJOR << "." << CMAKETest_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number " << std::endl;
    }

    #ifdef USE_TEST
        test();
    #endif

    return 0;
}