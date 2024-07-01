#include<stdio.h>
struct complex_number{
    int x;
    int y;
}c;
void multi(struct complex_number c[],int* x3,int* y3){
    *x3 = ((c[0].x) *(c[1].x))-((c[0].y)*(c[1].y));
    *y3 = ((c[0].x) *(c[1].y))+((c[0].y)*(c[1].x));
}
int main(){
    struct complex_number c[2];
    for(int i=0;i<2;i++){
        printf("Enter The Number%d:- ",i+1);
        scanf("%d",&c[i].x);
        printf("Enter The Number%d:- ",i+1);
        scanf("%d",&c[i].y);
    }
    int x3,y3;
    multi(c,&x3,&y3);
    printf("Complex Number After Multiplication: %d + %di\n",x3,y3);
    return 0;
}
