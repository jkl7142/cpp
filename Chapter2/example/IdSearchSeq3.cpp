#include <iostream>
using namespace std;

int nData = 200;

/*namespace TEST {
    int nData = 100;
    void TestFunc(void) {
        cout << nData << endl;
    }
}*/

namespace TEST {
    void TestFunc(void) {
        cout << nData << endl;
    }
    int nData = 100;
}

//int nData = 200;

int main(int argc, char* argv[]) {
    TEST::TestFunc();

    return 0;
}