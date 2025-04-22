/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLabel *label_29;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget_3;
    QLineEdit *lineEdit_matricule_2;
    QPushButton *pushButton_rechercher;
    QPushButton *pushButton_filtrer;
    QPushButton *pushButton_exportation;
    QPushButton *pushButton_supprimer;
    QLineEdit *lineEdit_3;
    QTableView *tableView;
    QPushButton *pushButton_4;
    QPushButton *pushButton_statistique;
    QWidget *tab_2;
    QWidget *widget_4;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_25;
    QLineEdit *lineEdit_matricule;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_mdp;
    QPushButton *pushButton_ajouter;
    QComboBox *comBox;
    QLabel *label_26;
    QWidget *tab_4;
    QWidget *widget_8;
    QWidget *widget_9;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QPushButton *pushButton_modifier;
    QLabel *label_40;
    QLineEdit *lineEdit_25;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_45;
    QLabel *label_44;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1572, 1049);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 30, 1331, 671));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 30, 201, 621));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 163, 184);"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 140, 111, 16));
        label_3->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"font: 700 italic 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 170, 91, 16));
        label_4->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"font: 700 italic 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 200, 101, 16));
        label_5->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"font: 700 italic 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 230, 91, 16));
        label_7->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"font: 700 italic 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_4 = new QLineEdit(widget_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(0, 100, 201, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background color gb(0, 0, 0)\n"
"font: 700 9pt \"Segoe UI\";"));
        label_29 = new QLabel(widget_2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(40, 550, 131, 41));
        label_29->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);\n"
"font: 700 italic 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(240, 30, 991, 561));
        tabWidget->setMinimumSize(QSize(611, 0));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 0, 185);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        widget_3 = new QWidget(tab);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 981, 511));
        lineEdit_matricule_2 = new QLineEdit(widget_3);
        lineEdit_matricule_2->setObjectName("lineEdit_matricule_2");
        lineEdit_matricule_2->setGeometry(QRect(10, 10, 131, 21));
        lineEdit_matricule_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"QWidget {\n"
"    background-color: #FF9A8B;\n"
"    color: black;\n"
"    border: 1px solid transparent; /* Force la coloration */\n"
"}"));
        pushButton_rechercher = new QPushButton(widget_3);
        pushButton_rechercher->setObjectName("pushButton_rechercher");
        pushButton_rechercher->setGeometry(QRect(160, 0, 111, 31));
        pushButton_rechercher->setStyleSheet(QString::fromUtf8("    	\n"
"background-color: rgb(104, 163, 184);\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px; /* Espacement interne */\n"
""));
        pushButton_filtrer = new QPushButton(widget_3);
        pushButton_filtrer->setObjectName("pushButton_filtrer");
        pushButton_filtrer->setGeometry(QRect(810, 10, 111, 31));
        pushButton_filtrer->setStyleSheet(QString::fromUtf8("    	\n"
"background-color: rgb(104, 163, 184);\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px; /* Espacement interne */\n"
""));
        pushButton_exportation = new QPushButton(widget_3);
        pushButton_exportation->setObjectName("pushButton_exportation");
        pushButton_exportation->setGeometry(QRect(60, 460, 121, 31));
        pushButton_exportation->setStyleSheet(QString::fromUtf8("    	\n"
"background-color: rgb(104, 163, 184);\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px; /* Espacement interne */\n"
""));
        pushButton_supprimer = new QPushButton(widget_3);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(810, 460, 121, 31));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("    	\n"
"background-color: rgb(104, 163, 184);\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px; /* Espacement interne */\n"
""));
        lineEdit_3 = new QLineEdit(widget_3);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(720, 460, 71, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        tableView = new QTableView(widget_3);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(95, 91, 761, 341));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(149, 200, 255);"));
        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(430, 470, 83, 29));
        pushButton_statistique = new QPushButton(widget_3);
        pushButton_statistique->setObjectName("pushButton_statistique");
        pushButton_statistique->setGeometry(QRect(450, 10, 131, 29));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, -30, 1141, 601));
        label_15 = new QLabel(widget_4);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 20, 161, 16));
        label_16 = new QLabel(widget_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(50, 80, 71, 16));
        label_17 = new QLabel(widget_4);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(50, 110, 61, 16));
        label_18 = new QLabel(widget_4);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(50, 140, 61, 16));
        label_19 = new QLabel(widget_4);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(50, 170, 37, 12));
        label_25 = new QLabel(widget_4);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 210, 37, 12));
        lineEdit_matricule = new QLineEdit(widget_4);
        lineEdit_matricule->setObjectName("lineEdit_matricule");
        lineEdit_matricule->setGeometry(QRect(120, 80, 341, 21));
        lineEdit_matricule->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_nom = new QLineEdit(widget_4);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(110, 110, 321, 20));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_prenom = new QLineEdit(widget_4);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(110, 140, 311, 20));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_email = new QLineEdit(widget_4);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(110, 170, 331, 21));
        lineEdit_email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_mdp = new QLineEdit(widget_4);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(110, 205, 321, 21));
        lineEdit_mdp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_ajouter = new QPushButton(widget_4);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(470, 270, 81, 41));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("    	\n"
"background-color: rgb(104, 163, 184);\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px; /* Espacement interne */\n"
""));
        comBox = new QComboBox(widget_4);
        comBox->addItem(QString());
        comBox->addItem(QString());
        comBox->setObjectName("comBox");
        comBox->setGeometry(QRect(110, 240, 251, 28));
        label_26 = new QLabel(widget_4);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(50, 240, 41, 21));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        widget_8 = new QWidget(tab_4);
        widget_8->setObjectName("widget_8");
        widget_8->setGeometry(QRect(-1, -11, 871, 521));
        widget_9 = new QWidget(widget_8);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(30, 40, 861, 491));
        widget_9->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 0, 185);\n"
