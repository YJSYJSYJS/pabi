// fscanf와 fprintf가 파일포인터를 공유하기 때문에 파일포인터를 조정해줘야함
#include<stdio.h>
//Input: 학번 과제1(10%) 중간고사(30%) 과제2(20%) 기말고사(40%)
//Output: 학번 평균 학점

int num = 5;
int g;
//making input.txt file Function
void make_input(FILE* input);
//grading Function
char* grading(int avr);
//making output.txt file function
void cal_make_output(FILE* input, FILE* output);

int main(){
    FILE* If = fopen("grading_file_io_c/input.txt","w");
    if(!If){
        printf("Error on opening input file\n");
        return 100;
    }
    FILE* Of = fopen("grading_file_io_c/output.txt","w");
    if(!Of){
        printf("Error on opening output file\n");
        return 101;
    }

    for(int i=0; i<num; i++){
        g = ftell(If);
        make_input(If);
        g = g - ftell(If);
        fseek(If, g, SEEK_END);
        cal_make_output(If, Of);
        fseek(If, -g, SEEK_END);
    }

    fclose(If);
    fclose(Of);
    
    return 0;
}

void make_input(FILE* input){
    int ID, hw1, mid, hw2, fin;
    float avr;
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
    fprintf(input, "\n");
    //여러번의 fprintf로 인해 파일포인터가 뒤로 이동 - > fscanf 사용 시 파일포인터를 되돌려줘야할 필요
    fflush(input);
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

void cal_make_output(FILE* input, FILE* output){
        int id, hw1, mid, hw2, fin;
        float avr;
        char* grade;
        //fscanf 사용시 file pointer 자동으로 증가!!!
        //make_input에서 사용한 fprintf로 인해 파일포인터를 앞으로 되돌려줘야함 -> rewind 함수 사용 - main
        //rewind함수로 인해 input파일의 파일포인터가 입력될때마다 초기화되는 문제발생 -> fseek함수로 대체
        //fseek(input, )
        fscanf(input, "%d %d %d %d %d", &id, &hw1, &mid, &hw2, &fin);
        printf("%d %d %d %d %d\n", id, hw1, mid, hw2, fin);
        avr = 0.1 * (float)hw1 + 0.3 * (float)mid + 0.2 * (float)hw2 + 0.4 * (float)fin;
        grade = grading(avr);
        fprintf(output, "%d %f %s\n", id, avr, grade);
}