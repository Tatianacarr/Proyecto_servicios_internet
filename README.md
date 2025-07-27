# Proyecto_servicios_internet
#include <iostream>
#include <string>
#include <vector>

QColor color;
    if (row % 3 == 0)
        color = QColor("#FFC0CB");
    else if (row % 3 == 1)
        color = QColor("#B2FFFF");
    else
        color = QColor("#98FB98");

    for (int col = 0; col < tabla->columnCount(); ++col) {
        tabla->item(row, col)->setBackground(QBrush(color));
    }

    // Guardar en archivo en carpeta usuario
    QString rutaArchivo = QDir::homePath() + "/datos.txt";
    QFile archivo(rutaArchivo);
    if (!archivo.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para guardar en:\n" + archivo.fileName());
        return;
    }
    QTextStream out(&archivo);
    out << txtId->text() << ","
        << txtNombre->text() << ","
        << txtDireccion->text() << ","
        << txtEmail->text() << ","
        << cmbPlan->currentText() << ","
        << cmbPrecio->currentText() << ","
        << dateInicio->date().toString("dd/MM/yyyy") << ","
        << cmbEstado->currentText() << "\n";
    archivo.close();

    QMessageBox::information(this, "Mensaje", "Registro agregado y guardado correctamente.");
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
