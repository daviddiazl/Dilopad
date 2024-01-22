#include "mmenu.h"
#include "ui_mmenu.h"

mMenu::mMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mMenu)
{
    ui->setupUi(this);
    ui->treeView->setModel(&modelo);

}

mMenu::~mMenu()
{
    delete ui;
}


void mMenu::startMenu(QString path)
{
    modelo.setRootPath(path);
}
