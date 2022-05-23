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
    void ronda1Verde();

    void ronda1Amarillo();

    void ronda1Rojo();

    void ronda2Verde();

    void ronda2Amarillo();

    void ronda2Rojo();

    void ronda3Verde();

    void ronda3Amarillo();

    void ronda3Rojo();

    void ronda4Verde();

    void ronda4Amarillo();

    void ronda4Rojo();

    void ronda5Verde();

    void ronda5Amarillo();

    void ronda5Rojo();

    void ronda6Verde();

    void ronda6Amarillo();

    void ronda6Rojo();

    void ronda7Verde();

    void ronda7Amarillo();

    void ronda7Rojo();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
