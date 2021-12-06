#ifndef LISTE_ANNIVERSAIRE_H
#define LISTE_ANNIVERSAIRE_H
#include <QDate>
#include <qsqlquerymodel.h>
class liste_anniversaire
{
public:
    liste_anniversaire();
    QSqlQueryModel *recherche(QString);
};

#endif // LISTE_ANNIVERSAIRE_H
