// ressource.cpp

#include "ressource.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox> // Pour afficher les erreurs ou infos

// Constructeur par défaut
Ressource::Ressource() : REFERENCE(""), PRIX(""), NOM(""), QUANTITE(""), ETAT(""), TEMPERATUREMIN(""), TEMPERATUREMAX("") {} // Initialiser les nouveaux champs

// Constructeur paramétré mis à jour
Ressource::Ressource(QString reference, QString prix, QString nom, QString quantite, QString etat, QString tempMin, QString tempMax) {
    this->REFERENCE = reference;
    this->PRIX = prix;
    this->NOM = nom;
    this->QUANTITE = quantite;
    this->ETAT = etat;
    this->TEMPERATUREMIN = tempMin; // Initialiser
    this->TEMPERATUREMAX = tempMax; // Initialiser
}

// Getters
QString Ressource::getREFERENCE() const { return REFERENCE; }
QString Ressource::getPRIX() const { return PRIX; }
QString Ressource::getNOM() const { return NOM; }
QString Ressource::getQUANTITE() const { return QUANTITE; }
QString Ressource::getETAT() const { return ETAT; }
QString Ressource::getTEMPERATUREMIN() const { return TEMPERATUREMIN; } // Implémentation
QString Ressource::getTEMPERATUREMAX() const { return TEMPERATUREMAX; } // Implémentation

// Setters
void Ressource::setREFERENCE(QString reference) { this->REFERENCE = reference; }
void Ressource::setPRIX(QString prix) { this->PRIX = prix; }
void Ressource::setNOM(QString nom) { this->NOM = nom; }
void Ressource::setQUANTITE(QString quantite) { this->QUANTITE = quantite; }
void Ressource::setETAT(QString etat) { this->ETAT = etat; }
void Ressource::setTEMPERATUREMIN(QString tempMin) { this->TEMPERATUREMIN = tempMin; } // Implémentation
void Ressource::setTEMPERATUREMAX(QString tempMax) { this->TEMPERATUREMAX = tempMax; } // Implémentation


// Ajouter une ressource (NON MODIFIÉ pour la température, comme demandé)
bool Ressource::ajouter()
{
    QSqlQuery query;
    // La requête n'inclut PAS TEMPERATUREMIN et TEMPERATUREMAX
    query.prepare("INSERT INTO RESS (REFERENCE, PRIX, NOM, QUANTITE, ETAT) "
                  "VALUES (:reference, :prix, :nom, :quantite, :etat)");

    query.bindValue(":reference", REFERENCE);
    query.bindValue(":prix", PRIX); // Assurez-vous que PRIX est un nombre valide ou gérez la conversion
    query.bindValue(":nom", NOM);
    query.bindValue(":quantite", QUANTITE); // Idem pour QUANTITE
    query.bindValue(":etat", ETAT);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de la ressource:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur Ajout", "Impossible d'ajouter la ressource : " + query.lastError().text());
        return false;
    }

    return true;
}

// Afficher les ressources (MODIFIÉ)
QSqlQueryModel* Ressource::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlDatabase db = QSqlDatabase::database("my_connection"); // Vérifie si tu utilises une connexion nommée
    if (!db.isValid()) {
        db = QSqlDatabase::database(); // Connexion par défaut
    }
    QSqlQuery query(db);
    // Sélectionner les nouvelles colonnes
    query.prepare("SELECT REFERENCE, PRIX, NOM, QUANTITE, ETAT, TEMPERATUREMIN, TEMPERATUREMAX FROM RESS");

    if(!query.exec()){
        qDebug() << "Erreur d'exécution requête afficher:" << query.lastError();
        QMessageBox::critical(nullptr, "Erreur Affichage", "Impossible d'afficher les ressources : " + query.lastError().text());
        delete model;
        return nullptr;
    }

    model->setQuery(std::move(query));

    // Mettre à jour les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEMP. MIN")); // Nouvel en-tête
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEMP. MAX")); // Nouvel en-tête

    return model;
}

