#include<stdlib.h>
#include<stdio.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double  monthly_change(retire_info info, double balance){
  balance = balance * (1 + info.rate_of_return) + info.contribution;
  return balance;
}


void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired) //info about being retired
{ double balance = initial;
  int i,j ;
  int age_in_months = startAge;
  int age_in_yrs = 0;
  int months_left = 0;
  for(i=0; i< working.months; i++){
    age_in_yrs = age_in_months/12;
    months_left = age_in_months - age_in_yrs * 12;
    printf("Age %3d month %2d you have $%.2lf\n", age_in_yrs, months_left, balance);
    balance = monthly_change(working, balance);
    age_in_months++;
  }
 
  for(j=0; j< retired.months; j++){
    age_in_yrs = age_in_months/12;
    months_left = age_in_months - age_in_yrs * 12;
    printf("Age %3d month %2d you have $%.2lf\n", age_in_yrs, months_left, balance);
    age_in_months++;
    balance = monthly_change(retired, balance);
    }
  return;
}


int main(){
  
  retire_info working, retired;
  int startAge = 327;
  double initial = 21345.0;
  
  working.months = 489;
  working.contribution = 1000.0;
  working.rate_of_return = 0.045/12;
  
  retired.months = 384;
  retired.contribution = -4000.0;
  retired.rate_of_return = 0.01/12;

  retirement(startAge, initial, working, retired);
  return 0;
}
