#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFont font;
    font.setPointSize(16);
    ui->setupUi(this);
    setCentralWidget(ui->texto);
    this->setStyleSheet("QMainWindow { background-color : white; color : yellow; }");
    ui->menubar->setStyleSheet("QMenuBar { background-color : white ; color : blue;}");
    ui->texto->setStyleSheet("QPlainTextEdit { background-color : blue; color : white; }");
    ui->texto->setFont(font);
    this->myPath = "";
}

MainWindow::~MainWindow()
{
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
        ui->texto->clear();
        ui->texto->appendPlainText(io.readAll());
        arch.close();
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
        io << ui->texto->toPlainText();
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
        io << ui->texto->toPlainText();
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
    ui->texto->copy();
}


void MainWindow::on_actionPegar_triggered()
{
    ui->texto->paste();
}


void MainWindow::on_actionCortar_triggered()
{
    ui->texto->cut();
}


void MainWindow::on_actionBorrar_triggered()
{
    ui->texto->clear();
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

