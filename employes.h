#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QSqlQueryModel>
#include<QString>
#include <QSqlQuery>
#include "QMessageBox"

class Employes
{
public:
    Employes();
    Employes(int,QString,QString,QString,QString,QString,QString);


    int getcin();
    QString getnom();
    QString getprenom();
    QString getdate_de_naissance();
    QString getservice();
    QString getnumero_tel();
    QString getadresse();


    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    void setdate_de_naissance(QString);
    void setservice(QString);
    void setnumero_tel(QString);
    void setadresse(QString);



    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int );




private:
    int cin;
    QString nom,prenom,date_de_naissance,service,numero_tel,adresse;

};

#endif // EMPLOYES_H
