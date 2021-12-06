#ifndef OFFRE_H
#define OFFRE_H

#include <QString>
#include <qsqlquerymodel.h>
#include <QDate>
class Offre
{
public:
    Offre();
    Offre(int,QString,QDate,QDate,int);
    int getid();
    QString gettype();

    int getprix();
    void setid(int);
    void settype(QString);

    void setprix(int);
    bool ajouter();
    QSqlQueryModel* afficher();
  bool supprimer(int);
    bool modifier();
private:
    int prix,id;
    QString type;
    QDate debut,fin;



};

#endif // OFFRE_H
