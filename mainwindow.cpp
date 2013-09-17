#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    crearActions();
    agregar();
    activardesactivarMenus(false);
}

MainWindow::~MainWindow()
{
}

void MainWindow::crearActions(){
    //Menu Archivo
    actionNuevoArchivo= new QAction("&Nuevo",this);
    actionNuevoArchivo->setShortcut(tr("Ctrl+N"));
    connect(actionNuevoArchivo,SIGNAL(triggered()),this,SLOT(nuevoArchivo()));

    actionAbrirArchivo= new QAction("&Abrir",this);
    actionAbrirArchivo->setShortcut(tr("Ctrl+O"));
    connect(actionAbrirArchivo,SIGNAL(triggered()),this,SLOT(abrirArchivo()));

    actionGuardarArchivo= new QAction("&Guardar",this);
    actionGuardarArchivo->setShortcut(tr("Ctrl+S"));
    connect(actionGuardarArchivo,SIGNAL(triggered()),this,SLOT(guardarArchivo()));

    actionImprimirArchivo= new QAction("&Imprimir",this);
    actionImprimirArchivo->setShortcut(tr("Ctrl+P"));
    connect(actionImprimirArchivo,SIGNAL(triggered()),this,SLOT(imprimirArchivo()));

    actionCerrarArchivo= new QAction("&Cerrar",this);
    actionCerrarArchivo->setShortcut(tr("Ctrl+C"));
    connect(actionCerrarArchivo,SIGNAL(triggered()),this,SLOT(cerrarArchivo()));

    actionSalirArchivo= new QAction("&Salir",this);
    actionSalirArchivo->setShortcut(tr("Ctrl+X"));
    connect(actionSalirArchivo,SIGNAL(triggered()),this,SLOT(salir()));

    //Menu Campo
    actionCrearCampo= new QAction("&Crear Campo",this);
    actionCrearCampo->setShortcut(tr("Ctrl+C"));
    connect(actionCrearCampo,SIGNAL(triggered()),this,SLOT(crearCampo()));

    actionModificarCampo= new QAction("&Modificar Campo",this);
    actionModificarCampo->setShortcut(tr("Ctrl+M"));
    connect(actionModificarCampo,SIGNAL(triggered()),this,SLOT(modificarCampo()));

    actionListarCampo= new QAction("&Listar Campos",this);
    actionListarCampo->setShortcut(tr("Ctrl+L"));
    connect(actionListarCampo,SIGNAL(triggered()),this,SLOT(listarCampo()));

    //Menu Registro
    actionIntroducirRegistro=new QAction("Introducir Registro",this);
    connect(actionIntroducirRegistro,SIGNAL(triggered()),this,SLOT(introducirRegistro()));

    actionBuscarRegistro=new QAction("Buscar Registro",this);
    connect(actionBuscarRegistro,SIGNAL(triggered()),this,SLOT(buscarRegistro()));

    actionBorrarRegistro=new QAction("Borrar Registro",this);
    connect(actionBorrarRegistro,SIGNAL(triggered()),this,SLOT(borrarRegistro()));

    actionListarRegistro=new QAction("Listar Registro",this);
    connect(actionListarRegistro,SIGNAL(triggered()),this,SLOT(listarRegistro()));

    //Menu Indices
    actionCrearIndiceSimple=new QAction("Crear Indice Simple",this);
    connect(actionCrearIndiceSimple,SIGNAL(triggered()),this,SLOT(crearIndiceSimple()));

    actionCrearArbolB=new QAction("Crear Arbol B",this);
    connect(actionCrearArbolB,SIGNAL(triggered()),this,SLOT(crearArbolB()));

    actionReindexar=new QAction("Reindexar",this);
    connect(actionReindexar,SIGNAL(triggered()),this,SLOT(reindexar()));

    //Menu Utilidades
    actionImportarXML=new QAction("Impotar XML",this);
    connect(actionImportarXML,SIGNAL(triggered()),this,SLOT(importarXML()));

    actionExportarXML=new QAction("Exportar XML",this);
    connect(actionExportarXML,SIGNAL(triggered()),this,SLOT(exportarXML()));

    actionImportarJSON=new QAction("Impotar JSON",this);
    connect(actionImportarJSON,SIGNAL(triggered()),this,SLOT(importarJSON()));

    actionExportarJSON=new QAction("Exportar JSON",this);
    connect(actionExportarJSON,SIGNAL(triggered()),this,SLOT(exportarJSON()));

}

