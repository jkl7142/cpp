#include <iostream>
using namespace std;

int TestFunc(int nParam = 5, int nParam2, int nParam3 = 10);    // 중간 인스턴스 디폴트 값을 건너뛰고 왼쪽의 인스턴스 디폴트 값이 정해짐
int TestFunc(int nParam1 = 5, int nParam2); // 오른쪽 인스턴스의 디폴트 값부터 설정해야함

int main(void) {
    return 0;
}