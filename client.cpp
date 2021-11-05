#include "client.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

client::client()
{
id_c=0;
cin_c=0;
nom_c="";
prenom_c="";
tel_c=0;
adresse_c="";
}

client::client(int id_c,int cin_c,QString nom_c,QString prenom_c,int tel_c,QString adresse_c)
{
  this->id_c=id_c;
  this->cin_c=cin_c;
  this->nom_c=nom_c;
  this->prenom_c=prenom_c;
  this->tel_c=tel_c;
  this->adresse_c=adresse_c;
}

int client::get_id_c(){return id_c;}
int client::get_cin_c(){return  cin_c;}
QString client::get_nom_c(){return nom_c;}
QString client::get_prenom_c(){return prenom_c ;}
int client::get_tel_c(){return tel_c;}
QString client::get_adresse_c(){return adresse_c;}



bool client::ajouter()
{
QSqlQuery query;

QString res= QString::number(id_c);

query.prepare("INSERT INTO client (id_c,cin_c,nom_c,prenom_c,tel_c,adresse_c) "
                    "VALUES (:id_c,:cin_c,:nom_c,:prenom_c,:tel_c,:adresse_c)");

query.bindValue(":id_c",res);

query.bindValue(":cin_c",cin_c);
query.bindValue(":nom_c",nom_c);
query.bindValue(":prenom_c",prenom_c);
query.bindValue(":tel_c",tel_c);
query.bindValue(":adresse_c",adresse_c);



return    query.exec();
}

QSqlQueryModel * client::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMERO TEL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));

return model;
}

bool client::supprimer(int id_c)
{
    QSqlQuery query;


    QString res= QString::number(id_c);

    query.prepare("Delete from client where id_c= :id_c");
    query.bindValue(":id_c", res);
    return    query.exec();
}




bool client::modifier(int id_c,int cin_c,QString nom_c,QString prenom_c,int tel_c,QString adresse_c)
{ QSqlQuery query;
    QString res1= QString::number(id_c);
    QString res2= QString::number(cin_c);
    QString res3=QString::number(tel_c);

    query.prepare("update client set id_c=:id_c,cin_c=:cin_c,nom_c=:nom_c,prenom_c=:prenom_c,tel_c=:tel_c,adresse_c=:adresse_c where id_c=:id_c");
    query.bindValue(":id_c",res1);
    query.bindValue(":cin_c",res2);
    query.bindValue(":nom_c",nom_c);
    query.bindValue(":prenom_c",prenom_c);
    query.bindValue(":tel_c", res3);
    query.bindValue(":adresse_c",adresse_c);

    return    query.exec();

}
