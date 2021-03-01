add_library(
    database
    cli/cli.cpp
    databasemanager/databasemanager.cpp
    datastructure/datastructure.cpp
    logger/logger.cpp
    rwdata/rwdata.cpp
)

file(GLOB_RECURSE header_files "./*.h")

install(TARGETS database DESTINATION ${PROJECT_SOURCE_DIR}/build/installer/lib)
install(FILES ${header_files} DESTINATION ${PROJECT_SOURCE_DIR}/build/installer/include)
