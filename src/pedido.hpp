#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include <iostream>
#include <string>

class Pedido {
private:
    int id;
    std::string cliente;
    std::string producto;
    int cantidad;

public:
    Pedido();
    int getId() const;
    int getCantidad() const;

    friend std::istream& operator>>(std::istream& in, Pedido& p);
    friend std::ostream& operator<<(std::ostream& out, const Pedido& p);

    bool operator<(const Pedido& other) const;
};

#endif

