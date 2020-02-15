#include<stdio.h>

int main(){
    struct stu{
        int id;
        float kor, eng, math;
        float avg;
        char grade;
    };
    typedef struct stu stu;
    
    int num;
    printf("how many students are in your class?: ");
    scanf("%d", &num);
    printf("start to input %d students' info\n", num);
    stu s[40];
    for(int i=0;i<num;i++){
        printf("<input student %d's info>\n", i+1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Korean score: ");
        scanf("%f", &s[i].kor);
        printf("English score: ");
        scanf("%f", &s[i].eng);
        printf("Math score: ");
        scanf("%f", &s[i].math);    
        float sum = (s[i].kor + s[i].eng + s[i].math);
        s[i].avg = sum/3;
        printf("Average score: %f\n", s[i].avg);
        if(s[i].avg>=90)
            s[i].grade = 'A';
        else if(s[i].avg>=80)
            s[i].grade = 'B';
        else if(s[i].avg>=70)
            s[i].grade = 'C';
        else if(s[i].avg>=60)
            s[i].grade = 'D';
        else
        {
            s[i].grade = 'F';
        }
        printf("Grade: %c\n", s[i].grade);
    }
    return 0;
}