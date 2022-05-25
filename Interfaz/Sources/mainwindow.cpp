#include "Headers/mainwindow.h"
#include "Headers/ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!Rondas Transito!*/

/*!Ronda 1 de transito - Verde!*/
void MainWindow::ronda1Verde()
{
    /*! Arriba del croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);

    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVN.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/SurVerde.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/NorteVerde.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);

    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVN.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);
}

/*!Ronda 1 de transito - Amarillo!*/
void MainWindow::ronda1Amarillo()
{
    /*! Arriba del croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);

    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/SurAmarillo.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/NorteAmarillo.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);

    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);
}

/*!Ronda 1 de transito - Rojo!*/
void MainWindow::ronda1Rojo()
{
    /*! Arriba del croquis!*/
    ui->Sur1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur1->setTextFormat(Qt::RichText);
    ui->Sur2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur2->setTextFormat(Qt::RichText);

    ui->Norte1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte1->setTextFormat(Qt::RichText);
    ui->Norte2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte2->setTextFormat(Qt::RichText);

    ui->SV1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVN.png'/></p></body></html>"));
    ui->SV1A->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->Sur3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur3->setTextFormat(Qt::RichText);
    ui->Sur4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/SurRojo.png'/></p></body></html>"));
    ui->Sur4->setTextFormat(Qt::RichText);

    ui->Norte3->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte3->setTextFormat(Qt::RichText);
    ui->Norte4->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/NorteRojo.png'/></p></body></html>"));
    ui->Norte4->setTextFormat(Qt::RichText);

    ui->SV1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVN.png'/></p></body></html>"));
    ui->SV1B->setTextFormat(Qt::RichText);
}

/*!Ronda 2 de transito - Verde!*/
void MainWindow::ronda2Verde()
{
    /*! Derecha del croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteVerde.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteVerde.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeHO.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);

    /*! Izquierda del croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/EsteVerde.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/OesteVerde.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeHE.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);
}

/*!Ronda 2 de transito - Amarillo!*/
void MainWindow::ronda2Amarillo()
{
    /*! Derecha del croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteAmarillo.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteAmarillo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloH.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);


    /*! Izquierda del croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/EsteAmarillo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/OesteAmarillo.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloH.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);

}

/*!Ronda 2 de transito - Rojo!*/
void MainWindow::ronda2Rojo()
{
    /*! Derecha del croquis!*/
    ui->Este1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteRojo.png'/></p></body></html>"));
    ui->Este1->setTextFormat(Qt::RichText);
    ui->Oeste1->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteRojo.png'/></p></body></html>"));
    ui->Oeste1->setTextFormat(Qt::RichText);

    ui->SV2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoHO.png'/></p></body></html>"));
    ui->SV2A->setTextFormat(Qt::RichText);

    /*! Izquierda del croquis!*/
    ui->Este2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/EsteRojo.png'/></p></body></html>"));
    ui->Este2->setTextFormat(Qt::RichText);
    ui->Oeste2->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/OesteRojo.png'/></p></body></html>"));
    ui->Oeste2->setTextFormat(Qt::RichText);

    ui->SV2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoHE.png'/></p></body></html>"));
    ui->SV2B->setTextFormat(Qt::RichText);
}

/*!Ronda 3 de transito - Verde!*/
void MainWindow::ronda3Verde()
{
    /*! Arriba del croquis!*/
    ui->IzqSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/IzqSurVerde.png'/></p></body></html>"));
    ui->IzqSur->setTextFormat(Qt::RichText);

    ui->SV3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVN.png'/></p></body></html>"));
    ui->SV3A->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->IzqNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/IzqNorteVerde.png'/></p></body></html>"));
    ui->IzqNorte->setTextFormat(Qt::RichText);

    ui->SV3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularVerde/Vehiculares/VerdeVS.png'/></p></body></html>"));
    ui->SV3B->setTextFormat(Qt::RichText);
}

/*!Ronda 3 de transito - Amarillo!*/
void MainWindow::ronda3Amarillo()
{
    /*! Arriba del croquis!*/
    ui->IzqSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/IzqSurAmarillo.png'/></p></body></html>"));
    ui->IzqSur->setTextFormat(Qt::RichText);

    ui->SV3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV3A->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->IzqNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/IzqNorteAmarillo.png'/></p></body></html>"));
    ui->IzqNorte->setTextFormat(Qt::RichText);

    ui->SV3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularAmarillo/Vehiculares/AmarilloV.png'/></p></body></html>"));
    ui->SV3B->setTextFormat(Qt::RichText);
}

/*!Ronda 3 de transito - Rojo!*/
void MainWindow::ronda3Rojo()
{
    /*! Arriba del croquis!*/
    ui->IzqSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/IzqSurRojo.png'/></p></body></html>"));
    ui->IzqSur->setTextFormat(Qt::RichText);

    ui->SV3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVN.png'/></p></body></html>"));
    ui->SV3A->setTextFormat(Qt::RichText);

    /*! Abajo del croquis!*/
    ui->IzqNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/IzqNorteRojo.png'/></p></body></html>"));
    ui->IzqNorte->setTextFormat(Qt::RichText);

    ui->SV3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/VehicularRojo/Vehiculares/RojoVS.png'/></p></body></html>"));
    ui->SV3B->setTextFormat(Qt::RichText);
}

/*! Fin de rondas transito!*/

/*!Rondas Peatonales!*/

/*!Ronda 4 de Peatonal - Verde!*/
void MainWindow::ronda4Verde()
{
    ui->PTNorte->setTextFormat(Qt::RichText);
    ui->PTNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/Verde.png'/></p></body></html>"));
    ui->SP1A->setTextFormat(Qt::RichText);
    ui->SP1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP1B->setTextFormat(Qt::RichText);
    ui->SP1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));

    ronda2Verde();
}

/*!Ronda 4 de Peatonal - Amarillo!*/
void MainWindow::ronda4Amarillo()
{
    ui->PTNorte->setTextFormat(Qt::RichText);
    ui->PTNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->SP1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1A->setTextFormat(Qt::RichText);
    ui->SP1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1B->setTextFormat(Qt::RichText);

    ronda2Amarillo();
}

/*!Ronda 4 de Peatonal - Verde!*/
void MainWindow::ronda4Rojo()
{
    ui->PTNorte->setTextFormat(Qt::RichText);
    ui->PTNorte->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->SP1A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1A->setTextFormat(Qt::RichText);
    ui->SP1B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP1B->setTextFormat(Qt::RichText);

    ronda2Rojo();
}

/*!Ronda 5 de Peatonal - Verde!*/
void MainWindow::ronda5Verde()
{
    ui->PTOeste->setTextFormat(Qt::RichText);
    ui->PTOeste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/VerdeVertical.png'/></p></body></html>"));
    ui->SP2A->setTextFormat(Qt::RichText);
    ui->SP2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP2B->setTextFormat(Qt::RichText);
    ui->SP2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));

    ronda1Verde();
}

