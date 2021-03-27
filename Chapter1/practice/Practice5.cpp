#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    // 상수형 참조가 기존의 참조 형식과 다른점은?

    // int &num = 10;  // 참조는 변수에 대해서만 가능하다.
    const int &num = 10; // 이 경우 10을 임시 변수에 저장한 후 num은 그 임시 변수를 참조하기 때문에 가능하다.
    cout << num << endl;
    
    // r-value 참조의 경우 변수와 상수 모두 참조가 가능하다.
    int &&rnum = 10;  // 이 경우도 마찬가지로 임시 결과에 대한 참조로 생성 당시는 소멸되지만 나중에 재활용이 가능하다.
    cout << rnum << endl;

    return 0;
}