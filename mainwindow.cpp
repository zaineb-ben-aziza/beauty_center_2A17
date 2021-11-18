#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id_produit->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_nombre_produit->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_produit->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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




void MainWindow::on_pb_modifier_clicked()
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

void MainWindow::on_pushButton_22_clicked()
{
    Produit e;
        QString mode;
         if (ui->rb_asc_historique->isChecked()==true)
    {
             ui->tableView_6->setModel(e.trie());


    }
         else if(ui->rb_desc_historique->isChecked()==true)

             ui->tableView_6->setModel(e.trie2());
}



void MainWindow::on_pushButton_18_clicked()
{
    Produit Etmp;

    QMessageBox::critical(nullptr, QObject::tr("liste des produits finis"),
                QObject::tr("voici la liste des produits qui riquent de finir.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    {ui->alerteperime->setModel(Etmp.affichere());}
}

void MainWindow::on_pushButton_19_clicked()
{

}
