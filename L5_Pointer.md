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
### Kích thước con trỏ
+ Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc kiến trúc vi xử lý (stm8, stm32, esp32).
+ stm8 -> 8 bits -> 1 byte
+ stm32 -> 32 bits -> 4 bytes

## 3. Các loại con trỏ
### Void Pointer
+ Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
+ Cú pháp:
```
void *ptr_void;
```
### Function Pointer
+ Con trỏ hàm là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
+ Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
+ Cú pháp:
```
<return_type> (*func_pointer)(<data_type_1>, <data_type_2>);
```
### Pointer to Const (Con trỏ hằng)
+ Là cách định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
+ 0x01 (10) -> đọc giá trị 10, không được phép thay đổi
+ 0x02 (20) -> đọc giá trị 20
+ Cú pháp:
```
<data_type> const *ptr_const;
const <data_type> *ptr_const;
```
### Constant Pointer (Hằng con trỏ)
+ Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
+ 0x01 (10) -> đọc giá trị, ghi giá trị mới (20)
+ 0x02 -> không thể trỏ tới
+ Cú pháp:
```
int *const const_ptr = &value;
```

```C
#include <stdio.h>

// DIFF
//"Const char *" is a pointer to a const char.
//"char * const" is a constant pointer to a char.
// "const char * const"

int main(){
    char a = 'A';
    char b = 'B';
    char c = 'C';
  
    const char *ptr = &a;
    *ptr = 'B';   // error: Lỗi vì  value không được thay đổi 
    ptr = &b;    // address thay đổi được
    
    char *const ptr1 = &b;
    *ptr1 = 'A';   //  value thay đổi được
    ptr1 = &b;    // error: Lỗi vì address không  được thay đổi
    
    const char * const ptr2 = &c;
    *ptr2 = 'B';   // error: Lỗi vì value không được thay đổi 
    ptr2 = &c;    // error: Lỗi vì address không được thay đổi 

    return 0;
}


```




### Pointer to pointer
+ Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. 
+ Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
+ Cú pháp:
```
int test = 5;      // Address: 0x01
                   // Value:	5

int *ptr = &test;  // Address: 	0xf1
                   // Value:	0x01

int **ptp = &ptr;  // Address: 	0xe1
                   // Value:	0xf1
```
#### Ứng dụng
+ Kiểu dữ liệu JSON
+ Cấu trúc dữ liệu danh sách liên kết

### Null Pointer
+ Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. 
+ Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null, C++ (NULL, nullptr).
Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa.
+ Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.


