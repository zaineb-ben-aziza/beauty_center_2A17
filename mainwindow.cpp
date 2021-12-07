#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QIntValidator>
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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



void MainWindow::on_pb_arduino_clicked()
{
QSqlQuery query;
int nbr = 0;
query.prepare("SELECT nombre_produit FROM gc_produit WHERE nom_produit = ?");
query.addBindValue(ui->le_arduino->text());
query.exec();

if (query.next()) {
    nbr = query.value(0).toInt();
    qDebug()<<nbr;
}
if(nbr<10)
    {
         A.write_to_arduino(("1"));
    }
   else if(nbr>=10)
    {
         A.write_to_arduino(("0"));
    }
}
