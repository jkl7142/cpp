#include <iostream>
using namespace std;

class CMyData {
    public:
        int GetData() { return m_nData; }

        void SetData(int nParam) { m_nData = nParam; }

    private:
        int m_nData = 0;
};

class CMyDataEx : public CMyData {
    public:
        void SetData(int nParam) {
            if(nParam < 0)
                CMyData::SetData(0);    // 동일한 메소드 실행시 소속 클래스 명시

            if(nParam > 10)
                CMyData::SetData(10);
        }
};

int main(int argc, char* argv[]) {
    CMyData a;
    a.SetData(-10);
    cout << a.GetData() << endl;

    CMyDataEx b;
    b.SetData(15);
    cout << b.GetData() << endl;

    CMyData &rData = a;     // CMyData 클래스
    rData.SetData(15);      // CMyData::SetData()
    cout << rData.GetData() << endl;

    CMyData *pData = new CMyDataEx; // CMyData 클래스
    pData->SetData(5);      // CMyData::SetData()
    delete pData;

    return 0;
}