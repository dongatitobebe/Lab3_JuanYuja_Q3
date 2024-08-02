#ifndef PRODUCTOCONSTOCK_H
#define PRODUCTOCONSTOCK_H

#include "producto.h"

class ProductoConStock : public Producto {
public:
    ProductoConStock(const std::string& nombre, double precio, const std::string& descripcion, int cantidad);
    double calcularValorTotal() const override;
    void mostrarInformacion() const override;
    int getCantidad() const;

private:
    int cantidad;
};

#endif // PRODUCTOCONSTOCK_H
