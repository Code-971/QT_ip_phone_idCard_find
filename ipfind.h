//
// Created by 86156 on 2023/1/14.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

#ifndef IPDEMO_IPFIND_H

#define IPDEMO_IPFIND_H
#define IP_Len 683845

struct IpData{
    char data[1024];
    char ipStartString[15];
    char ipEndString[15];
    char cityData[100];
    long long ipStartNumber;
    long long ipEndNumber;

};
int getIpFileDataAndLen(FILE *file,struct IpData *ipData);

char *showIpFileData(struct IpData *ipData, char *searchedString,char *ip_string, int len);

long long ipAddressProcessing( char *searchedIpString);


#endif //IPDEMO_IPFIND_H

