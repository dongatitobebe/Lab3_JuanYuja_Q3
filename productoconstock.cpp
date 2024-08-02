#include "productoConStock.h"

ProductoConStock::ProductoConStock(const std::string& nombre, double precio, const std::string& descripcion, int cantidad)
    : Producto(nombre, precio, descripcion), cantidad(cantidad) {}

double ProductoConStock::calcularValorTotal() const {
    return precio * cantidad;
}

void ProductoConStock::mostrarInformacion() const {
    Producto::mostrarInformacion();
    std::cout << "Cantidad en stock: " << cantidad << std::endl;
}

int ProductoConStock::getCantidad() const {
    return cantidad;
}
