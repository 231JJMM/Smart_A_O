// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ressource.h"    // Classe Ressource
#include "qrcode.h"       // Classe pour QR Code (Vérifiez ce nom/chemin)


// Includes Qt nécessaires
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QString>
#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QTime>
#include <QPrinter>
#include <QPdfWriter>     // Nécessaire pour QPrinter::PdfFormat si < Qt 5.15
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPageSize>      // Pour le format de page PDF
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QLayout>
#include <QVector>
#include <QStringList>
#include <QPalette>
#include <QApplication>
#include <QImage>         // Pour le QR Code
#include <QPixmap>        // Pour afficher le QR Code

// Includes Qt SQL
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>     // <<<--- INCLUDE ESSENTIEL
#include <QDebug>

// Includes Qt Charts (si utilisés dans ressource.cpp)
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <qserialport.h>
#include <QSerialPortInfo>

QSerialPort *serial;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // --- Feuille de style ---
    QString styles = R"(
    /* ===================================================== */
    /*      Feuille de Style - Thème Bleu Foncé Moderne      */
    /* ===================================================== */

    /* 🌌 Fenêtre principale et Widgets par défaut */
    QWidget {
        background-color: #012c4a; /* Bleu très foncé */
        font-family: 'Segoe UI', sans-serif; /* Police moderne */
        font-size: 13px; /* Taille de police standard */
        color: #e6f2fa; /* Texte blanc cassé par défaut */
    }

    /* 🔷 Champs de Texte (QLineEdit) */
    QLineEdit {
        background-color: #e6f2fa; /* Fond bleu très clair */
        color: #012c4a; /* Texte bleu foncé */
        border: 1px solid #02456e; /* Bordure subtile bleu foncé */
        border-radius: 8px; /* Coins arrondis */
        padding: 7px 10px; /* Espacement intérieur */
        font-size: 13px; /* Correspondance taille police */
    }

    QLineEdit:focus {
        border: 1px solid #00aaff; /* Bordure bleu vif en focus */
        background-color: #ffffff; /* Fond blanc en focus */
    }

    /* 🔘 Boutons (QPushButton) */
    QPushButton {
        background-color: #00aaff; /* Bleu vif */
        color: white;
        border: none; /* Pas de bordure */
        border-radius: 8px; /* Coins arrondis */
        padding: 8px 18px; /* Espacement */
        font-weight: bold;
        font-size: 13px; /* Correspondance taille police */
    }

    QPushButton:hover {
        background-color: #0292c4; /* Bleu légèrement plus foncé au survol */
    }

    QPushButton:pressed {
        background-color: #017cb0; /* Bleu encore plus foncé quand pressé */
    }

    /* 🔻 Listes Déroulantes (QComboBox) */
    QComboBox {
        background-color: #e6f2fa; /* Fond bleu très clair */
        color: #012c4a; /* Texte bleu foncé */
        border: 1px solid #02456e; /* Bordure subtile */
        border-radius: 8px; /* Coins arrondis */
        padding: 6px 10px; /* Espacement */
    }

    QComboBox::drop-down {
        border: none; /* Pas de bordure pour la flèche */
        background: transparent;
        /* image: url(:/icons/down_arrow.png); */
        /* width: 15px; */
    }

    QComboBox QAbstractItemView { /* La liste qui apparaît */
        background-color: #e6f2fa;
        color: #012c4a;
        border: 1px solid #00aaff; /* Bordure bleu vif */
        selection-background-color: #cceeff; /* Fond de sélection plus clair */
        selection-color: #012c4a; /* Texte de sélection */
        outline: none; /* Pas de contour de focus */
    }

    /* 🧾 Labels (QLabel) - Style de base */
    QLabel {
        color: #e6f2fa; /* Texte blanc cassé par défaut */
        background-color: transparent; /* Assure la transparence */
        border: none; /* Assure pas de bordure par défaut */
        padding: 2px; /* Petit padding pour l'espacement */
    }

    /* 📦 Group Box (QGroupBox) */
    QGroupBox {
        background-color: #02385a; /* Bleu légèrement plus clair que le fond */
        border: 1px solid #00aaff; /* Bordure bleu vif */
        border-radius: 10px;
        padding: 20px 10px 10px 10px; /* Espacement : haut, droite, bas, gauche */
        margin-top: 15px; /* Espace au-dessus de la boîte */
        font-size: 13px; /* Hérité */
        color: #e6f2fa; /* Hérité */
    }

    QGroupBox::title {
        subcontrol-origin: margin;
        subcontrol-position: top left;
        padding: 0 8px; /* Espacement autour du titre */
        left: 10px; /* Décalage du titre */
        color: #00aaff; /* Titre en bleu vif */
        font-weight: bold;
    }

    /* 📑 Onglets (QTabWidget & QTabBar) */
    QTabWidget::pane {
        border: 1px solid #00aaff; /* Bordure bleu vif autour du contenu */
        border-top: none; /* Pas de bordure en haut (géré par l'onglet) */
        border-radius: 0 0 8px 8px; /* Coins arrondis en bas */
        background-color: #012c4a; /* Fond du contenu des onglets */
    }

    QTabBar::tab {
        background-color: #02456e; /* Fond onglet inactif (bleu foncé moyen) */
        color: #cceeff; /* Texte onglet inactif (bleu clair) */
        border: 1px solid #012c4a; /* Bordure discrète */
        border-bottom: none; /* Pas de bordure en bas */
        border-top-left-radius: 8px;
        border-top-right-radius: 8px;
        padding: 8px 18px; /* Espacement */
        margin-right: 3px; /* Espace entre les onglets */
        font-weight: bold;
    }

    QTabBar::tab:selected {
        background-color: #00aaff; /* Fond onglet actif (bleu vif) */
        color: white; /* Texte onglet actif */
        border-color: #00aaff; /* Bordure assortie */
    }

    QTabBar::tab:hover:!selected {
        background-color: #035f8a; /* Fond au survol (inactif) */
        color: white;
    }

    /* 📊 Tableaux (QTableView) */
    QTableView {
        background-color: #e6f2fa; /* Fond tableau (bleu très clair) */
        alternate-background-color: #dceffc; /* Fond alternatif (un peu plus foncé) */
        color: #012c4a; /* Texte du tableau (bleu foncé) */
        border: 1px solid #00aaff; /* Bordure bleu vif */
        gridline-color: #b3e5fc; /* Lignes de grille claires */
        outline: none; /* Pas de contour de focus */
        font-size: 12px; /* Taille police légèrement réduite pour table */
    }

    /* En-têtes de Tableau */
    QHeaderView::section {
        background-color: #00aaff; /* Fond en-tête (bleu vif) */
        color: white;
        padding: 6px;
        border: none; /* Pas de bordure entre les sections */
        border-right: 1px solid #012c4a; /* Ligne séparatrice discrète */
        font-weight: bold;
        font-size: 13px; /* Correspondance taille police */
    }

    QHeaderView::section:last {
         border-right: none; /* Pas de séparateur après la dernière colonne */
    }

    QTableView::item {
        padding: 4px; /* Espacement dans les cellules */
    }

    QTableView::item:selected {
        background-color: #00aaff; /* Fond cellule sélectionnée */
        color: white; /* Texte cellule sélectionnée */
    }

    /* 📝 Zone de Texte multiligne (QTextEdit) - Style de base */
    QTextEdit {
        background-color: #e6f2fa; /* Similaire à QLineEdit */
        color: #012c4a;
        border: 1px solid #02456e;
        border-radius: 8px;
        padding: 8px;
    }

    QTextEdit:focus {
        border: 1px solid #00aaff;
        background-color: #ffffff;
    }

    /* --- Styles spécifiques de votre UI (Adaptez si besoin) --- */
    /* Applique un style spécifique aux QTextEdit utilisés comme titres */
    QTextEdit#textEdit_7, QTextEdit#textEdit_6, QTextEdit#textEdit_5, QTextEdit#textEdit_9 {
        background-color: transparent; /* Fond transparent */
        color: #00aaff; /* Texte bleu vif */
        border: none; /* Pas de bordure */
        font-size: 16px; /* Taille plus grande */
        font-weight: bold;
        padding: 5px;
    }

)"; // Fin de la chaîne brute R"(...)"
    this->setStyleSheet(styles);
    // --- Fin de la feuille de style ---

    // --- Validateurs et ReadOnly (Vérifier les noms dans le .ui!) ---
    ui->lineEdit_3->setValidator(new QDoubleValidator(-273.15, 2000.0, 2, this));
    ui->lineEdit_4->setValidator(new QDoubleValidator(-273.15, 2000.0, 2, this));
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);

    // --- Initialisation ---
    refreshTableView();
    updateAlertsTab();

    // Rendre les champs de l'onglet Delete non éditables
    ui->lineR_4->setReadOnly(true);
    ui->lineP_4->setReadOnly(true);
    ui->lineN_4->setReadOnly(true);
    ui->lineQ_4->setReadOnly(true);
    ui->lineE_4->setReadOnly(true);

    // Initialisation du QLabel QR Code
    // Adaptez le chemin si vous avez une icône dans vos ressources (ex: ":/icons/qr_placeholder.png")
    // ui->qrCodeLabel_2->setPixmap(QPixmap(":/icons/qr_placeholder.png"));
    ui->qrCodeLabel_2->setAlignment(Qt::AlignCenter);
    ui->qrCodeLabel_2->setText(tr("Sélectionnez une ressource"));
    ui->qrCodeLabel_2->setStyleSheet("background-color: lightgray; border: 1px solid gray; padding: 5px;");
   //Arduino

        serial = new QSerialPort(this);
        serial->setPortName("COM3"); // ⚠️ Mets le bon port ici
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (!serial->open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, "Erreur Port Série", "Impossible d'ouvrir le port série !");
        }
        else{
            qDebug() << "Connexion Arduino réussie";
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- Fonctions Utilitaires ---

void MainWindow::refreshTableView() {
    QSqlQueryModel* model = R.afficher(); // Doit sélectionner TEMP_MIN/MAX
    if (model) {
        QAbstractItemModel* oldModel = ui->tableView_2->model();
        ui->tableView_2->setModel(model);
        if(oldModel && oldModel != model) { // S'assurer de ne pas supprimer le modèle actuel
             // Laisser Qt gérer la suppression via setModel OU gérer manuellement si nécessaire
             // en fonction de la propriété du modèle (parent). Pour être sûr :
             oldModel->deleteLater(); // Suppression sûre
        }
        ui->tableView_2->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de charger les données des ressources."));
        QAbstractItemModel* oldModel = ui->tableView_2->model();
        ui->tableView_2->setModel(nullptr);
        if(oldModel) oldModel->deleteLater();
    }
}

void MainWindow::clearInputFieldsCreate() {
    ui->lineR_6->clear();
    ui->lineP_6->clear();
    ui->lineN_6->clear();
    ui->lineQ_6->clear();
    ui->lineE_6->clear();
}

void MainWindow::clearInputFieldsUpdate() {
    ui->lineR_5->clear();
    ui->lineP_5->clear();
    ui->lineN_5->clear();
    ui->lineQ_5->clear();
    ui->lineE_5->clear();
    // Utiliser les noms corrects du .ui
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineR_5->setReadOnly(false); // Permettre la sélection d'une autre référence
}

void MainWindow::clearInputFieldsDelete() {
    ui->lineR_4->clear();
    ui->lineP_4->clear();
    ui->lineN_4->clear();
    ui->lineQ_4->clear();
    ui->lineE_4->clear();
}

void MainWindow::updateAlertsTab() {
    QSqlQueryModel *model = new QSqlQueryModel(this); // 'this' comme parent pour gestion mémoire auto
    const int SEUIL_ALERTE = 10; // Ou la valeur désirée
    QSqlQuery query;
    query.prepare("SELECT REFERENCE, NOM, QUANTITE FROM RESS WHERE QUANTITE < :seuil ORDER BY QUANTITE ASC, NOM ASC");
    query.bindValue(":seuil", SEUIL_ALERTE);

    if (!query.exec()) {
        qDebug() << "Erreur chargement alertes:" << query.lastError().text();
        model->clear();
    } else {
        model->setQuery(std::move(query));
    }

    // Utiliser les noms corrects du .ui pour l'onglet Alerte
    QAbstractItemModel* oldModel = ui->tableView->model(); // 'tableView'
    ui->tableView->setModel(model);
    if(oldModel && oldModel != model) oldModel->deleteLater();

    model->setHeaderData(0, Qt::Horizontal, tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, tr("QUANTITE (< %1)").arg(SEUIL_ALERTE));
    ui->tableView->resizeColumnsToContents();

    int alertCount = model->rowCount();
    bool alertsExist = (alertCount > 0);

    ui->textEdit_9->setVisible(alertsExist); // 'textEdit_9'

    int alertTabIndex = 5; // Index 5 correspond à tab_6
    ui->tabWidget->setTabEnabled(alertTabIndex, alertsExist); // 'tabWidget'
    QColor defaultTextColor = ui->tabWidget->tabBar()->palette().windowText().color();

    if (alertsExist) {
        ui->tabWidget->tabBar()->setTabText(alertTabIndex, tr("Alerte (%1)").arg(alertCount));
        ui->tabWidget->tabBar()->setTabTextColor(alertTabIndex, Qt::red);
        ui->statusbar->showMessage(tr("%1 ressource(s) avec quantité faible!").arg(alertCount), 0);
    } else {
        ui->tabWidget->tabBar()->setTabText(alertTabIndex, tr("Alerte"));
        ui->tabWidget->tabBar()->setTabTextColor(alertTabIndex, defaultTextColor);
        if (ui->statusbar->currentMessage().contains("quantité faible")) {
            ui->statusbar->clearMessage();
        }
    }
}


// === SLOTS DES BOUTONS ET ACTIONS ===

// --- Onglet CREATE ---
void MainWindow::on_pushButton_29_clicked() // Ajout
{
    QString reference = ui->lineR_6->text();
    QString prix = ui->lineP_6->text();
    QString nom = ui->lineN_6->text();
    QString quantite = ui->lineQ_6->text();
    QString etat = ui->lineE_6->text();

    if (reference.isEmpty() || nom.isEmpty() || prix.isEmpty() || quantite.isEmpty()) {
        QMessageBox::warning(this, tr("Champ manquant"), tr("Veuillez remplir Référence, Nom, Prix et Quantité."));
        return;
    }
    bool okPrix, okQuantite;
    prix.toDouble(&okPrix);
    quantite.toInt(&okQuantite);
    if (!okPrix || !okQuantite) {
        QMessageBox::warning(this, tr("Format invalide"), tr("Le prix et la quantité doivent être des nombres valides."));
        return;
    }

    Ressource nouvelleRessource(reference, prix, nom, quantite, etat, "", ""); // TEMP MIN/MAX initialisés à vide
    if (nouvelleRessource.ajouter()) { // La méthode ajouter N'insère PAS les températures
        refreshTableView();
        updateAlertsTab();
        QMessageBox::information(this, tr("Ajout réussi"), tr("La ressource a été ajoutée."));
        clearInputFieldsCreate();
        ui->tabWidget->setCurrentIndex(1); // Aller à l'onglet Read (Index 1)
    } else {
        // L'erreur est (ou devrait être) gérée dans Ressource::ajouter via QMessageBox
    }
}

// --- Onglet UPDATE ---
void MainWindow::on_pushButton_27_clicked() // Modification
{
    QString reference = ui->lineR_5->text();
    if (reference.isEmpty()) {
        QMessageBox::warning(this, tr("Sélection manquante"), tr("Veuillez sélectionner une ressource à modifier."));
        return;
    }
    QString prix = ui->lineP_5->text();
    QString nom = ui->lineN_5->text();
    QString quantite = ui->lineQ_5->text();
    QString etat = ui->lineE_5->text();
    // Utiliser les noms corrects du .ui
    QString tempMin = ui->lineEdit_3->text();
    QString tempMax = ui->lineEdit_4->text();

    if (nom.isEmpty() || prix.isEmpty() || quantite.isEmpty()) {
        QMessageBox::warning(this, tr("Champ manquant"), tr("Veuillez remplir Nom, Prix et Quantité."));
        return;
    }
    bool okMin=true, okMax=true;
    if (!tempMin.isEmpty()) tempMin.toDouble(&okMin);
    if (!tempMax.isEmpty()) tempMax.toDouble(&okMax);
    if (!okMin || !okMax) {
         QMessageBox::warning(this, tr("Température invalide"), tr("Veuillez entrer des nombres valides pour les températures ou laisser vide."));
         return;
    }
    if (!tempMin.isEmpty() && !tempMax.isEmpty() && okMin && okMax && tempMin.toDouble() > tempMax.toDouble()) {
         QMessageBox::warning(this, tr("Logique Température"), tr("La température minimale ne peut pas être supérieure à la température maximale."));
         return;
    }
    bool okPrix, okQuantite;
    prix.toDouble(&okPrix);
    quantite.toInt(&okQuantite);
    if (!okPrix || !okQuantite) {
        QMessageBox::warning(this, tr("Format invalide"), tr("Le prix et la quantité doivent être des nombres valides."));
        return;
    }

    Ressource ressourceAModifier(reference, prix, nom, quantite, etat, tempMin, tempMax); // Avec températures
    if (ressourceAModifier.modifier(reference)) { // La méthode modifier DOIT gérer les températures
        refreshTableView();
        updateAlertsTab();
        QMessageBox::information(this, tr("Modification réussie"), tr("La ressource a été modifiée."));
        clearInputFieldsUpdate();
        ui->tabWidget->setCurrentIndex(1); // Revenir à l'onglet Read
    } else {
         // L'erreur est (ou devrait être) gérée dans Ressource::modifier
    }
}

// --- Onglet DELETE ---
void MainWindow::on_pushButton_23_clicked() // Suppression
{
    QString referenceASupprimer = ui->lineR_4->text();
    if (referenceASupprimer.isEmpty()) {
        QMessageBox::warning(this, tr("Sélection manquante"), tr("Veuillez sélectionner une ressource à supprimer."));
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Confirmation"),
                                  tr("Supprimer la ressource '%1' ?").arg(referenceASupprimer),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (R.supprimer(referenceASupprimer)) {
            refreshTableView();
            updateAlertsTab();
            QMessageBox::information(this, tr("Suppression réussie"), tr("La ressource '%1' a été supprimée.").arg(referenceASupprimer));
            clearInputFieldsDelete();
            clearInputFieldsUpdate();
            // Vider les champs Temp dans Read (Utiliser les noms corrects du .ui)
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            // Vider QR Code (Utiliser nom correct du .ui)
            ui->qrCodeLabel_2->clear();
            ui->qrCodeLabel_2->setText(tr("Sélectionnez une ressource"));
            ui->qrCodeLabel_2->setStyleSheet("background-color: lightgray; border: 1px solid gray; padding: 5px;");
        } else {
            // L'erreur est (ou devrait être) gérée dans Ressource::supprimer
        }
    }
}

// --- Onglet READ - Sélection dans la table ---
// --- Onglet READ - Sélection dans la table ---
void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{
    if (!index.isValid()) return;

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView_2->model());
    if (!model) {
        qDebug() << "Modèle invalide dans on_tableView_2_activated";
        return;
    }
    QSqlRecord record = model->record(index.row()); // Obtenir l'enregistrement

    // Récupérer toutes les valeurs depuis l'enregistrement
    QString ref = record.value("REFERENCE").toString();
    QString prix = record.value("PRIX").toString();
    QString nom = record.value("NOM").toString();
    QString qte = record.value("QUANTITE").toString();
    QString etat = record.value("ETAT").toString();
    QString tempMin = record.value("TEMPERATUREMIN").toString();
    QString tempMax = record.value("TEMPERATUREMAX").toString();

    // Remplir Onglet Update (Utiliser les noms corrects du .ui : lineEdit_3, lineEdit_4)
    ui->lineR_5->setText(ref);
    ui->lineP_5->setText(prix);
    ui->lineN_5->setText(nom);
    ui->lineQ_5->setText(qte);
    ui->lineE_5->setText(etat);
    ui->lineEdit_3->setText(tempMin);
    ui->lineEdit_4->setText(tempMax);
    ui->lineR_5->setReadOnly(true);

    // Remplir Onglet Delete
    ui->lineR_4->setText(ref);
    ui->lineP_4->setText(prix);
    ui->lineN_4->setText(nom);
    ui->lineQ_4->setText(qte);
    ui->lineE_4->setText(etat);

    // Remplir les champs d'affichage Read (Utiliser les noms corrects du .ui : lineEdit, lineEdit_2)
    ui->lineEdit->setText(tempMin);
    ui->lineEdit_2->setText(tempMax);

    // --- Bloc de génération du QR Code utilisant qrcodegen ---
    // Ce bloc est correct MAIS il nécessite que la bibliothèque qrcodegen
    // soit correctement ajoutée à votre projet (.pro, fichiers .hpp/.cpp)
    // pour résoudre l'erreur "qrcodegen.hpp: No such file or directory".

    QString qrCodeData = QString("Ref: %1\nNom: %2\nPrix: %3\nQte: %4\nEtat: %5\nTempMin: %6\nTempMax: %7")
                             .arg(ref).arg(nom).arg(prix).arg(qte).arg(etat).arg(tempMin).arg(tempMax);

    using namespace qrcodegen; // Nécessaire si vous utilisez la bibliothèque qrcodegen
    try {
        // Utilisation de la classe QrCode de la bibliothèque qrcodegen
        QrCode qr = QrCode::encodeText(qrCodeData.toUtf8().constData(), QrCode::Ecc::MEDIUM);

        // Création de l'image
        qint32 sz = qr.getSize();
        QImage im(sz, sz, QImage::Format_RGB32);
        QRgb black = qRgb(0, 0, 0);
        QRgb white = qRgb(255, 255, 255);
        for (int y = 0; y < sz; y++) {
            for (int x = 0; x < sz; x++) {
                im.setPixel(x, y, qr.getModule(x, y) ? black : white);
            }
        }

        // Affichage dans le QLabel (Utiliser nom correct du .ui : qrCodeLabel_2)
        ui->qrCodeLabel_2->setPixmap(QPixmap::fromImage(im.scaled(ui->qrCodeLabel_2->size()*0.95, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
        ui->qrCodeLabel_2->setAlignment(Qt::AlignCenter);
        ui->qrCodeLabel_2->setStyleSheet("background-color: white; border: 1px solid black; padding: 2px;"); // Style normal

    } catch (const data_too_long &e) { // Erreur spécifique de qrcodegen si données trop longues
        qDebug() << "Erreur génération QR Code (données trop longues):" << e.what();
        ui->qrCodeLabel_2->clear(); ui->qrCodeLabel_2->setText(tr("Erreur: Données trop longues pour QR"));
        ui->qrCodeLabel_2->setStyleSheet("background-color: white; color: red; border: 1px solid red; padding: 5px; qproperty-alignment: 'AlignCenter';");
    } catch (const std::exception& e) { // Autres erreurs standard
        qDebug() << "Erreur génération QR Code:" << e.what();
        ui->qrCodeLabel_2->clear(); ui->qrCodeLabel_2->setText(tr("Erreur QR"));
        ui->qrCodeLabel_2->setStyleSheet("background-color: white; color: red; border: 1px solid red; padding: 5px; qproperty-alignment: 'AlignCenter';");
    } catch (...) { // Attrape tout le reste
        qDebug() << "Exception inconnue lors de la génération du QR Code.";
        ui->qrCodeLabel_2->clear(); ui->qrCodeLabel_2->setText(tr("Erreur QR Inconnue"));
        ui->qrCodeLabel_2->setStyleSheet("background-color: white; color: red; border: 1px solid red; padding: 5px; qproperty-alignment: 'AlignCenter';");
    }
    // --- Fin du bloc QR Code ---
}
// --- Onglet READ - Export PDF ---
void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"),
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/liste_ressources.pdf",
                                                    tr("Fichiers PDF (*.pdf)"));
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) fileName += ".pdf";

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15)); // Marges en mm
    printer.setPageSize(QPageSize(QPageSize::A4));

    QTextDocument doc;
    QString htmlContent;
    QTextStream out(&htmlContent);

    // --- Construction du HTML ---
    out << "<!DOCTYPE html><html><head><meta charset='utf-8'><title>Liste des Ressources</title><style>"
        << "body { font-family: 'Segoe UI', Arial, sans-serif; font-size: 10pt; }"
        << "h1 { color: #2c3e50; text-align: center; border-bottom: 2px solid #3498db; padding-bottom: 5px; }"
        << ".header-info { text-align: right; font-size: 9pt; color: #555; margin-bottom: 20px; }"
        << "table { border-collapse: collapse; width: 100%; margin-top: 15px; }"
        << "th, td { border: 1px solid #bdc3c7; padding: 8px; text-align: left; word-wrap: break-word; }" // word-wrap ajouté
        << "th { background-color: #3498db; color: white; font-weight: bold; text-align: center; }"
        << "tr:nth-child(even) { background-color: #ecf0f1; }"
        << ".footer { text-align: right; font-size: 8pt; color: #7f8c8d; margin-top: 20px; position: fixed; bottom: 0; right: 15mm; width: calc(100% - 30mm); }" // Pied de page fixe
        << "</style></head><body>";
    out << "<div class='header-info'>Date: " << QDate::currentDate().toString("dd/MM/yyyy") << "</div><div style='clear: both;'></div>";
    out << "<h1>Liste des Ressources</h1>";

    QAbstractItemModel *model = ui->tableView_2->model();
    if (!model || model->rowCount() == 0) {
        out << "<p>Aucune donnée à afficher.</p></body></html>";
        doc.setHtml(htmlContent);
        doc.print(&printer);
        QMessageBox::warning(this, tr("Export PDF"), tr("Aucune donnée dans la table à exporter."));
        return;
    }
    const int columnCount = model->columnCount();
    const int rowCount = model->rowCount();
    out << "<table><thead><tr>";
    for (int column = 0; column < columnCount; ++column) {
        if (!ui->tableView_2->isColumnHidden(column)) {
            out << "<th>" << model->headerData(column, Qt::Horizontal).toString().toHtmlEscaped() << "</th>"; // Échappement HTML
        }
    }
    out << "</tr></thead><tbody>";
    for (int row = 0; row < rowCount; ++row) {
        out << "<tr>";
        for (int column = 0; column < columnCount; ++column) {
            if (!ui->tableView_2->isColumnHidden(column)) {
                QString data = model->data(model->index(row, column)).toString().toHtmlEscaped(); // Échappement HTML
                out << "<td>" << (data.isEmpty() ? " " : data) << "</td>"; // Utiliser   pour vide
            }
        }
        out << "</tr>";
    }
    out << "</tbody></table>";
    // Le pied de page sera positionné par CSS
    out << "<div class='footer'>Document généré le " << QDate::currentDate().toString("dd/MM/yyyy") << " à " << QTime::currentTime().toString("hh:mm:ss") << "</div>";
    out << "</body></html>";

    doc.setHtml(htmlContent);
    // Utiliser la taille de page par défaut du document si QPageSize fonctionne
    doc.setPageSize(printer.pageRect(QPrinter::Point).size()); // Essayer avec QPrinter::Point
    doc.print(&printer);

    QMessageBox::information(this, tr("Export PDF"), tr("Le document a été exporté vers\n%1").arg(QDir::toNativeSeparators(fileName)));
}


