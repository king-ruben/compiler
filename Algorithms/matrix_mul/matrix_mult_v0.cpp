#include <iostream>


/**
 * v0
*/
int main(int argc, char** argv)
{
    int m1[2][2] = { {5,5}, 
                     {6,6} };

    int m2[2][2] = { {7,8},
                     {10,11} };



    // std::cout << "Matrix1: " << std::endl;
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         std::cout << m1[i][j] << "\t";
    //     }   std::cout << std::endl;
    // }

    //  std::cout << "Matrix2: " << std::endl;
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         std::cout << m2[i][j] << "\t";
    //     }   
    //       std::cout << std::endl;
    // }

    //Result matrix(C=AxB)
    std::cout <<"Result: "<< std::endl;
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            int sum = 0;
            for(int k = 0;  k< 2; k++){
            sum = sum + m1[i][k] * m2[k][j];
            }

            std::cout << sum << "\t";
        }   std::cout << std::endl;
    }

    return 0;
}