# Bài 2: Thư viện STDARG và ASSERT
## 1. Thư viện STDARG
### Chức năng của thư viện STDARG?
  + Cung cấp các phương thức để làm việc với các hàm có số lượng input parameter không cố định.
  + Các hàm như printf và scanf là ví dụ điển hình.
### Hàm có trong thư viện STDARG?
-----
|Tên hàm|Chức năng|
|---------|---------------------------|
|`va_list`| Là một kiểu dữ liệu để đại diện cho danh sách các đối số biến đổi|
|`va_start`| Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên|
|`va_arg`| Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai|
|`va_end`| Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm|
|`va_copy`| Sao chép dữ liệu giữa 2 biến cùng kiểu va_list|
#### Ví dụ các hàm
```c
#include <stdio.h>
#include <stdarg.h>

void test(int count, ...)
{
    va_list(args); // typedef char* va_list
                   // args = "int count, 100,12,"hello","a",3.5"
    va_start(args, count);  // args = "100,12,"hello","a",3.5"
                            // args = ["\100","\12","hello","\a"","\3.5"]

    printf("value 1: %d\n", va_arg(args,int)); // "\100" -> (int)"\1" = 1
    printf("value 2: %d\n", va_arg(args,int));
    printf("value 3: %s\n", va_arg(args,char*));
    printf("value 4: %c\n", va_arg(args,char*));
    printf("value 5: %f\n", va_arg(args,double));

    va_end(args);   // Thu hồi pointer address
}

int main(int argc, char const *argv[]){
    test(5, 100, 12, "hello", 'a', 3.5);
}
```
#### Output
```
value 1: 100
value 2: 12
value 3: hello
value 4: a
value 5: 3.500000
```

## 2. Thư viện ASSERT
+ Cung cấp macro assert. 
+ Macro này được sử dụng để kiểm tra một điều kiện. 
+ Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
+ Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.
+ **Dùng trong debug, dùng #define NDEBUG để tắt debug**
### Cú pháp sử dụng của hàm **assert**
```c
#include <stdio.h>
#include <assert.h>

/*
hàm assert(Điều kiện);
- Dùng để debug
- Lỗi thì dừng chương trình lập tức và in ra dòng bị lỗi
*/

void divide(int x){
    assert(x == 5 && "X is not a number 5");
    printf("%d la so 5", x);
}
int main()
{
    divide(6);
}
```
#### Output
```
assertion "x == 5 && "X is not a number 5"" failed: file "assert.c", line 11, function: divide
```



