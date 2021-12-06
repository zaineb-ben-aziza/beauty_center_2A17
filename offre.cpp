#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include "offre.h"
Offre::Offre()
{
id=0;
type="";
debut=QDate::currentDate();
fin=QDate::currentDate();
prix=0;
}
Offre::Offre(int id,QString type,QDate debut,QDate fin,int prix)
{this->id=id;
this->type=type;
this->debut=debut;
this->fin=fin;
this->prix=prix;
}
int Offre::getid(){return id ;}
QString Offre::gettype(){return type;}
//QString Offre::getfin(){return fin;}
//QString Offre::getdebut(){return debut;}
int Offre::getprix(){return prix;}
void Offre::setid(int id ){this->id=id;}
void Offre::settype(QString type){this->type=type;}

void Offre::setprix (int prix ){this->prix=prix;}
bool Offre::ajouter()
{

   
   QSqlQuery query;
   query.prepare("select * from OFFRES   WHERE id=:id" );
   query.bindValue(":id", id );

   if (query.exec())
    {
       if( !query.next())
       {
   query.prepare("INSERT INTO OFFRES (id, type, date_debut,date_fin,prix) "
                 "VALUES (:id, :type, :debut, :fin , :prix)");
   query.bindValue(":id", id);
         query.bindValue(":type", type);
         query.bindValue(":debut", debut);
          query.bindValue(":fin", fin);
           query.bindValue(":prix", prix);
         query.exec();
         return true;
}
   
   }
   return false;
    
}

bool Offre::supprimer(int id)
{


    QSqlQuery query;


        query.prepare("select * from OFFRES WHERE ID = :id ");

        query.bindValue(":id", id);



         if(query.exec()) //existe

         {

        if (!query.next())

         {
          query.prepare("Delete from OFFRES where id=:id");
          query.bindValue(":id", id);

         query.exec();
         return true;
          }
          }

}
QSqlQueryModel * Offre::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


        model->setQuery("SELECT*  FROM OFFRES");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_fin"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;

}


bool Offre::modifier()

{
QSqlQuery query;


    query.prepare("select * from OFFRES   WHERE id=:id ");

        query.bindValue(":id",id);

       if (query.exec())  //existe

       {
           if( query.next())
           {

    query.prepare("update OFFRES set type=:type,date_debut=:debut,date_fin=:fin,prix=:prix where id=id");
    query.bindValue(":id",id);
    query.bindValue(":type", type);
     query.bindValue(":debut", debut);
      query.bindValue(":fin", fin);
      query.bindValue(":prix", prix);
      query.exec();
      return  true;
}
}

       return  false;
}

