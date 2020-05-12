#include <iostream>
#include "ProjectA.h"
#include "test.h"


int main(int argc, char** argv) {

    if (argc < 2) {
        std::cout << argv[0] << " version " << CMAKETest_VERSION_MAJOR << "." << CMAKETest_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number " << std::endl;
    }

    testLib::test();

    return 0;
}