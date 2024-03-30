cmake_minimum_required(VERSION 3.26)
project(ProyectoFinalV2)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProyectoFinalV2 view/main.cpp
        model/enum/Discarted/enum_Ubicacion.cpp
        model/enum/Discarted/enum_Marca.cpp
        model/enum/Discarted/enum_EstadoEquipo.cpp
        model/enum/Discarted/enum_TipoHinmobiliario.cpp
        model/enum/Discarted/enum_TipoElectrodomestico.cpp
        model/enum/EstadoEquipo.cpp
        model/enum/EstadoEquipo.h
        model/enum/Marca.cpp
        model/enum/Marca.h
        model/enum/TipoElectrodomestico.cpp
        model/enum/TipoElectrodomestico.h
        model/enum/TipoHinmobiliario.cpp
        model/enum/TipoHinmobiliario.h
        model/enum/Ubicacion.cpp
        model/enum/Ubicacion.h
        model/electrodomesticos/Electrodomestico.cpp
        model/electrodomesticos/Electrodomestico.h
        model/hinmoviliarios/Hinmobiliario.cpp
        model/hinmoviliarios/Hinmobiliario.h
        model/medios/Medio.cpp
        model/medios/Medio.h
        controller/ServiceC.cpp
        controller/ServiceC.h
        model/exeption/MainInsertExeption.cpp
        model/exeption/MainInsertExeption.h)
