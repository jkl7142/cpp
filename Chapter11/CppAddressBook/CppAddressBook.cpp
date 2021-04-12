#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

int main(int argc, char* argv[]) {
    //CMyListEx DB(new CUserData("Dummy", "Head"));
    CMyList DB(new CUserData);
    CUserInterface UI(DB);
    UI.Run();

    return 0;
}