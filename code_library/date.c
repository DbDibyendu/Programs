#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day,month,year,day_in_feb=28;
    printf("Enter the date");
    scanf("%d%d%d",&day,&month,&year);
    if((year%4==0&&year%100!=0)||(year%400==0))
    {
        day_in_feb=29;
    }

        switch(month)
 {
    case 2:
        day+= 31;
        break;
    case 3:
        day += 31+day_in_feb;
        break;
    case 4:
        day += 31+day_in_feb+31;
        break;
    case 5:
        day += 31+day_in_feb+31+30;
        break;
    case 6:
        day += 31+day_in_feb+31+30+31;
        break;
    case 7:
        day +=31+day_in_feb+31+30+31+30;
        break;
    case 8:
        day +=31+day_in_feb+31+30+31+30+31;
        break;
    case 9:
        day +=31+day_in_feb+31+30+31+30+31+30;
        break;
    case 10:
        day +=31+day_in_feb+31+30+31+30+31+30+31;
        break;
    case 11:
        day +=31+day_in_feb+31+30+31+30+31+30+31+30;
        break;
    case 12:
        day +=31+day_in_feb+31+30+31+30+31+30+31+30+31;
        break;
 }
   int weekday=day%7;
        switch(weekday)
        {
        case 0:
            printf("The day is sunday");
            break;
        case 1:
            printf("The day is monday");
            break;
        case 2:
            printf("The day is tuesday");
            break;
        case 3:
            printf("The day is wednesday");
            break;
        case 4:
            printf("The day is thursday");
            break;
        case 5:
            printf("The day is friday");
            break;
        case 6:
            printf("The day is saturday");
            break;

        }

    printf("%d",day);


        return 0;

    }
