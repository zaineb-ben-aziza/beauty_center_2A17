#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "produit.h"
#include "fournisseur.h"
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


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pdf_pb_clicked();

    void on_pb_arduino_clicked();

private:
    Ui::MainWindow *ui;
    Produit P;
    fournisseur f;
    Arduino A;
};

#endif // MAINWINDOW_H
