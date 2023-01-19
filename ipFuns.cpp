

#include "ipfind.h"


long long ipAddressProcessing(char *searchedIpString) {
    int nTmpIP[4] = {0};
    long long nIPAddress = 0;
    sscanf(searchedIpString, "%d.%d.%d.%d", &nTmpIP[0], &nTmpIP[1], &nTmpIP[2], &nTmpIP[3]);
    for (int i = 0; i < 4; i++) {
        nIPAddress += (nTmpIP[i] << (24 - (i * 8)) & 0xFFFFFFFF);
    }
    return nIPAddress;
}