/*!Ronda 5 de Peatonal - Amarillo!*/
void MainWindow::ronda5Amarillo()
{
    ui->PTOeste->setTextFormat(Qt::RichText);
    ui->PTOeste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->SP2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2A->setTextFormat(Qt::RichText);
    ui->SP2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2B->setTextFormat(Qt::RichText);

    ronda1Amarillo();
}

/*!Ronda 5 de Peatonal - Rojo!*/
void MainWindow::ronda5Rojo()
{
    ui->PTOeste->setTextFormat(Qt::RichText);
    ui->PTOeste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->SP2A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2A->setTextFormat(Qt::RichText);
    ui->SP2B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP2B->setTextFormat(Qt::RichText);

    ronda1Rojo();
}

/*!Ronda 6 de Peatona - Verde!*/
void MainWindow::ronda6Verde()
{
    ui->PTSur->setTextFormat(Qt::RichText);
    ui->PTSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/Verde.png'/></p></body></html>"));
    ui->SP3A->setTextFormat(Qt::RichText);
    ui->SP3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP3B->setTextFormat(Qt::RichText);
    ui->SP3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));

    ronda2Verde();
}

/*!Ronda 6 de Peatona - Amarillo!*/
void MainWindow::ronda6Amarillo()
{
    ui->PTSur->setTextFormat(Qt::RichText);
    ui->PTSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->SP3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3A->setTextFormat(Qt::RichText);
    ui->SP3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3B->setTextFormat(Qt::RichText);

    ronda2Amarillo();
}

/*!Ronda 6 de Peatona - Rojo!*/
void MainWindow::ronda6Rojo()
{
    ui->PTSur->setTextFormat(Qt::RichText);
    ui->PTSur->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/Rojo.png'/></p></body></html>"));
    ui->SP3A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3A->setTextFormat(Qt::RichText);
    ui->SP3B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP3B->setTextFormat(Qt::RichText);

    ronda2Rojo();
}

