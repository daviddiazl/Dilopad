#ifndef MEDITORTEXTO_H
#define MEDITORTEXTO_H

#include <QWidget>

namespace Ui {
class mEditorTexto;
}

class mEditorTexto : public QWidget
{
    Q_OBJECT

public:
    explicit mEditorTexto(QWidget *parent = nullptr);
    ~mEditorTexto();
    void introText(const QString texto);
    QString getText();
    void copyEditor();
    void pasteEditor();
    void cutEditor();
    void clearEditor();

private:
    Ui::mEditorTexto *ui;
};

#endif // MEDITORTEXTO_H
