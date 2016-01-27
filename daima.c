#include<stdio.h>
int main()
{
int a,b,c,d,e,f,g;
scanf("%d %d",&a,&b);
c=a+b;
if(c<1000&&c>-1000)
printf("%d",c);
else if(c<1000000&&c>-1000000)
{d=c%1000;
e=c/1000;
if(d<0)
d=-d;
printf("%d,%03d",e,d);}
else
{d=c%1000;
e=c/1000;
f=e%1000;
g=e/1000;
if(d<0)
d=-d;
if(f<0)
f=-f;
printf("%d,%03d,%03d",g,f,d);}
return 0;}
