#include <iostream>
using namespace std;

void ExceptTest1() {
    int nInput;
    cout << "1~10 ���� ������ �Է��ϼ���.: ";
    cin >> nInput;

    if(nInput < 1 || nInput > 10)
        throw nInput;
}

void ExceptTest2() {
    char ch;
    cout << "Menu: [A]dd\t[D]elete\t[E]xit\n:";
    cin >> ch;

    if(ch != 'A' && ch != 'D' && ch != 'E')
        throw ch;
}

int main(int argc, char* argv[]) {
    cout << "*****Begin*****" << endl;

    //ExceptTest1();

    try
    {
        ExceptTest1();
        ExceptTest2();
    }
    catch(int nExp)
    {
        cout << "ERROR:" << nExp << "��(��) ������ ��� �����Դϴ�." << endl;
    }

    catch(char ch)
    {
        cout << "ERROR: " << ch << " �� �� ���� �޴��Դϴ�." << endl;
    }
    catch(...)
    {
        
    }

    //if(ExceptTest1() == -1) cout << "Error" << endl;
    //if(ExceptTest2() == -1) cout << "Error" << endl;

    cout << "******End******" << endl;
    
    return 0;
}