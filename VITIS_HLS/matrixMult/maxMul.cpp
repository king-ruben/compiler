

#define R1 100
#define C1 100

#define R2 100
#define C2 100


void matrixMul(void){

	//Matrix A
#pragma HLS PIPELINE
	int A[R1][C1];
	for(int i = 0; i < R1; i++){
		for(int j = 0; j < C1; j++){
			A[i][j] = i;
		}
	}

	//Matrix B
	int B[R2][C2];
	for(int i = 0; i < R2; i++){
		for(int j = 0; j < C2; j++){
			B[i][j] = i+1;
		}
	}

	int rslt[R1][C2];
#pragma HLS PIPELINE
	for(int i = 0; i < R1; i++){
		for(int j = 0; j < C2; j++){
			 rslt[i][j] = 0;
			for(int k = 0; k < R2; k++){
				rslt[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}



