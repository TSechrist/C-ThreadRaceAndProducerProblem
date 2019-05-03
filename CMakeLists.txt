cmake_minimum_required(VERSION 3.13)
project(csc415_p5_TSechrist C)

set(CMAKE_C_STANDARD 11)

add_executable(csc415_p5_TSechrist
        part1/pthread_race.c
        part2/pandc.c)
