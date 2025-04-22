/********************************************************************************
** Form generated from reading UI file 'Inscription.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTION_H
#define UI_INSCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inscription
{
public:
    QPushButton *pushButton_register;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_email;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_matricule;

    void setupUi(QWidget *Inscription)
    {
        if (Inscription->objectName().isEmpty())
            Inscription->setObjectName("Inscription");
        Inscription->resize(700, 563);
        Inscription->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 3, 148);"));
        pushButton_register = new QPushButton(Inscription);
        pushButton_register->setObjectName("pushButton_register");
        pushButton_register->setGeometry(QRect(430, 440, 121, 41));
        pushButton_register->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 10pt \"Segoe UI\";\n"
"    \n"
"	background-color:  rgb(88, 124, 255) ;\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 4px; /* Coins arrondis */\n"
"    padding: 4px; /* Espacement interne */\n"
"}"));
        lineEdit_nom = new QLineEdit(Inscription);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(300, 230, 161, 31));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: black; /* Texte en blanc */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espacement \303\240 l'int\303\251rieur du bouton */\n"
"    cursor: pointer; /* Changer le curseur pour indiquer qu'il est cliquable */\n"
"    transition: background-color 0.3s ease; /* Animation de la couleur au survol */\n"
"}"));
        lineEdit_password = new QLineEdit(Inscription);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(300, 380, 161, 31));
        lineEdit_password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: black; /* Texte en blanc */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espacement \303\240 l'int\303\251rieur du bouton */\n"
"    cursor: pointer; /* Changer le curseur pour indiquer qu'il est cliquable */\n"
"    transition: background-color 0.3s ease; /* Animation de la couleur au survol */\n"
"}"));
        lineEdit_prenom = new QLineEdit(Inscription);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(300, 280, 161, 31));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: black; /* Texte en blanc */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espacement \303\240 l'int\303\251rieur du bouton */\n"
"    cursor: pointer; /* Changer le curseur pour indiquer qu'il est cliquable */\n"
"    transition: background-color 0.3s ease; /* Animation de la couleur au survol */\n"
"}"));
        lineEdit_email = new QLineEdit(Inscription);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(300, 330, 161, 31));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: black; /* Texte en blanc */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espacement \303\240 l'int\303\251rieur du bouton */\n"
"    cursor: pointer; /* Changer le curseur pour indiquer qu'il est cliquable */\n"
"    transition: background-color 0.3s ease; /* Animation de la couleur au survol */\n"
"}"));
        label = new QLabel(Inscription);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 230, 101, 31));
        label->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(Inscription);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 280, 101, 31));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(Inscription);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 330, 101, 31));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(Inscription);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 380, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(Inscription);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(330, 70, 131, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 143, 255);\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(Inscription);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(160, 170, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8(""));
        lineEdit_matricule = new QLineEdit(Inscription);
        lineEdit_matricule->setObjectName("lineEdit_matricule");
        lineEdit_matricule->setGeometry(QRect(300, 170, 161, 31));
        lineEdit_matricule->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: rgb(255, 255, 255);\n"
"    color: black; /* Texte en blanc */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espacement \303\240 l'int\303\251rieur du bouton */\n"
"    cursor: pointer; /* Changer le curseur pour indiquer qu'il est cliquable */\n"
"    transition: background-color 0.3s ease; /* Animation de la couleur au survol */\n"
"}"));

        retranslateUi(Inscription);

        QMetaObject::connectSlotsByName(Inscription);
    } // setupUi

    void retranslateUi(QWidget *Inscription)
    {
        Inscription->setWindowTitle(QCoreApplication::translate("Inscription", "Form", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Inscription", "s'incrire", nullptr));
        label->setText(QCoreApplication::translate("Inscription", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Nom</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Inscription", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Prenom</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Inscription", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Email</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Inscription", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">mot de passe</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Inscription", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:700;\">Inscription</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Inscription", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Matricule</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inscription: public Ui_Inscription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTION_H
