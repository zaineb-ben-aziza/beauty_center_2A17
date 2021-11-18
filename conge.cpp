#include "conge.h"
#include<QSqlQuery>
#include <QSqlQueryModel>
#include<QtDebug>
#include<QObject>
conge::conge()
{
   cin_c=0 ;
   id_c=0;
   date=" "; duree=" ";etat="" ;

}
conge::conge(int id_l,int cin_l,QString date_l,QString duree_l,QString etat_l)
{
    cin_c=cin_l;
   date=date_l;
    id_c=id_l;
    duree=duree_l;
    etat=etat_l;

}

int conge :: getcin_c()
{return cin_c;}
int conge :: getid_c()
{return id_c;}
QString conge :: getdate()
{return date;}
QString conge ::getduree()
{return duree;}
QString conge ::getetat()
{return etat;}

void conge :: setcin_c(int cin_c)
{this->cin_c=cin_c;}
void conge :: setid_c(int id_c)
{this->id_c=id_c;}
void conge :: setdate(QString date)
{this->date=date;}
void conge :: setduree(QString duree)
{this->duree=duree;}
void conge :: setetat(QString etat)
{this->etat=etat;}


bool conge ::ajouter_c()
{

    QSqlQuery query;

          query.prepare("SELECT * from GS_CONGE where (ID_EMPLOYE=:id_c)");

          query.bindValue(":ID_EMPLOYE",id_c);

         query.exec();
         int existe=0;
         while (query.next()) {
             existe=1;
             return 0;
         }
         if(existe==0)
         {
             QSqlQuery query;
             QString cin_c_string=QString::number(cin_c);
             QString id_c_string=QString::number(id_c);
             query.prepare("INSERT INTO GS_CONGE (ID_C, CIN_C,DATE_CONGE,DUREE,ETAT)"
                           "VALUES (:ID_C,:CIN_C,:DATE_CONGE,:DUREE,:ETAT)");
          query.bindValue(0, id_c_string);
          query.bindValue(1, cin_c_string);
          query.bindValue(2, date);
          query.bindValue(3, duree);
          query.bindValue(4, etat);
    return query.exec();

     }
         return 1 ;
  }

QSqlQueryModel* conge :: afficher_c()
{

  QSqlQueryModel *model=new QSqlQueryModel();



   model->setQuery(QString("Select * from GS_CONGE"));
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("  ID_C    "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("  CIN_C    "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("  DATE_CONGE "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("  DUREE    "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("   ETAT  "));




    return model;
}
bool conge::modifier_c()
{

QSqlQuery query;


query.prepare("Update GS_CONGE set ID_C=:id_c , CIN_C=:cin_c , DATE_CONGE=:date ,DUREE=:duree ,  ETAT=:etat where ID_C=:id_c ");

query.bindValue(":id_c", id_c);
query.bindValue(":cin_c", cin_c);
query.bindValue(":date",date);
query.bindValue(":duree", duree);
query.bindValue(":etat",etat);
return    query.exec();
}
bool conge::supprimer_c(int cinn)
{ QSqlQuery query;
    QString s = QString::number(cinn);
          query.prepare("Delete from GS_CONGE where ID_C=:id_c");
          query.bindValue(0,s);

    return query.exec();


}
