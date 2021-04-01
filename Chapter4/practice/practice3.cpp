#include <iostream>
using namespace std;
/*
void TestFunc(const CTestData &param) {

}
*/
int main(int argc, char* argv[]) {

    //TestFunc(5);

    // 위와 같은 문법은 컴파일러가 마음대로 임시 객체를 생성한 후, 임시 객체에 대한 참조가 TestFunc() 함수로 전달된 것이다.
    // 사용자가 모르게 호출될 가능성을 차단하기 위해선 변환 생성자 앞에 explicit 예약어를 적용하면 된다.

    return 0;
}