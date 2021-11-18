#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>


Produit::Produit()
{

}

Produit::Produit(int id_produit, QString nom_produit, QString date_exp, QString type_produit, int nombre_produit)
{
    this->id_produit = id_produit;
    this->nom_produit = nom_produit;
    this->date_exp = date_exp;
    this->type_produit = type_produit;
    this->nombre_produit = nombre_produit;
}

int Produit::getId_produit(){return id_produit;}
QString Produit::getNom_produit(){return nom_produit;}
QString Produit::getDate_exp(){return date_exp;}
QString Produit::getType_produit(){return type_produit;}
int Produit::getNombre_produit(){return nombre_produit;}


void Produit::setId_produit(int id_produit){this->id_produit = id_produit;}
void Produit::setNom_produit(QString nom_produit){this->nom_produit = nom_produit;}
void Produit::setDate_exp(QString date_exp){this->date_exp = date_exp;}
void Produit::setType_produit(QString type_produit){this->type_produit = type_produit;}
void Produit::setNombre_produit(int  nombre_produit){this-> nombre_produit =  nombre_produit;}

bool Produit::ajouter()
{
    QSqlQuery query;
    QString id_prod = QString::number(id_produit);
    QString nomb = QString::number(nombre_produit);
          query.prepare("INSERT INTO GC_PRODUIT (id_produit, nom_produit, date_exp, type_produit, nombre_produit) "
                        "VALUES (:id_produit, :nom_produit, TO_DATE(:date_exp, 'DD/MM/YYYY'), :type_produit, :nombre_produit)");

          query.bindValue(":id_produit", id_prod);
          query.bindValue(":date_exp", date_exp);
          query.bindValue(":nom_produit", nom_produit);
          query.bindValue(":nombre_produit", nomb);
          query.bindValue(":type_produit", type_produit);


    return query.exec();
}

QSqlQueryModel * Produit::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * from GC_PRODUIT ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_produit"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_exp"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre_produit"));

    return model;
}



QSqlQueryModel * Produit::affichere()
{


    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * from GC_PRODUIT where nombre_produit < 10 ");



          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_produit"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_exp"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre_produit"));







    return model;
}



bool Produit::suprimmer(int id_produit)
{
    QSqlQuery query;
          query.prepare("DELETE FROM GC_PRODUIT where id_produit =: id_prod");
          query.bindValue(0, id_produit);

    return query.exec();
}

bool Produit::modifier()

{

         QSqlQuery query;

         query.prepare("UPDATE GC_PRODUIT set nom_produit=:nom_produit,date_exp= TO_DATE(:date_exp, 'DD/MM/YYYY'),type_produit=:type_produit,nombre_produit=:nombre_produit where id_produit=:id_produit");

         query.bindValue(":id_produit", id_produit);

         query.bindValue(":nom_produit",nom_produit);

         query.bindValue(":date_exp", date_exp);

         query.bindValue(":type_produit", type_produit);

         query.bindValue(":nombre_produit", nombre_produit);

         return query.exec();



}

QSqlQueryModel* Produit::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from GC_PRODUIT ORDER BY Id_produit asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_produit"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_exp"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre_produit"));


    return model;
}

QSqlQueryModel* Produit::trie2(){
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from GC_PRODUIT ORDER BY Id_produit desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_produit"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_exp"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre_produit"));
    return model;
}


QSqlQueryModel * Produit::chercher_pr(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from GC_PRODUIT where ((Id_produit ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_exp"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre_produit"));
    return model;
}


QSqlQueryModel * Produit::chercher_emp1(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from GC_PRODUIT where ((Nombre_produit ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_exp"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre_produit"));

    return model;
}

QSqlQueryModel * Produit::chercher_emp2(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from GC_PRODUIT where ((Nom_produit ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_exp"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type_produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre_produit"));
    return model;
}


