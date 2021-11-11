#ifndef PERSONNELS_H
#define PERSONNELS_H

#include<QSqlQueryModel>
#include<QString>
class personnels
{
        public:
            personnels();
            (int,QString,QString);
            int getid();
            QString getnom();
            QString getprenom();
            void setid(int);
            void setnom(QString);
            void setprenom(QString);
            bool ajouter();
            QSqlQueryModel* afficher();
            bool supprimer(int);
        private:
            int id;
            QString nom,prenom;
        };

#endif // PERSONNELS_H
