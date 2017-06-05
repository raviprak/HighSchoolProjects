#include<iostream.h>
#include<conio.h>
#include<time.h>

float start, end;

void str()
{
 start=clock();
}

float endd()
{
 float temp=clock();
 end=(temp-start);
 return end;
}
