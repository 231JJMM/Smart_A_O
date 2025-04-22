#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Connexion à la base de données
    Connection c;
    if (c.createconnect()) {
        QMessageBox::information(nullptr, QObject::tr("Base de données ouverte"),
                                 QObject::tr("Connexion réussie.\nCliquez sur OK pour continuer."),
                                 QMessageBox::Ok);

        // Affichage de la fenêtre de login
        Login loginWindow;
        if (loginWindow.exec() == QDialog::Accepted) {
            MainWindow mainWindow;
            mainWindow.show();
            return a.exec();
        } else {
            return 0;  // L'utilisateur a fermé ou annulé le login
        }

    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur de base de données"),
                              QObject::tr("Échec de connexion à la base.\nCliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
        return -1;
    }
}
