#include "datafind.h"
#include "ipfind.h"

char *
showPhoneFileData(struct PhoneData *phoneData, char *searchedString, char *mobile_phone_string, int len) {
    const char *Exception = "IPFileData is NULL!";
    const char *NotFind = "null";
    int findPhone;
    sscanf(searchedString, "%7d", &findPhone);
    if (len == Mobile_Phone_Len) {
        return const_cast<char *>(Exception);
    }

    int left = 0;
    int right = len; //定义target在左闭右开的区间里，即[left, right)
    while (left <= right) {    //因为left = right的时候，在[left, right)区间上无意义
        int middle = left + ((right - left) / 2);
        if (phoneData[middle].phoneNumber > findPhone) {
            right = middle - 1; //target 在左区间，在[left, middle)中
        } else if (phoneData[middle].phoneNumber < findPhone) {
            left = middle + 1;
        } else {
            return phoneData[middle].cityData;
        }
    }
    for (int i = 0; i < len; i++) {
        if (phoneData[i].phoneNumber == findPhone)
            return phoneData[i].cityData;
    }
    return const_cast<char *>(NotFind);
}

char *showIdCardFileData(struct IdCardData *idCardData, char *searchedString, char *Id_string, int len) {
    const char *Exception = "IDFileData is NULL!";
    const char *NotFind = "null";
    int findID;
    sscanf(searchedString, "%6d", &findID);
    if (len == Id_Card_Len) {
        return const_cast<char *>(Exception);
    }
    int left = 0;
    int right = len + 1; //定义target在左闭右开的区间里，即[left, right)
    while (left < right) {    //因为left = right的时候，在[left, right)区间上无意义
        int middle = left + ((right - left) / 2);
        if (idCardData[middle].idNumber > findID) {
            right = middle; //target 在左区间，在[left, middle)中
        } else if (idCardData[middle].idNumber < findID) {
            left = middle + 1;
        } else {
            return idCardData[middle].cityData;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (idCardData[i].idNumber == findID) {
            return idCardData[i].cityData;
        }
    }

    return const_cast<char *>(NotFind);
}

char *showIpFileData(struct IpData *ipData, char *searchedIpString, char *ip_string, int len) {
    const char *Exception = "IPFileData is NULL!";
    const char *NotFind = "null";
    long long findIpaddr = ipAddressProcessing(searchedIpString);
    if (len == IP_Len) {
        return const_cast<char *>(Exception);
    }
    for (int i = 0; i < len; ++i) {
        if (ipData[i].ipStartNumber <= findIpaddr && ipData[i].ipEndNumber >= findIpaddr) {
            return ipData[i].cityData;
        }
    }
    //在有序表R[0..n-1]中进行二分查找，成功时返回结点的位置，失败时返回-1
    //    int low = 0, high = len - 1, mid;     //置当前查找区间上、下界的初值
    //    while (low < high) {
    //        if (ipData[low].ipStartNumber <= findIpaddr && ipData[low].ipEndNumber >= findIpaddr)
    //            return ipData[low].cityData;
    //        if (ipData[high].ipStartNumber <= findIpaddr && ipData[high].ipEndNumber >= findIpaddr)
    //            return ipData[high].cityData;          //当前查找区间R[low..high]非空
    //        mid = low + (high - low) / 2;
    //        /*使用(low+high)/2会有整数溢出的问题
    //        （问题会出现在当low+high的结果大于表达式结果类型所能表示的最大值时，
    //            这样，产生溢出后再/2是不会产生正确结果的，而low+((high-low)/2)
    //            不存在这个问题*/
    //        if (ipData[mid].ipStartNumber <= findIpaddr && ipData[mid].ipEndNumber >= findIpaddr)
    //            return ipData[mid].cityData;             //查找成功返回
    //        if (ipData[low].ipStartNumber > findIpaddr || ipData[low].ipEndNumber < findIpaddr)
    //            low = mid + 1;              //继续在R[mid+1..high]中查找
    //        else
    //            high = mid - 1;             //继续在R[low..mid-1]中查找
    //    }
    //    if (low >= high)
    //        return NotFind;//当low>high时表示所查找区间内没有结果，查找失败
    //    return NULL;
    return const_cast<char *>(NotFind);
}
