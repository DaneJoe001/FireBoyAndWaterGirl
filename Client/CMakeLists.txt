file(GLOB_RECURSE SOURCES source/*.cpp source/*.cc include/*.h include/*.hpp)

set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/Client/resource")

# 将资源路径定义为预处理宏
add_definitions(-DRESOURCE_DIR="${RESOURCE_DIR}")

add_executable(client ${SOURCES})

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_include_directories(client PUBLIC include)

target_link_libraries(client
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )

target_link_libraries(client PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

target_link_libraries(client PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)

target_link_libraries(client PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

target_link_libraries(client PRIVATE nlohmann_json::nlohmann_json)
