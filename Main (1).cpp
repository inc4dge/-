#include<cstdio>
int main()
{
    int x,y,z,sum;
    float average;
    scanf("%d %d %d",&x,&y,&z);
    sum=x+y+z;
    average=(float)sum/3;
    printf("%d\n%.2f",sum,average);
    return 0;
}




