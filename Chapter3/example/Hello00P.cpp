#include <cstdio>

// Developer code
class USERDATA {

public:
    int nAge;
    char szName[32];

    void Print(void) {
        printf("%d, %s\n", nAge, szName);
    }
};

// User code
int main(int argc, char* argv[]) {
    USERDATA user = { 10, "Ã¶¼ö" };

    user.Print();

    return 0;
}