#include "historique.h"
#include "offre.h"
#include <QDate>
Historique::Historique()
{

}
void Historique::save(QString id,QString type,QString debut,QString fin,QString prix)

{
    Offre O;
    QFile file ("C:/Users/mes documents/Desktop/rihem/histo.txt");
     if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
      qDebug()<<"erreur";
     QTextStream out(&file);
     out << id+"\n"+type+"\n"+debut+"\n"+fin+"\n"+prix << "\n";



}

