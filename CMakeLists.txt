cmake_minimum_required(VERSION 3.26)
project(projet_info_TG C)

set(CMAKE_C_STANDARD 23)

add_executable(projet_info_TG main.c
        Affichagegeneral.c
        listedependance.c
        listedependance.h
        disparition_espece.h
        disparition_espece.c
        listedependance.h
        connexite.c
        connexite.h
        centralite.c
        centralite.h
        NivTrophiquesMaxLim.c
        NivTrophiquesMaxLim.h
        dynamique.c
        dynamique.h)

