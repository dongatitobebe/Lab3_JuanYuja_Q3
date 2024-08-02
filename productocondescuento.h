#ifndef PRODUCTOCONDESCUENTO_H
#define PRODUCTOCONDESCUENTO_H

#include "producto.h"

class ProductoConDescuento : public Producto {
public:
    ProductoConDescuento(const std::string& nombre, double precio, const std::string& descripcion, double descuento);
    double calcularValorTotal() const override;
    void mostrarInformacion() const override;

private:
    double descuento;
};

#endif // PRODUCTOCONDESCUENTO_H
