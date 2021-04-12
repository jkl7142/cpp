#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    vector<int> vec(3);
    vec[0] = 10;
    vec[1] = 20;
    vec[2] = 20;

    for (auto &n : vec) {
        cout << n << '\t';
    }
    cout << endl;

    // 뒤에 새로운 요소 추가
    vec.push_back(30);
    vec.push_back(40);

    for (auto &n : vec) {
        cout << n << '\t';
    }

    cout << endl;

    return 0;
}