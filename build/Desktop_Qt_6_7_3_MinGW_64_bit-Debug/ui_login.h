/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *lineEdit_password;
    QLabel *label_4;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_username;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_oublie;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_inscrire;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(925, 663);
        Login->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 6, 127);"));
        lineEdit_password = new QLineEdit(Login);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(390, 310, 161, 31));
        lineEdit_password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: black; /* Texte en blanc */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espacement \303\240 l'int\303\251rieur du bouton */\n"
"    cursor: pointer; /* Changer le curseur pour indiquer qu'il est cliquable */\n"
"    transition: background-color 0.3s ease; /* Animation de la couleur au survol */\n"
"}"));
        label_4 = new QLabel(Login);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(370, 280, 16, 16));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/cadenas.png")));
        label_4->setScaledContents(true);
        pushButton_login = new QPushButton(Login);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(380, 400, 161, 41));
        pushButton_login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 10pt \"Segoe UI\";\n"
"    \n"
"	background-color:  rgb(88, 124, 255) ;\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 4px; /* Coins arrondis */\n"
"    padding: 4px; /* Espacement interne */\n"
"}"));
        lineEdit_username = new QLineEdit(Login);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(390, 260, 161, 31));
        lineEdit_username->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border-color: rgb(0, 0, 0);\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: black; /* Texte en blanc */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espacement \303\240 l'int\303\251rieur du bouton */\n"
"    cursor: pointer; /* Changer le curseur pour indiquer qu'il est cliquable */\n"
"    transition: background-color 0.3s ease; /* Animation de la couleur au survol */\n"
"}"));
        label_3 = new QLabel(Login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(370, 240, 21, 21));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/utilisateur.png")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(Login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 310, 121, 31));
        pushButton_oublie = new QPushButton(Login);
        pushButton_oublie->setObjectName("pushButton_oublie");
        pushButton_oublie->setGeometry(QRect(520, 350, 191, 29));
        label_5 = new QLabel(Login);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(350, 40, 241, 161));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/Screenshots/Screenshot 2025-03-13 001726.png")));
        label_6 = new QLabel(Login);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 260, 121, 31));
        pushButton_inscrire = new QPushButton(Login);
        pushButton_inscrire->setObjectName("pushButton_inscrire");
        pushButton_inscrire->setGeometry(QRect(280, 350, 141, 29));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        label_4->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("Login", "Login", nullptr));
        lineEdit_username->setText(QString());
        label_3->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">mot de passe</span></p></body></html>", nullptr));
        pushButton_oublie->setText(QCoreApplication::translate("Login", "mot de passe oubli\303\251 ?", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">email</span></p></body></html>", nullptr));
        pushButton_inscrire->setText(QCoreApplication::translate("Login", "s'inscrire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
