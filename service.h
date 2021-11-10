#ifndef SERVICE_H
#define SERVICE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class service
{
private:
    int id,prix;
    QString nom;

public:
    service();
    service(int,QString,int);

    bool ajouter();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * afficher();


};

#endif // SERVICE_H
