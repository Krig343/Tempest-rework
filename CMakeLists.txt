cmake_minimum_required(VERSION 3.0)

# General informations about the top level project
project(projet_prog_avancee_tempest
        VERSION 1.0
        DESCRIPTION "Project for the Programmation Avancée cours"
        LANGUAGES CXX)

# Use c++20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/projet/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/SDL/sdl2_base_vectors")