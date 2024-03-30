//
// Created by Jorge Luis on 3/29/2024.
//

#ifndef PROYECTOFINALV2_SERVICEC_H
#define PROYECTOFINALV2_SERVICEC_H

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include "../model/hinmoviliarios/Hinmobiliario.h"
#include "../model/electrodomesticos/Electrodomestico.h"

class ServiceC {
private:
    std::vector<Hinmobiliario> inmoviliarios;
    std::vector<Electrodomestico> electrodomesticos;
    int cont = 0;

public:
    ServiceC() {

    }


    //Manipular Listas

    void m_Costo_Total_EquiposANDMuebles() {
        double costoElectrodomesticos = std::accumulate(electrodomesticos.begin(), electrodomesticos.end(), 0.0, [](double sum, const Electrodomestico& e) {
            return sum + e.m_CostoElectrodomestico();
        });

        double costoHinmobiliaria = std::accumulate(inmoviliarios.begin(), inmoviliarios.end(), 0.0, [](double sum, const Hinmobiliario& i) {
            return sum + i.m_CostoInmobiliario();
        });

        std::cout << "------------------------Costo Total------------------------\n"
                  << "Equipos:   " << costoElectrodomesticos << "\n"
                  << "Muebles:   " << costoHinmobiliaria << "\n"
                  << "-----------------------------------------------------------------\n";
    }


    void m_showEquiposDelMismoTipo() {
        int cantiadAires[5] = {0, 0, 0, 0, 0};
        int cantiadComputadoras[5] = {0, 0, 0, 0, 0};
        int cantidadRefrigerador[5] = {0, 0, 0, 0, 0};
        int cantiadTelevisor[5] = {0, 0, 0, 0, 0};
        int cantiadVideoCasetera[5] = {0, 0, 0, 0, 0};

        for (const auto& elect : this->electrodomesticos) {
            switch (elect.getTipoElectrodomestico()) {
                case TipoElectrodomestico::AireAcondicionado:
                    refeactory_Switch_cantidadElementosMismoTipo(cantiadAires, elect.getMarca());
                    break;
                case TipoElectrodomestico::Videocasetera:
                    refeactory_Switch_cantidadElementosMismoTipo(cantiadVideoCasetera, elect.getMarca());
                    break;
                case TipoElectrodomestico::Computadora:
                    refeactory_Switch_cantidadElementosMismoTipo(cantiadComputadoras, elect.getMarca());
                    break;
                case TipoElectrodomestico::Televisor:
                    refeactory_Switch_cantidadElementosMismoTipo(cantiadTelevisor, elect.getMarca());
                    break;
                case TipoElectrodomestico::Refrigerador:
                    refeactory_Switch_cantidadElementosMismoTipo(cantidadRefrigerador, elect.getMarca());
                    break;
            }
        }

        std::cout << "------------------------Cantidad Elementos Mismo Tipo------------------------\n"
                  << "Aires:   " << cantiadAires[4] << "\n"
                  << "Computadoras:   " << cantiadComputadoras[4] << "\n"
                  << "Televisores:   " << cantiadTelevisor[4] << "\n"
                  << "Videocaseteras:   " << cantiadVideoCasetera[4] << "\n"
                  << "Refrigeradores:   " << cantidadRefrigerador[4] << "\n"
                  << "-----------------------------------------------------------------\n";
    }

    void refeactory_Switch_cantidadElementosMismoTipo(int cantiadEquipos_Mismo_Tipo[], Marca marca) {
        switch (marca) {
            case Marca::LG:
                cantiadEquipos_Mismo_Tipo[4]++;
                break;
            case Marca::Panda:
                cantiadEquipos_Mismo_Tipo[3]++;
                break;
            case Marca::Atec:
                cantiadEquipos_Mismo_Tipo[2]++;
                break;
            case Marca::Sanyo:
                cantiadEquipos_Mismo_Tipo[1]++;
                break;
            case Marca::Sony:
                cantiadEquipos_Mismo_Tipo[0]++;
                break;
        }
    }


    std::vector<Hinmobiliario> getInmoviliarios() {
        return inmoviliarios;
    }


    std::vector<Electrodomestico> getElectrodomesticos() {
        return electrodomesticos;
    }

    void m_RemuveAll_Inmobiliario() {
        inmoviliarios.clear();
    }

    void m_RemuveAll_Electrodomesticos() {
        electrodomesticos.clear();
    }

    void addNewInmoviliario_Object(Hinmobiliario i) {
        inmoviliarios.push_back(i);
    }

    void addNewElectrodomestico_Object(Electrodomestico e) {
        electrodomesticos.push_back(e);
    }

    void m_ShowDate_Electrodomesticos_Consola() {

        // Imprimir elementos de electrodomesticos
        for (const auto& electrodomestico : electrodomesticos) {
            std::cout << electrodomestico.toString() << std::endl;
        }
    }

    void m_ShowDate_Hinmobiliaria_Consola() {
        for (const auto& inmobiliario : inmoviliarios) {
            std::cout << inmobiliario.toString() << std::endl;
        }

    }
/**
 *
Elimina por número de inventario
 */
    void m_RemuveElement(int numeroInventario) {
        try {
            for (auto it = inmoviliarios.begin(); it != inmoviliarios.end(); ++it) {
                if (it->getNumeroInventario() == numeroInventario) {
                    inmoviliarios.erase(it);
                    std::cout << "Se elimino correctamente el hinmoviliario" << std::endl;
                    return;
                }
            }
            for (auto it = electrodomesticos.begin(); it != electrodomesticos.end(); ++it) {
                if (it->getNumeroInventario() == numeroInventario) {
                    electrodomesticos.erase(it);
                    std::cout << "Se elimino correctamente el electrodomestico" << std::endl;
                    return;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        std::cout << "No existe el elemento que desea eliminar" << std::endl;
    }
};

#endif //PROYECTOFINALV2_SERVICEC_H
