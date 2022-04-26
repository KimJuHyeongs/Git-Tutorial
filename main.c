#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define MAX_USER 5
#define MAX_IDPWLEN 10

void disp_calendar();
int check_leap(int);
void enroll_num();
void login_out();
int is_enroll_num(char*, char*);
void logout();

char id[MAX_IDPWLEN][MAX_USER];
char pw[MAX_IDPWLEN][MAX_USER];
int user_cnt = 0, login = 0;

int main(void)
{
    int input, out = 1;
    while (out)
    {
        printf("0.End Program\n1. Make Id\n2. Login\n3.Logout\nEnter number : ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            enroll_num();
            break;
        case 2:
            login_out();
            break;
        case 3:
            logout();
            break;
        case 4:
            disp_calendar();
            break;
        default:
            out = 0;
            break;
        }
    }
    return 0;
}

void disp_calendar()
{
    int year, month, i, tot = 0, start_day = 0, cur_day = 0, cnt = 0;
    printf("Enter Year, Month. ");
    scanf("%d %d", &year, &month);

    for (i = 1; i < year; i++)
    {
        if (check_leap(i))
            tot += 366;
        else
            tot += 365;
    }

    for (i = 0; i < month - 1; i++)
        tot += mdays[i];
    if (check_leap(year) && month > 2)
        tot++;
    tot++;

    start_day += tot % 7;

    cur_day = mdays[month - 1];
    if (check_leap(year) && month == 2)
        cur_day++;

    printf("\n=============< %4d. %2d >=============\n\n", year, month);
    printf("----------------------------------------\n");
    printf("%5s%5s%5s%5s%5s%5s%5s\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");
    printf("----------------------------------------\n");

    for (i = 0; i < start_day; i++)
    {
        printf("%5c", ' ');
        cnt++;
    }

    for (i = 1; i <= cur_day; i++)
    {
        printf("%5d", i);
        cnt++;
        if (cnt % 7 == 0)
            printf("\n");
    }
    printf("\n----------------------------------------\n");
}

int check_leap(int y)
{
    if (y % 4 != 0)
        return 0;
    else if (y % 100 != 0)
        return 1;
    else if (y % 400 == 0)
        return 1;
    else
        return 0;
}

void enroll_num(){
    char i[MAX_IDPWLEN], p[MAX_IDPWLEN];
    printf("Enter Id (within 10) : ");
    fflush(stdin);
    fgets(i,MAX_IDPWLEN,stdin);
    i[strlen(i)-1] = '\0';
    fflush(stdin);
    printf("Endter password (within 10) : ");
    fgets(p,MAX_IDPWLEN,stdin);
    p[strlen(p)-1] = '\0';

    if(user_cnt < MAX_USER){
        strcpy(id[user_cnt],i);
        strcpy(pw[user_cnt],p);
        user_cnt++;
    }
    else    printf("There are full user.\nPlease remove user.\n");
}

void login_out(){
    int idx,login_check=0;
    char i[MAX_IDPWLEN], p[MAX_IDPWLEN];
    printf("Enter your id : ");
    fflush(stdin);
    fgets(i,MAX_IDPWLEN,stdin);
    i[strlen(i)-1] = '\0';
    printf("Enter your password : ");
    fflush(stdin);
    fgets(p,MAX_IDPWLEN,stdin);
    p[strlen(p)-1] = '\0';
    login_check = is_enroll_num(i,p);
    if(login_check){
        printf("Success Login.\n");
        login = 1;
    }
    else printf("Fail Login.\nPlease check your id and password.\n");
}

int is_enroll_num(char* i, char* p){
    int idx,login_check = 0;
    for(idx=0;idx<user_cnt;idx++){
        if ((!strcmp(id[idx],i))&&(!strcmp(pw[idx],p))){
            return 1;
        }
    }
    return 0;
}

void logout(){
    if(login == 0){
        printf("Please Login First.\n");
        return;
    }
    printf("Success Logout\n");
    login = 0;
}