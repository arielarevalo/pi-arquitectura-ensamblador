#include "Sources/Headers/mainwindow.h"
#include "Sources/Headers/ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cambio(int ruta)
{
    switch (ruta) {
    case 0:
        switch (fase) {
        case 0:
            ronda0Verde();
            break;
        case 1:
            ronda0Amarillo();
            break;
        case 2:
            ronda0Rojo();
            break;
        }
        break;
    case 1:
        switch (fase) {
        case 0:
            ronda1Verde();
            break;
        case 1:
            ronda1Amarillo();
            break;
        case 2:
            ronda1Rojo();
            break;
        }
        break;
    case 2:
        switch (fase) {
        case 0:
            ronda2Verde();
            break;
        case 1:
            ronda2Amarillo();
            break;
        case 2:
            ronda2Rojo();
            break;
        }
        break;
    case 3:
        switch (fase) {
        case 0:
            ronda3Verde();
            break;
        case 1:
            ronda3Amarillo();
            break;
        case 2:
            ronda3Rojo();
            break;
        }
        break;
    case 4:
        switch (fase) {
        case 0:
            ronda4Verde();
            break;
        case 1:
            ronda4Amarillo();
            break;
        case 2:
            ronda4Rojo();
            break;
        }
        break;
    case 5:
        switch (fase) {
        case 0:
            ronda5Verde();
            break;
        case 1:
            ronda5Amarillo();
            break;
        case 2:
            ronda5Rojo();
            break;
        }
        break;
    case 6:
        switch (fase) {
        case 0:
            ronda6Verde();
            break;
        case 1:
            ronda6Amarillo();
            break;
        case 2:
            ronda6Rojo();
            break;
        }
        break;
    }
    ++fase %= 3;
}

int MainWindow::getButton()
{
    pressed = false;
    return button;
}

bool MainWindow::isPressed()
{
    return pressed;
}

/*!Rondas Transito!*/

/*!Ronda 0 de transito - Verde!*/
void MainWindow::ronda0Verde()
{
    /*!Flechas!*/

    /*!Arriba croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurDrcVerde.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);
    ui->IzqSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/IzqSurVerde.png'/></p></body></html>"));
    ui->IzqSur->setTextFormat(Qt::RichText);

    /*!Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteVerde.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*!Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteVerde.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVN.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);
    ui->SV3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVN.png'/></p></body></html>"));
    ui->SV3A->setTextFormat(Qt::RichText);

}

/*!Ronda 0 de transito - Amarillo!*/
void MainWindow::ronda0Amarillo()
{
    /*!Flechas!*/

    /*!Arriba croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurDrcAmarillo.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);
    ui->IzqSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/IzqSurAmarillo.png'/></p></body></html>"));
    ui->IzqSur->setTextFormat(Qt::RichText);

    /*!Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteAmarillo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*!Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteAmarillo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);
    ui->SV3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV3A->setTextFormat(Qt::RichText);
}

/*!Ronda 0 de transito - Rojo!*/
void MainWindow::ronda0Rojo()
{
    /*!Flechas!*/
    /*!Arriba croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurDrcRojo.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);
    ui->IzqSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/IzqSurRojo.png'/></p></body></html>"));
    ui->IzqSur->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteRojo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*!Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteRojo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVN.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);
    ui->SV3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVN.png'/></p></body></html>"));
    ui->SV3A->setTextFormat(Qt::RichText);
}

/*!Ronda 1 de transito - Verde!*/
void MainWindow::ronda1Verde()
{
    /*!Flechas!*/
    /*!Izquierda croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteDrcVerde.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteVerde.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteVerde.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteDrcVerde.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    /*!Arriba croquis!*/
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeHO.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);
    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeHE.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);

}

/*!Ronda 1 de transito - Amarillo!*/
void MainWindow::ronda1Amarillo()
{
    /*!Flechas!*/
    /*!Izquierda croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteDrcAmarillo.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteAmarillo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteAmarillo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteDrcAmarillo.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    /*!Arriba croquis!*/
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloH.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);
    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloH.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);
}

/*!Ronda 1 de transito - Rojo!*/
void MainWindow::ronda1Rojo()
{
    /*!Flechas!*/
    /*!Izquierda croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteDrcRojo.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteRojo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteRojo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteDrcRojo.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    /*!Arriba croquis!*/
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoHO.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);
    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoHE.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);
}

