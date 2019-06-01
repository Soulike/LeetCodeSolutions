#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

int reverse(int x)
{
    int isNegativeMax = x == INT32_MIN; // 是否正好是负数最大值，需要进行特殊处理（否则取绝对值后就溢出了）
    if (isNegativeMax)
    {
        x += 1;
    }

    int absX = abs(x); // 统一转换成正数

    int numbers[10] = {0}; // 存储各位数字，10 位足够用，事先初始化成全 0

    int numberLength = 0; // 数字的长度

    int lastNumber = 0; // 取余后剩下的数字

    // 取出各位数字
    for (int i = 1; i <= 10 && absX > 0; i++)
    {
        lastNumber = absX % (int)pow(10, i);
        numbers[i - 1] = lastNumber / (int)pow(10, i - 1);
        absX -= lastNumber;
        numberLength = i;
    }

    int reversedX = 0;
    int numToAdd = 0;

    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] == 0)
        {
            continue;
        }
        else
        {
            if (numberLength - i - 1 == 9 && numbers[i] > 2) // 首位就溢出了
            {
                return 0;
            }
            numToAdd = numbers[i] * (int)pow(10, numberLength - i - 1);
            if (INT32_MAX - reversedX < numToAdd)   // 查看是不是加上这个数之后会溢出
            {
                return 0;
            }
            reversedX += numbers[i] * (int)pow(10, numberLength - i - 1);
        }
    }

    return x > 0 ? reversedX : isNegativeMax ? -1 * reversedX - 1 : -1 * reversedX;
}

int main()
{
    printf("%d", reverse(1563847412));
}