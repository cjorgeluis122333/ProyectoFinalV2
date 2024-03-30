//
// Created by Jorge Luis on 3/29/2024.
//

#ifndef PROYECTOFINALV2_ELECTRODOMESTICO_H
#define PROYECTOFINALV2_ELECTRODOMESTICO_H


#include <iostream>
#include <string>
#include "../enum/TipoElectrodomestico.h"
#include "../medios/Medio.h"
#include "../enum/Marca.h"

class Electrodomestico : public Medio {
    private:
        TipoElectrodomestico tipoElectrodomestico;
        Marca marca;
        int garantiaMes;

    public:
        // Constructor
        Electrodomestico(int numeroInventario, double costoUnitario, EstadoEquipo estadoActual, TipoElectrodomestico tipoElectrodomestico, Marca marca, int garantiaMes)
                : Medio(numeroInventario, costoUnitario, estadoActual), tipoElectrodomestico(tipoElectrodomestico), marca(marca), garantiaMes(garantiaMes) {}

        // Método para calcular el costo electrodoméstico
        double m_CostoElectrodomestico() const {
            return costoUnitario * (garantiaMes * 0.08333);
        }

        // Getters y Setters
        TipoElectrodomestico getTipoElectrodomestico() const { return tipoElectrodomestico; }
        void setTipoElectrodomestico(TipoElectrodomestico tipoElectrodomestico) { this->tipoElectrodomestico = tipoElectrodomestico; }

        Marca getMarca() const { return marca; }
        void setMarca(Marca marca) { this->marca = marca; }

        int getGarantiaMes() const { return garantiaMes; }
        void setGarantiaMes(int garantiaMes) { this->garantiaMes = garantiaMes; }

        //Valor del enum
        const char * to_strTipe(TipoElectrodomestico te) const {
            switch(te) {
                case TipoElectrodomestico::Refrigerador: return "Refrigerador";
                case TipoElectrodomestico::Computadora: return "Computadora";
                case TipoElectrodomestico::AireAcondicionado: return "AireAcondicionado";
                case TipoElectrodomestico::Televisor: return "Televisor";
                case TipoElectrodomestico::Videocasetera: return "Videocasetera";

            }
            return "<none>"; // Valor por defecto en caso de un valor desconocido
        }

    const char * to_steMarca(Marca m) const {
        switch(m) {
            case Marca::Atec: return "Atec";
            case Marca::LG: return "LG";
            case Marca::Panda: return "Panda";
            case Marca::Sanyo: return "Sanyo";
            case Marca::Sony: return "Sony";
        }
        return "<none>"; // Valor por defecto en caso de un valor desconocido
    }
    const char * to_steEstado(EstadoEquipo m) const {
        switch(m) {
            case EstadoEquipo::Bien: return "Bien";
            case EstadoEquipo::Mal: return "Mal";
            case EstadoEquipo::Regular: return "Regular";

        }
        return "<none>"; // Valor por defecto en caso de un valor desconocido
    }

        // Método toString
        std::string toString() const {
            return "\n Type:                " + std::string(to_strTipe(tipoElectrodomestico)) +
                   "\n Marc:                " + std::string(to_steMarca(marca)) +
                   "\n Mon Warranty:        " + std::to_string(garantiaMes) +
                   "\n Number Inventory:    " + std::to_string(getNumeroInventario()) +
                   "\n Unite Cost:          " + std::to_string(getCostoUnitario()) +
                   "\n Estate:              " + std::string (to_steEstado(estadoActual));
        }

    // Método para representación modelada
        std::string m_ToStringModelado() {
            return "\n Type:            2   " + std::to_string(static_cast<int>(tipoElectrodomestico)) +
                   "\n Marc:               " + std::to_string(static_cast<int>(marca)) +
                   "\n Mon Warranty:       " + std::to_string(garantiaMes) +
                   "\n Number Inventory:   " + std::to_string(getNumeroInventario()) +
                   "\n Unite Cost:               " + std::to_string(getCostoUnitario()) +
                   "\n Final Cost:        " + std::to_string(m_CostoElectrodomestico()) +
                   "\n Estate:             " + std::to_string(static_cast<int>(getEstadoActual()));
        }

        // Métodos para comparar y serializar (deberás implementarlos según tus necesidades)
        bool operator==(const Electrodomestico& other) const {
            return this->numeroInventario == other.getNumeroInventario();
        }

    };


#endif //PROYECTOFINALV2_ELECTRODOMESTICO_H
