#POINTER
## 1. Pointer là gì?
+ Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm). 
+ Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn.
### Cách khai báo
```c
int *ptr_int;       // con trỏ đến kiểu int
char *ptr_char;     // con trỏ đến kiểu char
float *ptr_float;   // con trỏ đến kiểu float
```
### Cú pháp lấy địa chỉ một biến
```c
int x = 10;
int *ptr_x = &x;  // ptr_x chứa địa chỉ của x
```
### Truy cập giá trị( giải tham chiếu - dereference)
```c
int y = *ptr_x;   // y sẽ bằng giá trị của x
ptr_x = &x;
*ptr_x = *(0x01) = 10
```
## 2. Các kiểu lưu trữ và phân bố dữ liệu có trong pointer
### Endianness
+ Endianness là thứ tự lưu trữ các byte của dữ liệu nhiều byte (multi-byte) trong bộ nhớ.
+ Dùng để xác định byte thấp và byte cao nằm ở đâu.
+ Có 2 kiểu phổ biến: Little Endian và Big Endian.
#### Little Endian
+ Byte thấp (Least Significant Byte - LSB) nằm ở địa chỉ thấp nhất.
+ Byte cao (Most Significant Byte - MSB) nằm ở địa chỉ cao nhất.
+ Ex: 0x12345678
-----
| Địa chỉ | Giá trị |
|--------|--------|
|0x01|0x78|
|0x02|0x56|
|0x03|0x34|
|0x04|0x12|
#### Big Endian
+ Byte cao (MSB) nằm ở địa chỉ thấp nhất.
+ Byte thấp (LSB) nằm ở địa chỉ cao nhất.
+ Ex: 0x12345678
-----
| Địa chỉ | Giá trị |
|--------|--------|
|0x01|0x12|
|0x02|0x34|
|0x03|0x56|
|0x04|0x78|
## Kích thước con trỏ
+ Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc kiến trúc vi xử lý (stm8, stm32, esp32).
+ stm8 -> 8 bits -> 1 byte
+ stm32 -> 32 bits -> 4 bytes
