#include <stdio.h>

#define STUDENT_NUM      5 //学生总数

//学生信息结构体
struct STUDENT
{
    char ID[16];
    char name[16];
    float math_grade;
    float english_grade;
    float computer_grade;
};

//给学生结构体定义别名为STUDENT
typedef struct STUDENT STUDENT;

int main()
{
    float grade_sum[STUDENT_NUM];
    float math_grade_max = 0.0; //记录当前高数的最高分
    STUDENT student[STUDENT_NUM];

    //输入学生信息
    printf("请输入学生信息:\n");
    for (int i = 0; i < STUDENT_NUM; i++)
    {
        scanf("%s %s %f %f %f", student[i].ID,
                                student[i].name,
                                &student[i].math_grade,
                                &student[i].english_grade,
                                &student[i].computer_grade);
    }

    //计算每个学生的总分，并得出高数的最高得分
    for (int i = 0; i < STUDENT_NUM; i++)
    {
        grade_sum[i] = student[i].math_grade + student[i].english_grade + student[i].computer_grade;
        if (math_grade_max < student[i].math_grade)
        {
            math_grade_max = student[i].math_grade;
        }
    }

    //打印结果
    for (int i = 0; i < STUDENT_NUM; i++)
    {
        printf("%s 的总分为：%f\n", student[i].name, grade_sum[i]);
    }
    printf("高数最高分为：%f\n", math_grade_max);

    return 0;
}
