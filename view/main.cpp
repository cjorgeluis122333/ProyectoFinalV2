#include <iostream>
#include "../controller/ServiceC.h"
#include "../model/exeption/MainInsertExeption.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

/**
 *@author Jorge Luis Castillo Vidal
 * @param cont
 * @param service
 * Inserta un nuevo inmobiliarios  a un vector de la clase serviceC
 */

void insertarNuevoHinmoviliario(int cont, ServiceC &service) {

    double cost;
    int estTpInt, typeH, garantia, tipeUbication;
    EstadoEquipo estado;
    TipoHinmobiliario typeHimobiliarios;
    Ubicacion ubicacion;

    std::cout << "Inserta el costo del inmobiliarios " << std::endl;
    std::cin >> cost;

    std::cout << "Inserta el estado del inmobiliarios \n1- Bien\n2- Mal\n3- Regular" << std::endl;
    std::cin >> estTpInt;
    switch (estTpInt) {
        case 1:
            estado = EstadoEquipo::Bien;
            break;
        case 2:
            estado = EstadoEquipo::Mal;
            break;
        case 3:
            estado = EstadoEquipo::Regular;
            break;
        default:
            throw MainInsertExeption("Invalid estado");
    }

    std::cout << "Inserta el tipo del inmobiliarios \n1- Buro\n2- Cama\n3- Mesa\n4- Mueble_PC\n5- Silla" << std::endl;
    std::cin >> typeH;
    switch (typeH) {
        case 1:
            typeHimobiliarios = TipoHinmobiliario::Buro;
            break;
        case 2:
            typeHimobiliarios = TipoHinmobiliario::Cama;
            break;
        case 3:
            typeHimobiliarios = TipoHinmobiliario::Mesa;
            break;
        case 4:
            typeHimobiliarios = TipoHinmobiliario::Mueble_PC;
            break;
        case 5:
            typeHimobiliarios = TipoHinmobiliario::Silla;
            break;
        default:
            throw MainInsertExeption("Invalid tipo");
    }

    std::cout << "Inserte la garantia en meses del hinmobiliario" << std::endl;
    std::cin >> garantia;

    std::cout << "Inserte el lugar del hinmobiliario\n1- Laboratorio\n2- Aula\n3- Apartamento\n4- Oficina" << std::endl;
    std::cin >> tipeUbication;
    switch (tipeUbication) {
        case 1:
            ubicacion = Ubicacion::Laboratorio;
            break;
        case 2:
            ubicacion = Ubicacion::Aula;
            break;
        case 3:
            ubicacion = Ubicacion::Apartamento;
            break;
        case 4:
            ubicacion = Ubicacion::Oficina;
            break;
        default:
            throw MainInsertExeption("Invalid ubicación");
    }

    service.addNewInmoviliario_Object(
            Hinmobiliario(cont, cost, estado, typeHimobiliarios, "Gobierno", garantia, ubicacion));
    std::cout << "El inmoviliario a sido guardado correctamente" << std::endl;

}

void insertNewElectrodomestic(int cont, ServiceC &service) {

    double cost;
    int estTpInt, typeH, garantia, tipeMarca;
    EstadoEquipo estado;
    TipoElectrodomestico typeElectrodomestico;
    Marca marca;

    std::cout << "Inserta el costo del electrodomestico" << std::endl;
    std::cin >> cost;

    std::cout << "Inserta el estado del electrodomestico\n1- Bien\n2- Mal\n3- Regular" << std::endl;
    std::cin >> estTpInt;
    switch (estTpInt) {
        case 1:
            estado = EstadoEquipo::Bien;
            break;
        case 2:
            estado = EstadoEquipo::Mal;
            break;
        case 3:
            estado = EstadoEquipo::Regular;
            break;
        default:
            throw MainInsertExeption("Invalid estado");
    }

    std::cout
            << "Inserta el tipo de electrodomestico\n1- AireAcondicionado\n2- Computadora\n3- Refrigerador\n4- Televisor\n5- Videocasetera"
            << std::endl;
    std::cin >> typeH;
    switch (typeH) {
        case 1:
            typeElectrodomestico = TipoElectrodomestico::AireAcondicionado;
            break;
        case 2:
            typeElectrodomestico = TipoElectrodomestico::Computadora;
            break;
        case 3:
            typeElectrodomestico = TipoElectrodomestico::Refrigerador;
            break;
        case 4:
            typeElectrodomestico = TipoElectrodomestico::Televisor;
            break;
        case 5:
            typeElectrodomestico = TipoElectrodomestico::Videocasetera;
            break;
        default:
            throw MainInsertExeption("Invalid tipo");
    }

    std::cout << "Inserte la garantia del electrodomestico (numero de mese)" << std::endl;
    std::cin >> garantia;

    std::cout << "Inserte la marca del electrodomestico\n1- Sony\n2- Sanyo\n3- Atec\n4- Panda\n5- LG" << std::endl;
    std::cin >> tipeMarca;
    switch (tipeMarca) {
        case 1:
            marca = Marca::Sony;
            break;
        case 2:
            marca = Marca::Sanyo;
            break;
        case 3:
            marca = Marca::Atec;
            break;
        case 4:
            marca = Marca::Panda;
            break;
        case 5:
            marca = Marca::LG;
            break;
        default:
            throw MainInsertExeption("Invalid marca");
    }

    // Assuming Electrodomestico constructor and addNewElectrodomestico_Object method are defined
    service.addNewElectrodomestico_Object(Electrodomestico(cont, cost, estado, typeElectrodomestico, marca, garantia));
    std::cout << "El electrodomestico a sido guardado correctamente" << std::endl;
}

