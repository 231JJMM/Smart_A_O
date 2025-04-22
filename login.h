#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPushButton>
#include <QLineEdit> // Pour manipuler les champs de texte (username, password)

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    // Fonction pour envoyer l'email de réinitialisation
    void sendResetEmailMailjet(const QString& userEmail);
    QString generateResetToken();  // Déclaration de la fonction pour générer un token
  // Déclaration de la fonction pour générer un token


private slots:
    // Slot pour gérer la connexion
    void on_pushButton_login_clicked();

    // Slot pour gérer le mot de passe oublié
    void on_pushButton_oublie_clicked();

    // Slot pour ouvrir la fenêtre d'inscription
    void ouvrirInscription();

private:
    Ui::Login *ui;

    // Déclaration d'un QNetworkAccessManager pour gérer les requêtes réseau
    QNetworkAccessManager *networkManager;
};

#endif // LOGIN_H
