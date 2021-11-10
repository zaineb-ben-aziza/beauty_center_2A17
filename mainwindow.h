#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_tableView_6_clicked(const QModelIndex &index);

    void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
