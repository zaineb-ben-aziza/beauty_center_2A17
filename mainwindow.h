#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employes.h"
#include <QMainWindow>
#include"arduino.h"

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


private:
    Ui::MainWindow *ui;
    //Employes E;
    QStringList files;
    conge C;//ajout d'un attribut de la classe mainwindow pour pouvoir faire appel a la methode supprimer
    Arduino A;
};

#endif // MAINWINDOW_H
