#include <iostream>

#define N 4

bool areSame(int A[][N], int B[][N]);

int main(int argc, char** argv)
{
   int A[][N] = {  {1, 1, 1, 1}, 
                    {2, 1, 2, 2}, 
                    {3, 3, 3, 3}, 
                    {4, 4, 4, 4} }; 
  
    int B[][N] = {  {1, 1, 1, 1}, 
                    {2, 1, 2, 2}, 
                    {3, 3, 3, 3}, 
                    {4, 4, 4, 4} }; 

//Function call
    if( areSame(A,B) )
        std::cout << "Matrix are identical." << std::endl;
    else
        std::cout << "Matrix are not identical." << std::endl;
    
    return 0;
}


bool areSame(int A[][N], int B[][N]){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] != B[i][j])
                return 0;
        }
    } 
    return 1;
}