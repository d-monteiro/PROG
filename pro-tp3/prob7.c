#include <stdio.h>

int anos(float pa,float pb,float ta,float tb) {
    
    int anos =0;
    while (pb<pa) {
        pa*=(1+(ta/100));
        pb*=(1+(tb/100));
        anos++;
    }
    return anos;
    
}

int main () {
    float ta,tb,pa,pb;
    scanf(" %f %f %f %f",&pa,&pb,&ta,&tb);
    printf("%d\n",anos(pa,pb,ta,tb));
    return 0;
}