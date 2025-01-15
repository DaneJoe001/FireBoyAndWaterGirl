file(GLOB_RECURSE SOURCES source/*.cpp source/*.cc include/*.h include/*.hpp)

add_executable(client ${SOURCES})

target_include_directories(client PUBLIC include)