// --- Onglet READ - Afficher Statistiques ---
void MainWindow::on_pushButton_26_clicked()
{
    R.afficherDiagramme_ressource_Stat(); // La logique est dans ressource.cpp
}

// --- Onglet READ - Recherche dynamique ---
void MainWindow::on_linerech_2_textChanged(const QString &arg1)
{
    QSqlQueryModel* model = nullptr; // Initialiser à nullptr
    if (arg1.isEmpty()) {
        model = R.afficher();
    } else {
        model = R.rechercherRessource(arg1); // Doit sélectionner toutes les colonnes
    }

    if (model) {
         QAbstractItemModel* oldModel = ui->tableView_2->model();
         ui->tableView_2->setModel(model);
         if(oldModel && oldModel != model) oldModel->deleteLater();
         ui->tableView_2->resizeColumnsToContents();
    } else {
         // Si la recherche retourne nullptr (erreur dans Ressource::rechercherRessource)
         QMessageBox::warning(this, tr("Recherche"), tr("Erreur lors de l'exécution de la recherche."));
         // Optionnel: Revenir à l'affichage complet
         QAbstractItemModel* oldModel = ui->tableView_2->model();
         ui->tableView_2->setModel(R.afficher());
         if(oldModel) oldModel->deleteLater();
         ui->tableView_2->resizeColumnsToContents();
    }
}

