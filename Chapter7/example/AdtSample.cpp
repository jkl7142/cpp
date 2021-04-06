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
    // 영유아(0~7세) 요금 계산
    virtual void CalcFare() {
        m_nFare = 0;    // 0%
    }
};

class CChild : public CPerson {
public:
    // 어린이(8~13세) 요금 계산
    virtual void CalcFare() {
        m_nFare = DEFAULT_FARE * 50 / 100;  // 50%
    }
};

class CTeen : public CPerson {
public:
    // 청소년(14~19세) 요금 계산
    virtual void CalcFare() {
        m_nFare = DEFAULT_FARE * 75 / 100;  // 75%
    }
};

class CAdult : public CPerson {
    // 성인(20세 이상) 요금 계산
    virtual void CalcFare() {
        m_nFare = DEFAULT_FARE; // 100%
    }
};

int main(int argc, char* argv[]) {
    CPerson* arList[3] = { 0 };
    int nAge = 0;

    // 자료 입력
    for (auto &person : arList) {
        cout << "나이를 입력하세요: ";
        cin >> nAge;
        if (nAge < 8) person = new CBaby;
        else if (nAge < 14) person = new CChild;
        else if (nAge < 20) person = new CTeen;
        else person = new CAdult;

        person->CalcFare();
    }

    // 자료 출력
    for (auto person : arList) {
        cout << person->GetFare() << "원" << endl;
    }

    // 자료 삭제 및 종료
    for (auto person : arList) {
        delete person;
    }

    return 0;
}