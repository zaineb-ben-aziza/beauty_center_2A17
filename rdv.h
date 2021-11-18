#ifndef RDV_H
#define RDV_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class RDV
{
public:
    RDV();
    RDV(int,int,QString,QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString);
    QSqlQueryModel * afficherRech(QString,QString);


private:
    QString dater,service;
    int id_c,ref;
};

#endif // RDV_H
