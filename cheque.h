#ifndef CHEQUE_H
#define CHEQUE_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QDate>

class cheque
{
public:
    cheque ();
    cheque(int num_cheque,int cin_client,QString statut_cheque,int montant_cheque);
    int getNum_cheque();
    int getCin_client();
    QString getStatut_cheque();
   int getMontant_cheque();

    void setNum_cheque(int);
    void setCin_client(int);
    void setStatut_cheque(QString);
    void setMontant_cheque(int);

bool ajouter();
QSqlQueryModel* afficher();
bool supprimer();
void modifier();

    private:
        int num_cheque;
        int cin_client;
        QString statut_cheque;
        int montant_cheque;
};

#endif // CHEQUE_H