// --- Onglet READ - Tri ---
void MainWindow::on_pushButton_5_clicked()
{
    int index = ui->comboBox_2->currentIndex();
    QSqlQueryModel* model = nullptr;

    if (index == 0) { model = R.tri_par_prix(); } // Doit sélectionner toutes les colonnes
    else if (index == 1) { model = R.tri_par_quantite(); } // Doit sélectionner toutes les colonnes
    else { model = R.afficher(); } // Cas par défaut

    if (model) {
        QAbstractItemModel* oldModel = ui->tableView_2->model();
        ui->tableView_2->setModel(model);
        if(oldModel && oldModel != model) oldModel->deleteLater();
        ui->tableView_2->resizeColumnsToContents();
    } else {
        QMessageBox::warning(this, tr("Tri"), tr("Erreur lors du tri."));
        QAbstractItemModel* oldModel = ui->tableView_2->model();
        ui->tableView_2->setModel(R.afficher()); // Revenir à l'affichage complet
        if(oldModel) oldModel->deleteLater();
        ui->tableView_2->resizeColumnsToContents();
    }
}

//Arduino
void MainWindow::envoyerSeuilsAuto()
{
    float minVal = 0, maxVal = 0;

    // Étape 1 : Lire les seuils depuis la base de données (table SEUILS)
    QSqlQuery query;
    query.prepare("SELECT TEMPERATUREMIN, TEMPERATUREMAX FROM RESS WHERE ID_P = :id");
    query.bindValue(":id", 1); // Modifier ici si tu veux un autre ID_P que 1

    if (query.exec() && query.next()) {
        minVal = query.value(0).toFloat();
        maxVal = query.value(1).toFloat();
        qDebug() << "Seuils récupérés : Temp Min =" << minVal << ", Temp Max =" << maxVal;
    } else {
        QMessageBox::warning(this, "Erreur", "Impossible de lire les seuils depuis la base de données SEUILS.");
        return;
    }

    // Étape 2 : Vérifier que min < max
    if (minVal >= maxVal) {
        QMessageBox::warning(this, "Erreur", "Le seuil minimum doit être inférieur au seuil maximum.");
        return;
    }

    // Étape 3 : Envoyer vers Arduino
    if (serial && serial->isOpen()) {
        QString seuils = QString("%1,%2\n")
        .arg(minVal, 0, 'f', 1)  // Formate minVal avec 1 chiffre après la virgule
            .arg(maxVal, 0, 'f', 1); // Formate maxVal avec 1 chiffre après la virgule

        serial->write(seuils.toUtf8());  // Envoie la donnée à Arduino
        qDebug() << "Seuils envoyés à Arduino : " << seuils;

        QMessageBox::information(this, "Seuils envoyés", "Les seuils ont été envoyés à l'Arduino.");
    } else {
        QMessageBox::critical(this, "Erreur de connexion", "La connexion série n'est pas ouverte.");
    }
}
