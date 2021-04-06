#include <iostream>
using namespace std;

#define DEFAULT_FARE 1000

class CPerson {
public:
    CPerson() { }
    virtual ~CPerson() {
        cout << "virtual ~CPerson()" << endl;
    }

    virtual void CalcFare() = 0;
    virtual unsigned int GetFare() { return m_nFare; }

protected:
    unsigned int m_nFare = 0;
};

class CBaby : public CPerson {
public:
    // ������(0~7��) ��� ���
    virtual void CalcFare() {
        m_nFare = 0;    // 0%
    }
};

class CChild : public CPerson {
public:
    // ���(8~13��) ��� ���
    virtual void CalcFare() {
        m_nFare = DEFAULT_FARE * 50 / 100;  // 50%
    }
};

class CTeen : public CPerson {
public:
    // û�ҳ�(14~19��) ��� ���
    virtual void CalcFare() {
        m_nFare = DEFAULT_FARE * 75 / 100;  // 75%
    }
};

class CAdult : public CPerson {
    // ����(20�� �̻�) ��� ���
    virtual void CalcFare() {
        m_nFare = DEFAULT_FARE; // 100%
    }
};

int main(int argc, char* argv[]) {
    CPerson* arList[3] = { 0 };
    int nAge = 0;

    // �ڷ� �Է�
    for (auto &person : arList) {
        cout << "���̸� �Է��ϼ���: ";
        cin >> nAge;
        if (nAge < 8) person = new CBaby;
        else if (nAge < 14) person = new CChild;
        else if (nAge < 20) person = new CTeen;
        else person = new CAdult;

        person->CalcFare();
    }

    // �ڷ� ���
    for (auto person : arList) {
        cout << person->GetFare() << "��" << endl;
    }

    // �ڷ� ���� �� ����
    for (auto person : arList) {
        delete person;
    }

    return 0;
}