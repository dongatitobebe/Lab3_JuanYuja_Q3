#include "producto.h"

Producto::Producto(const std::string& nombre, double precio, const std::string& descripcion)
    : nombre(nombre), precio(precio), descripcion(descripcion) {}

Producto::~Producto() {}

void Producto::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Precio: " << precio << std::endl;
    std::cout << "Descripción: " << descripcion << std::endl;
}

std::string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const {
    return precio;
}