// Modifier une ressource (MODIFIÉ)
bool Ressource::modifier(QString reference) // La référence de la ligne à modifier
{
    QSqlQuery query;
    // Ajouter les champs de température à la requête UPDATE
    query.prepare("UPDATE RESS SET PRIX = :prix, NOM = :nom, QUANTITE = :quantite, ETAT = :etat, "
                  "TEMPERATUREMIN = :tempmin, TEMPERATUREMAX = :tempmax "
                  "WHERE REFERENCE = :reference");

    // Binder toutes les valeurs, y compris les températures
    query.bindValue(":prix", PRIX); // Assurer conversion si nécessaire
    query.bindValue(":nom", NOM);
    query.bindValue(":quantite", QUANTITE); // Assurer conversion si nécessaire
    query.bindValue(":etat", ETAT);
    query.bindValue(":tempmin", TEMPERATUREMIN); // Binder la nouvelle valeur
    query.bindValue(":tempmax", TEMPERATUREMAX); // Binder la nouvelle valeur
    query.bindValue(":reference", reference);    // La clé primaire pour le WHERE

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la ressource:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur Modification", "Impossible de modifier la ressource : " + query.lastError().text());
        return false;
    }

    // Vérifier si au moins une ligne a été affectée
    if (query.numRowsAffected() > 0) {
        return true;
    } else {
        qDebug() << "Aucune ressource trouvée avec la référence" << reference << "pour la modification.";
        // Optionnel: Afficher un message si aucune ligne n'a été modifiée
        // QMessageBox::information(nullptr, "Modification", "Aucune ressource correspondante trouvée pour la modification.");
        return false; // Ou true si ne pas trouver n'est pas une erreur en soi
    }
}

// Supprimer une ressource (NON MODIFIÉ)
bool Ressource::supprimer(QString reference)
{
    QSqlQuery query;
    query.prepare("DELETE FROM RESS WHERE REFERENCE = :reference");
    query.bindValue(":reference", reference);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de la ressource:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur Suppression", "Impossible de supprimer la ressource : " + query.lastError().text());
        return false;
    }
    // Vérifier si au moins une ligne a été affectée
    if (query.numRowsAffected() > 0) {
        return true;
    } else {
        qDebug() << "Aucune ressource trouvée avec la référence" << reference << "pour la suppression.";
        // Optionnel: Afficher un message si aucune ligne n'a été supprimée
        // QMessageBox::warning(nullptr, "Suppression", "Aucune ressource correspondante trouvée pour la suppression.");
        return false; // Indique qu'aucune ligne n'a été supprimée
    }
}


// --- Diagramme Circulaire --- (NON MODIFIÉ - basé sur ETAT)
QChartView* Ressource::DiagrammeCirculaire() {
    QSqlDatabase db = QSqlDatabase::database("my_connection");
    if (!db.isValid()) {
        db = QSqlDatabase::database();
    }
    QSqlQuery query(db);
    QPieSeries *series = new QPieSeries();

    query.prepare("SELECT ETAT, COUNT(*) AS count FROM RESS GROUP BY ETAT");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête pour le diagramme : " << query.lastError();
        delete series;
        return nullptr;
    }

    while (query.next()) {
        QString etat = query.value(0).toString();
        int count = query.value(1).toInt();
        if (count > 0) {
            series->append(etat.isEmpty() ? QObject::tr("Non défini") : etat, count);
        }
    }

    if (series->isEmpty()) {
        qDebug() << "Aucune donnée pour générer le diagramme circulaire.";
        delete series;
        QChart *emptyChart = new QChart();
        emptyChart->setTitle(QObject::tr("Aucune donnée de ressource par état disponible"));
        QChartView *emptyChartView = new QChartView(emptyChart);
        emptyChartView->setRenderHint(QPainter::Antialiasing);
        return emptyChartView; // Retourne un graphique vide plutôt que nullptr
    }


    QList<QColor> couleurs = { /* ... couleurs ... */ };
    int couleurIndex = 0;
    for (QPieSlice *slice : series->slices()) {
        QColor couleur = couleurs[couleurIndex % couleurs.size()];
        couleurIndex++;
        slice->setBrush(couleur);
        slice->setLabel(slice->label() + " (" + QString::number(slice->percentage() * 100, 'f', 1) + "%)");
        slice->setLabelVisible(true);

        QObject::connect(slice, &QPieSlice::hovered, [slice](bool state) {
            slice->setExploded(state);
        });
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QObject::tr("Répartition des ressources par état"));
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}

