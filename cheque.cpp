#include "cheque.h"
#include <QSqlQueryModel>
#include "connection.h"
#include <QDebug>

cheque::cheque()
{
    num_cheque=0;
    montant_cheque=0;

}
cheque::cheque(int num_cheque,int cin_client,QString statut_cheque,int montant_cheque)
{
    this->num_cheque=num_cheque;
    this->cin_client=cin_client;
    this->statut_cheque=statut_cheque;
    this->montant_cheque=montant_cheque;
}
bool cheque::ajouter()
{

    QSqlQuery query(QSqlDatabase::database("projet2a"));
    query.prepare("insert into cheque (NUM_CHEQUE,CIN_CLIENT,STATUT_CHEQUE,MONTANT_CHEQUE) values (:NUM_PAIEMENT,:CIN_CLIENT,:STATUT_CHEQUE,:MONTANT_CHEQUE)");
    query.bindValue(":NUM_PAIEMENT",num_cheque);
    query.bindValue(":CIN_CLIENT",cin_client);
    query.bindValue(":STATUT_CHEQUE",statut_cheque);
    query.bindValue(":MONTANT_CHEQUE",montant_cheque);
    qDebug()<<num_cheque;


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
    QString s= QString::number(num_cheque);
    QSqlQuery query;
    query.prepare(QString("DELETE from cheque where num_cheque=:id"));
    query.bindValue(":id",s);
   return query.exec();
}
void cheque::setNum_cheque(int x)
{

    num_cheque=x;
}
void cheque::modifier()
{

    QSqlQuery query;
    QString s= QString::number(num_cheque);
    query.prepare(QString("update cheque set statut_cheque=:statut_cheque where num_cheque=:NUM_CHEQUE"));
    query.bindValue(":statut",statut_cheque);
    query.bindValue(":NUM_PAIEMENT",s);

    query.exec();



}

