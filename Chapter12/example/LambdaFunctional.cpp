// function ��ü ���
#include <functional>
#include <iostream>
using namespace std;

// std::function ���ø� Ŭ������ �Ű������� ����
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