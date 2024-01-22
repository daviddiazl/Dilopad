#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    modes = new mmodes();
    proyectos = new mMenu();
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow { background-color : gray; color : yellow; }");
    ui->menubar->setStyleSheet("QMenuBar { background-color : white ; color : blue;}");
    this->ui->lProyects->addWidget(proyectos);
    this->ui->lEditor->addWidget(modes);
    this->myPath = "";
}

MainWindow::~MainWindow()
{
    delete proyectos;
    delete modes;
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{

    QFile arch;
    QTextStream io;
    QString fileName = QFileDialog::getOpenFileName(this,"Abrir",QString(),tr("Text files (*.txt);;C files (*.c)"));
    arch.setFileName(fileName);
    arch.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!arch.isOpen())
    {
        QMessageBox::critical(this,"Error",arch.errorString());
    }else
    {
        io.setDevice(&arch);
        modes->getEditorTexto()->clearEditor();
        modes->getEditorTexto()->introText(io.readAll());
        arch.close();
        QMessageBox::information(this,"Abierto",fileName);
        this->myPath = fileName;
    }

}


void MainWindow::on_actionGuardar_triggered()
{
    QFile arch;
    QTextStream io;
    //QString fileName = QFileDialog::getSaveFileName(this,"Guardar");
    if(myPath == "")
    {
        QMessageBox::critical(this,"Error","No existe el archivo");
        return;
    }
    arch.setFileName(this->myPath);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen())
    {
        QMessageBox::critical(this,"Error",arch.errorString());
    }else
    {
        //QString texto = ui->texto->toPlainText();
        io.setDevice(&arch);
        io << modes->getEditorTexto()->getText();
        arch.flush();
        arch.close();
    }

}


void MainWindow::on_actionGuardar_como_triggered()
{

    QFile arch;
    QTextStream io;
    QString fileName = "";
    QFileDialog fD;
    //QString fileName = QFileDialog::getSaveFileName(this,"Guardar");
    fileName = fD.getSaveFileName(this,"Guardado",QString(),tr("Text files (*.txt);;C files (*.c)"));
    arch.setFileName(fileName);
    arch.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!arch.isOpen())
    {
        QMessageBox::critical(this,"Error",arch.errorString());
    }else
    {
        //QString texto = ui->texto->toPlainText();
        io.setDevice(&arch);
        io << modes->getEditorTexto()->getText();
        arch.flush();
        arch.close();
        //txt += filePath.fileName();
        QMessageBox::information(this,"Guardado",fileName);
        this->myPath = fileName;
    }

}


void MainWindow::on_actionCerrar_triggered()
{
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this,"Cerrar","¿Quiere cerrar la aplicación?", QMessageBox::Yes | QMessageBox::No );
    if(result == QMessageBox::Yes)
    {
        this->close();
    }
}


void MainWindow::on_actionCopiar_triggered()
{
    modes->getEditorTexto()->copyEditor();
}


void MainWindow::on_actionPegar_triggered()
{
    modes->getEditorTexto()->pasteEditor();
}


void MainWindow::on_actionCortar_triggered()
{
    modes->getEditorTexto()->cutEditor();
}


void MainWindow::on_actionBorrar_triggered()
{
    modes->getEditorTexto()->clearEditor();
}


void MainWindow::on_actionSobre_Qt_triggered()
{
    QMessageBox::aboutQt(this,"Sobre Qt");
}


void MainWindow::on_actionAcerca_de_triggered()
{
    QString txt = "Creador: David Díaz López\n";
    txt += "Fecha: 04/01/2024\n";
    txt += "(C) Dilopad (R)";
    QMessageBox::about(this,"Dilopad",txt);
}


void MainWindow::on_actionProyectos_triggered()
{
    this->proyectos->startMenu(this->myPath);
   // this->ui->horizontalLayout_2->addWidget(proyectos,0);

}

