#include "editortexto.h"
#include "ui_editortexto.h"

EditorTexto::EditorTexto(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditorTexto)
{
    ui->setupUi(this);
    QFont font;
    this->ui->texto->setCenterOnScroll(1);
    font.setPointSize(16);
    ui->texto->setStyleSheet("QPlainTextEdit { background-color : blue; color : white; }");
    ui->texto->setFont(font);
}

EditorTexto::~EditorTexto()
{
    delete ui;
}
