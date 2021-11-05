#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
#include <QDialog>
#include <QObject>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_c_clicked();

    void on_pushButton_supprimer_c_clicked();

    void on_pushButton_rafraichir_clicked();

    void on_pushButton_rafraichir_c_clicked();

    void on_pushButton_modifier_c_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_quitter_clicked();

    void on_pushButton_quitter_clicked();

private:
    Ui::MainWindow *ui;
    client tmp;
};
#endif // MAINWINDOW_H
