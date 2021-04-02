#include <iostream>
using namespace std;

class CMyData {

public:
    explicit CMyData(int nParam) {
        m_pnData = new int(nParam);
    }

    ~CMyData() { delete m_pnData; }

    operator int() { return *m_pnData; }

    CMyData& operator=(const CMyData &rhs) {    // 반환 형식을 참조자로 설정해 a = b = c 해결
        if(this == &rhs) {  // a = a 해결
            return *this;
        }

        delete m_pnData;

        //m_pnData = new int;
        //*m_pnData = *rhs.m_pnData;
        m_pnData = new int(*rhs.m_pnData);

        return *this;
    }

private:
    int *m_pnData = nullptr;
};

int main(int argc, char* argv[]) {

    CMyData a(0), b(5), c(10);

    // a = a; 논리적 오류 : 데이터를 복사하기 전에 원본을 삭제
    // a = b = c;
    a = b;
    cout << a << endl;

    return 0;
}