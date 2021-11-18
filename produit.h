#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlQuery>
#include <QString>
#include <QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QTableView>
#include <QDate>
class Produit
{
public:
    Produit();
   Produit(int, QString, QString, QString, int);

    //GETTERS
    int getId_produit();
    QString getNom_produit();
    QString getDate_exp();
    QString getType_produit();
    int getNombre_produit();

    //SETTERS
    void setId_produit(int); //changer les noms
    void setNom_produit(QString);
    void setDate_exp(QString);
    void setType_produit(QString);
    void setNombre_produit(int);

    //functions
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * affichere();

    bool suprimmer(int id_produit);
    bool modifier();
   QSqlQueryModel* trie();
        QSqlQueryModel* trier(const QString, const QString);
        QSqlQueryModel* trie2();
        QSqlQueryModel *chercher_pr(const QString &aux);
        QSqlQueryModel *chercher_emp1(const QString &aux);
        QSqlQueryModel *chercher_emp2(const QString &aux);
private:
    int id_produit, nombre_produit;
    QString nom_produit, date_exp, type_produit;
    QDate date;












};

#endif // PRODUIT_H
