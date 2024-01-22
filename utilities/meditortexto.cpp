#include "meditortexto.h"
#include "ui_meditortexto.h"

mEditorTexto::mEditorTexto(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mEditorTexto)
{
    QFont font;
    font.setPointSize(12);
    ui->setupUi(this);
    ui->textEdit->setCenterOnScroll(1);
    ui->textEdit->setStyleSheet("QPlainTextEdit { background-color : blue; color : white; }");
    ui->textEdit->setFont(font);

}

mEditorTexto::~mEditorTexto()
{
    delete ui;
}

void mEditorTexto::clearEditor()
{
    this->ui->textEdit->clear();
}

void mEditorTexto::cutEditor()
{
    this->ui->textEdit->cut();
}

void mEditorTexto::copyEditor()
{
    this->ui->textEdit->copy();
}

void mEditorTexto::pasteEditor()
{
    this->ui->textEdit->paste();
}

void mEditorTexto::introText(const QString texto)
{
    this->ui->textEdit->appendPlainText(texto);
}

QString mEditorTexto::getText()
{
    return this->ui->textEdit->toPlainText();
}
