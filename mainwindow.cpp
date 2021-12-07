#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "smptp.h"

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

