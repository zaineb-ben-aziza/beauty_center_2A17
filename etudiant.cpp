#include "etudiant.h"
#include <QString>

Etudiant::Etudiant()
{
id=0; nom=" "; prenom=" ";
}


Etudiant: :Etudiant(int id, QString nom, QString prenom);
{this->id=id; this->nom=nom; this->prenom=prenom;}
int getid();
QString getnom();
QString getprenom();
void setid(int);
void setnom(QString);
void setprenom(QSring);

