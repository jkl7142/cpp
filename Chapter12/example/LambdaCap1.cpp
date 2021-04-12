#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

    int nData = 10;
    cout << nData << endl;
    /*
    auto TestFunc = [nData](void)->void {
    auto TestFunc = [nData](void) {
    auto TestFunc = [nData]() {
    auto TestFunc = [nData] {
    */
    auto TestFunc = [nData](void)->void {
        cout << nData << endl;
    };

    TestFunc();

    return 0;
}