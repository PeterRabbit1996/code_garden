第一部分（至少回答1题）
1. 实现一个string数据结构，能够动态管理自符串缓冲区，给出几个关键函数的实现代码。
2. 实现一个Matrix C++类，实现下面的矩阵访问方式，矩阵只用考虑存储double类型元素：
```
  Matrx a;
  a[i][j] = 10.0;
  double count = a[i+1][j];
```

第二部分（至少回答3题）：
1. 编写代码，将一个字符串分割为字符串数组，
   如：csv文件的一行字符为： “1,2,3,4”，分割符为','，则分割后为：
   "1"
   "2"
   "3"
   "4"

2. 假设你有个array（长度为N），它包含了1～N天的股票价格，你最多只能交易一个回合（先买后卖），那么使用代码计算你能获取的最大收益，时间复杂度限制为O(N)。

3. 请找出以下程序的所有问题：
 ```
 1 
 2 static char *
 3 get_str1(void)
 4 {
 5      char msg[128];
 6 
 7      strcpy(msg, "Hello");
 8 
 9      return msg;
10 }
11 
12 
13 static char *
14 get_str2(void)
15 {
16       char *msg;
17 
18       msg = malloc(128*sizeof(char));
19 
20       strcpy(msg, "Hello");
21 
22       return msg;
23 }
24 
25 int
26 main(int argc, char *argv[])
27 {
28        char *buff1 = get_str1();
28        char *buff2 = get_str2();
29 
30        strcpy(buff1, " World!\n");
31        strcpy(buff2, " World!\n");
32 
33        printf("%s", buff1);
34        printf("%s", buff2);
35 
36        return 0;
37 }
```

4. 请找出数组中唯一的重复数值。
数值1-10000放在含有10001个元素的数组中，它们中只有唯一的一个数值重复，其它均只出现一次。
每个数组元素只能访问一次，设计一个算法，将这个数值找出来。（注意：不使用辅助存储空间）

第3部分：（至少回答1题）
1. 有哪些方式可以降低程序执行延迟？
2. 有哪些方式可以提高程序的吞吐量？




  


