cmake_minimum_required(VERSION 3.23.0)

project(2DPlatformer)

set(DEPS_DIR ${CMAKE_SOURCE_DIR}/build/external)

add_subdirectory(external/SDL2)

add_subdirectory(external/SDL_image)

file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB HEADER_FILES include/*.h)
  
add_executable(2DPlatformer ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(2DPlatformer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/
                                            ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL2/include/
                                            ${CMAKE_CURRENT_SOURCE_DIR}/external/SDL_image/)

target_link_libraries(2DPlatformer SDL2 SDL2main SDL2_image)

add_custom_command(TARGET 2DPlatformer POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    "${DEPS_DIR}/SDL2/Debug/SDL2d.dll"
                    "${DEPS_DIR}/SDL_image/Debug/SDL2_imaged.dll"
                    $<TARGET_FILE_DIR:2DPlatformer>)

add_custom_command(TARGET 2DPlatformer POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:2DPlatformer>/res)