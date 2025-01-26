cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

project(FireBoyAndWaterGirl LANGUAGES CXX)

add_subdirectory(Client)

add_subdirectory(Server)