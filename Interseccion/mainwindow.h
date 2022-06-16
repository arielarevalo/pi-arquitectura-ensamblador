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
    void ronda0Verde();

    void ronda0Amarillo();

    void ronda0Rojo();

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

    void on_btnPeatonal1B_clicked();

    void on_btnPeatonal1A_clicked();

    void on_btnPeatonal2A_clicked();

    void on_btnPeatonal2B_clicked();

    void on_btnPeatonal3A_clicked();

    void on_btnPeatonal3B_clicked();

    void on_btnPeatonal4B_clicked();

    void on_btnPeatonal4A_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
