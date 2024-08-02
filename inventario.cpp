#include "inventario.h"
#include <algorithm>
#include <iostream>

Inventario::Inventario() {

}

Inventario::~Inventario() {
    for (Producto* producto : productos) {
        delete producto;
    }
    productos.clear();
}

void Inventario::agregarProducto(Producto* producto) {
    productos.push_back(producto);
}

void Inventario::eliminarProducto(const std::string& nombre) {
    auto it = std::find_if(productos.begin(), productos.end(), [&](Producto* producto) {
        return producto->getNombre() == nombre;
    });

    if (it != productos.end()) {
        delete *it;
        productos.erase(it);
    } else {
        std::cerr << "Producto no encontrado para eliminar." << std::endl;
    }
}

Producto* Inventario::buscarProducto(const std::string& nombre) const {
    auto it = std::find_if(productos.begin(), productos.end(), [&](Producto* producto) {
        return producto->getNombre() == nombre;
    });

    if (it != productos.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

void Inventario::mostrarInventario() const {
    for (const Producto* producto : productos) {
        producto->mostrarInformacion();
        std::cout << std::endl;
    }
}

double Inventario::calcularValorInventario() const {
    double valorTotal = 0.0;
    for (const Producto* producto : productos) {
        valorTotal += producto->calcularValorTotal();
    }
    return valorTotal;
}
