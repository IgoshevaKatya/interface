#include "serialbt.h"
#include "mainwindow.h"

SerialBT::SerialBT()
{
}

void SerialBT::open_serial(QString necessaryPort)
{
    QString PortName = "";
    QSerialPortInfo *info = new QSerialPortInfo();
    foreach (*info, QSerialPortInfo::availablePorts()) {
           qDebug() << "Name : " << info->portName();
           qDebug() << "Description : " << info->description();
           qDebug() << "Manufacturer: " << info->manufacturer();
           if (info->portName() == necessaryPort){
//           //if (info->description() == "Bluetooth Serial Port") {
               PortName = necessaryPort;
               qDebug() << PortName;
               break;
           }
    }

    this->setPortName(PortName);
    this->setBaudRate(QSerialPort::Baud57600);
    //this->setBaudRate(QSerialPort::Baud115200);
    this->setDataBits(QSerialPort::Data8);
    this->setParity(QSerialPort::NoParity);
    this->setStopBits(QSerialPort::OneStop);
    this->setFlowControl(QSerialPort::NoFlowControl);

    if (this->open(QIODevice::ReadWrite)) {
        qDebug() << "Open serial" << PortName;
        QMessageBox msgbox;
        msgbox.QDialog::setWindowTitle("Макет");
        msgbox.setText(PortName + " порт открыт");
        //msgbox.exec();
    } else {
        qDebug() << "Serial busy" << PortName;
        QMessageBox msgbox;
        msgbox.QDialog::setWindowTitle("Макет");
        msgbox.setText(PortName + " порт занят");
        //msgbox.exec();
    }
}

void SerialBT::writeData(const QByteArray &data)
{
    if (this->isOpen())
        this->write(data);
}

QByteArray SerialBT::readData()
{
    QByteArray data = 0;
    if (this->isOpen())
        data = this->readAll();

    return data;
}

void SerialBT::close_serial()
{
    if (this->isOpen()) {
        qDebug() << "Close " << this->portName();
        this->close();

        QMessageBox msgbox;
        msgbox.QDialog::setWindowTitle("Макет");
        msgbox.setText(this->portName() + " порт закрыт");
        //msgbox.exec();
    } else {
        QMessageBox msgbox;
        msgbox.QDialog::setWindowTitle("Макет");
        msgbox.setText(this->portName() + " порт не открыт");
        //msgbox.exec();
    }
}

SerialBT::~SerialBT()
{
   this->close();
}