/*!Ronda 2 de transito - Verde!*/
void MainWindow::ronda2Verde()
{
    /*!Flechas!*/

    /*!Abajo croquis!*/
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteDrcVerde.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);
    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);
    ui->IzqNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/IzqNorteVerde.png'/></p></body></html>"));
    ui->IzqNorte->setTextFormat(Qt::RichText);

    /*!Arriba croquis!*/
    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteVerde.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteVerde.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVS.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);
    ui->SV3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVS.png'/></p></body></html>"));
    ui->SV3B->setTextFormat(Qt::RichText);
}

/*!Ronda 2 de transito - Amarillo!*/
void MainWindow::ronda2Amarillo()
{
    /*!Flechas!*/

    /*!Abajo croquis!*/
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteDrcAmarillo.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);
    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);
    ui->IzqNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/IzqNorteAmarillo.png'/></p></body></html>"));
    ui->IzqNorte->setTextFormat(Qt::RichText);

    /*!Arriba croquis!*/
    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteAmarillo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteAmarillo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);
    ui->SV3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV3B->setTextFormat(Qt::RichText);

}

/*!Ronda 2 de transito - Rojo!*/
void MainWindow::ronda2Rojo()
{
    /*!Flechas!*/

    /*!Abajo croquis!*/
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteDrcRojo.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);
    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);
    ui->IzqNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/IzqNorteRojo.png'/></p></body></html>"));
    ui->IzqNorte->setTextFormat(Qt::RichText);

    /*!Arriba croquis!*/
    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Derecha croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteRojo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteRojo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVS.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);
    ui->SV3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVS.png'/></p></body></html>"));
    ui->SV3B->setTextFormat(Qt::RichText);
}

/*! Fin de rondas transito!*/

/*!Rondas Peatonales!*/

