//
// Created by Jorge Luis on 3/29/2024.
//

#ifndef PROYECTOFINALV2_MEDIO_H
#define PROYECTOFINALV2_MEDIO_H

#include <iostream>
#include <string>
#include "../enum/EstadoEquipo.h"

class Medio {

protected:
    int numeroInventario;
    double costoUnitario;
    EstadoEquipo estadoActual;

public:
    // Constructor
    Medio(int numeroInventario, double costoUnitario, EstadoEquipo estadoActual)
            : numeroInventario(numeroInventario), costoUnitario(costoUnitario), estadoActual(estadoActual) {}

    // Getters y Setters
    int getNumeroInventario() const { return numeroInventario; }
    void setNumeroInventario(int numeroInventario) { this->numeroInventario = numeroInventario; }

    double getCostoUnitario() const { return costoUnitario; }
    void setCostoUnitario(double costoUnitario) { this->costoUnitario = costoUnitario; }

    EstadoEquipo getEstadoActual() const { return estadoActual; }
    void setEstadoActual(EstadoEquipo estadoActual) { this->estadoActual = estadoActual; }


    virtual // Método toString
    std::string toString() const {
        return "numeroInventario=" + std::to_string(numeroInventario) +
               ", costoUnitario=" + std::to_string(costoUnitario) +
               ", estadoActual=" + std::to_string(static_cast<int>(estadoActual));
    }
};


#endif //PROYECTOFINALV2_MEDIO_H