/*!Ronda 7 de Peatona - Verde!*/
void MainWindow::ronda7Verde()
{
    ui->PTEste->setTextFormat(Qt::RichText);
    ui->PTEste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/VerdeVertical.png'/></p></body></html>"));
    ui->SP4A->setTextFormat(Qt::RichText);
    ui->SP4A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));
    ui->SP4B->setTextFormat(Qt::RichText);
    ui->SP4B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalVerde/Peatonales/SV.png'/></p></body></html>"));

    ronda1Verde();
}

/*!Ronda 7 de Peatona - Amarillo!*/
void MainWindow::ronda7Amarillo()
{
    ui->PTEste->setTextFormat(Qt::RichText);
    ui->PTEste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->SP4A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4A->setTextFormat(Qt::RichText);
    ui->SP4B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4B->setTextFormat(Qt::RichText);

    ronda1Amarillo();
}

/*!Ronda 7 de Peatona - Rojo!*/
void MainWindow::ronda7Rojo()
{

    ui->PTEste->setTextFormat(Qt::RichText);
    ui->PTEste->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/RojoVertical.png'/></p></body></html>"));
    ui->SP4A->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4A->setTextFormat(Qt::RichText);
    ui->SP4B->setText(QString::fromUtf8("<html><head/><body><p><img src=':/PeatonalRojo/Peatonales/SR.png'/></p></body></html>"));
    ui->SP4B->setTextFormat(Qt::RichText);

    ronda1Rojo();
}

/*! Fin de rondas peatonales!*/

/*! Inicio funcionalidad botones!*/

/*! Botones Peatonales !*/

/*!Boton Peatonal Norte - Verde!*/
void MainWindow::on_pushButton_clicked()
{
    ronda4Verde();
}

/*!Boton Peatonal Norte - Amarillo!*/
void MainWindow::on_pushButton_18_clicked()
{
    ronda4Amarillo();
}

/*!Boton Peatonal Norte - Rojo!*/
void MainWindow::on_pushButton_2_clicked()
{
    ronda4Rojo();
}


/*!Boton Peatonal Oeste - Verde!*/
void MainWindow::on_pushButton_4_clicked()
{
    ronda5Verde();
}

/*!Boton Peatonal Oeste - Verde!*/
void MainWindow::on_pushButton_19_clicked()
{
    ronda5Amarillo();
}

/*!Boton Peatonal Oeste - Rojo!*/
void MainWindow::on_pushButton_5_clicked()
{
    ronda5Rojo();
}


/*!Boton Peatonal Sur - Verde!*/
void MainWindow::on_pushButton_6_clicked()
{
    ronda6Verde();
}

/*!Boton Peatonal Sur - Rojo!*/
void MainWindow::on_pushButton_20_clicked()
{
    ronda6Amarillo();
}

/*!Boton Peatonal Sur - Rojo!*/
void MainWindow::on_pushButton_7_clicked()
{
ronda6Rojo();
}


/*!Boton Peatonal Este - Verde!*/
void MainWindow::on_pushButton_8_clicked()
{
    ronda7Verde();
}

/*!Boton Peatonal Este - Amarillo!*/
void MainWindow::on_pushButton_21_clicked()
{
    ronda7Amarillo();
}

/*!Boton Peatonal Este - Rojo!*/
void MainWindow::on_pushButton_9_clicked()
{
    ronda7Rojo();
}

/*! Fin Botones Peatonales !*/

/*! Inicio Botones Vehiculares!*/

/*!Boton para Ronda 1 - Verde!*/
void MainWindow::on_pushButton_3_clicked()
{
    ronda1Verde();
}

/*!Boton para Ronda 1 - Amarillo!*/
void MainWindow::on_pushButton_10_clicked()
{
    ronda1Amarillo();
}

/*!Boton para Ronda 1 - Rojo!*/
void MainWindow::on_pushButton_11_clicked()
{
    ronda1Rojo();
}

/*!Boton para Ronda 2 - Verde!*/
void MainWindow::on_pushButton_12_clicked()
{
    ronda2Verde();
}

/*!Boton para Ronda 2 - Amarillo!*/
void MainWindow::on_pushButton_13_clicked()
{
    ronda2Amarillo();
}

/*!Boton para Ronda 2 - Rojo!*/
void MainWindow::on_pushButton_14_clicked()
{
    ronda2Rojo();
}

/*!Boton para Ronda 3 - Verde!*/
void MainWindow::on_pushButton_15_clicked()
{
    ronda3Verde();
}

/*!Boton para Ronda 3 - Amarillo!*/
void MainWindow::on_pushButton_16_clicked()
{
    ronda3Amarillo();
}

/*!Boton para Ronda 3 - Rojo!*/
void MainWindow::on_pushButton_17_clicked()
{
    ronda3Rojo();
}

/*! Fin Botones Vehiculares!*/
