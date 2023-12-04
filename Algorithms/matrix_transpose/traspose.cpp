#include <iostream>

#define R 2
#define C 3

void trasposeMatrix(int A[][C]);

int main(int argc, char** argv)
{
    int A[R][C] = { {1,1,1},{1,1,1} };
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    //Function call
    trasposeMatrix(A);
    return 0;
}


void trasposeMatrix(int M[][C])
{
    for(int i = 0; i < C; i++){
        for(int j = 0; j < R ; j++){
            std::cout << M[j][i] << "\t";
        } std::cout << std::endl;
    }
}