#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employes.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    Employes E; //ajout d'un attribut de la classe mainwindow pour pouvoir faire appel a la methode supprimer
};

#endif // MAINWINDOW_H
