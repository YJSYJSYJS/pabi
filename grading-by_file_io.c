#include<stdio.h>
#include<string.h>
//Input: 학번 과제1(10%) 중간고사(30%) 과제2(20%) 기말고사(40%)
//Output: 학번 평균 학점

int num = 5;

//making input.txt file Function
void make_input(FILE* input);
//grading Function
char* grading(int avr);
//making output.txt file function
void cal_make_output(FILE* input, FILE* output);

int main(){
    FILE* If = fopen("grading_file_io_c\\input.txt","w");
    if(!If){
        printf("Error on opening input file\n");
        return 100;
    }
    FILE* Of = fopen("grading_file_io_c\\output.txt","w");
    if(!Of){
        printf("Error on opening output file\n");
        return 101;
    }

    make_input(If);
    cal_make_output(If, Of);

    fclose(If);
    fclose(Of);
    return 0;
}

void make_input(FILE* input){
    int ID, hw1, mid, hw2, fin;
    float avr;
    char grade[10];
    for(int i=0; i<num; i++){
        printf("ID: ");
        scanf("%d", &ID);
        printf("First Homework: ");
        scanf("%d", &hw1);
        printf("Midterm Exam: ");
        scanf("%d", &mid);
        printf("Second Homeword: ");
        scanf("%d", &hw2);
        printf("Finalterm Exam: ");
        scanf("%d", &fin);
        fprintf(input, "%d %d %d %d %d", ID, hw1, mid, hw2, fin);
        if(i!=num-1)
            fprintf(input, "\n");
    }
}

char* grading(int avr){
    if(avr>=90){
        char* gr = "Aplus";
        return gr;
    }
    else if(avr>=80){
        char* gr = "A";
        return gr;
    }
    else if(avr>=70){
        char* gr = "Bplus";
        return gr;
    }
    else if(avr>=60){
        char* gr = "B";
        return gr;
    }
    else if(avr>=50){
        char* gr = "Cplus";
        return gr;
    }
    else if(avr>=40){
        char* gr = "C";
        return gr;
    }
    else if(avr>=30){
        char* gr = "Dplus";
        return gr;
    }
    else if(avr>=20){
        char* gr = "D";
        return gr;
    }
    else{
        char* gr = "F";
        return gr;
    }
}

//getdelim으로 수정(한줄씩 띄어쓰기로 구분하여 하나씩 받아오기 가능)
void cal_make_output(FILE* input, FILE* output){
    for(int i=0;i<num;i++){
        int id, hw1, mid, hw2, fin;
        float avr;
        char* grade;
        fscanf(input, "%d %d %d %d %d", &id, &hw1, &mid, &hw2, &fin);
        avr = 0.1 * (float)hw1 + 0.3 * (float)mid + 0.2 * (float)hw2 + 0.4 * (float)fin;
        grade = grading(avr);
        fprintf(output, "%d %f %s\n", id, avr, grade);
    }    
}

