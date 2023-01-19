//
// Created by 86156 on 2023/1/5.
//

// You may need to build the project (run Qt uic code generator) to get "ui_widget.h" resolved

#include <iostream>
#include "widget.h"
#include "ui_widget.h"
#include "QFile"
#include "QFileDialog"
#include "string"
#include "ui_StartAndEnd.h"
#include "datafind.h"
#include "ipfind.h"

widget::widget(QWidget *parent) :
        QWidget(parent), ui(new Ui::widget) {
    ui->setupUi(this);
    //点击按钮弹出文件选择对话框
    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "./");
        ui->lineEdit->setText(path);
        std::string filename = path.toStdString();
        //读取内容
        //#define Mobile_Phone_Len 473605
        SourceFile = fopen(filename.c_str(), "r");
        while (SourceFile == nullptr) {
            sourceLen = 0;
            ui->textEdit->setText("getSourceFile error！");
            return;
        }
        //ui->textEdit->setText(*source_data_array);
        memset(source_data_array, 0, sizeof(struct SourceData) * MAX_Source_Data_Len);
        sourceLen = getSourceFileDataAndLen(SourceFile, source_data_array);

        fclose(SourceFile);
    });
    connect(ui->pushButton_3, &QPushButton::clicked, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "./");
        ui->lineEdit_2->setText(path);
        std::string filename = path.toStdString();
        //读取内容
        IdCardFile = fopen(filename.c_str(), "r");
        if (IdCardFile == nullptr) {
            ui->textEdit->setText("getIdCardFile error！");
            return;
        }
        memset(id_card_array, 0, sizeof(struct IdCardData) * idCardLen);
        idCardLen = getIdCardFileDataAndLen(IdCardFile, id_card_array);
        fclose(IdCardFile);
    });
    //idCard处理入口
    connect(ui->pushButton_6, &QPushButton::clicked, [=]() {
        ui->textEdit->setText("idCard处理:\0\n");
        ui->progressBar->setValue(0);
        if (start > end || end > sourceLen || start < 0 || end < 0) {
            ui->textEdit->setText("开始或结束端点异常！");
            return;
        }
        QFile file("./idCardOutput.csv");
        //打开文件，不存在则创建
        file.open(QIODevice::ReadWrite | QIODevice::Text);

        for (int i = start; i <= end; ++i) {
            this->id_card_string = showIdCardFileData(id_card_array, source_data_array[i].idCard, id_card_string,
                                                      idCardLen);
            double numValue = double(100) / (end - start + 1) * i;
            file.write(id_card_string);
            file.write(",");
            file.write("\n");
            ui->progressBar->setValue(numValue);
            ui->textEdit->append(id_card_string);
        }
        file.close();
        ui->progressBar->setValue(100);
        //char text[20] = "130102199001070000";
        //ui->textEdit->setText(showIdCardFileData(id_card_array, text, id_card_string, start,end, idCardLen));
        return;
    });
    connect(ui->pushButton_4, &QPushButton::clicked, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "./");
        ui->lineEdit_3->setText(path);
        std::string filename = path.toStdString();
        //读取内容
        IpFile = fopen(filename.c_str(), "r");
        if (IpFile == nullptr) {
            ui->textEdit->setText("getIPFile error！");
            return;
        }
        memset(ip_data_array, 0, sizeof(struct IpData) * IP_Len);
        ipLen = getIpFileDataAndLen(IpFile, ip_data_array);
        fclose(IpFile);
    });
    //IP处理入口
    connect(ui->pushButton_7, &QPushButton::clicked, [=]() {
        ui->textEdit->setText("IP处理\0\n");
        ui->progressBar->setValue(0);

        if (start > end || end > sourceLen || start < 0 || end < 0) {
            ui->textEdit->setText("开始或结束端点异常！");
            return;
        }
        QFile file("./IPOutput.csv");
        //打开文件，不存在则创建
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        for (int i = start; i <= end; ++i) {
            ip_string = showIpFileData(ip_data_array, source_data_array[i].ipaddr, ip_string, ipLen);
            double numValue = double(100) / (end - start + 1) * i;
            file.write(ip_string);
            file.write(",");
            file.write("\n");
            ui->progressBar->setValue(numValue);
            ui->textEdit->append(ip_string);
        }
        ui->progressBar->setValue(100);
        return;
    });

    connect(ui->pushButton_5, &QPushButton::clicked, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "打开文件", "./");
        ui->lineEdit_4->setText(path);
        std::string filename = path.toStdString();
        //读取内容
        PhoneFile = fopen(filename.c_str(), "r");
        if (PhoneFile == nullptr) {
            ui->textEdit->setText("getPhoneFile error！");
            return;
        }
        memset(mobile_phone_array, 0, sizeof(PhoneData) * mobileLen);
        mobileLen = getPhoneFileDataAndLen(PhoneFile, mobile_phone_array);
        fclose(PhoneFile);
    });
    //phone处理入口
    connect(ui->pushButton_8, &QPushButton::clicked, [=]() {
        ui->textEdit->setText("mobilePhone处理:\0\n");
        ui->progressBar->setValue(0);

        if (start > end || end > sourceLen || start < 0 || end < 0) {
            ui->textEdit->setText("开始或结束端点异常！");
            return;
        }
        QFile file("./mobilePhoneOutput.csv");
        //打开文件，不存在则创建
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        for (int i = start; i <= end; ++i) {
            this->mobile_phone_string = showPhoneFileData(mobile_phone_array, source_data_array[i].mobilePhone,
                                                          mobile_phone_string,
                                                          mobileLen);
            double numValue = double(100) / (end - start + 1) * i;
            file.write(mobile_phone_string);
            file.write(",");
            file.write("\n");
            ui->progressBar->setValue(numValue);
            ui->textEdit->append(mobile_phone_string);

        }
        ui->progressBar->setValue(100);
        return;
    });
    connect(ui->pushButton_2, &QPushButton::clicked, [=]() {
        this->startAndEnd->show();
        this->start = this->startAndEnd->get_start();
        this->end = this->startAndEnd->get_end();
    });
}

widget::~widget() {
    delete ui;
    delete startAndEnd;
    delete IdCardFile;
    delete PhoneFile;
    delete IpFile;
    delete SourceFile;
    delete[] source_data_string;
    delete[] id_card_string;
    delete[] ip_string;
    delete[] mobile_phone_string;
    free(id_card_array);
    free(ip_data_array);
    free(mobile_phone_array);
    free(source_data_array);
}

