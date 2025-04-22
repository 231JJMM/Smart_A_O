#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QDialog>
#include "ui_Inscription.h"  // Utilisez maintenant ui_Inscription.h

class Inscription : public QDialog
{
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = nullptr);
    ~Inscription();

private slots:
    void on_pushButton_register_clicked();

private:
    Ui::Inscription *ui;  // Déclaration correcte de l'objet ui
};

#endif // INSCRIPTION_H
