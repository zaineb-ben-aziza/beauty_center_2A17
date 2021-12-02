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
    cheque();
    cheque(int numcheque,int cin,QString statut,QString montant);
    int getnum_cheque();
    int getcin_client();
    QString getstatut_cheque();
    QString getmontant_cheque();

    void setnum_cheque(int);
    void setcin_client(int);
    void setstatut_cheque(QString);
    void setmontant_cheque(QString);

bool ajouter();
QSqlQueryModel* afficher();
bool supprimer();
void modifier();

    private:
        int numcheque;
        int cinclient ;
        QString statutcheque;
        QString montantcheque;
};

#endif // CHEQUE_H
