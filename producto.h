#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

class Producto {
public:
    Producto(const std::string& nombre, double precio, const std::string& descripcion);
    virtual ~Producto();

    virtual void mostrarInformacion() const;
    std::string getNombre() const;
    double getPrecio() const;
    virtual double calcularValorTotal() const = 0;

protected:
    std::string nombre;
    double precio;
    std::string descripcion;
};

#endif // PRODUCTO_H
