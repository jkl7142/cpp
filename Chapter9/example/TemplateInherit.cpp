#include <iostream>
using namespace std;

template<typename T>
class CMyData {
public:

protected:
    T m_Data;
};

template<typename T>
class CMyDataEx : public CMyData<T> {
public:
    // T GetData() const { return m_Data; }
    T GetData() const { return this->m_Data; }
    //void SetData(T param) { m_Data = param; }
    void SetData(T param) { this->m_Data = param; }
};

int main(int argc, char* argv[]) {

    CMyDataEx<int> a;
    a.SetData(5);
    cout << a.GetData() << endl;

    return 0;
}