"color: rgb(255, 255, 255);"));
        lineEdit_15 = new QLineEdit(widget_9);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(280, 10, 221, 21));
        lineEdit_15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_17 = new QLineEdit(widget_9);
        lineEdit_17->setObjectName("lineEdit_17");
        lineEdit_17->setGeometry(QRect(280, 70, 201, 21));
        lineEdit_20 = new QLineEdit(widget_9);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setGeometry(QRect(280, 130, 191, 21));
        lineEdit_21 = new QLineEdit(widget_9);
        lineEdit_21->setObjectName("lineEdit_21");
        lineEdit_21->setGeometry(QRect(280, 190, 181, 21));
        pushButton_modifier = new QPushButton(widget_9);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(600, 340, 121, 31));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("    	\n"
"background-color: rgb(104, 163, 184);\n"
"    color: black; /* Texte noir */\n"
"    border: 2px solid black; /* Bordure noire */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 5px; /* Espacement interne */\n"
""));
        label_40 = new QLabel(widget_9);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(140, 250, 111, 16));
        lineEdit_25 = new QLineEdit(widget_9);
        lineEdit_25->setObjectName("lineEdit_25");
        lineEdit_25->setGeometry(QRect(280, 250, 181, 20));
        label_42 = new QLabel(widget_9);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(150, 190, 111, 16));
        label_43 = new QLabel(widget_9);
        label_43->setObjectName("label_43");
        label_43->setGeometry(QRect(150, 10, 111, 16));
        label_45 = new QLabel(widget_9);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(150, 130, 111, 16));
        label_44 = new QLabel(widget_9);
        label_44->setObjectName("label_44");
        label_44->setGeometry(QRect(150, 70, 111, 16));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1572, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "projets", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "plans", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "resources", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "      Employes", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Se d\303\251connecter ", nullptr));
        lineEdit_matricule_2->setText(QString());
        pushButton_rechercher->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        pushButton_filtrer->setText(QCoreApplication::translate("MainWindow", "Filtrer par ID", nullptr));
        pushButton_exportation->setText(QCoreApplication::translate("MainWindow", "Exportation", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        lineEdit_3->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "refresh", nullptr));
        pushButton_statistique->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Afficher Employer", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Ajouter un Employer", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "matricule", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "MDP", nullptr));
        lineEdit_matricule->setText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        comBox->setItemText(0, QCoreApplication::translate("MainWindow", "Admin ", nullptr));
        comBox->setItemText(1, QCoreApplication::translate("MainWindow", "Responsable humaine", nullptr));

        label_26->setText(QCoreApplication::translate("MainWindow", "role", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "ajouter Employer", nullptr));
        lineEdit_17->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "mot de passe", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "matricule", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "modifier Employer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
