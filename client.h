#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(int,int,QString,QString,int,QString);
    int get_id_c();
    int get_cin_c();
    QString get_nom_c();
    QString get_prenom_c();
    int get_tel_c();
    QString get_adresse_c();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString,int,QString);


private:
    QString nom_c,prenom_c,adresse_c;
    int id_c,cin_c,tel_c;
};

#endif // CLIENT_H
