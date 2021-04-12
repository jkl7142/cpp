#include <iostream>
using namespace std;

class CCompareBase {
public:
    virtual int operator()(int a, int b) const = 0;
};

class CTestData {
public:
    CTestData() {
        m_array[0] = 30;
        m_array[1] = 10;
        m_array[2] = 50;
        m_array[3] = 20;
        m_array[4] = 40;
    }

    void Print() {
        for (auto &n : m_array) {
            cout << n << '\t';
        }
        cout << endl;
    }

    void Sort(const CCompareBase &cmp) {
        int nTmp;

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                if (cmp(m_array[i], m_array[j]) < 0) {
                    nTmp = m_array[i];
                    m_array[i] = m_array[j];
                    m_array[j] = nTmp;
                }
            }
        }
    }

private:
    int m_array[5];
};

class CMyCmpDesc : public CCompareBase {
public:
    int operator()(int a, int b) const { return a - b; }
};

class CMyCmpAsce : public CCompareBase {
public:
    int operator()(int a, int b) const { return b - a; }
};

int main(int argc, char* argv[]) {
    CTestData data;

    // ��������
    CMyCmpDesc desc;
    data.Sort(desc);
    data.Print();

    // ��������
    CMyCmpAsce asce;
    data.Sort(asce);
    data.Print();

    return 0;
}