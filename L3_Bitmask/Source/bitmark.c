#include <stdio.h>
#include "bitmask.h"

void EnableFeature(uint8_t *option, uint8_t feature)
{
    *option = *option | feature; // dùng phép OR để bật bit
}

void DisableFeature(uint8_t *option, uint8_t feature)
{
    *option = *option & (~feature); // dùng phép AND + NOT để tắt bit
    // *option &= ~feature;
}

int8_t IsFeatureEnable(int8_t option, uint8_t feature)
{
    return ((option & feature)!= 0); // Kiểm tra tính năng đã được hay chưa
}

void ListFeatureEnabled(int8_t option)
{
    printf("Selected Features:\n");

    if (option & GENDER) // Dùng and để kiểm tra có tính năng hay không
    {
        printf("- Gender\n");
    }


    if (option & SHOES)
    {
        printf("- Shoes\n");
    }

    if(option & HAT)
    {
        printf("- Hat\n");
    }

    if(option & TSHIRT)
    {
        printf("- Tshirt\n");
    }

    if(option & FEATURE1)
    {
        printf("- Feature1\n");
    }

    if(option & FEATURE2)
    {
        printf("- Feature2\n");
    }

    if(option & FEATURE3)
    {
        printf("- Feature3\n");
    }

    if(option & FEATURE4)
    {
        printf("- Feature4\n");
    }

    // ỉn ra các bit được bật (1) và tắt (0)


    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", (option >> i));
        printf("feature selected: %d\n", (option >> i) & 1);
    }

}