void MainWindow::agregar(){

    //Ventana Principal
    this->setMinimumSize(370, 200);
    this->setWindowTitle("Proyecto - Lusilla");

    //Menu Archivo
    mArchivo=menuBar()->addMenu("&Archivo");
    mArchivo->addAction(actionNuevoArchivo);
    mArchivo->addAction(actionAbrirArchivo);
    mArchivo->addAction(actionGuardarArchivo);
    mArchivo->addAction(actionImprimirArchivo);
    mArchivo->addAction(actionCerrarArchivo);
    mArchivo->addAction(actionSalirArchivo);

    //Menu Campo
    mCampo=menuBar()->addMenu("&Campo");
    mCampo->addAction(actionCrearCampo);
    mCampo->addAction(actionModificarCampo);
    mCampo->addAction(actionListarCampo);

    //Menu Registro
    mRegistro=menuBar()->addMenu("&Registro");
    mRegistro->addAction(actionIntroducirRegistro);
    mRegistro->addAction(actionBorrarRegistro);
    mRegistro->addAction(actionBuscarRegistro);
    mRegistro->addAction(actionListarRegistro);

    //Menu Indices
    mIndices=menuBar()->addMenu("&Indices");
    mIndices->addAction(actionCrearIndiceSimple);
    mIndices->addAction(actionCrearArbolB);
    mIndices->addAction(actionReindexar);

    //Menu Utilidades
    mUtilidades=menuBar()->addMenu("&Utilidades");
    mUtilidades->addAction(actionImportarXML);
    mUtilidades->addAction(actionExportarXML);
    mUtilidades->addAction(actionImportarJSON);
    mUtilidades->addAction(actionExportarJSON);

    //Dialogo Crear Campo
    dialogcrearCampo=new QDialog(this,Qt::Dialog);
    dialogcrearCampo->hide();
    dialogcrearCampo->setMinimumSize(350,350);
    dialogcrearCampo->setWindowTitle("Crear Campo");
    dialogcrearCampo->setModal(true);
    dialogcrearCampo->setWindowModality(Qt::WindowModal);

    labelCampo=new QLabel("Nombre",dialogcrearCampo);
    labelCampo->move(20,50);
    lineNombreCampo=new QLineEdit(dialogcrearCampo);
    lineNombreCampo->move(100,50);
    lineNombreCampo->setMinimumWidth(100);

    labelCampo=new QLabel("Tipo",dialogcrearCampo);
    labelCampo->move(20,100);
    comboTipoCampo= new QComboBox(dialogcrearCampo);
    comboTipoCampo->move(100,100);
    QStringList tipos;
    tipos<<"Cadena"<<"Entero"<<"Real";
    comboTipoCampo->addItems(tipos);
    connect(comboTipoCampo,SIGNAL(currentIndexChanged(int)),this,SLOT(cambiarTipoCampo()));

    labelCampo=new QLabel("Longitud",dialogcrearCampo);
    labelCampo->move(20,150);
    spinLongitud=new QSpinBox(dialogcrearCampo);
    spinLongitud->move(100,150);
    spinLongitud->setValue(1);

    labelCampo=new QLabel("Decimal",dialogcrearCampo);
    labelCampo->move(20,200);
    spinDecimal=new QSpinBox(dialogcrearCampo);
    spinDecimal->move(100,200);
    spinDecimal->setEnabled(false);

    labelCampo=new QLabel("Llave",dialogcrearCampo);
    labelCampo->move(20,250);
    checkLlave=new QCheckBox(dialogcrearCampo);
    checkLlave->move(100,250);

    aceptarcrearCampo=new QPushButton("Aceptar",dialogcrearCampo);
    aceptarcrearCampo->move(50,300);
    connect(aceptarcrearCampo,SIGNAL(clicked()),this,SLOT(click_aceptarCrearCampo()));

    cancelarcrearCampo=new QPushButton("Cancelar",dialogcrearCampo);
    cancelarcrearCampo->move(300,300);
    connect(cancelarcrearCampo,SIGNAL(clicked()),this,SLOT(click_cancelarCampo()));

    //Dialogo Listar Campos
    dialoglistarCampo = new QDialog(this,Qt::Dialog);
    dialoglistarCampo->hide();
    dialoglistarCampo->setMinimumSize(550,350);
    dialoglistarCampo->setWindowTitle("Listar Campos");
    dialoglistarCampo->setModal(true);
    dialoglistarCampo->setWindowModality(Qt::WindowModal);

    aceptarlistarCampo=new QPushButton("Aceptar",dialoglistarCampo);
    aceptarlistarCampo->move(450,320);
    connect(aceptarlistarCampo,SIGNAL(clicked()),this,SLOT(click_aceptarListarCampo()));

    //Tabla Listar Campos
    tableCampo= new QTableWidget(0,5,dialoglistarCampo);
    QStringList titulo;
    titulo << "Nombre" << "Tipo"<<"Longitud"<<"Decimal"<<"Llave";
    tableCampo->setHorizontalHeaderLabels(titulo);
    tableCampo->setMinimumSize(550,250);
    tableCampo->move(50,50);
    tableCampo->setColumnWidth(0,130);

    //Dialogo Introducir Registro
    dialogIntroducirRegistro=new QDialog(this,Qt::Dialog);
    dialogIntroducirRegistro->hide();
    dialogIntroducirRegistro->setMinimumSize(500,500);
    dialogIntroducirRegistro->setWindowTitle("Introducir Registro");
    dialogIntroducirRegistro->setModal(true);
    dialogIntroducirRegistro->setWindowModality(Qt::WindowModal);

    aceptarIntroducirRegistro=new QPushButton("Aceptar",dialogIntroducirRegistro);
    aceptarIntroducirRegistro->move(50,400);
    connect(aceptarIntroducirRegistro,SIGNAL(clicked()),this,SLOT(click_aceptarIntroducirRegistro()));

    cancelarIntroducirRegistro=new QPushButton("Cancelar",dialogIntroducirRegistro);
    cancelarIntroducirRegistro->move(300,400);
    connect(cancelarIntroducirRegistro,SIGNAL(clicked()),this,SLOT(click_cancelarIntroducirRegistro()));

}

