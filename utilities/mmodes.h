#ifndef MMODES_H
#define MMODES_H

#include <QWidget>
#include "meditortexto.h"


namespace Ui {
class mmodes;
}

class mmodes : public QWidget
{
    Q_OBJECT

public:
    explicit mmodes(QWidget *parent = nullptr);
    ~mmodes();
    mEditorTexto* getEditorTexto();

private:
    Ui::mmodes *ui;
    mEditorTexto *editorTexto;
};

#endif // MMODES_H
