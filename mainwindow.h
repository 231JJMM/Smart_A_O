#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "ressource.h"
#include <QPrinter>
#include <QPainter>
#include "qrcode.h"
#include <QDate>
#include <QTextStream>
#include <QTextDocument>
// Inclure le fichier d'en-tête pour la vue de graphique QtCharts
#include <QtCharts/QChartView>
// Inclure le fichier d'en-tête pour la série de diagramme circulaire QtCharts
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
// Inclure le fichier d'en-tête pour la gestion de la disposition horizontale
#include <QHBoxLayout>
#include <QtCharts/QLegend>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <QBarSet>
#include <QBarSeries>
#include <QLayout>
#include <QVector>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QPalette>
#include <QSqlQuery>
#include<QSerialPort>
#include<QSerialPortInfo>

#include <QMainWindow>

namespace Ui { class MainWindow; }
class QSqlTableModel;
class QItemSelection;
class QModelIndex;
class QSqlQueryModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots renommés selon le nouveau fichier UI

    // Onglet "Create"
    void on_pushButton_29_clicked(); // Ancien: on_pushButton_13_clicked

    // Onglet "Read"
    void on_tableView_2_activated(const QModelIndex &index); // Ancien: on_tableView_activated
    void on_pushButton_4_clicked();   // Export PDF - Ancien: on_pushButton_3_clicked
    void on_pushButton_26_clicked();  // Statistiques - Ancien: on_pushButton_25_clicked
    void on_linerech_2_textChanged(const QString &arg1); // Recherche - Ancien: on_linerech_textChanged
    void on_pushButton_5_clicked();   // Tri/Filter - Ancien: on_pushButton_2_clicked

    // Onglet "Update"
    void on_pushButton_27_clicked(); // Ancien: on_pushButton_15_clicked

    // Onglet "Delete"
    void on_pushButton_23_clicked(); // Ancien: on_pushButton_14_clicked

    // Note: pushButton_28 dans l'onglet Qrcode n'avait pas de slot correspondant dans l'ancien code.
    // Le QR code est généré dans on_tableView_2_activated. Si pushButton_28 doit faire qqch, ajoutez un slot.

private:
    Ui::MainWindow *ui;
    Ressource R; // Instance de la classe Ressource

    // Helper function to clear input fields in a specific tab
    void clearInputFieldsCreate();
    void clearInputFieldsUpdate();
    void clearInputFieldsDelete();
    void refreshTableView(); // Fonction pour rafraîchir la table
    void updateAlertsTab();  // <--- AJOUTER/VÉRIFIER CETTE LIGNE (pour l'onglet Alerte)
    void envoyerSeuilsAuto();
    QSerialPort *serial;
};
#endif // MAINWINDOW_H
