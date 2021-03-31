#include <stdio.h>

// Developer code
typedef struct USERDATA {
    int nAge;
    char szName[32];
} USERDATA;

// User code
int main(void) {
    USERDATA user = {20, "Ã¶¼ö"};
    printf("%d, %s\n", user.nAge, user.szName);

    return 0;
}