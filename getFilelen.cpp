#include"datafind.h"
#include "ipfind.h"

int getSourceFileDataAndLen(FILE *file, struct SourceData *sourceData) {
    int len = 0;
    int first = 0, second = 0, third = 0;
    if (file == nullptr) {
        return 0;
    }
    char buf[1024];
    memset(buf, 0, sizeof buf);
    //读取每一行
    while (fgets(buf, 1024, file) != nullptr) {
        strcpy(sourceData[len].data, buf);
        for (int i = 0, counts = 0, flag = 0; i < strlen(buf); ++i) {
            if (buf[i] == ',') {
                ++counts;
            }
            if (counts == 1 && flag == 0) {
                first = i;
                for (int j = 0; j < first; ++j) {
                    sourceData[len].mobilePhone[j] = buf[j];
                }
                ++flag;
            }
            if (counts == 2 && flag == 1) {
                second = i;
                for (int j = first + 1; j < second; ++j) {
                    sourceData[len].ipaddr[j - first - 1] = buf[j];
                }
                ++flag;
            }
            if (counts == 3 && flag == 2) {
                third = i;
                for (int j = second + 1; j < third; ++j) {
                    sourceData[len].idCard[j - second - 1] = buf[j];
                }
            }
        }
        memset(buf, 0, 1024);
        len++;
    }
    return len;
}

int getPhoneFileDataAndLen(FILE *file, struct PhoneData *phoneData) {
    int len = 0;
    int first = 0, second = 0;
    if (file == nullptr) {
        return 0;
    }
    char buf[1024];
    memset(buf, 0, sizeof buf);
    //读取每一行
    while (fgets(buf, 1024, file) != nullptr) {
        strcpy(phoneData[len].data, buf);
        for (int i = 0, counts = 0, flag = 0; i < strlen(buf); ++i) {
            if (buf[i] == ',') {
                ++counts;
            }
            if (counts == 1 && flag == 0) {
                first = i;
                for (int j = 0; j < first; ++j) {
                    phoneData[len].phoneData[j] = buf[j];
                }
                sscanf(phoneData[len].phoneData, "%8d", &phoneData[len].phoneNumber);
                flag++;
            }
            if (counts == 2 && flag == 1) {
                second = i;
                for (int j = first + 1; j < second; ++j) {
                    if (buf[j] == ',') {
                        buf[j] = ' ';
                    }
                    phoneData[len].cityData[j - first - 1] = buf[j];
                }
            }
        }
        memset(buf, 0, 1024);
        len++;
    }
    return len;
}

int getIdCardFileDataAndLen(FILE *file, struct IdCardData *idCardData) {
    int len = 0;
    int first = 0, second = 0;
    if (file == nullptr) {
        return 0;
    }
    char buf[1024];
    memset(buf, 0, sizeof buf);
    //读取每一行
    while (fgets(buf, 1024, file) != nullptr) {
        strcpy(idCardData[len].data, buf);
        for (int i = 0, counts = 0, flag = 0; i < strlen(buf); ++i) {
            if (buf[i] == ',') {
                ++counts;
            }
            if (counts == 1 && flag == 0) {
                first = i;
                for (int j = 0; j < first; ++j) {
                    idCardData[len].idData[j] = buf[j];
                }
                sscanf(idCardData[len].idData, "%6d", &idCardData[len].idNumber);
                flag++;
            }
            if (counts == 2 && flag == 1) {
                second = i;
                for (int j = first + 1; j < second; ++j) {
                    if (buf[j] == ',') {
                        buf[j] = ' ';
                    }
                    idCardData[len].cityData[j - first - 1] = buf[j];
                }
            }
        }
        memset(buf, 0, 1024);
        len++;
    }
    return len;
}

int getIpFileDataAndLen(FILE *file, struct IpData *ipData) {
    int len = 0;
    int first, second, third;
    if (file == nullptr) {
        return 0;
    }
    char buf[1024];
    memset(buf, 0, sizeof buf);
    //读取每一行
    while (fgets(buf, 1024, file) != nullptr) {
        strcpy(ipData[len].data, buf);
        for (int i = 0, counts = 0, flag = 0; i < strlen(buf); ++i) {
            if (buf[i] == ',') {
                ++counts;
            }
            if (counts == 1 && flag == 0) {
                first = i;
                for (int j = 0; j < first; ++j) {
                    ipData[len].ipStartString[j] = buf[j];
                }
                ipData[len].ipStartNumber = ipAddressProcessing(ipData[len].ipStartString);
                flag++;
            }
            if (counts == 2 && flag == 1) {
                second = i;
                for (int j = first + 1; j < second; ++j) {
                    ipData[len].ipEndString[j - first - 1] = buf[j];
                }
                ipData[len].ipEndNumber = ipAddressProcessing(ipData[len].ipEndString);
                flag++;
            }
            if (counts == 5 && flag == 2) {
                third = i;
                for (int j = second + 1; j < third; ++j) {
                    if (buf[j] == ',') {
                        buf[j] = ' ';
                    }
                    ipData[len].cityData[j - second - 1] = buf[j];
                }

            }
        }
        memset(buf, 0, 1024);
        len++;
    }
    return len;
}
