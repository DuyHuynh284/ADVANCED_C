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
