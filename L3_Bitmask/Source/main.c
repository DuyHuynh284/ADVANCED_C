#include <stdio.h>
#include "bitmask.h"

uint8_t option = 0x00; // khởi tạo tính năng ban đầu không có gì: 0b0000 0000

int main(){

    // Thêm tính năng
    EnableFeature(&option, GENDER | HAT | SHOES | TSHIRT | FEATURE1 ); // &user: Chọn địa chỉ user để lưu trữ
    // kết quả 0b0000 1111

    // Xóa tính năng
    DisableFeature(&option, FEATURE1);
    // Liệt kê các tính năng
    ListFeatureEnabled(option);

    // tính năng vòng lặp for trong hàm liệt kê
    /* Lần lập  i = 0, x >> 0
        0b0000 1111(BIN) -> 15(DEC)
    and
        0b0000 0001
    =   0b0000 0001 -> 1
    Lần lặp i = 1, x >> 1
        0b0000 0111
    and
        0b0000 0001
    =   0b0000 0001 -> 1
    ...
    Lần lặp i = 4 -> i >> 4
        0b0000 0000
    and
        0b0000 0001
    =   0b0000 0000 -> 0
    */
    // lý do tại sao and với 1 ra 1
}


