#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include "inventario.h"

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    explicit cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void agregarProducto();
    void eliminarProducto();
    void verInventario();
    void verStock();
    void mostrarPaginaAgregar();
    void mostrarPaginaMostrar();
    void mostrarPaginaEliminar();
    void on_comboBox_activated(int index);

    void on_pushButton_5_clicked();

private:
    Ui::cframe *ui;
    Inventario *inventario;
};

#endif // CFRAME_H
