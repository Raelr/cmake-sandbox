# Set the required version of CMAKE
cmake_minimum_required(VERSION 3.10)

# Set some requirements.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# Set the project name
project(CMAKETest VERSION 0.1)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

#option(USE_TEST "Use the test implementation" ON)

# Set the configuration file (which defines macros)
configure_file(ProjectA.h.in ProjectA.h)

# Use conditional formatting to include project.
#if (USE_TEST)
    # Adds TestLib as a subdirectory from which to take code.
    #add_subdirectory(TestLib)
    #list(APPEND EXTRA_LIBS TestLib)
#endif()

add_subdirectory(TestLib)

# Defines which file will act as the entrypoint. 
add_executable(CMAKETest ProjectA.cpp)

# Link TestLib with the current project. 
target_link_libraries(CMAKETest PUBLIC TestLib)
# Set the project to search the following directories for the files. 
target_include_directories(CMAKETest PUBLIC "${PROJECT_BINARY_DIR}")

#install(TARGETS CMAKETest DESTINATION bin)
#install(FILES "${PROJECT_BINARY_DIR}/ProjectA.h"
#        DESTINATION include
#        )

# ------------------- TESTING ---------------------------------------

enable_testing()

# Tests whether the application runs.
add_test(NAME Runs COMMAND CMAKETest)

# -------------- SYSTEM INTROSPECTION ------------------------------- 

# NOTE this is isn't really needed anymore since we've defined this in the TestLib 
# CMAKElists.

# Allows us to check if specific methods or symbols exist in a file.
# include(CheckSymbolExists)

# Checks the cmath library for whether the 'log' and 'exp' symbols exist.
# binds the output to the macros: HAVE_LOG and HAVE_EXP
# set(CMAKE_REQUIRED_LIBRARIES "m")

# check_symbol_exists(log "math.h" HAVE_LOG)
# check_symbol_exists(exp "math.h" HAVE_EXP)

# --------------------- INSTALLER ------------------------------------

# includes any runtime libraries needed by the project. 
include(InstallRequiredSystemLibraries)
# Sets the version of the project.
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
# include the CPack module for building. 
include(CPack)