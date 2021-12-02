#include "cheque.h"
#include <QSqlQueryModel>
#include "connection.h"

cheque::cheque()
{
    numcheque=0;

}
cheque::cheque(int numcheque,int cin,QString statut,QString montant)
{
    this->numcheque=numcheque;
    this->cinclient=cin;
    this->statutcheque=statut;
    this->montantcheque=montant;
}
bool cheque::ajouter()
{

QString res=QString::number(numcheque);
QString ci=QString::number(cinclient);

QSqlQuery query;
query.prepare("INSERT INTO cheque (num_cheque,cin_client,statut_cheque,montant_cheque) values (:numcheque,:cinclient,:statutcheque,:montantcheque)");
query.bindValue(":num_cheque",res);
query.bindValue("cin_client",ci);
query.bindValue(":statut_cheque",statutcheque);
query.bindValue(":montant_cheque",montantcheque);

return query.exec();
}


QSqlQueryModel *cheque::afficher()
{
QSqlQuery query;
QSqlQueryModel *model=new QSqlQueryModel();
query.prepare(QString("Select * from cheque"));
query.exec();
model->setQuery(query);

return model;
}
bool cheque::supprimer()
{
    QString s= QString::number(numcheque);
    QSqlQuery query;
    query.prepare(QString("DELETE from cheque where num_cheque=:numcheque"));
    query.bindValue(":numcheque",s);
   return query.exec();
}
void cheque::setnum_cheque(int x)
{

    numcheque=x;
}
void cheque::modifier()
{
    QSqlQuery query;
    QString s= QString::number(numcheque);
    query.prepare(QString("update cheque set statut_cheque=:STATUT_CHEQUE, where num_cheque=:numcheque"));
    query.bindValue(":STATUT_CHEQUE",statutcheque);
    query.bindValue(":numcheque",s);

    query.exec();
}

