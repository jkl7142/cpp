#include <stdio.h>

// Developer code
typedef struct USERDATA {
    int nAge;
    char szName[32];
} USERDATA;

void PrintData(USERDATA *pUser) {
    printf("%d, %s\n", pUser->nAge, pUser->szName);
}

// User code
int main(void) {
    USERDATA user = {20, "Ã¶¼ö"};
    //printf("%d, %s\n", user.nAge, user.szName);
    PrintData(&user);

    return 0;
}