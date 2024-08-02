#include "productoConDescuento.h"

ProductoConDescuento::ProductoConDescuento(const std::string& nombre, double precio, const std::string& descripcion, double descuento)
    : Producto(nombre, precio, descripcion), descuento(descuento) {}

double ProductoConDescuento::calcularValorTotal() const {
    return precio * (1 - descuento / 100);
}

void ProductoConDescuento::mostrarInformacion() const {
    Producto::mostrarInformacion();
    std::cout << "Descuento: " << descuento << "%" << std::endl;
    std::cout << "Precio con descuento: " << calcularValorTotal() << std::endl;
}
