//
// Created by 86156 on 2023/1/13.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

#ifndef QT_MOBILEPHONEFIND_H
#define QT_MOBILEPHONEFIND_H
#define Id_Card_Len 5900
#define Mobile_Phone_Len 473605
#define MAX_Source_Data_Len 1048576
struct SourceData {
    char data[1024];
    char mobilePhone[15];
    char idCard[20];
    char ipaddr[15];
};
struct PhoneData {
    char data[1024];
    char phoneData[10];
    char cityData[30];
    int phoneNumber;
};
struct IdCardData {
    char data[1024];
    char idData[20];
    char cityData[66];
    int idNumber;
};

int getSourceFileDataAndLen(FILE *file, struct SourceData *sourceData);

int getPhoneFileDataAndLen(FILE *file, struct PhoneData *phoneData);

int getIdCardFileDataAndLen(FILE *file, struct IdCardData *idCardData);

char *
showPhoneFileData(struct PhoneData *phoneData, char *searchedString, char *mobile_phone_string, int len);

char *
showIdCardFileData(struct IdCardData *idCardData, char *searchedString, char *Id_string, int len);


#endif //QT_MOBILEPHONEFIND_H
