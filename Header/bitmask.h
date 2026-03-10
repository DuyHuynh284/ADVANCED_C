#ifndef BITMASK_H
#define BITMASK_H
#include <stdio.h>
#include <stdint.h>

//0b0000 0000
#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)     //0b0000 0001
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)     //0b0000 0010
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)         //0b0000 0100
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)        //0b0000 1000

// Tự thêm tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1                     //0b0001 0000
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2                     //0b0010 0000
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3                     //0b0100 0000
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4                     //0b1000 0000

// uint8_t 1 bytes = 8 bits
void EnableFeature(uint8_t *option, uint8_t feature); // Bật tính năng

void DisableFeature(uint8_t *option, uint8_t feature); // Tắt tính năng

int8_t IsFeatureEnable(int8_t option, uint8_t feature); // Kiểm tra tính năng đã bật chưa

void ListFeatureEnabled(int8_t option); // Liệt kê các tính năng đã lựa chọn

#endif
