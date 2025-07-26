#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>
#include <QTableWidget>

//Hola mundo 
//Karen Lozano
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void agregarRegistro();
    void eliminarRegistro();
    void editarRegistro();
    void limpiarCampos();

private:
    QLineEdit *txtId;
    QLineEdit *txtNombre;
    QLineEdit *txtDireccion;
    QLineEdit *txtEmail;
    QComboBox *cmbPlan;
    QDateEdit *dateInicio;
    QComboBox *cmbEstado;
    QComboBox *cmbPrecio;

    QPushButton *btnGuardar;
    QPushButton *btnEliminar;
    QPushButton *btnActualizar;
    QPushButton *btnLimpiar;

    QTableWidget *tabla;
};

#endif // MAINWINDOW_H

