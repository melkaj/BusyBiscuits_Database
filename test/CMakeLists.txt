# Recursively searches through paths to find all TEST files
file(GLOB_RECURSE test_files "*.cpp")

# add_executable(tests test_methods.cpp)
add_executable(tests ${test_files})
target_link_libraries(tests PRIVATE catch2 ds)
