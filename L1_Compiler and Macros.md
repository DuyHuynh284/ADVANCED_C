# Bài 1: Compiler và Macros 
## 1. Compiler làm gì?
- Máy tính, MCU chỉ làm việc với hệ nhị phân 0|1 chính vì vậy cần compiler để chuyển các ngôn ngữ bậc cao như C, C++,...
sang nhị phân thì máy tính, MCU mới hiểu và thực thi được ví dụ như nói chuyện với người nước ngoài cần 1 công cụ dịch thuật 
như google dịch để dịch ngôn ngữ của mình sang ngôn ngữ họ để họ hiểu.  
###  Đặc điểm của Compiler?
- Quá trình biên dịch trải qua 4 giai đoạn chính
 ----
| Bước | Tên bước        | Mô tả |Cú pháp|
|-----|-----------------|------|----------|
| 1   | Preprocessing        | Thực hiện copy mã nguồn của thư viện, thay thế macro|gcc -E main.c -o main.i|
| 2   | Compilation           | Biên dịch sang ngôn ngữ assembly để tương tác với máy tính |gcc -S main.i -o main.s|
| 3   | Assemble        | Chuyển thành file chứa mã nhị phân có quy tắc để máy tính hiểu và thực thi được  |gcc -c main.s -o main.o|
| 4   | Linking      | Liên kết các file object từ bước 3 thành file exe để chạy chương trình |gcc <file.o> main.o -o main|

## 2. Macro là gì?
- Là từ hay chỉ thị dùng để chỉ những thông tin được xử lý ở quá trình tiền xử lý. 
- Macro được chia thành 3 nhóm chính:
    + Chỉ thị bao hàm tệp (**#include**)
    + Chỉ thị định nghĩa, hủy định nghĩa (**#define, #undef**)
    + Chỉ thị biên dịch có điều kiện (**#if, #elif, #else, #ifdef, #ifndef, #endif**)
### *Chỉ Thị bao hàm tệp (#include)*
  + Chỉ thị **#include** dùng để chèn nội dung của một file vào mã nguồn chương trình.
  +	Tái sử dụng mã nguồn.
  +	Phân chia chương trình thành các phần nhỏ, giúp quản lý mã nguồn hiệu quả.
```                            
#include <stdio.h>
#include "library.h"
```                            
### *Chỉ thị định nghĩa (#define)*
  +	Macro là một khái niệm dùng để định nghĩa một tập hợp các hướng dẫn tiền xử lý
  +	Dùng để thay thế một chuỗi mã nguồn bằng một chuỗi khác trước khi chương trình biên dịch.
  +	Giúp giảm lặp lại mã, dễ bảo trì chương trình.
  +	Macro được định nghĩa bằng cách sử dụng chỉ thị tiền xử lý **#define**
``` 
#define SIZE 50
#define PI 3.14
```
### *Chỉ thị hủy định nghĩa (#undef)*
  +	Chỉ thị #undef dùng để hủy định nghĩa của một macro đã được định nghĩa trước đó bằng **#define**.
``` 
#define SIZE 50
#undef SIZE
```
### *Chỉ thị biên dịch có điều kiện (#if, #elif, #else)*
+ #if sử dụng để bắt đầu một điều kiện tiền xử lý.
+ Nếu điều kiện trong #if là đúng, các dòng mã nguồn sau #if sẽ được biên dịch
+ Nếu sai, các dòng mã nguồn sẽ bị bỏ qua đến khi gặp #endif
+ #elif dùng để thêm một điều kiện mới khi điều kiện trước đó trong #if hoặc #elif là sai
+ #else dùng khi không có điều kiện nào ở trên đúng.
```c 
#include <stdio.h>

typedef enum{
    LOW,    // LOW = 0
    HIGH    // HIGH = 1
} Status;

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
} Pin;

#define ESP32      1
#define STM32      2
#define ATmega324  3

#define MCU STM32

#if MCU == STM32
    void digitalWrite(Pin pin, Status state) {
        if (state == HIGH){
            GPIOA->BSRR = (1 << pin);  // Đặt bit tương ứng để thiết lập chân
        }
        else {
            GPIOA->BSRR = (1 << (pin + 16));  // Đặt bit tương ứng để reset chân
        }
    }

#elif MCU == ESP32
    void digitalWrite(Pin pin, Status state) {
        if (state == HIGH) {
            GPIO.out_w1ts = (1 << pin);  // Đặt bit tương ứng để thiết lập chân HIGH
        }
        else {
            GPIO.out_w1tc = (1 << pin);  // Đặt bit tương ứng để reset chân LOW
        }
    }

#else
    void digitalWrite(Pin pin, Status state) {
        if (state == HIGH) {
            PORTA |= (1 << pin);  // Đặt bit tương ứng để thiết lập chân HIGH
        }
        else {
            PORTA &= ~(1 << pin);  // Xóa bit tương ứng để reset chân LOW
        }
    }
   
#endif

int main(int argc, char const *argv[])
{
    while(1)
    {
        digitalWrite(PIN0, HIGH);
        // delay(1);
    }

    return 0;
```
### *Chỉ thị biên dịch có điều kiện (#ifdef, #ifndef,#endif)*
+	#ifdef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì mã nguồn sau #ifdef sẽ được biên dịch.
+	#ifndef dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro chưa được định nghĩa thì mã nguồn sau #ifndef sẽ được biên dịch.
+ #endif để kết thúc việc kiểm tra
  
