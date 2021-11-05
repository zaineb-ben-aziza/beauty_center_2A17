#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_c_clicked()
{
    client c;
        int id_c = ui->lineEdit_id_c->text().toInt();
        int cin_c= ui->lineEdit_cin_c->text().toInt();
        QString nom_c= ui->lineEdit_nom_c->text();
        QString prenom_c= ui->lineEdit_prenom_c->text();
        int tel_c= ui->lineEdit_tel_c->text().toInt();
        QString adresse_c= ui->lineEdit_adresse_c->text();

      client C (id_c,cin_c,nom_c,prenom_c,tel_c,adresse_c);
      bool test=C.ajouter();

      if(test)
    {
          ui->tableView->setModel(tmp.afficher());//refresh
          QMessageBox msgBox ;
   QMessageBox::information(this,"information","client ajouté");
               ui->lineEdit_id_c->setText("");
               ui->lineEdit_cin_c->setText("");
               ui->lineEdit_nom_c->setText("");
               ui->lineEdit_prenom_c->setText("");
               ui->lineEdit_tel_c->setText("");
               ui->lineEdit_adresse_c->setText("");
  }

  else

  {
  QMessageBox msgBox ;
    msgBox.setText("client non ajouté ");
    //msgBox.exec();
  }
}


void MainWindow::on_pushButton_supprimer_c_clicked()
{
    int id_c = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=tmp.supprimer(id_c);
    if(test)
    {
        ui->tableView->setModel(tmp.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","client supprimé");
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("client non Supprimer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_rafraichir_clicked()
{
     ui->tableView->setModel(tmp.afficher());
}


void MainWindow::on_pushButton_rafraichir_c_clicked()
{
    ui->lineEdit_id_c->setText("");
    ui->lineEdit_cin_c->setText("");
    ui->lineEdit_nom_c->setText("");
    ui->lineEdit_prenom_c->setText("");
    ui->lineEdit_tel_c->setText("");
    ui->lineEdit_adresse_c->setText("");
}


void MainWindow::on_pushButton_modifier_c_clicked()
{
    int id_c = ui->lineEdit_id_c->text().toInt();
    int cin_c= ui->lineEdit_cin_c->text().toInt();
    QString nom_c= ui->lineEdit_nom_c->text();
    QString prenom_c= ui->lineEdit_prenom_c->text();
    int tel_c= ui->lineEdit_tel_c->text().toInt();
    QString adresse_c= ui->lineEdit_adresse_c->text();




          bool test=tmp.modifier(id_c, cin_c, nom_c, prenom_c, tel_c, adresse_c);
             if (test)
             {
                  ui->tableView->setModel(tmp.afficher());
                  QMessageBox msgBox ;
           QMessageBox::information(this,"information","client bien Modifié");
                       ui->lineEdit_id_c->setText("");
                       ui->lineEdit_cin_c->setText("");
                       ui->lineEdit_nom_c->setText("");
                       ui->lineEdit_prenom_c->setText("");
                       ui->lineEdit_tel_c->setText("");
                       ui->lineEdit_adresse_c->setText("");

                }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    ui->lineEdit_id_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->lineEdit_cin_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->lineEdit_nom_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->lineEdit_prenom_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
    ui->lineEdit_tel_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->lineEdit_adresse_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString());

}


void MainWindow::on_pushButton_2_quitter_clicked()
{
    close();
}


void MainWindow::on_pushButton_quitter_clicked()
{
    close();
}


