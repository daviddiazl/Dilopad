#include "mmodes.h"
#include "ui_mmodes.h"

mmodes::mmodes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mmodes)
{
    editorTexto = new mEditorTexto();
    ui->setupUi(this);
    ui->lTexto->addWidget(editorTexto);
}

mmodes::~mmodes()
{
    delete editorTexto;
    delete ui;
}

mEditorTexto* mmodes::getEditorTexto()
{
    return this->editorTexto;
}
