#include "inscription.h"
#include "ui_inscription.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Inscription::Inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inscription)
{
    ui->setupUi(this);
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::on_pushButton_register_clicked()
{
    // Récupère les valeurs du formulaire
    QString matricule = ui->lineEdit_matricule->text();  // <-- Ajout ici
    QString email = ui->lineEdit_email->text();
    QString motDePasse = ui->lineEdit_password->text();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();

    // Vérifie que tous les champs sont remplis
    if (matricule.isEmpty() || email.isEmpty() || motDePasse.isEmpty() || nom.isEmpty() || prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Vérifie que l'email n'existe pas déjà
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec()) {
        query.next();
        if (query.value(0).toInt() > 0) {
            QMessageBox::warning(this, "Erreur", "Cet email est déjà utilisé.");
            return;
        }
    } else {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    // Prépare et exécute l'insertion
    query.prepare("INSERT INTO EMPLOYES (MATRICULE, EMAIL, MDP, NOM, PRENOM) "
                  "VALUES (:matricule, :email, :mdp, :nom, :prenom)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":email", email);
    query.bindValue(":mdp", motDePasse);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Employé enregistré avec succès.");
        this->close();
    } else {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
    }
}
