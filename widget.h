#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QComboBox>
#include <QLabel>
#include <QList>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = 0);
  ~Widget();

private:
  const QStringList buf1 = QStringList()<<"4800"<<"9600"<<"15200";
  const QStringList buf2 = QStringList()<<"Data8"<<"Data16";
  const QStringList buf3 = QStringList()<<"有"<<"无";
  const QStringList buf4 = QStringList()<<"有"<<"无";

  QSerialPort *serial;
  QComboBox   *comboBox;
  QComboBox   *comboBox1;
  QComboBox   *comboBox2;
  QComboBox   *comboBox3;
  QComboBox   *comboBox4;
  QLabel      *label;
  QLabel      *label1;
  QLabel      *label2;
  QLabel      *label3;
  QLabel      *label4;

  QLineEdit   *lineedit;

  QPushButton *pButton1;
  QPushButton *pButton2;
  QPushButton *pButton3;

  QTextBrowser *tBrowser;

  void serialInit();
private slots:
  void serialRead();
  void serialtest();
  void serialtest1();
};

#endif // WIDGET_H
