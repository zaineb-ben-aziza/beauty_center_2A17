#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");
db.setUserName("lassaad");//inserer nom de l'utilisateur
db.setPassword("lassad");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
