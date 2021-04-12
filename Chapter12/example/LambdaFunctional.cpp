// function 객체 헤더
#include <functional>
#include <iostream>
using namespace std;

// std::function 템플릿 클래스를 매개변수로 받음
void TestFunc(char* pszParam, std::function<int(char*, int)> param) {
    cout << pszParam << endl;
    param("Hello", 10);
}

int main(int argc, char* argv[]) {

    cout << "*****Begin*****" << endl;
    ::TestFunc(
        "TestFunc()",
        [](char *pszParam, int nParam)->int {
            cout << pszParam << " : " << nParam << endl;

            return 0;
        }
    );

    cout << "******End******" << endl;

    return 0;
}