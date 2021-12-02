#ifndef FINANCIER_H
#define FINANCIER_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QDate>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class paiement
{
public:
    paiement();
    paiement(int,QString,QString,QString);
    int getnum_paiement();
    int getdate_paiement();
    float getmontant();
    QString gettype();
    QString gettype2();
    void setnum_paiement(int num_paiement);
    void setmontant(QString);
    void settype(QString);
    void settype2(QString);
QSqlQueryModel * chercher();



bool ajouter();
QSqlQueryModel* afficher();
bool supprimer();
void modifier();
void recherche(Ui::MainWindow *ui);
QSqlQueryModel* afficher_CIN();
QSqlQueryModel *calculer();
private:
    int num_paiement;
    QString montant;
    QString type,type2;



};

#endif // FINANCIER_H
