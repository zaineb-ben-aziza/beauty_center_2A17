#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QString>
#include<QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include<QSqlDatabase>
#include "conge.h"
#include <QDate>
#include <QDateTime>
#include <QString>
#include <QDialog>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <windows.h>
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
    QSqlQueryModel* afficher1();
    bool supprimer(int);
    bool modifier();
   QSqlQueryModel* afficher_CIN();
   QSqlQueryModel* afficher_Nom();
   QSqlQueryModel* afficher_SERVICE();
    void recherche(Ui::MainWindow *ui);
private:
    int cin;
    QString nom,prenom,date_de_naissance,service,numero_tel,adresse;

};

#endif // EMPLOYES_H
