#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "utilities/mmenu.h"
#include "utilities/meditortexto.h"
#include "utilities/mmodes.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_actionGuardar_triggered();

    void on_actionGuardar_como_triggered();

    void on_actionCerrar_triggered();

    void on_actionCopiar_triggered();

    void on_actionPegar_triggered();

    void on_actionCortar_triggered();

    void on_actionBorrar_triggered();

    void on_actionSobre_Qt_triggered();

    void on_actionAcerca_de_triggered();

    void on_actionProyectos_triggered();

private:
    Ui::MainWindow *ui;
    QString myPath;

    mMenu *proyectos;
    //mEditorTexto *editorTexto;
    mmodes *modes;

};
#endif // MAINWINDOW_H
