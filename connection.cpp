#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Gestion_Employes");
db.setUserName("zeineb");//inserer nom de l'utilisateur
db.setPassword("zeineb");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}


