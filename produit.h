#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlQuery>
#include <QString>
#include <QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QTableView>
class Produit
{
public:
    Produit();
   Produit(int, QString, QString, QString, int);

    //GETTERS
    int getId_produit();
    QString getNom_produit();
    QString getDate_exp();
    QString getType_produit();
    int getNombre_produit();

    //SETTERS
    void setId_produit(int); //changer les noms
    void setNom_produit(QString);
    void setDate_exp(QString);
    void setType_produit(QString);
    void setNombre_produit(int);

    //functions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool suprimmer(int id_produit);
    bool modifier();
private:
    int id_produit, nombre_produit;
    QString nom_produit, date_exp, type_produit;
};

#endif // PRODUIT_H
