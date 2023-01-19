/********************************************************************************
** Form generated from reading UI file 'StartAndEnd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTANDEND_H
#define UI_STARTANDEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartAndEnd
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *StartAndEnd)
    {
        if (StartAndEnd->objectName().isEmpty())
            StartAndEnd->setObjectName(QString::fromUtf8("StartAndEnd"));
        StartAndEnd->resize(491, 368);
        verticalLayout = new QVBoxLayout(StartAndEnd);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_2 = new QLineEdit(StartAndEnd);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        lineEdit_4 = new QLineEdit(StartAndEnd);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 1, 1, 1, 1);

        lineEdit_5 = new QLineEdit(StartAndEnd);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 2, 0, 1, 2);

        lineEdit_3 = new QLineEdit(StartAndEnd);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        gridLayout->addWidget(lineEdit_3, 1, 0, 1, 1);

        lineEdit = new QLineEdit(StartAndEnd);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton = new QPushButton(StartAndEnd);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(StartAndEnd);

        QMetaObject::connectSlotsByName(StartAndEnd);
    } // setupUi

    void retranslateUi(QWidget *StartAndEnd)
    {
        StartAndEnd->setWindowTitle(QApplication::translate("StartAndEnd", "获取起始位置和结束位置", nullptr));
        lineEdit_3->setText(QApplication::translate("StartAndEnd", "\347\273\223\346\235\237\344\275\215\347\275\256\357\274\232", nullptr));
        lineEdit->setText(QApplication::translate("StartAndEnd", "\350\265\267\345\247\213\344\275\215\347\275\256\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("StartAndEnd", "\350\216\267\345\217\226\350\265\267\345\247\213\347\273\223\346\235\237\344\275\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui1 {
    class StartAndEnd: public Ui_StartAndEnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTANDEND_H
