#include <iostream>
using namespace std;

int CompareData(const void *pLeft, const void *pRight) {
    //return *(int *)pLeft - *(int *)pRight;  // 오름차순
    return *(int *)pRight - *(int *)pLeft;  // 내림차순
}

int main(int argc, char* argv[]) {
    
    int aList[5] = {30, 50, 10, 20, 40};

    // 각 항을 비교하는 방법(함수 주소)을 콜백 함수로 전달한다.
    qsort(aList, 5, sizeof(int), CompareData);

    for (auto &n : aList) {
        cout << n << endl;
    }
    
    cout << endl;

    return 0;
}