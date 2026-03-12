/*
    Description: Tạo một hàm tính tổng bất kỳ số nào đưa vào.
    Sử dụng: Thư viện STDARG và Variadic macro
*/
#include <stdio.h>
#include <stdarg.h>

//  Định nghĩa ham tổng thành hàm sum
#define tong(...) sum(__VA_ARGS__,"ab")

// Hàm tính tổng
int sum(int count,...)
{
    va_list args;    // Khai báo kiểu dữ liệu cho args, check
    va_list check;

    va_start(args, count);  // Lấy đối số đầu tiên - là số lượng phần tử
    va_copy(check, args);   // copy nội dung từ args sang check, sao chép dữ liệu phải cùng kiểu

    int result = count;         // gán result = đối số đầu tiên

    while (va_arg(check, char*) != "ab")     // ép những phần tử từ kiểu int to char để
    {                                        // so sánh với ký tự "ab", tính tổng đến khi gặp ký tự thì dừng
        result += va_arg(args, int);           // args : dùng để tính tổng
    }                                          // check : để kiểm tra dùng

    va_end(args); // kết thúc đối số

    return result;
}


int main(int argc, char const *argv[]) // int argc, char const *argv[]: Dùng khi cần nhập tham số input vào terminal
{
    printf("tong: %d", tong(1, 2, 4, 5, 5, 3, 6,6,7,7,45));
    return 0;
}


```
OUTPUT: tong: 91
```