/*!Ronda 3 peatonal - Verde!*/
void MainWindow::ronda3Verde()
{
    /*! Transito !*/
    /*! Izquierda croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteDrcVerde.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteVerde.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeHO.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/Verde.png'/></p></body></html>"));
    ui->PTNorte->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP1A->setTextFormat(Qt::RichText);
    ui->SP1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP1B->setTextFormat(Qt::RichText);
}

/*!Ronda 3 peatonal - Amarillo!*/
void MainWindow::ronda3Amarillo()
{
    /*! Transito !*/
    /*! Izquierda croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteDrcAmarillo.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteAmarillo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloH.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->PTNorte->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1A->setTextFormat(Qt::RichText);
    ui->SP1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1B->setTextFormat(Qt::RichText);
}

/*!Ronda 3 peatonal - Rojo!*/
void MainWindow::ronda3Rojo()
{
    /*! Transito !*/
    /*! Izquierda croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteDrcRojo.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteRojo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoHO.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->PTNorte->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1A->setTextFormat(Qt::RichText);
    ui->SP1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1B->setTextFormat(Qt::RichText);
}

/*!Ronda 4 de Peatonal - Verde!*/
void MainWindow::ronda4Verde()
{
    /*! Transito !*/
    /*! Arriba croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurDrcVerde.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);

    /*! Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    /*! Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteVerde.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVN.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTEste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/VerdeVertical.png'/></p></body></html>"));
    ui->PTEste->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP4A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP4A->setTextFormat(Qt::RichText);
    ui->SP4B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP4B->setTextFormat(Qt::RichText);
}

/*!Ronda 4 de Peatonal - Amarillo!*/
void MainWindow::ronda4Amarillo()
{
    /*! Transito !*/
    /*! Arriba croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurDrcAmarillo.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);

    /*! Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    /*! Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteAmarillo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTEste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->PTEste->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP4A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4A->setTextFormat(Qt::RichText);
    ui->SP4B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4B->setTextFormat(Qt::RichText);
}

/*!Ronda 4 de Peatonal - Verde!*/
void MainWindow::ronda4Rojo()
{
    /*! Transito !*/
    /*! Arriba croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurDrcRojo.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);

    /*! Abajo croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    /*! Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteRojo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVN.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTEste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->PTEste->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP4A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4A->setTextFormat(Qt::RichText);
    ui->SP4B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4B->setTextFormat(Qt::RichText);
}

/*!Ronda 5 de Peatonal - Verde!*/
void MainWindow::ronda5Verde()
{
    /*! Transito !*/
    /*! Derecha croquis!*/
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteDrcVerde.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    /*! Arriba croquis!*/
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*! Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteVerde.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeHE.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/Verde.png'/></p></body></html>"));
    ui->PTSur->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP3A->setTextFormat(Qt::RichText);
    ui->SP3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP3B->setTextFormat(Qt::RichText);
}

/*!Ronda 5 de Peatonal - Amarillo!*/
void MainWindow::ronda5Amarillo()
{
    /*! Transito !*/
    /*! Derecha croquis!*/
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteDrcAmarillo.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    /*! Arriba croquis!*/
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*! Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteAmarillo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloH.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->PTSur->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3A->setTextFormat(Qt::RichText);
    ui->SP3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3B->setTextFormat(Qt::RichText);
}

/*!Ronda 5 de Peatonal - Rojo!*/
void MainWindow::ronda5Rojo()
{
    /*! Transito !*/
    /*! Derecha croquis!*/
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteDrcRojo.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    /*! Arriba croquis!*/
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*! Izquierda croquis!*/
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteRojo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoHE.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->PTSur->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3A->setTextFormat(Qt::RichText);
    ui->SP3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3B->setTextFormat(Qt::RichText);
}

/*!Ronda 6 de Peatona - Verde!*/
void MainWindow::ronda6Verde()
{
    /*! Transito !*/
    /*! Abajo croquis!*/
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteDrcVerde.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);
    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);

    /*! Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteVerde.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*! Arriba croquis!*/
    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVS.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTOeste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/VerdeVertical.png'/></p></body></html>"));
    ui->PTOeste->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP2A->setTextFormat(Qt::RichText);
    ui->SP2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP2B->setTextFormat(Qt::RichText);
}

/*!Ronda 6 de Peatona - Amarillo!*/
void MainWindow::ronda6Amarillo()
{
    /*! Transito !*/
    /*! Abajo croquis!*/
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteDrcAmarillo.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);
    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);

    /*! Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteAmarillo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*! Arriba croquis!*/
    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTOeste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->PTOeste->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2A->setTextFormat(Qt::RichText);
    ui->SP2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2B->setTextFormat(Qt::RichText);
}

/*!Ronda 6 de Peatona - Rojo!*/
void MainWindow::ronda6Rojo()
{
    /*! Transito !*/
    /*! Abajo croquis!*/
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteDrcRojo.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);
    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);

    /*! Derecha croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteRojo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);

    /*! Arriba croquis!*/
    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    /*!Semaforo!*/
    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVS.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);

    /*!Peatonal!*/
    ui->PTOeste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->PTOeste->setTextFormat(Qt::RichText);

    /*!Semaforos!*/
    ui->SP2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2A->setTextFormat(Qt::RichText);
    ui->SP2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2B->setTextFormat(Qt::RichText);
}

/*! Fin de rondas peatonales!*/

/*! Inicio funcionalidad botones de los peatonales!*/

void MainWindow::setButton(int button)
{
    this->button = button;
    pressed = true;
}

/*! Boton Izquierdo Peatonal Arriba!*/
void MainWindow::on_btnPeatonal1A_clicked()
{
    setButton(0);
}

/*! Boton Derecho Peatonal Arriba!*/
void MainWindow::on_btnPeatonal1B_clicked()
{
    setButton(0);
}

/*! Boton Arriba Peatonal Izquierdo!*/
void MainWindow::on_btnPeatonal2A_clicked()
{
    setButton(3);
}

/*! Boton Abajo Peatonal Izquierdo!*/
void MainWindow::on_btnPeatonal2B_clicked()
{
    setButton(3);
}

/*! Boton Izquierdo Peatonal Abajo!*/
void MainWindow::on_btnPeatonal3A_clicked()
{
    setButton(2);
}

/*! Boton Derecho Peatonal Abajo!*/
void MainWindow::on_btnPeatonal3B_clicked()
{
    setButton(2);
}

/*! Boton Arriba Peatonal Derecho!*/
void MainWindow::on_btnPeatonal4A_clicked()
{
    setButton(1);
}

/*! Boton Abajo Peatonal Derecho!*/
void MainWindow::on_btnPeatonal4B_clicked()
{
    setButton(1);
}

/*! Fin Funcionalidad Botones Peatonales!*/