#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "smptp.h"
#include "produit.h"
#include "fournisseur.h"
#include "arduino.h"
#include "paiement.h"
#include "cheque.h"

//pdf
#include <QtPrintSupport/QPrinter>
#include <QPixmap>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>

#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
//mailling
#include <QPdfWriter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QVector2D>
#include <QVector>

#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include"conge.h"
//constructeur de la classe mainwindow generé automatiquement
MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
 ui(new Ui::MainWindow)
{     Employes E;
   ui->setupUi(this);
 //l'employe
 ui->le_cin->setValidator(new QIntValidator(0, 9999999, this));
 ui->lineEdit_9->setValidator(new QIntValidator(0, 9999999, this));
 ui->le_cin2->setValidator(new QIntValidator(0, 9999999, this));
 ui->tab_employes->setModel(E.afficher());
  //ui->tab_condition->setModel(E.afficher1());//instruction ajoutée dans le constructeur:appel ded la methode afficher via l'attribut E
//le conge
 ui->le_cin_2->setValidator(new QIntValidator(0, 9999999, this));
 ui->le_id_2->setValidator(new QIntValidator(0, 9999999, this));
ui->tab_conge->setModel(C.afficher_c());








  //**************************************************************************************//
  //partie achref
  ui->le_id_produit->setValidator(new QIntValidator(0, 9999999, this));
  ui->le_nombre_produit->setValidator(new QIntValidator(0, 9999999, this));
  ui->le_supprimer->setValidator(new QIntValidator(0, 9999999, this));
  ui->tab_produit->setModel(P.afficher());

  int ret=A.connect_arduino(); // lancer la connexion à arduino
      switch(ret){
      case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
          break;
      case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
         break;
      case(-1):qDebug() << "arduino is not available";}

        ui->l_supp_3->setValidator(new QIntValidator(100,9999,this));
        ui->npaiement_3->setValidator(new QIntValidator(100,9999,this));
        ui->pup_3->setValidator(new QIntValidator(100,9999,this));
         ui->montant_5->setValidator(new QIntValidator(100,9999,this));
         ui->num_3->setValidator(new QIntValidator(100,9999,this));
         ui->cin_3->setValidator(new QIntValidator(100,9999,this));
         ui->numcheque_3->setValidator(new QIntValidator(100,9999,this));
         ui->lineline_3->setValidator(new QIntValidator(100,9999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{qDebug()<<"hello";
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



// calculatrice




void MainWindow::on_pb_supprimer_clicked()
{Employes E;

    QSqlQueryModel *model=new QSqlQueryModel();
  QString cin = ui->lineEdit_9->text();


     model->setQuery(QString("Select * from GS_EMPLOYE where CIN="+cin));
     if (model->rowCount() != 0){
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
     else {
         QMessageBox msgBox;
         msgBox.setText("employe nexiste pas");
       msgBox.exec();
     }

}

void MainWindow::on_pb_modifier_clicked()
{       int cin=ui->le_cin2->text().toInt();
        QString CIN=ui->le_cin2->text();
        QString nom=ui->le_nom2->text();
        QString prenom=ui->le_prenom2->text();
        QString date_de_naissance =ui->le_date2->text();
        QString numero_tel =ui->le_numero->text();
        QString service =ui->le_service_2->text();
        QString adresse =ui->le_adresse2->text();

   QSqlQueryModel *model=new QSqlQueryModel();

     model->setQuery(QString("Select * from GS_EMPLOYE where CIN="+CIN));
            if (model->rowCount() != 0){

        Employes E (cin , nom, prenom, date_de_naissance, numero_tel, service, adresse);
         bool test=E.modifier();
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
            else {
                QMessageBox msgBox;
                msgBox.setText("employe nexiste pas");
              msgBox.exec();
            }




}

void MainWindow::on_pb_aj_clicked()
{
    int cin_c=ui->le_cin_2->text().toInt();
        int id_c=ui->le_id_2->text().toInt();
        QString date=ui->le_date_2->text();
        QString duree=ui->le_duree_2->text();
        QString etat=ui->le_etat_2->text();

    conge C(cin_c,id_c,date,duree,etat);
    bool test=C.ajouter_c();
       QMessageBox msgBox;
      if(test)
    { ui->tab_conge->setModel(C.afficher_c());
        msgBox.setText("ajout avec succes");

    }
     else
        msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void MainWindow::on_pb_mod_clicked()
{ int id_c=ui->le_id_modif->text().toInt();
    int cin_c=ui->le_cin_modif->text().toInt();
    QString date=ui->le_date_modif->text();
    QString duree=ui->le_duree_modif->text();
    QString etat=ui->le_etat_modif->text();

conge C(id_c,cin_c,date,duree,etat);
  bool test=C.modifier_c();
             if(test)
           {

                 ui->tab_conge->setModel(C.afficher_c());
           QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                             QObject::tr("conge modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

           }
             else
                 QMessageBox::critical(nullptr, QObject::tr("modifier un employe"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}

void MainWindow::on_pb_supp_clicked()
{conge C1; C1.setcin_c(ui->le_id_supp->text().toInt());//convertir la chaine saisie en un entier car lattribut id est de type int
    bool test=C1.supprimer_c(C1.getcin_c());

    QMessageBox msgBox;
   if (test)
   {
       ui->tab_conge->setModel(C.afficher_c());
       msgBox.setText("Suppression avec succes");

   }
   else
     msgBox.setText("Echec de suppression");
   msgBox.exec();


}

void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;
            QTextStream out(&strStream);



            const int rowCount = ui->tab_employes->model()->rowCount();
            const int columnCount = ui->tab_employes->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"

                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%60 les postes</title>\n").arg("poste")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<table border=1 cellspacing=0 cellpadding=2>\n";
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                if (! ui->tab_employes->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_employes->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_employes->isColumnHidden(column)) {
                        QString data = ui->tab_employes->model()->data(ui->tab_employes->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
            if (dialog->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;
}


void MainWindow::on_pushButton_clicked()
{
    QString link="https://www.google.com/?hl=fr";
    QDesktopServices::openUrl(QUrl (link)) ;
}

void MainWindow::on_pushButton_3_clicked()
{Employes E;
     ui->tab_employes->setModel(E.afficher_CIN());
}

void MainWindow::on_pushButton_4_clicked()
{Employes E;
    ui->tab_employes->setModel(E.afficher_Nom());
}

void MainWindow::on_pb_rechercher_clicked()
{
    Employes E ;
        ui->tab_employe1->setModel(E.afficher());


           E.recherche(ui);

}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("zaineb.benaziza@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("zaineb.benaziza@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("zaineb.benaziza@esprit.tn",ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}


void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP " ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}




void MainWindow::on_browseBtn_clicked()
{ files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::on_sendBtn_clicked()
{
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );

}
//partie achref




void MainWindow::on_pb_ajouter_2_clicked()
{
    int nombre_produit = ui->le_nombre_produit->text().toInt();
    int id_produit = ui->le_id_produit->text().toInt();
    QString nom_produit = ui->le_nom_produit->text();
    QString date_exp = ui->le_date_exp->text();
    QString type_produit = ui->le_type_produit->text();
    Produit P( id_produit, nom_produit, date_exp, type_produit, nombre_produit);
    //ui->tab_produit->setModel(P.afficher());
    bool test = P.ajouter();

    if(test)
    {
        ui->tab_produit->setModel(P.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Ok to exit."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

//suppression
void MainWindow::on_pushButton_13_clicked()
{


    Produit P1;P1.setId_produit(ui->le_supprimer->text().toInt());
    bool test = P1.suprimmer(P1.getId_produit());
    QMessageBox msgBox;
    if(test)
    {

        msgBox.setText("Suppression avec succes!");
    }
    else
    {
        msgBox.setText("Echec de suppression");
    }
    msgBox.exec();
     ui->tab_produit->setModel(P.afficher());
}




void MainWindow::on_pb_modifier_2_clicked()
{
    int id_produit=ui->le_id_produit->text().toInt();

        QString nom_produit=ui->le_nom_produit->text();

        QString date_exp=ui->le_date_exp->text();

        QString type_produit=ui->le_type_produit->text();

        int nombre_produit=ui->le_nombre_produit->text().toInt();

        Produit P(id_produit,nom_produit,date_exp,type_produit,nombre_produit);

        bool test=P.modifier();

        QMessageBox msgbox;

        if(test)

            {msgbox.setText("Modification avec succes.");

                ui->tab_produit->setModel(P.afficher());

                ui->le_id_produit->setText("");

                ui->le_nom_produit->setText("");

                ui->le_type_produit->setText("");

                ui->le_nombre_produit->setText("");

            }

            else

                msgbox.setText("Echec de modification");

            msgbox.exec();
}

void MainWindow::on_pushButton_20_clicked()
{
    Produit e;
    QString text;
    if (ui->radioButton_ID->isChecked()==true)
{
text=ui->line_recherche_critere->text();
     if(text == "")

     {

         ui->tableView_6->setModel(e.afficher());

     }

     else

     {



         ui->tableView_6->setModel(e.chercher_pr(text));

     }
    }
     if(ui->radioButton_salaire->isChecked()==true)
    {
        text=ui->line_recherche_critere->text();
             if(text == "")

             {

                 ui->tableView_6->setModel(e.afficher());

             }

             else

             {



                 ui->tableView_6->setModel(e.chercher_emp1(text));

             }

    }
     else if     (ui->radioButton_nom->isChecked()==true)
     {

         text=ui->line_recherche_critere->text();
              if(text == "")

              {

                  ui->tableView_6->setModel(e.afficher());

              }

              else

              {



                  ui->tableView_6->setModel(e.chercher_emp2(text));

              }
     }
}




void MainWindow::on_pdf_pb_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tab_produit->model()->rowCount();
        const int columnCount = ui->tab_produit->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("Produit")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tab_produit->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tab_produit->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_produit->isColumnHidden(column)) {
                    QString data = ui->tab_produit->model()->data(ui->tab_produit->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table>\n"
            "</body>\n"
            "</html>\n";

        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);

        QPrinter printer;

        QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
        if (dialog->exec() == QDialog::Accepted) {
            document->print(&printer);
}}





void MainWindow::on_pushButton_achrefajoutalerte_clicked()
{
    Produit Etmp;

    QMessageBox::critical(nullptr, QObject::tr("liste des produits finis"),
                QObject::tr("voici la liste des produits qui riquent de finir.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    {ui->alerteperime->setModel(Etmp.affichere());}
}


void MainWindow::on_pushButton_15_clicked()
{
    int id_fr = ui->lineEdit_7->text().toInt();
           int num_tel = ui->lineEdit_9->text().toInt();
           QString nom_fr = ui->lineEdit_8->text();

           fournisseur f( id_fr, num_tel, nom_fr);
           //ui->tab_produit->setModel(P.afficher());
           bool test = f.ajouter();

           if(test)
           {
               ui->tab_fournisseur->setModel(f.afficher());
               QMessageBox::information(nullptr, QObject::tr("OK"),
                           QObject::tr("Ajout effectué.\n"
                                       "Click Ok to exit."), QMessageBox::Ok);

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("Ajout non effectué.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

}
// calculatrice

void MainWindow::on_plus_clicked()
{
    ui->resultat->setText(QString::number(ui->n1->value() + ui->n2->value()));

}

void MainWindow::on_moins_clicked()
{
    ui->resultat->setText(QString::number(ui->n1->value() - ui->n2->value()));

}

void MainWindow::on_fois_clicked()
{
    ui->resultat->setText(QString::number(ui->n1->value() * ui->n2->value()));

}

void MainWindow::on_sur_clicked()
{
    ui->resultat->setText(QString::number(ui->n1->value() / ui->n2->value()));

}
//code achref w aziz
void MainWindow::on_butajoutp_clicked()
{
    QMessageBox msgBox;
paiement c(ui->npaiement_3->text().toInt(),ui->montant_5->text(),ui->comboBox_11->currentText(),ui->comboBox_12->currentText());
if (c.ajouter())
{

    msgBox.setText("Ajout avec succes.");
    msgBox.exec();

}
else
{
    msgBox.setText("Probleme d'ajout");
    msgBox.exec();
}

ui->tableView_5->setModel(c.afficher());
}

void MainWindow::on_butaffichep_clicked()
{
    paiement c;
    ui->tableView_5->setModel(c.afficher());
}
void MainWindow::on_butsuppp_clicked()
{
    paiement c;
    c.setnum_paiement(ui->l_supp_3->text().toInt());
    c.supprimer();
    ui->tableView_5->setModel(c.afficher());
}




void MainWindow::on_tableView_5_clicked(const QModelIndex &index)

 {
        QString num_paiement=ui->tableView_5->model()->data(ui->tableView_5->model()->index(index.row(),0)).toString();
        ui -> l_supp_3->setText(num_paiement);

        ui -> pup_3->setText(num_paiement);
}



void MainWindow::on_ajoutcheque_clicked()
{
   int num_cheque=ui->numcheque_3->text().toInt();
   int cin_client=ui->cin_3->text().toInt();
   int montantcheque=ui->montant_6->text().toInt();

cheque cc (num_cheque,cin_client,ui->statut_3->currentText(),montantcheque);


if (cc.ajouter())
{
    QMessageBox::information(this,"Ajouter","Ajout avec  succeés !");
ui->tablecheque_3->setModel(cc.afficher());
}
else
 QMessageBox::critical(this,"Ajouter","Probléme d'ajout !");
}

void MainWindow::on_affichercheque_clicked()
{
    cheque c;
    ui->tablecheque_3->setModel(c.afficher());
}




void MainWindow::on_suppcheque_clicked()
{
    cheque c;
    c.setNum_cheque(ui->lineline_3->text().toInt());
    c.supprimer();
    ui->tablecheque_3->setModel(c.afficher());
}




void MainWindow::on_achrefrech_clicked()
{
    paiement E ;

            ui->tableView_5->setModel(E.afficher());

               E.recherche(ui);


}

void MainWindow::on_tablecheque_3_clicked(const QModelIndex &index)
{
    QString num_cheque=ui->tablecheque_3->model()->data(ui->tablecheque_3->model()->index(index.row(),0)).toString();
    ui ->lineline_3->setText(num_cheque);
    ui ->numcheque_3->setText(num_cheque);
    /*ui ->lineEdit_9->setText(num_cheque);*/

}

void MainWindow::on_pushButton_34_clicked()
{
    QString strStream;
                QTextStream out(&strStream);



                const int rowCount = ui->tableView_5->model()->rowCount();
                const int columnCount = ui->tableView_5->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"

                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%60 les postes</title>\n").arg("poste")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<table border=1 cellspacing=0 cellpadding=2>\n";
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (! ui->tableView_5->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_5->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tableView_5->isColumnHidden(column)) {
                            QString data = ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                if (dialog->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;
}

void MainWindow::on_buttri_clicked()
{
    paiement E;

         ui->tableView_5->setModel(E.afficher_CIN());
}

void MainWindow::on_statbut_clicked()
{
    paiement p;
    ui->somme_3->setModel(p.calculer());
}

void MainWindow::on_moddifiecheque_clicked()
{
    cheque c;
    (ui->num_3->text().toInt(),ui->comboBox_14->currentText());
        c.modifier();
        ui->tablecheque_3->setModel(c.afficher());
}
// ard zeineb

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("Employe detecte"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("Pas de employe");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}





void MainWindow::on_pushButton_5_clicked()
{Employes E;
    ui->tab_employes->setModel(E.afficher_SERVICE());

}

void MainWindow::on_butmodifierp_clicked()
{
        paiement c(ui->pup_3->text().toInt(),ui->mup_3->text(),ui->comboBox_11->currentText(),ui->comboBox_12->currentText());
            c.modifier();
            ui->tableView_5->setModel(c.afficher());



}

void MainWindow::on_pushButton_7_clicked()
{
    qDebug()<<"hello";
}
