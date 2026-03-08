#include <stdio.h>
#include <assert.h>

/*
hàm assert(Điều kiện);
- Dùng để debug
- Lỗi thì dừng chương trình và hiện lỗi tại dòng nào
*/

void divide(int x){
    assert(x == 5 && "X is not a number 5");
    printf("%d la so 5", x);
}


int main()
{
    divide(6);
}