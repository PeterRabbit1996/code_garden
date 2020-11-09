#include <stdio.h>

#define STUDENT_NUM      5 //学生总数

//学生信息结构体
struct STUDENT
{
    char ID[16];
    char name[16];
    float grade_chinese; //语文成绩
    float grade_math;    //数学成绩
    float grade_english; //英语成绩
    float grade_sum;     //总分
    float grade_average; //平均成绩
};

//给学生结构体定义别名为STUDENT
typedef struct STUDENT STUDENT;

// student:学生信息结构体, size:学生数量，即结构体大小
int sync_to_file(STUDENT student[], int size)
{
    FILE *fd = NULL;

    // 打开文件
    if ((fd = fopen("c.txt", "a+")) == NULL)
        return -1;

    for (int i = 0; i < size; i++)
    {
        // fprintf 格式化将学生信息输出到文件中，类似于 printf 格式化输出到屏幕中。
        // 用法参考 http://c.biancheng.net/cpp/html/2520.html
        fprintf(fd, "%s %s %f %f %f %f %f\n", 
                     student[i].ID,
                     student[i].name,
                     student[i].grade_chinese,
                     student[i].grade_math,
                     student[i].grade_english,
                     student[i].grade_sum,
                     student[i].grade_average);
    }

    // 关闭文件
    fclose(fd);

    return 0;
}

int main()
{
    STUDENT student[STUDENT_NUM];

    for (int i = 0; i < STUDENT_NUM; i++)
    {
        scanf("%s %s %f %f %f", student[i].ID,
                                student[i].name,
                                &student[i].grade_chinese,
                                &student[i].grade_math,
                                &student[i].grade_english);
        student[i].grade_sum = student[i].grade_chinese + student[i].grade_math + student[i].grade_english;
        student[i].grade_average = student[i].grade_sum / 3.0;
    }

    if(sync_to_file(student, STUDENT_NUM) < 0)
        return -1;

    return 0;
}
