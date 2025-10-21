#include "pedido.hpp"

Pedido::Pedido() : id(0), cantidad(0) {}

int Pedido::getId() const { return id; }
int Pedido::getCantidad() const { return cantidad; }

std::istream& operator>>(std::istream& in, Pedido& p) {
    std::cout << "ID del pedido: ";
    in >> p.id;
    in.ignore();
    std::cout << "Nombre del cliente: ";
    std::getline(in, p.cliente);
    std::cout << "Producto: ";
    std::getline(in, p.producto);
    std::cout << "Cantidad: ";
    in >> p.cantidad;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pedido& p) {
    out << "Pedido #" << p.id << "\n"
        << "Cliente: " << p.cliente << "\n"
        << "Producto: " << p.producto << "\n"
        << "Cantidad: " << p.cantidad << "\n";
    return out;
}

bool Pedido::operator<(const Pedido& other) const {
    return cantidad < other.cantidad;
}
