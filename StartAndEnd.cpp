#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "string"
#include "ui_StartAndEnd.h"

StartAndEnd::StartAndEnd(QWidget *parent) :
        QWidget(parent), ui(new Ui1::StartAndEnd) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        QString start_string, end_string;
        start_string = ui->lineEdit_2->text();
        end_string = ui->lineEdit_4->text();
        start = start_string.toInt();
        end = end_string.toInt();
        QString set = "获取成功!start=" + QString::number(start) + ",end=" + QString::number(end);
        ui->lineEdit_5->setText(set);
    });
}

StartAndEnd::~StartAndEnd() {
    delete ui;
}
