#include <iostream>

#define ROWS_M1 2
#define COLS_M1 2

#define ROWS_M2 2
#define COLS_M2 2

void mulMat(int mat1[][COLS_M1], int mat2[][COLS_M2]);

int main(int argc, char** argv)
{

    
    int mat1[ROWS_M1][COLS_M1] = { {1,1}, 
                                   {2,0} };

    int mat2[ROWS_M2][COLS_M2] = { {0,1}, 
                                   {1,0} };

    if(COLS_M1 != ROWS_M2){
        std::cout << "The number of columns in Matrix-1 must "
                "be equal to the number of rows in "
                "Matrix-2"
                << std::endl;

        exit(EXIT_FAILURE);
    }

    
    mulMat(mat1,mat2);

    return 0;
}

void mulMat(int mat1[][COLS_M1], int mat2[][COLS_M2])
{
    int rslt[ROWS_M1][COLS_M2];
    for(int i = 0; i < ROWS_M1; i++){
        for(int j = 0; j < COLS_M2; j++){
            rslt[i][j] = 0;

            for(int k = 0; k < ROWS_M2; k++){
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }

            std::cout << rslt[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}