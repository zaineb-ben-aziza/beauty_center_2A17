#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "offre.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include "smtp.h"
#include "historique.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ Offre O;
    ui->setupUi(this);
    ui->le_id-> setValidator( new QIntValidator(0, 9999999, this));
    ui->le_id_supp-> setValidator( new QIntValidator(0, 9999999, this));
    ui->id_modif-> setValidator( new QIntValidator(0, 9999999, this));
    ui->le_prix-> setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_offre->setModel(O.afficher() );

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()

    {
    Offre O1;

O1.setid(ui->le_id->text().toInt());
O1.setid(ui->le_prix->text().toInt());
        int id=ui->le_id->text().toInt();
        QString type=ui->le_type->text();

       QDate debut = ui->dateEdit->date();
       QDate fin = ui->dateEdit->date();

        int prix=ui->le_prix->text().toInt();
        QString debut_s=debut.toString();
         QString fin_s=fin.toString();
        H.save("id:"+ui->le_id->text(),"type :"+ui->le_type->text(),"debut:"+debut_s,"fin:"+fin_s,"prix:"+ui->le_prix->text());
    Offre  O (id,type,debut,fin,prix);
       bool test=O.ajouter();
       QMessageBox msgBox;
       if(test)
          {
          A.write_to_arduino("1");
           msgBox.setText("Ajout avec succes");
   ui->tab_offre->setModel(O.afficher());
   msgBox.exec();
       }
       else
       {
         A.write_to_arduino("0");
           msgBox.setText("Echec d'ajout");
       msgBox.exec();
       }


}

void MainWindow::on_pb_supprimer_clicked()
{
    Offre O1;
    O1.setid(ui->le_id_supp->text().toInt());
    bool test=O1.supprimer(O1.getid());
    QMessageBox msgBox;
    if(test)
       {
        msgBox.setText("suppression avec succes");
ui->tab_offre->setModel(O1.afficher());
    }
    else

        msgBox.setText("Echec de suppresion");
    msgBox.exec();
}



void MainWindow::on_pb_modifier_clicked()
{


int id ;
int prix;
QString type;
    QDate debut,fin;

    Offre O1;

O1.setid(ui->id_modif->text().toInt());
id=ui->id_modif->text().toInt();
type=ui->type_modif->text();
fin=ui->debut_modif->date();
debut=ui->fin_modif->date();
prix=ui->prix_modif->text().toInt();
Offre  O(id,type,debut,fin,prix);
bool test = O.modifier();
QMessageBox msgBox;
if(test)
   { msgBox.setText("modification avec succes");
ui->tab_offre->setModel(O.afficher());
}
else
    msgBox.setText("Echec de modification");
msgBox.exec();
}


void MainWindow::on_envoyer_clicked()
{
    Smtp* smtp = new Smtp("rihemomrani69@gmail.com","rihem123","smtp.gmail.com",465);
    connect (smtp, SIGNAL (status (QString)), this, SLOT (mailSent(QString)));
    smtp->sendMail("rihemomrani69@gmail.com", ui->lineEdit_mail->text(), ui->subject->text(), ui->msg->toPlainText());
    ui->lineEdit_mail->setText("");
     ui->subject->setText("");
    ui->msg->setText("");
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->tab_trie->setModel(B.trier_nb());

    QMessageBox msgBox;

       msgBox.setText("les 10 premiers clients ont une reduction");


    msgBox.exec();


}

void MainWindow::on_le_recherche_clicked()
{
   QString date=ui->le_date->text();
    ui->tab_recherche->setModel(L.recherche(date));


}

