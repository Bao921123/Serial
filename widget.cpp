#include "widget.h"
#include <QGridLayout>
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{
  comboBox   = new QComboBox;

  comboBox1  = new QComboBox;
  comboBox1->addItems(buf1);
  comboBox2  = new QComboBox;
  comboBox2->addItems(buf2);
  comboBox3  = new QComboBox;
  comboBox3->addItems(buf3);
  comboBox4  = new QComboBox;
  comboBox4->addItems(buf4);

  label      = new QLabel;
  label->setText(tr("正在等待"));
  label1      = new QLabel;
  label1->setText(tr("波特率"));
  label2      = new QLabel;
  label2->setText(tr("数据位"));
  label3      = new QLabel;
  label3->setText(tr("奇偶校验"));
  label4      = new QLabel;
  label4->setText(tr("停止位"));

  serial     = new QSerialPort;

  lineedit   = new QLineEdit;

  pButton1   = new QPushButton;
  pButton1 ->setText(tr("发送"));
  pButton2   = new QPushButton;
  pButton2 ->setText(tr("链接"));
  pButton3   = new QPushButton;
  pButton3 ->setText(tr("断开"));

  tBrowser = new QTextBrowser;

  QGridLayout *layout = new QGridLayout();
  layout->addWidget(comboBox,0,0);
  layout->addWidget(label,0,1);
  layout->addWidget(label1,1,0);
  layout->addWidget(comboBox1,1,1);
  layout->addWidget(label2,2,0);
  layout->addWidget(comboBox2,2,1);
  layout->addWidget(label3,3,0);
  layout->addWidget(comboBox3,3,1);
  layout->addWidget(label4,4,0);
  layout->addWidget(comboBox4,4,1);
  layout->addWidget(pButton2,5,0);
  layout->addWidget(pButton3,5,1);
  layout->addWidget(lineedit,6,0);
  layout->addWidget(pButton1,6,1);
  layout->setColumnStretch(0,1);
  layout->setColumnStretch(1,1);

  QHBoxLayout *layout1 = new QHBoxLayout(this);
  layout1->addLayout(layout);
  layout1->addWidget(tBrowser);

  connect(pButton1,SIGNAL(clicked()),this,SLOT(serialRead()));
  connect(pButton2,SIGNAL(clicked()),this,SLOT(serialtest()));
  connect(pButton3,SIGNAL(clicked()),this,SLOT(serialtest1()));

  serialInit();
}

Widget::~Widget()
{

}

void Widget::serialInit()
{
  pButton1->setEnabled(false);
  connect(serial,SIGNAL(readyRead()),this,SLOT(serialRead()));

  QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
  if(infos.isEmpty())
    {
      label->setText(tr("没有可使用的串口"));
      return;
    }
  foreach (QSerialPortInfo info, infos) {
      comboBox->addItem(info.portName());
      qDebug() << info.portName();
      label->setText(tr("可用端口号"));
    }
}

void Widget::serialRead()
{
  tBrowser->setText(lineedit->text());
}

void Widget::serialtest()
{
  label->setText(tr("已连接"));
  comboBox->setEnabled(false);
  comboBox1->setEnabled(false);
  comboBox2->setEnabled(false);
  comboBox3->setEnabled(false);
  comboBox4->setEnabled(false);
  pButton1->setEnabled(true);
}

void Widget::serialtest1()
{
  label->setText(tr("可用端口号"));
  comboBox->setEnabled (true);
  comboBox1->setEnabled(true);
  comboBox2->setEnabled(true);
  comboBox3->setEnabled(true);
  comboBox4->setEnabled(true);
  pButton1->setEnabled(false);
}
