//
// Created by Jorge Luis on 3/29/2024.
//

#ifndef PROYECTOFINALV2_HINMOBILIARIO_H
#define PROYECTOFINALV2_HINMOBILIARIO_H


#include <iostream>
#include <string>
#include "../medios/Medio.h"
#include "../enum/TipoHinmobiliario.h"
#include "../enum/Ubicacion.h"

// Definición de las enums necesarias




// Clase Inmoviliario
class Hinmobiliario : public Medio {
private:
    TipoHinmobiliario tipoHimobiliarios;
    std::string probedor;
    int tiempoExplotacionMeses;
    Ubicacion ubicacion;

public:
    // Constructor
    Hinmobiliario(int numeroInventario, double costoUnitario, EstadoEquipo estadoActual,
                  TipoHinmobiliario tipoHimobiliarios, std::string probedor, int tiempoExplotacionMeses,
                  Ubicacion ubicacion)
            : Medio(numeroInventario, costoUnitario, estadoActual), tipoHimobiliarios(tipoHimobiliarios),
              probedor(probedor), tiempoExplotacionMeses(tiempoExplotacionMeses), ubicacion(ubicacion) {}

    // Método para calcular el costo inmobiliario
    double m_CostoInmobiliario() const {
        return costoUnitario * 0.05; // Valor de retorno temporal
    }

    // Getters y Setters
    TipoHinmobiliario getTipoHimobiliarios() const { return tipoHimobiliarios; }

    void setTipoHimobiliarios(TipoHinmobiliario tipoHimobiliarios) { this->tipoHimobiliarios = tipoHimobiliarios; }

    std::string getProbedor() const { return probedor; }

    void setProbedor(std::string probedor) { this->probedor = probedor; }

    int getTiempoExplotacionMeses() const { return tiempoExplotacionMeses; }

    void
    setTiempoExplotacionMeses(int tiempoExplotacionMeses) { this->tiempoExplotacionMeses = tiempoExplotacionMeses; }

    Ubicacion getUbicacion() const { return ubicacion; }

    void setUbicacion(Ubicacion ubicacion) { this->ubicacion = ubicacion; }

    //Valor del enum
    const char *to_strStateH(EstadoEquipo te) const {
        switch (te) {
            case EstadoEquipo::Bien:
                return "Bien";
            case EstadoEquipo::Mal:
                return "Mal";
            case EstadoEquipo::Regular:
                return "Regular";

        }
        return "<none>"; // Valor por defecto en caso de un valor desconocido
    }

    const char *to_steTipoE(TipoHinmobiliario m) const {
        switch (m) {
            case TipoHinmobiliario::Buro:
                return "Buro";
            case TipoHinmobiliario::Cama:
                return "Cama";
            case TipoHinmobiliario::Mesa:
                return "Mesa";
            case TipoHinmobiliario::Mueble_PC:
                return "Mueble_PC";
            case TipoHinmobiliario::Silla:
                return "Silla";
        }
        return "<none>"; // Valor por defecto en caso de un valor desconocido
    }

    const char *to_steUbicacion(Ubicacion m) const {
        switch (m) {
            case Ubicacion::Apartamento:
                return "Apartment";
            case Ubicacion::Aula:
                return "Class room";
            case Ubicacion::Laboratorio:
                return "Laboratory";
            case Ubicacion::Oficina:
                return "Office";
        }
        return "<none>"; // Valor por defecto en caso de un valor desconocido
    }


    // Método toString
    std::string toString() const {
        return "\nType:                " + std::string(to_steTipoE(tipoHimobiliarios)) +
               "\nSupplier:            " + probedor +
               "\nTime Exploitation:   " + std::to_string(tiempoExplotacionMeses) +
               "\nLocation:            " + std::string(to_steUbicacion(ubicacion)) +
               "\nNunInvent:           " + std::to_string(getNumeroInventario()) +
               "\nUnite Cost:          " + std::to_string(getCostoUnitario()) +
               "\nEstate:              " + std::string(to_strStateH(getEstadoActual()));
    }
    bool operator=(const Hinmobiliario& other) const {
        return this->numeroInventario == other.getNumeroInventario();
    }


};


#endif //PROYECTOFINALV2_HINMOBILIARIO_H
