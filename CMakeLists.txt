cmake_minimum_required(VERSION 3.26)
project(projet_info_TG C)

set(CMAKE_C_STANDARD 23)

add_executable(projet_info_TG main.c
        Affichagegeneral.c
        listedependance.c
        listedependance.h)
