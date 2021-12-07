#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QSqlQuery>
#include <QString>
#include <QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QTableView>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int, int, QString, int);
    fournisseur(int,int,QString);
     //GETTERS
     int getId_fr();
     int getId_produit();
     QString getNom_fr();
     int getNum_tel();

     //SETTERS
     void setId_fr(int);
     void setId_produit(int);//changer les noms
     void setNom_fr(QString);
     void setNum_tel(int);

     //functions
     bool ajouter();
     QSqlQueryModel * afficher();
     bool suprimmer(int id_produit);
     bool modifier();
private:
    int id_fr, id_produit, num_tel;
    QString nom_fr;
};

#endif // FOURNISSEUR_H
