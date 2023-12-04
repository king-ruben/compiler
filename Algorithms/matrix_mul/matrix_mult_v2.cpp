

//First I'll recreate v1

#include <iostream>

#define R1 2
#define C1 2

#define R2 2
#define C2 2

void matrixMult(int A[R1][C1], int B[R2][C2]);

int main(int argc, char** argv)
{
    int A[R1][C1];
    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C1; j++){
            A[i][j] = 5;
        }
    }

    int B[R2][C2];
    for(int i = 0; i < R2; i++){
        for(int j = 0; j < C2; j++){
            B[i][j] = 5;
        }
    }

    if(R1 != C2){
        std::cout << "Matrix dimensions error" << std::endl;
        exit(EXIT_FAILURE);
    }
    //Function call
    matrixMult(A,B);

    return 0;
}


void matrixMult(int A[R1][C1], int B[R2][C2])
{
    int rslt[R1][C2];
    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C2; j++){
            rslt[i][j] = 0;
            for(int k = 0; k < R2; k++){
             rslt[i][j] += A[i][k] * B[k][j];
            }
            std::cout << rslt[i][j] << "\t";
        }
            std::cout << std::endl;
    }

}