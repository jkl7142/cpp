#include <iostream>
using namespace std;

// �Լ� ��ü Ŭ���� ���� �� ����
class Add {
public:
    // �Լ� ȣ�� ������ ���� ����
    int operator()(int a, int b) {
        cout << "()(int, int)" << endl;

        return a + b;
    }

    double operator()(double a, double b) {
        cout << "()(double, double)" << endl;

        return a + b;
    }
};

void TestFunc(Add &add) {
    cout << add(3, 4) << endl;
}

int main(int argc, char* argv[]) {
    Add adder;

    // �Լ� ��ü�� ȣ���Ѵ�.
    cout << adder(3, 4) << endl;
    cout << adder(3.3, 4.4) << endl;

    TestFunc(adder);

    return 0;
}