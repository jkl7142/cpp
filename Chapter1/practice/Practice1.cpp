#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

    int age;
    string name;

    cout << "이름을 입력하세요." << endl;
    cin >> name;
    cout << "나이를 입력하세요." << endl;
    cin >> age;
    cout << "나의 이름은 " << name << "이고, " << age << "살입니다." << endl;

    return 0;
}