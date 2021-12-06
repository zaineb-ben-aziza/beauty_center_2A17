#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>



class Historique
{

public:
    Historique();
    void save(QString,QString,QString,QString,QString);

};

#endif // HISTORIQUE_H

