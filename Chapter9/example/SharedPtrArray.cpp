#include <memory>
#include <iostream>
using namespace std;

class CTest {
public:
    CTest() { cout << "CTest()" << endl; }
    ~CTest() { cout << "~CTest()" << endl; }
    void TestFunc() { cout << " TestFunc()" << endl; }
};

void RemoveTest(CTest *pTest) {
    cout << "RemoveTest()" << endl;

    delete [] pTest;
}

int main(int argc, char* argv[]) {

    cout << "*****Begin*****" << endl;
    
    shared_ptr<CTest> ptr(new CTest[3], RemoveTest);

    shared_ptr<CTest> ptr1(new CTest);
    ptr1.reset();
    cout << "******End******" << endl;

    return 0;
}