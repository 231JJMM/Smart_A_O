#include "resetpassworddialog.h"
#include "ui_resetpassworddialog.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

ResetPasswordDialog::ResetPasswordDialog(const QString &token, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::ResetPasswordDialog),
    resetToken(token)
{
    ui->setupUi(this);
}

ResetPasswordDialog::~ResetPasswordDialog()
{
    delete ui;
}

void ResetPasswordDialog::on_pushButton_reset_clicked()
{
    QString newPassword = ui->lineEdit_newPassword->text();
    QString confirmPassword = ui->lineEdit_confirmPassword->text();

    if (newPassword.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Les champs ne peuvent pas être vides.");
        return;
    }

    if (newPassword != confirmPassword) {
        QMessageBox::warning(this, "Erreur", "Les mots de passe ne correspondent pas.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM reset_tokens WHERE token = :token");
    query.bindValue(":token", resetToken);

    if (query.exec() && query.next()) {
        QString email = query.value("email").toString();
        query.prepare("UPDATE EMPLOYES SET MDP = :newPassword WHERE EMAIL = :email");
        query.bindValue(":newPassword", newPassword);
        query.bindValue(":email", email);

        if (query.exec()) {
            QMessageBox::information(this, "Succès", "Le mot de passe a été réinitialisé avec succès.");
            this->accept();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour du mot de passe.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Token invalide ou expiré.");
    }
}
