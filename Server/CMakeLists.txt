file(GLOB_RECURSE SOURCES source/*.cpp source/*.cc include/*.h include/*.hpp)

add_executable(server ${SOURCES})

target_include_directories(server PUBLIC include)