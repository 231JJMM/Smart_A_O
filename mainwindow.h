#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employes.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // Constructeur avec paramètre
    ~MainWindow();  // Destructeur
    void setRole(QString p);

private slots:
    void on_pushButton_ajouter_clicked();  // Slot pour gérer le bouton "ajouter"
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_rechercher_clicked();
    void on_pushButton_filtrer_clicked(); // <- Ajoute cette ligne ici
    void on_pushButton_exportation_clicked();
    void on_pushButton_statistique_clicked();




private:
    Ui::MainWindow *ui;
    Employe Etmp;
    QString role;
    // Pointeur vers l'interface utilisateur
    // Ajoutez votre objet employé ici si nécessaire
    // employe Etmp;   // Exemple d'un objet employé (à adapter selon votre code)
};

#endif // MAINWINDOW_H
