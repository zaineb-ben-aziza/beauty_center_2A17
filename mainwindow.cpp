#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QTextStream>
#include <QFileDialog>
#include <QPrinter>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmp.afficher());
    ui->tableView_2->setModel(tmprdv.afficher());
    ui->tableView_3->setModel(tmp.stat());
    QValidator *validator = new QIntValidator(100000, 999999, this);
    ui->lineEdit_id_c->setValidator(validator);
    QValidator *validator1 = new QIntValidator(10000000, 99999999, this);
    ui->lineEdit_cin_c->setValidator(validator1);
    ui->lineEdit_tel_c->setValidator(validator1);;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_c_clicked()
{

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
                  QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                     notifier->setIcon(QIcon(""));
                                      notifier->show();
                                      notifier->showMessage("Client modifié","Reussi",QSystemTrayIcon::Information,10000);
                       ui->lineEdit_id_c->setText("");
                       ui->lineEdit_cin_c->setText("");
                       ui->lineEdit_nom_c->setText("");
                       ui->lineEdit_prenom_c->setText("");
                       ui->lineEdit_tel_c->setText("");
                       ui->lineEdit_adresse_c->setText("");

                }else
             {
                 QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                    notifier->setIcon(QIcon(""));
                                     notifier->show();
                                     notifier->showMessage("Client non modifié","Echec",QSystemTrayIcon::Critical,10000);
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



void MainWindow::on_pushButton_ajouter_c_2_clicked()
{

        int id_c = ui->lineEdit_id_c_2->text().toInt();
        QValidator *validator = new QIntValidator(100000, 999999, this);
        ui->lineEdit_id_c_2->setValidator(validator);
        int ref= ui->lineEdit_ref->text().toInt();
        QString service= ui->lineEdit_service->text();
        QString dater= ui->dateEdit->text();

      RDV r(ref,id_c,dater,service);
      bool test=r.ajouter();

      if(test)
    {
          ui->tableView_2->setModel(tmprdv.afficher());//refresh
          QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                             notifier->setIcon(QIcon(""));
                              notifier->show();
                              notifier->showMessage("RDV ajouté","Reussi",QSystemTrayIcon::Information,10000);
               ui->lineEdit_id_c_2->setText("");
               ui->lineEdit_ref->setText("");
               ui->lineEdit_service->setText("");
  }

  else

  {
          QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                             notifier->setIcon(QIcon(""));
                              notifier->show();
                              notifier->showMessage("RDV non ajouté","Echec",QSystemTrayIcon::Critical,10000);
  }
}

void MainWindow::on_pushButton_modifier_c_2_clicked()
{
    int id_c = ui->lineEdit_id_c_2->text().toInt();
    int ref= ui->lineEdit_ref->text().toInt();
    QString service= ui->lineEdit_service->text();
    QString dater= ui->dateEdit->text();


  bool test=tmprdv.modifier(ref,id_c,dater,service);

  if(test)
{
      ui->tableView_2->setModel(tmprdv.afficher());//refresh
      QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                         notifier->setIcon(QIcon(""));
                          notifier->show();
                          notifier->showMessage("RDV modifié","Reussi",QSystemTrayIcon::Information,10000);
           ui->lineEdit_id_c_2->setText("");
           ui->lineEdit_ref->setText("");
           ui->lineEdit_service->setText("");
}

else

{
      QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                         notifier->setIcon(QIcon(""));
                          notifier->show();
                          notifier->showMessage("RDV non modifié","Echec",QSystemTrayIcon::Critical,10000);
}
}

void MainWindow::on_pushButton_supprimer_c_2_clicked()
{
    int ref = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),3)).toInt();
    bool test=tmprdv.supprimer(ref);
    if(test)
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                           notifier->setIcon(QIcon(""));
                            notifier->show();
                            notifier->showMessage("RDV supprimé","Reussi",QSystemTrayIcon::Information,10000);
    }

    else
    {
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                           notifier->setIcon(QIcon(""));
                            notifier->show();
                            notifier->showMessage("RDV non supprimé","Echec",QSystemTrayIcon::Critical,10000);
    }
}

void MainWindow::on_pushButton_rafraichir_2_clicked()
{
    ui->tableView_2->setModel(tmprdv.afficher());
}

void MainWindow::on_pushButton_2_quitter_2_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    tmp.ajouterRec(ui->reclamation->toPlainText());
    ui->reclamation->setPlainText("");
}

void MainWindow::on_pushButton_2_clicked()
{
 ui->tableView->setModel(tmp.afficherTri(ui->comboBoxTri->currentText()));
}

void MainWindow::on_pushButton_3_clicked()
{
ui->tableView_2->setModel(tmprdv.afficherRech(ui->comboBoxRech->currentText(),ui->Rech->text()));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tableView_3->model()->rowCount();
                        const int columnCount = ui->tableView_3->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Rapport de visite</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tableView_3->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tableView_3->isColumnHidden(column)) {
                                                QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);
                               printer.setPaperSize(QPrinter::A4);
                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);
                                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                doc.print(&printer);
}

void MainWindow::on_pushButton_5_clicked()
{
     int id_c = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
     tmp.fidelite(id_c);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView->setModel(tmprdv.afficher());
}
