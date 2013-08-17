#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QStringList>
#include <QLabel>
#include <QFileDialog>

#include <iostream>
#include <QVariant>
#include <string>
#include <sstream>

#include "Campo.h"
#include "HeaderFile.h"
#include "TDARecordFile.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //Menu Archivo
    QMenu* mArchivo;
    QAction* actionNuevoArchivo;
    QAction* actionAbrirArchivo;
    QAction* actionGuardarArchivo;
    QAction* actionImprimirArchivo;
    QAction* actionCerrarArchivo;
    QAction* actionSalirArchivo;

    //Menu Campos
    QMenu* mCampo;
    QAction* actionCrearCampo;
    QAction* actionModificarCampo;
    QAction* actionListarCampo;

    //Menu Registro
    QMenu* mRegistro;

    //Menu Indices
    QMenu* mIndices;

    //Menu Utilidades
    QMenu* mUtilidades;

    //Dialogo Campo
    QDialog* dialogcrearCampo;
    QPushButton* aceptarcrearCampo;
    QPushButton* cancelarcrearCampo;
    QLineEdit* lineNombreCampo;
    QComboBox* comboTipoCampo;
    QSpinBox* spinLongitud;
    QSpinBox* spinDecimal;
    QCheckBox* checkLlave;
    QLabel* labelCampo;

    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    //Slots Menu Archivo
    void nuevoArchivo();
    void abrirArchivo();
    void guardarArchivo();
    void imprimirArchivo();
    void cerrarArchivo();

    //Slots Menu Campos
    void crearCampo();
    void modificarCampo();
    void listarCampo();

    //Slots Menu Registro

    //Slots Menu Indices

    //Slots Menu Utilidades

    //Slots QDialog Campo
    bool click_aceptarCrearCampo();
    void click_cancelarCampo();
    bool click_aceptarModificarCampo();


private:
    void crearActions();
    void agregar();
    HeaderFile* heFile;
    TDARecordFile* archivo;

};
#endif // MAINWINDOW_H
