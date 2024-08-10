#include <stdio.h>
#include <windows.h>

typedef int (*MYINC)(int i);

int main()
{
    printf("Start\n");

    // DLL を明示的にロードする
    HMODULE hmodule = LoadLibrary("MyLibInc.dll");
    if (hmodule == NULL)
    {
        printf("LoadLibrary, err=%d\n", GetLastError());
        return 1;
    }

    // DLL の中にある特定の関数のアドレスを取得する
    MYINC fnMyInc = (MYINC)GetProcAddress(hmodule, "MyInc");
    if (fnMyInc == NULL)
    {
        printf("GetProcAddress, err=%d\n", GetLastError());
        return 1;
    }

    // DLL の中にある特定の関数を呼び出す
    int i = fnMyInc(7);
    printf("i=%d\n", i);

    // DLL をアンロードする
    BOOL bSuccess = FreeLibrary(hmodule);
    if (!bSuccess)
    {
        printf("FreeLibrary, err=%d\n", GetLastError());
        return 1;
    }

    return 0;
}