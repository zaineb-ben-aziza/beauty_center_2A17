#include "liste_anniversaire.h"
#include <qsqlquerymodel.h>
#include <qsqlquery.h>
liste_anniversaire::liste_anniversaire()
{
}

QSqlQueryModel *liste_anniversaire::recherche(QString date)
{

        //QString datee=date.toString();

        QSqlQueryModel * model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("select * from g_clients where date=:date_naiss ");
        query.bindValue("date:",date);
        query.exec();
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_naiss"));
        model->setQuery(query);//execution ta3 select

    return model;

}
