// StringCtrlSample.cpp
//

#include "stdafx.h"
#include "MyString.h"

int main(int argc, char* argv[]) {
    CMyString strData;
    strData.SetString("Hello");
    cout << strData.GetString() << endl;

    return 0;
}