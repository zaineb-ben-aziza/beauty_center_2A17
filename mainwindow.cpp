#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "service.h"
#include "QMessageBox"
service Sg;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_6->setModel(Sg.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_7_clicked()
{
    QString nom = ui->lineEdit_25->text();
    int id = ui->lineEdit_26->text().toInt();
    int prix = ui->lineEdit_27->text().toInt();

    service S(id,nom,prix);
    bool test = S.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                    QObject::tr("service ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView_6->setModel(Sg.afficher());

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("problème d'ajout.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_11_clicked()
{
    int id = ui->lineEdit_28->text().toInt();
    bool test = Sg.supprimer(id);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("suppression"),
                    QObject::tr("service supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView_6->setModel(Sg.afficher());

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("problème de suppression.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_tableView_6_clicked(const QModelIndex &index)
{
    QString id=ui->tableView_6->model()->data(ui->tableView_6->model()->index(index.row(),1)).toString();
    ui -> lineEdit_29->setText(id);
}

void MainWindow::on_pushButton_14_clicked()
{
    QString nom = ui->lineEdit_30->text();
    int id = ui->lineEdit_29->text().toInt();
    int prix = ui->lineEdit_31->text().toInt();

    service S(id,nom,prix);
    bool test = S.modifier();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modification"),
                    QObject::tr("service modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView_6->setModel(Sg.afficher());

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("problème de modification.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