//funciones Menu Archivo
void MainWindow::nuevoArchivo(){
    activardesactivarMenus(true);
    archivo=new TDARecordFile();
    header=new Header();
    indices= new Index();
    campos.clear();
    regIntroducido=false;
}

void MainWindow::abrirArchivo(){
    QString nombreArchivo = QFileDialog::getOpenFileName(this,tr("Abrir Documento"),QDir::currentPath(),"Lusilla (*.lsll)");
    if( !nombreArchivo.isNull() ){
        activardesactivarMenus(true);
        archivo=new TDARecordFile();
        header=new Header();
        indices= new Index();
        campos.clear();
        string fn = nombreArchivo.toStdString();
        archivo->open(fn,ios_base::out | ios_base::in);
        header->recuperarHeader(archivo);
        campos=header->getCampos();
        //indices->abrir(fn);
    }
}

void MainWindow::guardarArchivo(){
    if(!regIntroducido){
        QString nombreArchivo = QFileDialog::getSaveFileName(this,tr("Guardar Documento"),QDir::currentPath(),"Lusilla (*.lsll)");
        if(!nombreArchivo.isNull()){
            string fn = nombreArchivo.toStdString()+".lsll";
            archivo->open(fn,ios_base::out);
            header->crearHeader(campos);
            header->guardarHeader(archivo);
        }
    }
}

