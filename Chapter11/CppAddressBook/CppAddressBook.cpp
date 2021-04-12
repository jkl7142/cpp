#include "stdafx.h"
#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"

int main(int argc, char* argv[]) {
    CMyList DB(new CUserData);
    CUserInterface UI(DB);
    UI.Run();

    return 0;
}