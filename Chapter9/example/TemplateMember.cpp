#include <iostream>
using namespace std;

template<typename T>
class CTest {
public:
    CTest();
    T TestFunc();

protected:
    static T m_Data;
};

template<typename T>
CTest<T>::CTest() { }

template<typename T>
T CTest<T>::TestFunc() { return m_Data; }

template<typename T>
T CTest<T>::m_Data = 15;

int main(int argc, char* argv[]) {

    CTest<double> a;
    cout << a.TestFunc() << endl;

    return 0;
}