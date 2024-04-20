cmake_minimum_required(VERSION 3.0.0)
project(easylibc VERSION 0.1.0 LANGUAGES C)

include_directories(${PROJECT_SOURCE_DIR}/easylibc)

aux_source_directory(${PROJECT_SOURCE_DIR}/easylibc SRC)
add_executable(easylibc main.c ${SRC})


