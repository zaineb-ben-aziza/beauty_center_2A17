#ifndef CONGE_H
#define CONGE_H
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include<QSqlQueryModel>
#include<QString>
#include <QSqlQuery>
#include "QMessageBox"
class conge
{
public:
    conge();
    conge(int,int,QString,QString,QString);


    int getcin_c();
    int getid_c();
    QString getdate();
    QString getduree();
    QString getetat();

    void setcin_c(int);
    void setid_c(int);
    void setdate(QString);
    void setduree(QString);
    void setetat(QString);

    bool ajouter_c();
    QSqlQueryModel* afficher_c();
    bool supprimer_c(int);
    bool modifier_c();

private:
    int cin_c,id_c;
    QString date,duree,etat;

};

#endif // CONGE_H
