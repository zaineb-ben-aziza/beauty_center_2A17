#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "offre.h"
#include "historique.h"
#include "bons_de_reduction.h"
#include "liste_anniversaire.h"
#include "arduino.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pb_supprimer_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_envoyer_clicked();

    void on_pushButton_9_clicked();

    void on_le_recherche_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::MainWindow *ui;
   Offre O;
   Historique H ;
   bons_de_reduction B;
   liste_anniversaire L;
   QByteArray data; // variable contenant les données reçues

  Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
