#include "bons_de_reduction.h"
#include <qsqlquerymodel.h>

bons_de_reduction::bons_de_reduction()
{

}
QSqlQueryModel * bons_de_reduction ::trier_nb()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM  g_clientFidele ORDER BY nb_visites ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nb_visites"));
   return model;
}
