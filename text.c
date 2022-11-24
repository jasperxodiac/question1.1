#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

#define kernel_2D_memcpy 451

int main() {
    float MAT1[4][4] = {{8.0,2.0,3.0,7.0},{3.0,4.0,5.0,6.0},{5.0,9.0,7.0,6.0},{7.0,8.0,9.0,5.0}};
    float MAT2[4][4] = {{1.0,1.0,1.0,4.0},{1.0,1.0,1.0,7.0},{1.0,1.0,1.0,7.0},{1.0,1.0,1.0,6.0}};

    printf("This is the initial matrix1 is:\n");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%lf ", MAT1[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    printf("Given is the eventual matrix2 is:\n");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%lf ", MAT2[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    int res = syscall(kernel_2D_memcpy, MAT1, MAT2, 4, 4);


    printf("This is the final matrix1 is:\n");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%lf ", MAT1[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    printf("Given is the eventual matrix matrix2 is:\n");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%lf ", MAT2[i][j]);
            }
        printf("\n");
    }
    printf("\n"); 
    
    printf("Systemcall or syscalls 451 has been called successfully");

    return 0;
}
