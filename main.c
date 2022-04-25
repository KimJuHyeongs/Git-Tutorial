#include<stdio.h>
#include<stdlib.h>

int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void disp_calendar();
int check_leap(int);

int main(void){
    int input;
    printf("0.End Program\n1. display calendar\nEnter number : ");
    scanf("%d",&input);
    switch(input){
        case 1:
            disp_calendar();
            break;
        default:
            exit(0);
            break;
    }

}

void disp_calendar(){
    int year, month, i, tot=0, start_day = 0, cur_day = 0, cnt=0;
    printf("Enter Year, Month. ");
    scanf("%d %d",&year, &month);

    for(i=1;i<year;i++){
        if(check_leap(i)) tot+=366;
        else tot+=365;
    }

    for(i=0;i<month-1;i++) tot += mdays[i];
    if(check_leap(year)&&month>2) tot++;
    tot++;

    start_day += tot%7;

    cur_day = mdays[month-1];
    if(check_leap(year)&&month==2) cur_day++;

    printf("\n=============< %4d. %2d >=============\n\n", year,month);
    printf("----------------------------------------\n");
    printf("%5s%5s%5s%5s%5s%5s%5s\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");
    printf("----------------------------------------\n");

    for(i=0;i<start_day;i++){
        printf("%5c", ' ');
        cnt++;
    }

    for(i=1; i<=cur_day;i++){
        printf("%5d", i);
        cnt++;
        if(cnt%7 == 0) printf("\n");
    }
    printf("\n----------------------------------------\n");
}

int check_leap(int y){
    if (y%4!=0) return 0;
    else if(y%100!=0) return 1;
    else if(y%400==0) return 1;
    else return 0;
}