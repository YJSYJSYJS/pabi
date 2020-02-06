#include<iostream>
using namespace std;

void is_leap(int year);

int main(){
    int y;
    cout<<"input year: ";
    cin>>y;
    cout<<y<<" is ";
    is_leap(y);
    cout<<endl;
    return 0;
}

void is_leap(int year){
    if(year%4==0&&year%100!=0||year%400==0)
        cout<<"leap year";
    else
        cout<<"not leap year";
}