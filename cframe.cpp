#include "cframe.h"
#include "ui_cframe.h"
#include "productoConDescuento.h"
#include "productoConStock.h"
#include <sstream>

cframe::cframe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cframe),
    inventario(new Inventario)
{
    ui->setupUi(this);


    connect(ui->pushButton, &QPushButton::clicked, this, &cframe::mostrarPaginaAgregar);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &cframe::mostrarPaginaMostrar);
    connect(ui->Eliminar, &QPushButton::clicked, this, &cframe::mostrarPaginaEliminar);
    connect(ui->salir, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &cframe::agregarProducto);
    connect(ui->ver_inventario, &QPushButton::clicked, this, &cframe::verInventario);
    connect(ui->ver_stock, &QPushButton::clicked, this, &cframe::verStock);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &cframe::eliminarProducto);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &cframe::on_comboBox_activated);
}

cframe::~cframe() {
    delete ui;
    delete inventario;
}

void cframe::agregarProducto() {
    std::string nombre = ui->lineEdit->text().toStdString();
    double precio = ui->lineEdit_2->text().toDouble();
    std::string descripcion = ui->lineEdit_3->text().toStdString();
    int cantidad = ui->spinBox->value();
    double descuento = ui->comboBox->currentText().toDouble();

    Producto* producto;
    if (descuento > 0) {
        producto = new ProductoConDescuento(nombre, precio, descripcion, descuento);
    } else {

        if (cantidad <= 0) {
            cantidad = 0;
        }
        producto = new ProductoConStock(nombre, precio, descripcion, cantidad);
    }

    inventario->agregarProducto(producto);


    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->spinBox->setValue(0);
    ui->comboBox->setCurrentIndex(0);
}

void cframe::eliminarProducto() {
    std::string nombre = ui->lineEdit_4->text().toStdString();
    inventario->eliminarProducto(nombre);


    ui->lineEdit_4->clear();
}

void cframe::verInventario() {
    ui->textEdit->clear();
    std::ostringstream oss;
    std::streambuf* oldBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    inventario->mostrarInventario();

    std::cout.rdbuf(oldBuf);
    ui->textEdit->setText(QString::fromStdString(oss.str()));
}

void cframe::verStock() {
    std::string nombre = ui->lineEdit_5->text().toStdString();
    Producto* producto = inventario->buscarProducto(nombre);
    if (producto) {
        if (auto pStock = dynamic_cast<ProductoConStock*>(producto)) {
            ui->textEdit->setText(QString::number(pStock->getCantidad()));
        } else {
            ui->textEdit->setText("No es un producto con stock.");
        }
        delete producto;
    } else {
        ui->textEdit->setText("Producto no encontrado.");
    }
}

void cframe::mostrarPaginaAgregar() {
    ui->stackedWidget->setCurrentIndex(0);
}

void cframe::mostrarPaginaMostrar() {
    ui->stackedWidget->setCurrentIndex(1);
}

void cframe::mostrarPaginaEliminar() {
    ui->stackedWidget->setCurrentIndex(2);
}

void cframe::on_comboBox_activated(int index) {
    ui->stackedWidget->setCurrentIndex(index);
}

void cframe::on_pushButton_5_clicked()
{

}

