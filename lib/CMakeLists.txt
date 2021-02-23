add_library(
    catch2
    catch2/catch_amalgamated.cpp
    )

target_include_directories(catch2 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")