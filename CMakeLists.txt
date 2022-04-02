cmake_minimum_required(VERSION 3.5)

project(mvc LANGUAGES C)

add_executable( mvc main.c libraries.h controller/controlCliente.c model/modelCliente.c
                view/viewCliente.c dataTypes/opaqueTypeCliente.h dataTypes/opaqueTypeClienteIntern.h
                menu/menu.h menu/menu.c controller/controlAlimento.c model/modelAlimento.c view/viewAlimento.c)

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/dataTypes ${CMAKE_SOURCE_DIR}/menu)
