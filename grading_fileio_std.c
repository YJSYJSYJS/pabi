#include<stdio.h>

//데이터를 파일로부터 입력 받아 main 영역 변수에 저장
int getStu(FILE* spStu, int* stuID, int* exam1, int* exam2, int* final);
// 평균값을 사용하여 학점 계산
void calcGrade(int exam1, int exam2, int final, int* avrg, char* grade);
//out.txt 파일로 실행 결과 직접 출력, 모니터에는 나오지 않음
void writeStu(FILE* spGrades, int stuID, int avrg, char grade);

int main(){
    FILE* spStu; // input.txt 입력파일의 주소를 저장할 포인터 변수
    FILE* spGrades;// output.txt 출력파일의 주소를 저장할 포인터변수

    int stuID, exam1, exam2, final; //학번, 과제1, 과제2, 기말
    int avrg;// 평균
    char grade; // 학점
    printf("Begin student grading\n");

    if(!(spStu = fopen("in.txt", "r"))){//읽기모드 열기
        printf("Error opening student file\n");//에러처리
        return 100;
    }
    if(!(spGrades = fopen("out.txt", "w"))){//쓰기모드 열기
        printf("Error opening grades file\n");
        return 102;
    }
    while(getStu(spStu, &stuID, &exam1, &exam2, &final)){
        calcGrade(exam1, exam2, final, &avrg, &grade);
        writeStu(spGrades, stuID, avrg, grade);
    }
    fclose(spStu);//연결된 파일 포인터 변수 닫기
    fclose(spGrades);
    printf("End student grading\n");
    return 0;
}

int getStu(FILE* spStu, int* stuID, int* exam1, int* exam2, int* final){
    int ioResult;//입력데이터 에러여부 확인용 변수
    //데이터를 파일로부터 입력 받아 main 영역 변수에 저장
    ioResult = fscanf(spStu, "%d%d%d%d", stuID, exam1, exam2, final);
    if(ioResult == EOF) // End of File: 파일의 끝 확인
        return 0;
    else if(ioResult != 4){ // 데이터가 4개가 아니면 에러처리
        printf("Error reading data\n");
        return 0;
    } // 파일 데이터가 끝났거나 개수가 다른 경우 0값 리턴
    else
        return 1; // 정상 입력 시 1 값을 리턴
} // getStu

void calcGrade(int exam1, int exam2, int final, int* avrg, char* grade){
    *avrg = (exam1 + exam2 + final)/3;
    if(*avrg >= 90) // 평균값을 사용하여 학점 계산
        *grade = 'A';
    else if(*avrg >= 80)
        *grade = 'B';
    else if(*avrg >= 70)
        *grade = 'C';
    else if(*avrg >= 60)
        *grade = 'D';
    else
        *grade = 'F';
}

void writeStu(FILE* spGrades, int stuID, int avrg, char grade){
    //output.txt 파일로 실행 결과 직접 출력, 모니터에는 나오지 않음
    fprintf(spGrades, "%04d %d %c\n", stuID, avrg, grade);
}