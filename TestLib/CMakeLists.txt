# Define the library along with all related files associated with it. 
add_library(TestLib test.cpp)

# Requires that anyone linking to this lib MUST include current source directory. 
# Add this as an INTERFACE - meaning that consumers of this require the source whilst the producer doesn't. 
target_include_directories(TestLib 
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        # Find the path where we need to check for the config file.
        PRIVATE ${CMAKE_BINARY_DIR}
        )

# Define locations for the library to be built to.  
install(TARGETS TestLib DESTINATION lib)
install(FILES test.h DESTINATION include)