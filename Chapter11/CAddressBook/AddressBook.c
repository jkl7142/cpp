#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME "Address.dat"

void ReleaseList();

typedef struct _USERDATA {
    char szName[32];
    char szPhone[32];

    struct _USERDATA *pNext;
} USERDATA;

// ��� ���
USERDATA g_Head = {0};

// �̸����� ��带 �˻��ϴ� �Լ�
USERDATA *FindNode(char *pszName) {
    USERDATA *pTmp = g_Head.pNext;
    while (pTmp != NULL) {
        if (strcmp(pTmp->szName, pszName) == 0) {
            return pTmp;
        }
        pTmp = pTmp->pNext;
    }

    return NULL;
}

int AddNewNode(char *pszName, char *pszPhone) {
    USERDATA *pNewUser = NULL;

    // ����Ʈ �˻�
    if (FindNode(pszName) != NULL) {
        return 0;
    }

    // �޸� Ȯ��
    pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
    memset(pNewUser, 0, sizeof(USERDATA));

    // �޸𸮿� �� ����
    //sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
    //sprintf_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
    sprintf(pNewUser->szName, "%s", pszName);
    sprintf(pNewUser->szPhone, "%s", pszPhone);
    pNewUser->pNext = NULL;

    // ��� ��� �ٷ� �ڿ� �߰�
    pNewUser->pNext = g_Head.pNext;
    g_Head.pNext = pNewUser;

    return 1;
}

// �̸��� �Է¹޾� ����Ʈ�� �߰��ϴ� �Լ�
void Add() {
    char szName[32] = {0};
    char szPhone[32] = {0};

    printf("Input name : ");
    fflush(stdin);
    //gets_s(szName, sizeof(szName));
    gets(szName);

    printf("Input phone number : ");
    fflush(stdin);
    //gets_s(szPhone, sizeof(szPhone));
    gets(szPhone);

    // ����Ʈ�� �߰�
    AddNewNode(szName, szPhone);
}

// Ư�� ��带 �˻��ϴ� �Լ�
void Search() {
    char szName[32] = {0};
    USERDATA *pNode = NULL;

    printf("Input name : ");
    fflush(stdin);
    //gets_s(szName, sizeof(szName));
    gets(szName);

    pNode = FindNode(szName);
    if (pNode != NULL) {
        printf("[%p] %s\t%s [%p]\n",
            pNode,
            pNode->szName, pNode->szPhone,
            pNode->pNext);
    }
    else {
        puts("ERROR: �����͸� ã�� �� �����ϴ�.");
    }

    _getch();
}

// ����Ʈ�� ��� ������ ���
void PrintAll() {
    USERDATA *pTmp = g_Head.pNext;
    while (pTmp != NULL) {
        printf("[%p] %s\t%s [%p]\n",
            pTmp,
            pTmp->szName, pTmp->szPhone,
            pTmp->pNext);

        pTmp = pTmp->pNext;
    }

    _getch();
}

// Ư�� ��带 �����ϴ� �Լ�
int RemoveNode(char *pszName) {
    USERDATA *pPrevNode = &g_Head;
    USERDATA *pDelete = NULL;

    while (pPrevNode->pNext != NULL) {
        pDelete = pPrevNode->pNext;

        if (strcmp(pDelete->szName, pszName) == 0) {
            pPrevNode->pNext = pDelete->pNext;
            free(pDelete);

            return 1;
        }

        pPrevNode = pPrevNode->pNext;
    }

    return 0;
}

// �̸��� �Է¹޾� �����ϴ� �Լ�
void Remove() {
    char szName[32];

    printf("Input name : ");
    fflush(stdin);
    //gets_s(szName, sizeof(szName));
    gets(szName);

    RemoveNode(szName);
}

// �޴��� ����ϴ� UI �Լ�
int PrintUI() {
    int nInput = 0;

    system("cls");
    printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

    scanf("%d", &nInput);

    return nInput;
}

// ������ ���Ͽ��� ������ �о���� �Լ�
int LoadList(const char *pszFileName) {
    FILE *fp = fopen(pszFileName, "rb");
    USERDATA user = {0};

    //fopen_s(&fp, pszFileName, "rb");

    if (fp == NULL) {
        return 0;
    }

    ReleaseList();

    while (fread(&user, sizeof(USERDATA), 1, fp)) {
        AddNewNode(user.szName, user.szPhone);
    }

    fclose(fp);

    return 0;
}

// ����Ʈ ���·� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(const char *pszFileName) {
    FILE *fp = fopen(pszFileName, "wb");
    USERDATA *pTmp = g_Head.pNext;

    //fopen_s(&fp, pszFileName, "wb");

    if (fp == NULL) {
        puts("ERROR: ����Ʈ ������ ���� ���� ���� ���߽��ϴ�.");
        _getch();

        return 0;
    }

    while (pTmp != NULL) {
        if (fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1) {
            printf("ERROR: %s�� ���� ������ �����ϴ� �� �����߽��ϴ�.\n", pTmp->szName);
        }

        pTmp = pTmp->pNext;
    }

    fclose(fp);

    return 1;
}

// ����Ʈ�� ��� �����͸� �����ϴ� �Լ�
void ReleaseList() {
    USERDATA *pTmp = g_Head.pNext;
    USERDATA *pDelete = NULL;

    while (pTmp != NULL) {
        pDelete = pTmp;
        pTmp = pTmp->pNext;

        free(pDelete);
    }

    memset(&g_Head, 0, sizeof(USERDATA));
}

int main() {
    int nMenu = 0;
    LoadList(DATA_FILE_NAME);

    // ���� �̺�Ʈ �ݺ���
    while ((nMenu = PrintUI()) != 0) {
        switch(nMenu) {
        case 1: // Add
            Add();
            break;

        case 2: // Search
            Search();
            break;

        case 3: // Print all
            PrintAll();
            break;

        case 4: // Remove
            Remove();
            break;
        }
    }

    // ���� ���� ���� ���� & �޸� ����
    SaveList(DATA_FILE_NAME);
    ReleaseList();

    return 0;
}