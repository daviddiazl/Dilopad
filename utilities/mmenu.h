#ifndef MMENU_H
#define MMENU_H

#include <QWidget>
#include <QTreeWidget>
#include <QFileSystemModel>

namespace Ui {
class mMenu;
}

class mMenu : public QWidget
{
    Q_OBJECT

public:
    explicit mMenu(QWidget *parent = nullptr);
    ~mMenu();
    void startMenu(QString path);

private:
    Ui::mMenu *ui;

    QFileSystemModel modelo;
};

#endif // MMENU_H
