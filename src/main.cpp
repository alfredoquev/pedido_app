#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "pedido.hpp"

struct ComparadorPrioridad {
    bool operator()(const std::vector<Pedido>& a, const std::vector<Pedido>& b) const {
        int sumaA = 0, sumaB = 0;
        for (const auto& p : a) sumaA += p.getCantidad();
        for (const auto& p : b) sumaB += p.getCantidad();
        return sumaA < sumaB;
    }
};

std::vector<Pedido> pedidosRegistrados;
std::queue<std::vector<Pedido>> colaNormal;
std::priority_queue<std::vector<Pedido>, std::vector<std::vector<Pedido>>, ComparadorPrioridad> colaSuscriptores;

void registrarPedido() {
    std::vector<Pedido> nuevoGrupo;
    char agregarOtro;

    do {
        Pedido nuevo;
        std::cin >> nuevo;
        nuevoGrupo.push_back(nuevo);
        pedidosRegistrados.push_back(nuevo);

        std::cout << "¿Agregar otro pedido al grupo? (s/n): ";
        std::cin >> agregarOtro;
        std::cin.ignore();
    } while (agregarOtro == 's' || agregarOtro == 'S');

    char esSuscriptor;
    std::cout << "¿El cliente es suscriptor? (s/n): ";
    std::cin >> esSuscriptor;
    std::cin.ignore();

    if (esSuscriptor == 's' || esSuscriptor == 'S') {
        colaSuscriptores.push(nuevoGrupo);
        std::cout << "Grupo agregado a cola de suscriptores.\n";
    } else {
        colaNormal.push(nuevoGrupo);
        std::cout << "Grupo agregado a cola normal.\n";
    }
}

void procesarPedido() {
    if (!colaSuscriptores.empty()) {
        auto grupo = colaSuscriptores.top();
        std::cout << "Procesando grupo prioritario:\n";
        for (const auto& p : grupo) std::cout << p << "\n";
        colaSuscriptores.pop();
    } else if (!colaNormal.empty()) {
        auto grupo = colaNormal.front();
        std::cout << "Procesando grupo normal:\n";
        for (const auto& p : grupo) std::cout << p << "\n";
        colaNormal.pop();
    } else {
        std::cout << "No hay pedidos en cola.\n";
    }
}

void eliminarPedido() {
    int idEliminar;
    std::cout << "Ingrese el ID del pedido a eliminar: ";
    std::cin >> idEliminar;

    auto it = std::remove_if(pedidosRegistrados.begin(), pedidosRegistrados.end(),
                             [idEliminar](const Pedido& p) { return p.getId() == idEliminar; });

    if (it != pedidosRegistrados.end()) {
        pedidosRegistrados.erase(it, pedidosRegistrados.end());
        std::cout << "Pedido eliminado correctamente.\n";
    } else {
        std::cout << "No se encontró un pedido con ese ID.\n";
    }
}

void mostrarPedidos() {
    if (pedidosRegistrados.empty()) {
        std::cout << "No hay pedidos registrados.\n";
    } else {
        for (const auto& p : pedidosRegistrados) {
            std::cout << p << "\n";
        }
    }
}

int main() {
    int opcion;

    do {
        std::cout << "\n--- MENU DE PEDIDOS ---\n";
        std::cout << "1. Registrar pedido\n";
        std::cout << "2. Procesar pedido\n";
        std::cout << "3. Eliminar pedido\n";
        std::cout << "4. Mostrar pedidos\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1: registrarPedido(); break;
            case 2: procesarPedido(); break;
            case 3: eliminarPedido(); break;
            case 4: mostrarPedidos(); break;
            case 0: std::cout << "Saliendo del programa...\n"; break;
            default: std::cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}
