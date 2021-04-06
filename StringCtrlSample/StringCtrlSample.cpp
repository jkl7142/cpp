// StringCtrlSample.cpp
//

#include "stdafx.h"
#include "MyString.h"

// assignment4 TestFunc()
void TestFunc(const CMyString &strParam) {
    cout << strParam << endl;
}

/* assignment2 TestFunc()
void TestFunc(const CMyString &param) {
    cout << param.GetString() << endl;
}
*/

int main(int argc, char* argv[]) {

    // assignment4 output
    CMyString strData("Hello");

    ::TestFunc(strData);
    ::TestFunc(CMyString("Wrold"));

    /* assignment3 output
    CMyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("World");

    // ���� ����
    CMyString strNewData(strData);
    cout << strNewData.GetString() << endl;

    // �ܼ� ���� ������ ȣ��
    strNewData = strTest;
    cout << strNewData.GetString() << endl;
    */

    /* assignment2 output
    CMyString strData;
    strData.SetString("Hello");
    TestFunc(strData);
    */

    /* assignment1 output
    CMyString strData;
    strData.SetString("Hello");
    cout << strData.GetString() << endl;
    */

    return 0;
}