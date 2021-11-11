#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>

//constructeur de la classe mainwindow generé automatiquement
MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
 ui(new Ui::MainWindow)
{
   ui->setupUi(this);
 ui->le_cin->setValidator(new QIntValidator(0, 9999999, this));
ui->tab_employes->setModel(E.afficher());//instruction ajoutée dans le constructeur:appel ded la methode afficher via l'attribut E
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();

    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString date_de_naissance=ui->le_date->text();
    QString numero_tel=ui->le_num->text();
    QString service=ui->le_service->text();
    QString adresse=ui->le_adresse->text();


   Employes E(cin,nom,prenom,date_de_naissance,numero_tel,service,adresse);
bool test=E.ajouter();
   QMessageBox msgBox;
if(test)
     {
    ui->tab_employes->setModel(E.afficher());
    msgBox.setText("ajout avec succes");

}else
    msgBox.setText("Echec d'ajout");
    msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Employes E1; E1.setcin(ui->lineEdit_9->text().toInt());//convertir la chaine saisie en un entier car lattribut id est de type int
    bool test=E1.supprimer(E1.getcin());
    QMessageBox msgBox;
   if (test)
   {
       ui->tab_employes->setModel(E.afficher());
       msgBox.setText("Suppression avec succes");

   }
   else
     msgBox.setText("Echec de suppression");
   msgBox.exec();

}

void MainWindow::on_pb_modifier_clicked()
{



        int cin=ui->le_cin2->text().toInt();
        QString nom=ui->le_nom2->text();
        QString prenom=ui->le_prenom2->text();
        QString date_de_naissance =ui->le_date2->text();
        QString numero_tel =ui->le_numero->text();
        QString service =ui->le_service_2->text();
        QString adresse =ui->le_adresse2->text();




        Employes E (cin , nom, prenom, date_de_naissance, numero_tel, service, adresse);
         bool test=E.modifier(cin);
         if(test)
       {

             ui->tab_employes->setModel(E.afficher());
       QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                         QObject::tr("employe modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

       }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier un employe"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);



}
