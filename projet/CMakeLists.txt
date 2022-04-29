cmake_minimum_required(VERSION 3.0)

# General informations about the project
project(tempest
        VERSION 1.0
        DESCRIPTION "Rebuild of the arcade game tempest"
        LANGUAGES CXX)

add_executable("tempest")

target_sources(${PROJECT_NAME}
               PRIVATE
               game.h
               game.cpp
               character.h
               character.cpp
               player.h
               player.cpp
               electricwell.h
               electricwell.cpp
               lane.h
               lane.cpp
               missile.h
               missile.cpp
               flipper.h
               flipper.cpp
               tanker.h
               tanker.cpp
               main.cpp)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static)