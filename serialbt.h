#ifndef SERIALBT_H
#define SERIALBT_H


#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

class SerialBT: public QSerialPort
{
Q_OBJECT

public:
    SerialBT();

    void open_serial(QString necessaryPort);
    void writeData(const QByteArray &data);
    QByteArray readData();

    void close_serial();

    ~SerialBT();
};

#endif // SERIALBT_H