void MainWindow::imprimirArchivo(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no hizo esta parte");
}

void MainWindow::cerrarArchivo(){
    if(archivo->isOpen()){
        //indices->guardar();
        archivo->flush();
        archivo->close();
    }
    activardesactivarMenus(false);
}

void MainWindow::salir(){
    this->cerrarArchivo();
    this->close();
}

//Funcines Menu Campo
void MainWindow::crearCampo(){
    if(regIntroducido){
        errorM=new QErrorMessage(this);
        errorM->showMessage("Ya no puede crear campos");
        return;
    }
    dialogcrearCampo->show();
}

void MainWindow::modificarCampo(){
    if(regIntroducido || campos.size()==0){
        errorM=new QErrorMessage(this);
        errorM->showMessage("No puede modificar los campos");
    }
    else{
        errorM=new QErrorMessage(this);
        errorM->showMessage("Oh-no! Lucia no hizo esta parte");
    }
}

void MainWindow::listarCampo(){
    if(campos.size()==0)
        return;
        tableCampo->setRowCount(campos.size());
        string s="";
        stringstream tmp;
        for (unsigned int i = 0; i < campos.size(); i++) {
            s= campos.at(i)->getNombre();
            itemTableCampo= new QTableWidgetItem(0);
            itemTableCampo->setText(s.c_str());
            tableCampo->setItem(i,0,itemTableCampo);

            int tipo=campos.at(i)->getTipo();
            if(tipo==0)
                tmp<<"Cadena";
            if(tipo==1)
                tmp<<"Entero";
            if(tipo==2)
                tmp<<"Real";
            s=tmp.str();
            itemTableCampo= new QTableWidgetItem(0);
            itemTableCampo->setText(s.c_str());
            tableCampo->setItem(i,1,itemTableCampo);
            tmp.str("");

            tmp<<campos.at(i)->getLongitud();
            s=tmp.str();
            itemTableCampo= new QTableWidgetItem(0);
            itemTableCampo->setText(s.c_str());
            tableCampo->setItem(i,2,itemTableCampo);
            tmp.str("");

            tmp<<campos.at(i)->getDecimal();
            s=tmp.str();
            itemTableCampo= new QTableWidgetItem(0);
            itemTableCampo->setText(s.c_str());
            tableCampo->setItem(i,3,itemTableCampo);
            tmp.str("");

            int llave=campos.at(i)->getLlave();
            if(llave==1)
                tmp<<"Si";
            else
                tmp<<"No";
            s=tmp.str();
            itemTableCampo= new QTableWidgetItem(0);
            itemTableCampo->setText(s.c_str());
            tableCampo->setItem(i,4,itemTableCampo);
            tmp.str("");
        }
        dialoglistarCampo->show();
        tableCampo->show();
}

void MainWindow::click_aceptarCrearCampo(){
    Campo* c = new Campo();
    string nombre="";
    int tipo=0;
    int longitud=0;
    int decimal=0;
    bool llave = false;
    nombre=lineNombreCampo->text().toStdString();
    tipo=comboTipoCampo->currentIndex();
    longitud=spinLongitud->text().toInt();
    decimal=spinDecimal->text().toInt();
    llave=checkLlave->isChecked();
    if(nombre.length ()==0 ||longitud<=decimal){
        errorM=new QErrorMessage(this);
        errorM->showMessage("Hubo un error al querer crear el campo");
    }
    else{
        c->crearCampo(nombre,tipo,longitud,decimal,llave);
        campos.push_back(c);
        lineNombreCampo->setText("");
        comboTipoCampo->setCurrentIndex(0);
        spinLongitud->setValue(1);
        spinDecimal->setValue(0);
        checkLlave->setChecked(false);
    }
}

