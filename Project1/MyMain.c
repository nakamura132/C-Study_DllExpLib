#include <stdio.h>
#include "MyLibInc.h"

int main()
{
    printf("Start\n");

    int i = MyInc(3); // ★ 「プラス 1 する関数」の呼び出し
    printf("i=%d\n", i);

    return 0;
}