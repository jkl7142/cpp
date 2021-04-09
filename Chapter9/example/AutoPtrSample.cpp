#include <memory>
#include <iostream>
using namespace std;

class CMyData {
public:
    CMyData() { cout << "CMyData()" << endl; }
    ~CMyData() { cout << "~CMyData()" << endl; }
};

int main(int argc, char* argv[]) {

    cout << "*****Begin*****" << endl;
    {
        // ������ ����� ��ü�� �ڵ����� �Ҹ�
        auto_ptr<CMyData> ptrTest(new CMyData);

        // �迭�� �����ϸ� 3���� ��ü�� ���������� 1���� ��ü�� ������
        auto_ptr<CMyData> ptrTest(new CMyData[3]);
    }

    cout << "******End******" << endl;

    return 0;
}