void MainWindow::click_cancelarCampo(){
    dialogcrearCampo->close();
}

void MainWindow::click_aceptarListarCampo(){
    dialoglistarCampo->close();
}

void MainWindow::cambiarTipoCampo(){
    int tmp=comboTipoCampo->currentIndex();
    if(tmp==2){
        spinDecimal->setEnabled(true);
    }
    else{
        spinDecimal->setEnabled(false);
    }
}

//Funciones Menu Registro
void MainWindow::introducirRegistro(){
    if(campos.size()==0 || !archivo->isOpen()){
        errorM=new QErrorMessage(this);
        errorM->showMessage("Primero Introduzca Campos y Guarde el archivo");
    }
    else{
        registro.clear();
        stringstream tmp;
        for (unsigned int i = 0; i < campos.size(); i++) {
            int tipo = campos.at(i)->getTipo();
            if(tipo==0){
                QString cadena=QInputDialog::getText(this,QString(campos.at(i)->getNombre().c_str()),QString(campos.at(i)->getNombre().c_str()),QLineEdit::Normal,"");
                registro.push_back(cadena.toStdString());
            }
            if(tipo==1){
                int entero=QInputDialog::getInt(this,QString(campos.at(i)->getNombre().c_str()),QString(campos.at(i)->getNombre().c_str()));
                tmp<<entero;
                registro.push_back(tmp.str());
                tmp.str("");
            }
            if(tipo==2){
                double max=pow(10,campos.at(i)->getLongitud()-campos.at(i)->getDecimal());
                double real=QInputDialog::getDouble(this,QString(campos.at(i)->getNombre().c_str()),QString(campos.at(i)->getNombre().c_str()),0,-10000,max,campos.at(i)->getDecimal());
                tmp<<real;
                registro.push_back(tmp.str());
                tmp.str("");
            }
        }
        Registro* r= new Registro();
        r->crearRegistro(registro,campos);
        //if(!indices->verificarIndice()){
            archivo->addRecord(r,indices);
        /*}
        else{
            errorM=new QErrorMessage(this);
            errorM->showMessage("El registro con esa llave ya existe");
        }*/
    }
}

void MainWindow::click_aceptarIntroducirRegistro(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::click_cancelarIntroducirRegistro(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::crearDialogoIntroducirRegistro(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::buscarRegistro(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::borrarRegistro(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::listarRegistro(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

//Funciones Menu Indices
void MainWindow::crearIndiceSimple(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::crearArbolB(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::reindexar(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::importarXML(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::exportarXML(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::importarJSON(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}

void MainWindow::exportarJSON(){
    errorM=new QErrorMessage(this);
    errorM->showMessage("Oh-no! Lucia no ha hecho esta parte");
}


//----------------------------
void MainWindow::activardesactivarMenus(bool opcion){
    actionNuevoArchivo->setEnabled(!opcion);
    actionAbrirArchivo->setEnabled(!opcion);
    actionGuardarArchivo->setEnabled(opcion);
    actionCerrarArchivo->setEnabled(opcion);
    actionImprimirArchivo->setEnabled(opcion);
    actionCrearCampo->setEnabled(opcion);
    actionModificarCampo->setEnabled(opcion);
    actionListarCampo->setEnabled(opcion);
    actionIntroducirRegistro->setEnabled(opcion);
    actionBuscarRegistro->setEnabled(opcion);
    actionBorrarRegistro->setEnabled(opcion);
    actionListarRegistro->setEnabled(opcion);
    actionCrearIndiceSimple->setEnabled(opcion);
    actionCrearArbolB->setEnabled(opcion);
    actionReindexar->setEnabled(opcion);
    actionImportarXML->setEnabled(opcion);
    actionExportarXML->setEnabled(opcion);
    actionImportarJSON->setEnabled(opcion);
    actionExportarJSON->setEnabled(opcion);

}


