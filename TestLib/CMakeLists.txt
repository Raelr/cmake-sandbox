# Define the library along with all related files associated with it. 
add_library(TestLib test.cpp)

# Requires that anyone linking to this lib MUST include current source directory. 
# Add this as an INTERFACE - meaning that consumers of this require the source whilst the producer doesn't. 
target_include_directories(TestLib 
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        # Find the path where we need to check for the config file.
        # PRIVATE ${CMAKE_BINARY_DIR}
        )

target_compile_definitions(TestLib PRIVATE "EXPORTING_TEST")

# Define locations for the library to be built to.  
install(TARGETS TestLib DESTINATION lib)
install(FILES test.h DESTINATION include)

# ------------------ SYSTEM INTROSPECTION ----------------------------

# This is what it'd look like to add system introspection in the test library rather than
# the root cmakelists. 

include(CheckSymbolExists)

set(CMAKE_REQUIRED_LIBRARIES "m")

check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)

if (HAVE_EXP AND HAVE_LOG)
        target_compile_definitions(TestLib
                        PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()
