#include "paiement.h"
#include <QSqlQueryModel>
#include "mainwindow.h"

paiement::paiement()
{
num_paiement=0;
}

paiement::paiement(int x,QString z,QString type,QString type2)
{
 this->montant=z;
    this->num_paiement=x;
    this->type=type;
    this->type2=type2;
}

bool paiement::ajouter()
{
QSqlQuery query(QSqlDatabase::database("projet2a"));
query.prepare("insert into paiement (num_paiement,MONTANT,TYPE,type2) values (:id,:montant,:type,:type2)");
query.bindValue(":id",num_paiement);
query.bindValue(":montant",montant);
query.bindValue(":type",type);
query.bindValue(":type2",type2);

return query.exec();
}
QSqlQueryModel *paiement::afficher()
{
QSqlQuery query;
QSqlQueryModel *model=new QSqlQueryModel();
query.prepare(QString("Select * from paiement"));
query.exec();
model->setQuery(query);

return model;
}

bool paiement::supprimer()
{
    QString s= QString::number(num_paiement);
    QSqlQuery query;
    query.prepare(QString("DELETE from paiement where num_paiement=:id"));
    query.bindValue(":id",s);
   return query.exec();
}
void paiement::setnum_paiement(int num)
{

    num_paiement=num;
}
void paiement::modifier()
{
    QSqlQuery query;
    QString s= QString::number(num_paiement);
    query.prepare(QString("update paiement set montant=:MONTANT,type=:TYPE where num_paiement=:NUM_PAIEMENT"));
    query.bindValue(":MONTANT",montant);
    query.bindValue(":NUM_PAIEMENT",s);
    query.bindValue(":TYPE",type);
    query.exec();

}


void paiement::recherche(Ui::MainWindow *ui)

     {

         QSqlQuery q;

         QSqlQueryModel *modal=new QSqlQueryModel();

         QString  mot=ui->l_supp_4->text();

         q.prepare("select * from PAIEMENT where ( NUM_PAIEMENT LIKE '%"+mot+"%')");



         q.exec() ;

         modal->setQuery(q);

         ui->tableView_5->setModel(modal);



}
QSqlQueryModel *paiement:: afficher_CIN()

{

  QSqlQueryModel *model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM paiement ORDER BY  NUM_PAIEMENT");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE_DE_PAIEMENT"));

        model->setHeaderData(1, Qt::Horizontal, QObject::tr("MONTANT"));

        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));

        model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE2"));


        return model;

}
QSqlQueryModel *paiement::calculer()
{

        QSqlQuery query;
        QSqlQueryModel *model=new QSqlQueryModel();
        query.prepare(QString("SELECT SUM(MONTANT) AS montant_total from paiement"));
        query.exec();
        model->setQuery(query);
        return model;

}

