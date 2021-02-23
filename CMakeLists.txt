# Minimum CMake version allowed. This is the version on this environment
cmake_minimum_required(VERSION 3.16.3)

# Project name
project(BusyBiscuits_Database)

# Creating the flags variable to be all these flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

# Recursively searches through paths to find all .cpp files
# file(GLOB_RECURSE source_files "src/*.cpp" "lib/*.cpp")



# option(TestOption "TestOption" OFF)
# if (TestOption EQUAL "ON")
#     add_subdirectory()
add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test)

# Printing message to the console
# message (${source_files})

# Compiling the files in the 'source_files' variable and naming the 
#   executable 'main'
# add_executable(main ${source_files})
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE ds)
