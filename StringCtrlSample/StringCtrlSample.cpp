// StringCtrlSample.cpp
//

#include "stdafx.h"
//#include "MyString.h"
#include "MyStringEx.h"

/* assignment7 TestFunc()
void TestFunc(const CMyString &strParam) {
    cout << strParam[0] << endl;
    cout << strParam[strParam.GetLength() - 1] << endl;
}
*/

/* assignment5 TestFunc()
CMyString TestFunc(void) {
    CMyString strTest("TestFunc() return");
    cout << strTest << endl;

    return strTest;
}
*/

/* assignment4 TestFunc()
void TestFunc(const CMyString &strParam) {
    cout << strParam << endl;
}
*/

/* assignment2 TestFunc()
void TestFunc(const CMyString &param) {
    cout << param.GetString() << endl;
}
*/

int main(int argc, char* argv[]) {

    // assignment10 output
    CMyStringEx strTest;

    // 필터링 on
    strTest.SetString("멍멍이아들");
    cout << strTest << endl;

    // 필터링 off
    strTest.SetString("Hello");
    cout << strTest << endl;

    /* assignment9 output
    CMyStringEx strTest;
    strTest.SetString("I am a boy.");
    cout << strTest << endl;

    int nIndex = strTest.Find("am");
    cout << "Index: " << nIndex << endl;
    */

    /* assignment8 output
    CMyString strLeft("Test"), strRight("String");

    if (strLeft == strRight) {
        cout << "Same" << endl;
    }
    else {
        cout << "Different" << endl;
    }

    strLeft = CMyString("String");

    if (strLeft != strRight) {
        cout << "Different" << endl;
    }
    else {
        cout << "Same" << endl;
    }
    */

    /* assignment7 output
    CMyString strParam("HelloWrold");
    cout << strParam << endl;
    TestFunc(strParam);
    */

    /* assignment6 output
    CMyString strLeft("Hello"), strRight("World"), strResult;

    strResult = strLeft + strRight;
    cout << strResult << endl;

    cout << strLeft << endl;
    strLeft += CMyString("World");
    cout << strLeft << endl;
    */

    /* assignment5 output
    TestFunc();
    */

    /* assignment4 output
    CMyString strData("Hello");

    ::TestFunc(strData);
    ::TestFunc(CMyString("Wrold"));
    */

    /* assignment3 output
    CMyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("World");

    // 복사 생성
    CMyString strNewData(strData);
    cout << strNewData.GetString() << endl;

    // 단순 대입 연산자 호출
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