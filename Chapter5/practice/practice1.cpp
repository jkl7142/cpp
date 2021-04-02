#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    // 대입 연산자 오버로딩 시 주의해야 할 점
    // 1. a = a // 데이터를 복사하기도 전에 원본을 삭제해버림
    // 2. a = b = c // 대입 연산자 반환 형식이 void이기 때문에 대입이 불가능

    return 0;
}