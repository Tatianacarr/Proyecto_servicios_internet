#include "mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
//Angui Fierro
//Karen Lozano
//Sebastian Toapanta

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    this->setCentralWidget(central);

    QLabel *lblId = new QLabel("Id:");
    txtId = new QLineEdit;

    QLabel *lblNombre = new QLabel("Nombre:");
    txtNombre = new QLineEdit;

    QLabel *lblDireccion = new QLabel("Dirección:");
    txtDireccion = new QLineEdit;

    QLabel *lblEmail = new QLabel("Email:");
    txtEmail = new QLineEdit;

    QLabel *lblPlan = new QLabel("Plan:");
    cmbPlan = new QComboBox;
    cmbPlan->addItems({"Básico", "Premiun", "Corporativo"});

    QLabel *lblPrecio = new QLabel("Precio:");
    cmbPrecio = new QComboBox;
    cmbPrecio->addItems({"19.99", "30", "70"});

    QLabel *lblFecha = new QLabel("Fecha:");
    dateInicio = new QDateEdit(QDate::currentDate());

    QLabel *lblEstado = new QLabel("Estado:");
    cmbEstado = new QComboBox;
    cmbEstado->addItems({"Activo", "Inactivo"});

    btnGuardar = new QPushButton("Agregar");
    btnEliminar = new QPushButton("Eliminar");
    btnActualizar = new QPushButton("Editar");
    btnLimpiar = new QPushButton("Limpiar");

    tabla = new QTableWidget;
    tabla->setColumnCount(8);
    tabla->setHorizontalHeaderLabels({"ID", "Nombre", "Dirección", "Email", "Plan", "Precio", "Fecha", "Estado"});
    tabla->horizontalHeader()->setStretchLastSection(true);
    tabla->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Layouts
    QVBoxLayout *formLayout = new QVBoxLayout;
    formLayout->addWidget(lblId);        formLayout->addWidget(txtId);
    formLayout->addWidget(lblNombre);    formLayout->addWidget(txtNombre);
    formLayout->addWidget(lblDireccion); formLayout->addWidget(txtDireccion);
    formLayout->addWidget(lblEmail);     formLayout->addWidget(txtEmail);
    formLayout->addWidget(lblPlan);      formLayout->addWidget(cmbPlan);
    formLayout->addWidget(lblPrecio);    formLayout->addWidget(cmbPrecio);
    formLayout->addWidget(lblFecha);     formLayout->addWidget(dateInicio);
    formLayout->addWidget(lblEstado);    formLayout->addWidget(cmbEstado);

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(btnGuardar);
    btnLayout->addWidget(btnActualizar);
    btnLayout->addWidget(btnEliminar);
    btnLayout->addWidget(btnLimpiar);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(btnLayout);
    mainLayout->addWidget(tabla);

    central->setLayout(mainLayout);

    connect(btnGuardar, &QPushButton::clicked, this, &MainWindow::agregarRegistro);
    connect(btnEliminar, &QPushButton::clicked, this, &MainWindow::eliminarRegistro);
    connect(btnActualizar, &QPushButton::clicked, this, &MainWindow::editarRegistro);
    connect(btnLimpiar, &QPushButton::clicked, this, &MainWindow::limpiarCampos);


    connect(cmbPlan, &QComboBox::currentIndexChanged, this, [=](int index){
        cmbPrecio->setCurrentIndex(index);
    });
}

MainWindow::~MainWindow() {}

void MainWindow::agregarRegistro()
{
    int row = tabla->rowCount();
    tabla->insertRow(row);
    tabla->setItem(row, 0, new QTableWidgetItem(txtId->text()));
    tabla->setItem(row, 1, new QTableWidgetItem(txtNombre->text()));
    tabla->setItem(row, 2, new QTableWidgetItem(txtDireccion->text()));
    tabla->setItem(row, 3, new QTableWidgetItem(txtEmail->text()));
    tabla->setItem(row, 4, new QTableWidgetItem(cmbPlan->currentText()));
    tabla->setItem(row, 5, new QTableWidgetItem(cmbPrecio->currentText()));
    tabla->setItem(row, 6, new QTableWidgetItem(dateInicio->date().toString("dd/MM/yyyy")));
    tabla->setItem(row, 7, new QTableWidgetItem(cmbEstado->currentText()));

    QMessageBox::information(this, "Mensaje", "Registro agregado correctamente");
    limpiarCampos();
}

void MainWindow::eliminarRegistro()
{
    int row = tabla->currentRow();
    if (row >= 0) {
        tabla->removeRow(row);
        QMessageBox::information(this, "Mensaje", "Registro eliminado correctamente");
    }
}

void MainWindow::editarRegistro()
{
    int row = tabla->currentRow();
    if (row >= 0) {
        tabla->item(row, 0)->setText(txtId->text());
        tabla->item(row, 1)->setText(txtNombre->text());
        tabla->item(row, 2)->setText(txtDireccion->text());
        tabla->item(row, 3)->setText(txtEmail->text());
        tabla->item(row, 4)->setText(cmbPlan->currentText());
        tabla->item(row, 5)->setText(cmbPrecio->currentText());
        tabla->item(row, 6)->setText(dateInicio->date().toString("dd/MM/yyyy"));
        tabla->item(row, 7)->setText(cmbEstado->currentText());
        QMessageBox::information(this, "Mensaje", "Registro editado correctamente");
    }
}

void MainWindow::limpiarCampos()
{
    txtId->clear();
    txtNombre->clear();
    txtDireccion->clear();
    txtEmail->clear();
    cmbPlan->setCurrentIndex(0);
    cmbPrecio->setCurrentIndex(0);
    cmbEstado->setCurrentIndex(0);
    dateInicio->setDate(QDate::currentDate());
}

