cmake_minimum_required(VERSION 3.8)
project(Wiener_process)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
        main.c
        PRNG_uniform.c
        Marsaglia_polar_generator.c
        Wiener.h
        )
add_executable(Wiener_process ${SOURCE_FILES})

target_link_libraries(Wiener_process m)