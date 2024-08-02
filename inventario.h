#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
#include "producto.h"

class Inventario {
public:
    Inventario();
    ~Inventario();
    void agregarProducto(Producto* producto);
    void eliminarProducto(const std::string& nombre);
    Producto* buscarProducto(const std::string& nombre) const;
    void mostrarInventario() const;
    double calcularValorInventario() const;

private:
    std::vector<Producto*> productos;
};

#endif // INVENTARIO_H

