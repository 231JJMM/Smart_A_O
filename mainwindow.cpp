#include "mainwindow.h"
#include "employes.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QPainter>
#include <QTextDocument>
#include <QStandardItemModel>
#include <QTextStream>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());

    // Connexion des boutons

    connect(ui->pushButton_rechercher, &QPushButton::clicked, this, &MainWindow::on_pushButton_rechercher_clicked);
    connect(ui->pushButton_filtrer, &QPushButton::clicked, this, &MainWindow::on_pushButton_filtrer_clicked);
    connect(ui->pushButton_exportation, &QPushButton::clicked, this, &MainWindow::on_pushButton_exportation_clicked);
    connect(ui->pushButton_statistique, &QPushButton::clicked, this, &MainWindow::on_pushButton_statistique_clicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int matricule = ui->lineEdit_matricule->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString email = ui->lineEdit_email->text();
    QString mdp = ui->lineEdit_mdp->text();
    QString role = ui->comBox->currentText();

    // Validation email
    if (!email.contains('@')) {
        QMessageBox::warning(this, "Email invalide", "L'email doit contenir '@'.");
        return;
    }

    // Ajouter l'employé
    Employe E(matricule, nom, prenom, email, mdp, role);
    bool test = E.ajouter();

    if (test) {
        QMessageBox::information(this, "Succès", "Ajout effectué.");
        ui->tableView->setModel(Etmp.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout non effectué.");
    }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int matricule = ui->lineEdit_matricule->text().toInt();

    bool test = Etmp.supprimer(matricule);

    if (test) {
        QMessageBox::information(this, "Succès", "Suppression effectuée.");
        ui->tableView->setModel(Etmp.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression non effectuée.");
    }
}




void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(Etmp.afficher());
}
// Dans mainwindow.cpp

void MainWindow::on_pushButton_rechercher_clicked() {
    // Récupérer le matricule de la zone de texte
    int matricule = ui->lineEdit_matricule_2->text().toInt();

    // Appeler la méthode de recherche
    QSqlQueryModel* model = Etmp.rechercherParMatricule(matricule);

    // Vérifier si le modèle est valide
    if (model) {
        ui->tableView->setModel(model);  // Afficher les résultats dans le QTableView
    } else {
        QMessageBox::critical(this, "Erreur", "Aucun employé trouvé ou erreur dans la recherche.");
    }
}
void MainWindow::on_pushButton_filtrer_clicked() {
    Employe e;
    QSqlQueryModel* model = e.trierParMatricule();
    ui->tableView->setModel(model); // Remplace 'tableView' par le nom de ton tableau si différent
}
void MainWindow::on_pushButton_exportation_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter", "", "PDF (*.pdf);;Excel (*.csv)");
    if (fileName.isEmpty()) return;

    if (fileName.endsWith(".pdf")) {
        // Export PDF
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        QPainter painter(&printer);
        int y = 0;

        // Header
        painter.setFont(QFont("Arial", 12, QFont::Bold));
        painter.drawText(100, y += 50, "Liste des Employés");

        painter.setFont(QFont("Arial", 10));
        y += 50;

        for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
            QString line;
            for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
                QModelIndex index = ui->tableView->model()->index(row, col);
                line += index.data().toString() + "\t";
            }
            painter.drawText(100, y += 30, line);
        }

        painter.end();
        QMessageBox::information(this, "Succès", "PDF exporté avec succès !");
    }
    else if (fileName.endsWith(".csv")) {
        // Export Excel (CSV)
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            // En-têtes
            for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
                stream << ui->tableView->model()->headerData(col, Qt::Horizontal).toString();
                if (col != ui->tableView->model()->columnCount() - 1)
                    stream << ",";
            }
            stream << "\n";

            // Données
            for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
                for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
                    stream << ui->tableView->model()->data(ui->tableView->model()->index(row, col)).toString();
                    if (col != ui->tableView->model()->columnCount() - 1)
                        stream << ",";
                }
                stream << "\n";
            }

            file.close();
            QMessageBox::information(this, "Succès", "Fichier Excel (CSV) exporté !");
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier !");
        }
    }
}
void MainWindow::on_pushButton_statistique_clicked()
{
    QSqlQuery query;
    int totalEmployes = 0;

    // Requête pour compter tous les employés
    if (query.exec("SELECT COUNT(*) FROM EMPLOYES")) {
        if (query.next()) {
            totalEmployes = query.value(0).toInt();
        }
    }

    if (totalEmployes == 0) {
        QMessageBox::information(this, "Statistique", "Aucun employé trouvé !");
        return;
    }

    // Préparation des données pour le pie chart
    QPieSeries *series = new QPieSeries();
    series->append("Employés", totalEmployes);

    QPieSlice *slice = series->slices().at(0);
    slice->setLabel(QString("Employés (%1)").arg(totalEmployes));
    slice->setExploded(true);
    slice->setLabelVisible(true);
    slice->setBrush(QColor("#3498db"));  // Bleu

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique des employés (Total)");
    chart->legend()->hide();

    // Affichage du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(500, 400);
    chartView->show();
}
void MainWindow::setRole (QString p) {
    role = p;

    if (role == "Responsable humaines") {
        ui->pushButton_modifier->setEnabled(true);
        ui->pushButton_ajouter->setText("Valider");
        ui->pushButton_supprimer->setEnabled(false);
        ui->lineEdit_3->setReadOnly(true);

        ui->pushButton_exportation->setEnabled(true);
        ui->pushButton_statistique->setEnabled(true);
        ui->lineEdit_matricule_2->setEnabled(true);
        ui->lineEdit_matricule->setReadOnly(true);
        ui->lineEdit_nom->setReadOnly(true);
        ui->lineEdit_prenom->setReadOnly(true);
        ui->lineEdit_email->setReadOnly(true);

        ui->comBox->setDisabled(true);


        ui->lineEdit_mdp->setReadOnly(true);
    } else if (role == "Admin") {
        ui->pushButton_modifier->setEnabled(true);
        ui->pushButton_ajouter->setText("Valider");
        ui->pushButton_supprimer->setEnabled(true);
        ui->lineEdit_3->setReadOnly(true);

        ui->pushButton_exportation->setEnabled(true);
        ui->pushButton_statistique->setEnabled(true);
        ui->lineEdit_matricule_2->setEnabled(false);
        ui->lineEdit_matricule->setReadOnly(false);
        ui->lineEdit_nom->setReadOnly(false);
        ui->lineEdit_prenom->setReadOnly(false);
        ui->lineEdit_email->setReadOnly(false);

        ui->comBox->setDisabled(true);


        ui->lineEdit_mdp->setReadOnly(false);
    } {

        ui->pushButton_modifier->setEnabled(false);
        ui->pushButton_ajouter->setText("Valider");
        ui->pushButton_supprimer->setEnabled(false);
        ui->lineEdit_3->setReadOnly(false);

        ui->pushButton_exportation->setEnabled(false);
        ui->pushButton_statistique->setEnabled(true);
        ui->lineEdit_matricule_2->setEnabled(false);
        ui->lineEdit_matricule->setReadOnly(false);
        ui->lineEdit_nom->setReadOnly(true);
        ui->lineEdit_prenom->setReadOnly(true);
        ui->lineEdit_email->setReadOnly(true);

        ui->comBox->setDisabled(true);


        ui->lineEdit_mdp->setReadOnly(true);;
    }
}
