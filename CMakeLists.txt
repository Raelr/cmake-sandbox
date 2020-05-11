# Set the required version of CMAKE
cmake_minimum_required(VERSION 3.10)

# Set some requirements.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the project name
project(CMAKETest VERSION 0.1)

option(USE_TEST "Use the test implementation" ON)

# Set the configuration file (which defines macros)
configure_file(ProjectA.h.in ProjectA.h)

# Use conditional formatting to include project.
if (USE_TEST)
    # Adds TestLib as a subdirectory from which to take code.
    add_subdirectory(TestLib)
    list(APPEND EXTRA_LIBS TestLib)
endif()

# Defines which file will act as the entrypoint. 
add_executable(CMAKETest ProjectA.cpp)

# Link TestLib with the current project. 
target_link_libraries(CMAKETest PUBLIC ${EXTRA_LIBS})
# Set the project to search the following directories for the files. 
target_include_directories(CMAKETest PUBLIC "${PROJECT_BINARY_DIR}")
