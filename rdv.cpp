#include "rdv.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

RDV::RDV()
{

}

RDV::RDV(int ref,int id_c,QString dater,QString service)
{
  this->id_c=id_c;
  this->ref=ref;
  this->dater=dater;
  this->service=service;
}

bool RDV::ajouter()
{
QSqlQuery query;

QString res= QString::number(id_c);

query.prepare("INSERT INTO RDV (ref,id_c,dater,service) "
                    "VALUES (:ref,:id_c,:dater,:service)");

query.bindValue(":id_c",res);

query.bindValue(":ref",ref);
query.bindValue(":dater",dater);
query.bindValue(":service",service);
return    query.exec();
}

QSqlQueryModel * RDV::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from RDV");

return model;
}

bool RDV::supprimer(int ref)
{
    QSqlQuery query;


    QString res= QString::number(ref);

    query.prepare("Delete from RDV where ref= :ref");
    query.bindValue(":ref", res);
    return    query.exec();
}

QSqlQueryModel * RDV::afficherRech(QString critere,QString rech)
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from rdv where "+critere+" like '"+rech+"%'");

return model;
}


bool RDV::modifier(int ref,int id_c,QString dater,QString service)
{ QSqlQuery query;
    QString res1= QString::number(id_c);
    QString res2= QString::number(ref);

    query.prepare("update RDV set id_c=:id_c,dater=:dater,service=:service where ref=:ref");
    query.bindValue(":ref",res2);
    query.bindValue(":id_c",res1);
    query.bindValue(":dater",dater);
    query.bindValue(":service",service);

    return    query.exec();

}
