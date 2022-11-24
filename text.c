#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(){
    float array1[4][4] = {{1.0,2.0,3.0,4.0},{5.0,6.0,7.0,8.0},{9.0,10.0,11.0,12.0},{13.0,14.0,15.0,16.0}};
    float array2[4][4];

    int res = syscall(451,array1,array2,4,4);
    printf("System Before Result: %d\n",res);
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%f ",array1[i][j]);
        }
        printf("\n");
    }
    
    printf("System Call Result: %d\n",res);
    
    for(int i =0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("Array Elemnet %d%d: %f\n",i,j,array2[i][j]);
        }
    }
    return 0;
}
