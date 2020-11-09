/***********************************************
答案：
1、没有加以下三个头文件 
    #include <stdio.h>    // printf()
    #include <string.h>   // strcpy()
    #include <stdlib.h>   // malloc()
2、get_str1()函数无法获得msg的内容，因为其获得的内存的作用域有效范围仅仅在该函数内，因此第28行代码无法获得其内容
3、第30、31行的strcpy应该改为strcat()或strncat()
4、get_str2()函数中申请的msg内存在不使用后应该free()掉
***********************************************/

int main()
{

    return 0;
}
