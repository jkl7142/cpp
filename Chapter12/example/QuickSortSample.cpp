#include <iostream>
using namespace std;

int CompareData(const void *pLeft, const void *pRight) {
    //return *(int *)pLeft - *(int *)pRight;  // ��������
    return *(int *)pRight - *(int *)pLeft;  // ��������
}

int main(int argc, char* argv[]) {
    
    int aList[5] = {30, 50, 10, 20, 40};

    // �� ���� ���ϴ� ���(�Լ� �ּ�)�� �ݹ� �Լ��� �����Ѵ�.
    qsort(aList, 5, sizeof(int), CompareData);

    for (auto &n : aList) {
        cout << n << endl;
    }
    
    cout << endl;

    return 0;
}