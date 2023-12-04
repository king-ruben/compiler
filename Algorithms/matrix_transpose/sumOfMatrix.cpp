#include <iostream>

#define R 2
#define C 3

void matrixAdd(int A[][C], int B[][C]);
void matrixSubs(int A[][C], int B[][C]);

int main(int argc, char** argv)
{
    int A[R][C] = { {1,88,1},
                    {1,0,1} };

    int B[R][C] = { {1,88,15},
                    {-1,0,1} };
    
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            std::cout << A[i][j] << "\t";
        } std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            std::cout << B[i][j] << "\t";
        } std::cout << std::endl;
    }
    std::cout << std::endl;

    //Function call
    matrixAdd(A,B);
  

    return 0;
}

void matrixAdd(int A[][C], int B[][C])
{
    //Sum matrix:
    int S[R][C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            S[i][j] = A[i][j] + B[i][j];
            std::cout << S[i][j] << "\t";
        }   std::cout << std::endl;
    }
}

void matrixSubs(int A[][C], int B[][C])
{
    //Sum matrix:
    int S[R][C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            S[i][j] = A[i][j] - B[i][j];
            std::cout << S[i][j] << "\t";
        }   std::cout << std::endl;
    }
}

