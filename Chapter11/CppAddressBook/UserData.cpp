#include "stdafx.h"
#include "UserData.h"

int CUserData::nUserDataCounter = 0;

CUserData::CUserData() : pNext(NULL) {
    memset(szName, 0, sizeof(szName));
    memset(szPhone, 0, sizeof(szPhone));

    nUserDataCounter++;
}

CUserData::~CUserData() {
    nUserDataCounter--;
}