#include "fournisseur.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>


fournisseur::fournisseur()
{

}

fournisseur::fournisseur(int id_fr, int id_produit,QString nom_fr, int num_tel)
{
    this->id_fr = id_fr;
    this->id_produit = id_produit;
    this->nom_fr = nom_fr;
    this->num_tel = num_tel;

}

fournisseur::fournisseur(int id_fr, int num_tel,QString nom_fr)
{
    this->id_fr = id_fr;
    this->nom_fr = nom_fr;
    this->num_tel = num_tel;

}

int fournisseur::getId_fr(){return id_fr;}
int fournisseur::getId_produit(){return id_produit;}
QString fournisseur::getNom_fr(){return nom_fr;}
int fournisseur::getNum_tel(){return num_tel;}

void fournisseur::setId_fr(int id_fr){this->id_fr = id_fr;}
void fournisseur::setId_produit(int id_produit){this->id_produit = id_produit;}
void fournisseur::setNom_fr (QString nom_fr){this->nom_fr = nom_fr;}
void fournisseur::setNum_tel(int  num_tel){this-> num_tel =  num_tel;}

bool fournisseur::ajouter()
{
    QSqlQuery query;
    QString id_frr = QString::number(id_fr);
     QString num_tele = QString::number(num_tel);
          query.prepare("INSERT INTO GC_FOURNISSEURS ( id_fr, nom_fr, num_tel) "
                        "VALUES ( :id_fr, :nom_fr, :num_tel)");


          query.bindValue(":id_fr", id_frr);
          query.bindValue(":nom_fr", nom_fr);
          query.bindValue(":num_tel", num_tele);



    return query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * from GC_FOURNISSEURS ");

          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_fr"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_fr"));

          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num_tel"));

    return model;
}







bool fournisseur::suprimmer(int id_fr)
{
    QSqlQuery query;
          query.prepare("DELETE FROM GC_FOURNISSEURS where id_fr =: id_frr");
          query.bindValue(0, id_fr);

    return query.exec();
}

bool fournisseur::modifier()

{

         QSqlQuery query;

         query.prepare("UPDATE GC_FOURNISSEUR set id_produit=:id_produit,nom_fr=:nom_fr,num_tel=:num_tel, where id_fr=:id_fr");

         query.bindValue(":id_produit", id_produit);

         query.bindValue(":id_fr",id_fr);

         query.bindValue(":nom_fr", nom_fr);

         query.bindValue(":num_tel", num_tel);



         return query.exec();



}