int main() {

    ServiceC serviceC;
    serviceC.addNewElectrodomestico_Object(
            Electrodomestico(1, 1500, EstadoEquipo::Bien, TipoElectrodomestico::Computadora, Marca::Sony, 13));
    serviceC.addNewElectrodomestico_Object(
            Electrodomestico(2, 230, EstadoEquipo::Mal, TipoElectrodomestico::Televisor, Marca::LG, 13));
    serviceC.addNewElectrodomestico_Object(
            Electrodomestico(3, 600, EstadoEquipo::Regular, TipoElectrodomestico::AireAcondicionado, Marca::LG, 13));


    serviceC.addNewInmoviliario_Object(
            Hinmobiliario(4, 230, EstadoEquipo::Mal, TipoHinmobiliario::Buro, "Gobierno", 13, Ubicacion::Apartamento));
    serviceC.addNewInmoviliario_Object(
            Hinmobiliario(5, 330, EstadoEquipo::Mal, TipoHinmobiliario::Buro, "Gobierno", 22, Ubicacion::Oficina));
    serviceC.addNewInmoviliario_Object(
            Hinmobiliario(6, 530, EstadoEquipo::Bien, TipoHinmobiliario::Buro, "Gobierno", 5, Ubicacion::Apartamento));


    int a = -1;
    std::string input;
    int cont = 7;
    std::string msgTitle;
    msgTitle =
            "\n========================                        Select the option do you want                        ==================="
            "\n1. Insertar  un nuevo inmobiliarios "
            "\n2. Insertar  un nuevo electrodomestico"
            "\n3. Mostrar todos los inmobiliarios "
            "\n4. Mostrar todos los electrodomesticos"
            "\n5. Costo total equipos y inmobiliarios "
            "\n6. Electrodomesticos del mismo tipo"
            "\n7. Eliminar electrodomestico o hinmobiliario por numero de inventario"
            "\n8. Eliminar todos los inmobiliarios "
            "\n9. Eliminar todos los electrodomestico"

            "\n0. Salir";

    while (a != 0) {
        std::cout << msgTitle << std::endl;

        try {
            std::cin >> a;
            //std::cin >> a;
            switch (a) {
                case 1: {
                    std::cout << "========================                        Insertar un nuevo inmobiliarios "
                              << std::endl;
                    try {
                        insertarNuevoHinmoviliario(cont, serviceC);
                        cont = cont + 1;
                    } catch (const MainInsertExeption &e) {
                        std::cout << e.what() << std::endl;
                        a = 0;
                    }
                }
                    break;
                case 2: {
                    std::cout << "========================                        Insertar un nuevo electrodomestico"
                              << std::endl;
                    try {
                        insertNewElectrodomestic(cont, serviceC);
                        cont++;
                    } catch (const MainInsertExeption &e) {
                        std::cout << e.what() << std::endl;
                        a = 0;
                    }
                }
                    break;
                case 3:
                    serviceC.m_ShowDate_Hinmobiliaria_Consola();
                    break;
                case 4:
                    serviceC.m_ShowDate_Electrodomesticos_Consola();
                    break;
                case 5:
                    serviceC.m_Costo_Total_EquiposANDMuebles();
                    break;
                case 6:
                    serviceC.m_showEquiposDelMismoTipo();
                    break;
                case 7: {
                    int nu;
                    std::cout << "========================                        Inserte el numero de inventario)"
                              << std::endl;

                    std::cin >> nu;
                    serviceC.m_RemuveElement(nu);
                }
                    break;

                case 8: {
                    std::cout << "========================                        Todos los electrodomesticos fueron eliminados)"
                              << std::endl;
                    serviceC.m_RemuveAll_Electrodomesticos();
                }
                    break;
                case 9: {
                    std::cout << "========================                        Todos los inmobiliarios  fueron eliminados)"
                              << std::endl;
                    serviceC.m_RemuveAll_Inmobiliario();
                }
                    break;
                default: {
                    std::cout << "Apegese a las opciones" << std::endl;
                }
                    break;
            }
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;


}
