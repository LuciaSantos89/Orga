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
#include <QTableWidget>
#include <QTableWidgetItem>

/*#include <QListWidget>
#include <QListWidgetItem>*/

#include <iostream>
#include <string>
#include <sstream>

#include "Campo.h"
#include "Header.h"
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
    QAction* actionIntroducirRegistro;

    //Menu Indices
    QMenu* mIndices;

    //Menu Utilidades
    QMenu* mUtilidades;

    //Dialogo crear Campo
    QDialog* dialogcrearCampo;
    QPushButton* aceptarcrearCampo;
    QPushButton* cancelarcrearCampo;
    QLineEdit* lineNombreCampo;
    QComboBox* comboTipoCampo;
    QSpinBox* spinLongitud;
    QSpinBox* spinDecimal;
    QCheckBox* checkLlave;
    QLabel* labelCampo;

    //Dialogo listar Campos
    QDialog* dialoglistarCampo;
    QTableWidget* tableCampo;
    QTableWidgetItem* itemTableCampo;
    QPushButton* aceptarlistarCampo;

    //Dialogo introducirRegistro
    QDialog* dialogIntroducirRegistro;
    QTableWidget* tableRegistro;
    QTableWidgetItem* itemTableRegistro;
    QPushButton* aceptarIntroducirRegistro;
    QPushButton* cancelarIntroducirRegistro;


    
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
    void introducirRegistro();

    //Slots Menu Indices

    //Slots Menu Utilidades

    //Slots QDialog Crear Campo
    void cambiarTipoCampo();
    bool click_aceptarCrearCampo();
    void click_cancelarCampo();

    //Slots QDialog Listar Campo
    void click_aceptarListarCampo();

    //SlotsQDialgo Introducir Campo
    bool click_aceptarIntroducirRegistro();
    void click_cancelarIntroducirRegistro();


private:
    void crearActions();
    void agregar();
    void activardesactivarMenus(bool);
    void crearDialogoIntroducirRegistro();
    void agregartmp(string);
    Header* header;
    TDARecordFile* archivo;
    vector<Campo*> listaC;
    vector <char*> listaR;
    string unregistro;
    bool guardado;
    bool regIntroducido;

};
#endif // MAINWINDOW_H
