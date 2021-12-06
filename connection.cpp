#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("gestion des offres");
db.setUserName("rihem");//inserer nom de l'utilisateur
db.setPassword("rihem");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
