//
// Created by 86156 on 2023/1/5.
//

#ifndef QT_WIDGET_H
#define QT_WIDGET_H

#include <QWidget>
#include "StartAndEnd.h"
#include "string"
#include "ipfind.h"
#include "datafind.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class widget;
}
QT_END_NAMESPACE

class widget : public QWidget {
Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);

    ~widget() override;


    friend class StartAndEnd;

private:
    Ui::widget *ui;
    StartAndEnd *startAndEnd = new StartAndEnd;
    FILE *SourceFile;
    FILE *IdCardFile;
    FILE *PhoneFile;
    FILE *IpFile;
    int start{};
    int end{};
    unsigned int sourceLen = 1048576;
    int idCardLen = 5900;
    int ipLen = 683845;
    int mobileLen = 473605;
    struct SourceData *source_data_array = static_cast<SourceData *>(malloc(sizeof(struct SourceData) * sourceLen));
    struct IpData *ip_data_array = static_cast<IpData *>(malloc(sizeof(struct IpData) * ipLen));
    struct PhoneData *mobile_phone_array = static_cast<PhoneData *>(malloc(sizeof(struct PhoneData) * mobileLen));
    struct IdCardData *id_card_array = static_cast<IdCardData *>(malloc(sizeof(struct IdCardData) * idCardLen));
    char *source_data_string = new char[500];
    char *id_card_string = new char[100];
    char *ip_string = new char[100];
    char *mobile_phone_string = new char[100];
};

#endif //QT_WIDGET_H
