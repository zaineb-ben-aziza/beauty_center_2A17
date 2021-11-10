#include "service.h"

service::service()
{
id = 0;
nom="";
prix=0;
}

service::service(int ID,QString NOM,int PRIX)
{
    id=ID;
    nom=NOM;
    prix=PRIX;
}




bool service::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO GS_SERVICES (NOM_DE_SERVICE,ID_SERVICE,PRIX_SERVICE) "
                        "VALUES (:noms,:ids,:prixs)");
    query.bindValue(":noms", nom);
    query.bindValue(":ids", id);
    query.bindValue(":prixs", prix);


    return    query.exec();
}


bool service::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from GS_SERVICES where ID_SERVICE = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}


bool service::modifier()
{
    QSqlQuery query;
     query.prepare( "UPDATE GS_SERVICES SET NOM_DE_SERVICE=:noms,PRIX_SERVICE=:prixs WHERE ID_SERVICE = :ids;");
     query.bindValue(":noms", nom);
     query.bindValue(":ids", id);
     query.bindValue(":prixs", prix);



  return query.exec();
}


QSqlQueryModel * service::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from GS_SERVICES");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom service"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id service"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix service"));


    return model;
}


