cmake_minimum_required(VERSION 3.22)
project(chess)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wpedantic -Wextra")

# External Libraries
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/third_party/SDL/install")
find_package(SDL3 REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/source
)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/include/*.h"
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/source/*.cpp"
    "${PROJECT_SOURCE_DIR}/source/*.c"
)

add_executable(${CMAKE_PROJECT_NAME} ${all_SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} SDL3::SDL3)


add_custom_command(TARGET chess
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${PROJECT_SOURCE_DIR}/third_party/SDL/install/bin/SDL3.dll
                   $<TARGET_FILE_DIR:chess>/SDL3.dll
                   COMMENT "Copy SLD3.Dll into build folder"
                   )