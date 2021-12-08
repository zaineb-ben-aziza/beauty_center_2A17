#include "employes.h"
#include<QSqlQuery>
#include <QSqlQueryModel>
#include<QtDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QDateTime>
Employes::Employes()
{
   cin=0 ;
   nom=" "; prenom=" "; date_de_naissance=" ";numero_tel=" ";service=" ";
    adresse=" ";

}
Employes::Employes(int cin_1 , QString nom_1, QString prenom_1,QString date_de_naissance_1,QString numero_tel_1,QString service_1,QString adresse_1)
{
    cin=cin_1;
    nom=nom_1;
    prenom=prenom_1;
    date_de_naissance=date_de_naissance_1;
    numero_tel=numero_tel_1;
    service=service_1;
    adresse=adresse_1;

}

int Employes :: getcin()
{return cin;}
QString Employes :: getnom()
{return nom;}
QString Employes ::getprenom()
{return prenom;}
QString Employes ::getdate_de_naissance()
{return date_de_naissance;}
QString Employes ::getnumero_tel()
{return numero_tel;}
QString Employes ::getservice()
{return service;}
QString Employes ::getadresse()
{return adresse;}
void Employes :: setcin(int cin)
{this->cin=cin;}
void Employes :: setnom(QString nom)
{this->nom=nom;}
void Employes :: setprenom(QString prenom)
{this->prenom=prenom;}
void Employes :: setdate_de_naissance(QString date_de_naissance)
{this->date_de_naissance=date_de_naissance;}
void Employes :: setnumero_tel(QString numero_tel)
{this->numero_tel=numero_tel;}
void Employes :: setservice(QString service)
{this->service=service;}
void Employes :: setadresse(QString adresse)
{this->adresse=adresse;}

bool Employes ::ajouter()
{

    QSqlQuery query;

          query.prepare("SELECT * from GS_EMPLOYE where (CIN=:cin)");

          query.bindValue(":cin",cin);

         query.exec();
         int existe=0;
         while (query.next()) {
             existe=1;
             return 0;
         }
         if(existe==0)
         {
             QSqlQuery query;
             QString cin_string=QString::number(cin);
             query.prepare("INSERT INTO GS_EMPLOYE (CIN, NOM, PRENOM,DATE_DE_NAISSANCE, NUMERO_DE_TELEPHONE, SERVICE,ADRESSE)"
                           "VALUES (:CIN,:NOM,:PRENOM,:DATE_DE_NAISSANCE,:NUMERO_DE_TELEPHONE,:SERVICE,:ADRESSE)");
          query.bindValue(0, cin_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, date_de_naissance);
          query.bindValue(4, numero_tel);
          query.bindValue(5, service);
          query.bindValue(6,adresse );
    return query.exec();

     }
         return 1 ;
  }
bool Employes::modifier()
{

QSqlQuery query;


query.prepare("Update GS_EMPLOYE set CIN = :cin , NOM = :nom , PRENOM = :prenom ,DATE_DE_NAISSANCE= :date_de_naissance ,  NUMERO_DE_TELEPHONE= :numero_tel , SERVICE=:service, ADRESSE=:adresse  where CIN= :cin ");

query.bindValue(":cin", cin);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":date_de_naissance", date_de_naissance);
query.bindValue(":numero_tel",numero_tel);
query.bindValue(":service",service);
query.bindValue(":adresse",adresse);

return    query.exec();


}
bool Employes::supprimer(int cinn)
{ QSqlQuery query;
    QString s = QString::number(cinn);
          query.prepare("Delete from GS_EMPLOYE where CIN=:CIN");
          query.bindValue(0,s);

    return query.exec();


}
/*bool Employes::supprimer(int cinn)
{
    QSqlQuery query;
    query.prepare("SELECT * from GS_EMPLOYE where (CIN=:cin)");
    query.bindValue(":cin",cin);
    if(query.exec())
    {if(query.next())
       { query.prepare("Delete from GS_EMPLOYE where CIN=:CIN");
        query.bindValue(":cin",cin);
        query.exec();
        return true;
        }
    }
  return false;
}
*/



QSqlQueryModel* Employes :: afficher()
{

  QSqlQueryModel *model=new QSqlQueryModel();



   model->setQuery(QString("Select * from GS_EMPLOYE"));
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("  CIN    "));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("  NOM    "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("  PRENOM    "));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("  DATE_DE_NAISSANCE    "));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("   NUMERO_DE_TELEPHONE   "));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("   SERVICE   "));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("   ADRESSE   "));



    return model;
}
 QSqlQueryModel *Employes:: afficher_CIN()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM GS_EMPLOYE ORDER BY  CIN");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO_DE_TELEPHONE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr(" SERVICE "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr(" ADRESSE "));
        return model;
}
 QSqlQueryModel *Employes:: afficher_Nom()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM GS_EMPLOYE ORDER BY  NOM");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO_DE_TELEPHONE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr(" SERVICE "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr(" ADRESSE "));
        return model;
}

 QSqlQueryModel *Employes:: afficher_SERVICE()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM GS_EMPLOYE ORDER BY  SERVICE");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DE_NAISSANCE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO_DE_TELEPHONE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr(" SERVICE "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr(" ADRESSE "));
        return model;
}
 QSqlQueryModel* Employes :: afficher1()
 {

   QSqlQueryModel *model=new QSqlQueryModel();



    model->setQuery(QString("Select * from GS_EMPLOYE"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("  NOM    "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("  PRENOM    "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("   SERVICE   "));



     return model;
 }

 void Employes::recherche(Ui::MainWindow *ui)
 {
     QSqlQuery q;
     QSqlQueryModel *modal=new QSqlQueryModel();
     QString mot =ui->lineEdit_recherche->text();
     q.prepare("select * from GS_EMPLOYE where (NOM LIKE '%"+mot+"%' or CIN LIKE '%"+mot+"%' or SERVICE LIKE '%"+mot+"%' )");

     q.exec() ;
     modal->setQuery(q);
     ui->tab_employe1->setModel(modal);

 }
