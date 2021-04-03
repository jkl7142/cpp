#include <iostream>
using namespace std;

class CMyData {
    public:
        CMyData() { cout << "CMyData()" << endl; }
        CMyData(int nParam) { cout << "CMyData(int)" << endl; }
        CMyData(double dParam) { cout << "CMyData(double)" << endl; }
};

class CMyDataEx : public CMyData {
    public:
        // using CMyData::CMyData; // 다중 정의된 생성자들을 그대로 사용

        CMyDataEx() { cout << "CMyDataEx()" << endl; }

        CMyDataEx(int nParam) : CMyData(nParam) {
            cout << "CMyDataEx(int)" << endl;
        }

        CMyDataEx(double dParam) : CMyData() {
            cout << "CMyDataEx(double)" << endl;
        }
};

int main(int argc, char* argv[]) {
    CMyDataEx a;
    cout << "*********" << endl;
    CMyDataEx b(5);
    cout << "*********" << endl;
    CMyDataEx c(3.3);

    return 0;
}