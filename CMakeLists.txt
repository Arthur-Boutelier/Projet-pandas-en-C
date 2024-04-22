cmake_minimum_required(VERSION 3.27)
project(Projet_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_C
        colonne.c
        colonne.h
        cdataframe.h
        cdataframe.c
        list.h
        list.c
        sort.h
        sort.c
        main.c)
