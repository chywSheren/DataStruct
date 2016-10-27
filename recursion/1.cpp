int fibonacci(int n){
	if(n < 1){
		return 0;
	}
	if(n==1 || n==2){
		return 1;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}

//动态规划求矩阵从(0,0)到(i,j)的最短路径 
int minPathSum(int m[][]){
	int len = sizeof(m)/sizeof(int);
	int col = sizeof(m[0])/sizeof(int);
	int row = len/col;
	int dp[row][col];
	for(int i = 0; i < row; i++){
		if(i==0){
			dp[i][0] = data[i][0];
		}else{
			dp[i][0] = data[i][0]+dp[i-1][0];
		}
	}
	
	for(int j = 0; j < col; j++){
		if(j==0){
			dp[0][j] = data[0][j];
		}else{
			dp[0][j] = data[0][j]+dp[0][j-1];
		}
	}
	
	for(int i = 1; i < row; i++){
		for(int j = 1; j < col; j++){
			dp[i][j] = min(dp[i-1][j],dp[i][j-1])+data[i][j];
		}
	}
	return dp[row-1][col-1];
}
