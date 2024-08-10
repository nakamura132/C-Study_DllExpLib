#include <stdio.h>
#include <windows.h>

typedef int (*MYINC)(int i);

int main()
{
    printf("Start\n");

    // DLL �𖾎��I�Ƀ��[�h����
    HMODULE hmodule = LoadLibrary("MyLibInc.dll");
    if (hmodule == NULL)
    {
        printf("LoadLibrary, err=%d\n", GetLastError());
        return 1;
    }

    // DLL �̒��ɂ������̊֐��̃A�h���X���擾����
    MYINC fnMyInc = (MYINC)GetProcAddress(hmodule, "MyInc");
    if (fnMyInc == NULL)
    {
        printf("GetProcAddress, err=%d\n", GetLastError());
        return 1;
    }

    // DLL �̒��ɂ������̊֐����Ăяo��
    int i = fnMyInc(7);
    printf("i=%d\n", i);

    // DLL ���A�����[�h����
    BOOL bSuccess = FreeLibrary(hmodule);
    if (!bSuccess)
    {
        printf("FreeLibrary, err=%d\n", GetLastError());
        return 1;
    }

    return 0;
}