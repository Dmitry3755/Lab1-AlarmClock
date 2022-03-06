#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

     QTimer *timer = new QTimer();
     QTime clock = QTime::currentTime();
     QString text = clock.toString("hh:mm:ss");

     ui->lcdNumber->display(text);
     QObject::connect(timer,SIGNAL(timeout()), this, SLOT(eventTimer()));
     timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::eventTimer()
{
    QTime clock = QTime::currentTime();
    ui->lcdNumber->display(clock.toString("hh:mm:ss"));

    if((ui->alarmValueLabel->text() == clock.toString("hh:mm"))&&(ui->checkBox->isChecked()))
    {
       ui->alarmWentOffLabel->setText("Подъём!");
       ui->checkBox->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->alarmValueLabel->setText(ui->alarmEdit->dateTime().toString("hh:mm"));
    ui->checkBox->setCheckState(Qt::Checked);
}
