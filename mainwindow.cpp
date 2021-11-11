#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QIntValidator>
#include <QMessageBox>
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
        ui->tab_produit->setModel(P.afficher());
        msgBox.setText("Suppression avec succes!");
    }
    else
    {
        msgBox.setText("Echec de suppression");
    }
    msgBox.exec();
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
