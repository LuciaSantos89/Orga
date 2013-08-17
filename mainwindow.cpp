#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    crearActions();
    agregar();
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

    //Menu Indices
    mIndices=menuBar()->addMenu("&Indices");

    //Menu Utilidades
    mUtilidades=menuBar()->addMenu("&Utilidades");

    //Dialogo Campo
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

}

void MainWindow::nuevoArchivo(){
    std::cout<<"Holita"<<std::endl;
    heFile= new HeaderFile();
    archivo = new TDARecordFile();

}


void MainWindow::abrirArchivo(){

}

void MainWindow::guardarArchivo(){
    string camposLista=heFile->guardarCampos();
    QString filename = QFileDialog::getSaveFileName(this,tr("Save Document"),QDir::currentPath(),"Lusilla (*.lsll)");
    string fn = filename.toStdString();
    if( !filename.isNull() )
    {
        archivo->open(fn,ios_base::out);

        //guardarheader Campos
        //archivo->seek(0);
        int tamCampos=camposLista.size();
        cout<<camposLista<<endl;
        archivo->write(camposLista.c_str(),tamCampos);
        //guadarheader AvailList
    }
    archivo->flush();
    archivo->close();
}

void MainWindow::imprimirArchivo(){

}

void MainWindow::cerrarArchivo(){

}

void MainWindow::crearCampo(){
    dialogcrearCampo->show();
}

void MainWindow::modificarCampo(){

}

void MainWindow::listarCampo(){

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
    bool resp2=heFile->agregarCampo(c);
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

bool MainWindow::click_aceptarModificarCampo(){
    return true;
}

