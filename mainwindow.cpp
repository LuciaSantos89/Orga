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
    connect(actionSalirArchivo,SIGNAL(triggered()),this,SLOT(close()));

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
    actionIntroducirRegistro->setShortcut(tr("Ctrl+I"));
    connect(actionIntroducirRegistro,SIGNAL(triggered()),this,SLOT(introducirRegistro()));

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

    //Menu Indices
    mIndices=menuBar()->addMenu("&Indices");

    //Menu Utilidades
    mUtilidades=menuBar()->addMenu("&Utilidades");

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

    labelCampo=new QLabel("Longitud",dialogcrearCampo);
    labelCampo->move(20,150);
    spinLongitud=new QSpinBox(dialogcrearCampo);
    spinLongitud->move(100,150);

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
    dialoglistarCampo->setMinimumSize(700,350);
    dialoglistarCampo->setWindowTitle("Listar Campos");
    dialoglistarCampo->setModal(true);
    dialoglistarCampo->setWindowModality(Qt::WindowModal);

    aceptarlistarCampo=new QPushButton("Aceptar",dialoglistarCampo);
    aceptarlistarCampo->move(500,320);
    connect(aceptarlistarCampo,SIGNAL(clicked()),this,SLOT(click_aceptarListarCampo()));

    //Tabla Listar Campos
    tableCampo= new QTableWidget(0,5,dialoglistarCampo);
    QStringList titulo;
    titulo << "Nombre" << "Tipo"<<"Longitud"<<"Decimal"<<"Llave";
    tableCampo->setHorizontalHeaderLabels(titulo);
    tableCampo->setMinimumSize(600,250);
    tableCampo->move(50,50);

    //Dialogo Introducir Registro
    dialogIntroducirRegistro=new QDialog(this,Qt::Dialog);
    dialogIntroducirRegistro->hide();
    dialoglistarCampo->setMinimumSize(300,500);
    dialogIntroducirRegistro->setWindowTitle("Introducir Registro");
    dialogIntroducirRegistro->setModal(true);
    dialogIntroducirRegistro->setWindowModality(Qt::WindowModal);

    aceptarIntroducirRegistro=new QPushButton("Aceptar",dialogIntroducirRegistro);
    aceptarIntroducirRegistro->move(50,300);
    connect(aceptarIntroducirRegistro,SIGNAL(clicked()),this,SLOT(click_aceptarIntroducirRegistro()));

    cancelarIntroducirRegistro=new QPushButton("Cancelar",dialogIntroducirRegistro);
    cancelarIntroducirRegistro->move(300,300);
    connect(cancelarIntroducirRegistro,SIGNAL(clicked()),this,SLOT(click_cancelarIntroducirRegistro()));

}

//funciones Menu Archivo
void MainWindow::nuevoArchivo(){
    activardesactivarMenus(true);
    header= new Header();
    archivo = new TDARecordFile();
    archivo->open("tmp",ios_base::out);
    listaC.clear();
    listaR.clear();

}

void MainWindow::abrirArchivo(){
    archivo = new TDARecordFile();
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Document"),QDir::currentPath(),"Lusilla (*.lsll)");
    if( !filename.isNull() )
    {
        string fn = filename.toStdString();
        archivo->open(fn,ios_base::out|ios_base::in);
        activardesactivarMenus(true);
        QDir dir(QDir::current());
        string relative=dir.relativeFilePath(filename).toStdString();
        cout<<"abierto"<<endl;
        header= new Header();
        string tmp="";
        char buff[1];
        do{
            archivo->read(buff,1);
            tmp+=*buff;
        }while(*buff!='\n');
        cout<<tmp<<endl;
        header->recuperarCampos(strdup(tmp.c_str()));
    }


}

void MainWindow::guardarArchivo(){
    if(archivo->isOpen()){
        cout<<"esta abierto"<<endl;
        for (int i = 0; i < listaR.size(); ++i) {
            archivo->addRecord(header->getCampos(),listaR.at(i));
        }
    }
    else{
        string camposLista=header->guardarCampos();
        QString filename = QFileDialog::getSaveFileName(this,tr("Save Document"),QDir::currentPath(),"Lusilla (*.lsll)");
        string fn = filename.toStdString()+".lsll";
        if( !filename.isNull() )
        {
            archivo->open(fn,ios_base::out);

            //guardarheader
            archivo->seek(ios_base::beg);
            int tamCampos=camposLista.size();
            cout<<camposLista<<endl;
            archivo->write(camposLista.c_str(),tamCampos);
        }
        archivo->flush();
    }
}

void MainWindow::imprimirArchivo(){

}

void MainWindow::cerrarArchivo(){
    activardesactivarMenus(false);
    archivo->close();
}

void MainWindow::crearCampo(){
    dialogcrearCampo->show();
}


//Funcines Menu Campo
void MainWindow::modificarCampo(){
    header->getCampos();
}

void MainWindow::listarCampo(){
    listaC=header->getCampos();
    tableCampo->setRowCount(listaC.size());
    const char* s="";
    for (int i = 0; i < listaC.size(); i++) {
        s= listaC.at(i)->getNombre().c_str();
        itemTableCampo= new QTableWidgetItem(s);
        itemTableCampo->setText(s);
        tableCampo->setItem(i,0,itemTableCampo);
    }
    dialoglistarCampo->show();
    tableCampo->show();
}

bool MainWindow::click_aceptarCrearCampo(){
    Campo* c = new Campo();
    string nombre="";
    nombre=lineNombreCampo->text().toStdString();
    int tipo=0;
    tipo=comboTipoCampo->currentIndex();
    int longitud=0;
    longitud=spinLongitud->text().toInt();
    int decimal=0;
    decimal=spinDecimal->text().toInt();
    bool llave = false;
    llave=checkLlave->isChecked();

    bool resp1=c->crearCampo(nombre,tipo,longitud,decimal,llave);
    if(resp1)
        cout<<"Se creo"<<endl;
    //c->agregarCampo();
    bool resp2=header->agregarCampo(c);
    if(resp2)
        cout<<"Se agrego"<<endl;


    stringstream ss;
    ss << longitud;
    cout<<nombre<<endl<<ss.str()<<endl<<llave<<endl;

    dialogcrearCampo->hide();
    return true;
}

void MainWindow::click_cancelarCampo(){
    dialogcrearCampo->hide();
}

void MainWindow::click_aceptarListarCampo(){
    dialoglistarCampo->hide();
}

//Funciones Menu Registro
void MainWindow::introducirRegistro(){
    unregistro="";
    cout<<"Estoy aqui"<<endl;
    cout<<listaC.size()<<endl<<listaR.size()<<endl;
    dialogIntroducirRegistro->show();
}

bool MainWindow::click_aceptarIntroducirRegistro(){
    unregistro="el registro";
    listaR.push_back(unregistro);
    return true;
}

void MainWindow::click_cancelarIntroducirRegistro(){

}


//----------------------------
void MainWindow::activardesactivarMenus(bool opcion){
    banderaAbierto=opcion;
    actionNuevoArchivo->setEnabled(!opcion);
    actionAbrirArchivo->setEnabled(!opcion);
    actionGuardarArchivo->setEnabled(opcion);
    actionCerrarArchivo->setEnabled(opcion);
    actionImprimirArchivo->setEnabled(opcion);
    actionCrearCampo->setEnabled(opcion);
    actionModificarCampo->setEnabled(opcion);
    actionListarCampo->setEnabled(opcion);
    actionIntroducirRegistro->setEnabled(opcion);

}