// --- Afficher Fenêtre Statistiques --- (NON MODIFIÉ)
void Ressource::afficherDiagramme_ressource_Stat() {
    QChartView* chartView = DiagrammeCirculaire();
    if (chartView) {
        // Vérifier si le graphique retourné est le graphique "vide"
        if (chartView->chart()->series().isEmpty()) {
            QMessageBox::information(nullptr, QObject::tr("Statistiques"), QObject::tr("Aucune donnée disponible pour afficher les statistiques."));
            delete chartView; // Nettoyer le graphique vide
            return;
        }

        QMainWindow *window = new QMainWindow();
        window->setCentralWidget(chartView);
        window->resize(800, 600);
        window->setAttribute(Qt::WA_DeleteOnClose);
        window->setWindowTitle(QObject::tr("Statistiques des Ressources par État"));
        window->show();
    } else {
        qDebug() << "Erreur lors de la création du diagramme.";
        QMessageBox::critical(nullptr, QObject::tr("Erreur Statistiques"), QObject::tr("Impossible de générer le diagramme."));
    }
}


// --- Recherche --- (NON MODIFIÉ pour la température - peut être ajouté si besoin)
QSqlQueryModel *Ressource::rechercherRessource(QString recherche) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    // La requête sélectionne les nouvelles colonnes pour que le modèle soit cohérent
    query.prepare("SELECT REFERENCE, PRIX, NOM, QUANTITE, ETAT, TEMPERATUREMIN, TEMPERATUREMAX FROM RESS "
                  "WHERE UPPER(NOM) LIKE UPPER(:recherche) "
                  "OR UPPER(ETAT) LIKE UPPER(:recherche) "
                  "OR UPPER(REFERENCE) LIKE UPPER(:recherche)");
    query.bindValue(":recherche", "%" + recherche.toUpper() + "%"); // Utiliser toUpper() pour la recherche insensible à la casse

    if (!query.exec()) {
        qDebug() << "Erreur recherche ressource:" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(std::move(query));

    // Mettre à jour les en-têtes (important car le nombre de colonnes a changé)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEMP. MIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEMP. MAX"));

    return model;
}

// --- Tri --- (NON MODIFIÉ pour la température - peut être ajouté si besoin)
QSqlQueryModel *Ressource::tri_par_quantite() {
    QSqlQueryModel *model = new QSqlQueryModel();
    // Inclure les nouvelles colonnes dans le SELECT
    model->setQuery("SELECT REFERENCE, PRIX, NOM, QUANTITE, ETAT, TEMPERATUREMIN, TEMPERATUREMAX FROM RESS ORDER BY QUANTITE DESC"); // Adaptez avec CAST si QUANTITE est VARCHAR
    if (model->lastError().isValid()) {
        qDebug() << "Erreur tri par quantité:" << model->lastError();
    }
    // Mettre à jour les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEMP. MIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEMP. MAX"));
    return model;
}

QSqlQueryModel *Ressource::tri_par_prix() {
    QSqlQueryModel *model = new QSqlQueryModel();
    // Inclure les nouvelles colonnes dans le SELECT
    model->setQuery("SELECT REFERENCE, PRIX, NOM, QUANTITE, ETAT, TEMPERATUREMIN, TEMPERATUREMAX FROM RESS ORDER BY PRIX DESC"); // Adaptez avec CAST si PRIX est VARCHAR
    if (model->lastError().isValid()) {
        qDebug() << "Erreur tri par prix:" << model->lastError();
    }
    // Mettre à jour les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TEMP. MIN"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEMP. MAX"));
    return model;
}
