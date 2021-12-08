#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employes.h"
#include <QMainWindow>
#include"arduino.h"
#include "produit.h"
#include "fournisseur.h"
#include "arduino.h"

#include"conge.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //les boutons de zeineb
    void on_pb_supprimer_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_aj_clicked();

    void on_pb_mod_clicked();

    void on_pb_supp_clicked();

    void on_pb_pdf_clicked();

    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


      void mailSent(QString status);
       void  sendMail();

    void on_pb_rechercher_clicked();

    void on_browseBtn_clicked();

    void on_sendBtn_clicked();
//les boutons de achref

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pushButton_13_clicked();


    void on_pdf_pb_clicked();

    void on_pushButton_achrefajoutalerte_clicked();


    void on_pushButton_20_clicked();

    void on_pushButton_15_clicked();

    void on_plus_clicked();

    void on_moins_clicked();

    void on_fois_clicked();

    void on_sur_clicked();
    void on_butajoutp_clicked();

    void on_butaffichep_clicked();

    void on_butsuppp_clicked();


    //void on_tablele_clicked(const QModelIndex &index);

    void on_tableView_5_clicked(const QModelIndex &index);


    void on_ajoutcheque_clicked();

    void on_affichercheque_clicked();
     void on_suppcheque_clicked();


    void on_achrefrech_clicked();





    void on_tablecheque_3_clicked(const QModelIndex &index);


    void on_buttri_clicked();
    void on_pushButton_34_clicked();

    void on_statbut_clicked();

    void on_moddifiecheque_clicked();
    //achref

//arduino zeineb

       void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
       // ce slot est lancé à chaque réception d'un message de Arduino
       void on_pushButton_5_clicked();

       void on_butmodifierp_clicked();

       void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    //Employes E;
    QStringList files;
    conge C;//ajout d'un attribut de la classe mainwindow pour pouvoir faire appel a la methode supprimer
    //partie achref
    Produit P;
    fournisseur f;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
