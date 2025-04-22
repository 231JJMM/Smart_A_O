#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "Inscription.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QJsonArray>
#include <QUuid>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    // Connecter le bouton d'inscription
    connect(ui->pushButton_inscrire, &QPushButton::clicked, this, &Login::ouvrirInscription);
    connect(ui->pushButton_oublie, &QPushButton::clicked, this, &Login::on_pushButton_oublie_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom d'utilisateur et un mot de passe.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYES WHERE EMAIL = :email AND MDP = :mdp");
    query.bindValue(":email", username);
    query.bindValue(":mdp", password);

    if (query.exec() && query.next()) {
        QMessageBox::information(this, "Connexion réussie", "Bienvenue, " + username + " !");
        this->accept();  // 👈 Très important : ne ferme pas l'appli, signale juste le succès
    } else {
        QMessageBox::warning(this, "Échec de connexion", "Email ou mot de passe incorrect.");
    }
}

void Login::ouvrirInscription()
{
    this->close();  // Ferme la fenêtre de login
    Inscription inscriptionWindow;
    inscriptionWindow.exec();  // Affiche la fenêtre d'inscription
}

void Login::on_pushButton_oublie_clicked()
{
    QString email = ui->lineEdit_username->text();
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre adresse email.");
        return;
    }

    sendResetEmailMailjet(email);  // 💌 Envoie avec Mailjet
}
QString Login::generateResetToken()
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);  // Génère un UUID sans les accolades
}

void Login::sendResetEmailMailjet(const QString& userEmail)
{
    // 🔐 Génération d'un token
    QString token = generateResetToken();
    QString resetLink = "http://localhost:8000/reset-password?token=" + token;  // Remplace l'URL par celle de ton projet


    // 📁 Sauvegarde du token
    QFile file("reset_tokens.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << userEmail << ":" << token << "\n";
        file.close();
    }

    // 🔐 Identifiants Mailjet
    QString apiKey = "0a8110d291e2d0a03c267f5f79b19f56";
    QString apiSecret = "627b67fe64956a68abf9217443cbe642";

    QString credentials = apiKey + ":" + apiSecret;
    QByteArray authHeader = "Basic " + credentials.toUtf8().toBase64();

    QJsonObject message;
    message["From"] = QJsonObject{
        {"Email", "chernichahd5@gmail.com"},
        {"Name", "admin"}
    };
    message["To"] = QJsonArray{ QJsonObject{
        {"Email", userEmail},
        {"Name", "Utilisateur"}
    }};
    message["Subject"] = "🔐 Réinitialisation de votre mot de passe";
    message["TextPart"] = "Réinitialisez votre mot de passe ici : " + resetLink;
    message["HTMLPart"] =
        "<html><body>"
        "<h3>Réinitialisation de mot de passe</h3>"
        "<p>Bonjour,</p>"
        "<p>Cliquez sur ce lien pour réinitialiser votre mot de passe :</p>"
        "<p><a href='" + resetLink + "'>" + resetLink + "</a></p>"
                                         "<br><p>Si vous n'avez pas demandé ce changement, ignorez simplement cet e-mail.</p>"
                                         "</body></html>";

    QJsonObject mailData;
    mailData["Messages"] = QJsonArray{ message };

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("https://api.mailjet.com/v3.1/send"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", authHeader);

    QNetworkReply* reply = manager->post(request, QJsonDocument(mailData).toJson());

    connect(reply, &QNetworkReply::finished, this, [reply]() {
        QByteArray response = reply->readAll();
        qDebug() << "Réponse Mailjet:" << response;

        if (reply->error() == QNetworkReply::NoError) {
            QMessageBox::information(nullptr, "Succès", "Le lien de réinitialisation a été envoyé !");
        } else {
            QMessageBox::critical(nullptr, "Erreur", "Erreur d'envoi : " + reply->errorString());
        }
        reply->deleteLater();
    });
}
