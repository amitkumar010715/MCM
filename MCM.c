
// // matrix chain multiplication using recursion

// #include <limits.h>
// #include <stdio.h>

// // Matrix Ai has dimension p[i-1] x p[i]
// // for i = 1 . . . n
// int MCM(int p[], int i, int j)
// {
// 	if (i>=j)
// 		return 0;
// 	int k;
// 	int min = INT_MAX;// meanse infinity
// 	int count;

// 	for (k = i; k < j; k++)
// 	{
// 		count = MCM(p, i, k)
// 				+ MCM(p, k + 1, j)
// 				+ p[i - 1] * p[k] * p[j];

// 		if (count < min)
// 			min = count;
// 	}

// 	return min; //min count
// }

// int main()
// {
// 	int arr[] = { 1, 2, 3, 4, 3 };
// 	int N = sizeof(arr) / sizeof(arr[0]);

// 	printf("Minimum number of multiplications is %d ",
// 		MCM(arr, 1, N - 1));

// 	return 0;
// }

// *****************memoize_version**********************

// #include <limits.h>
// #include <stdio.h>

// int MCM_MEMO(int p[], int i, int j, int R[][21]);

// int R[21][21];

// void MCM_memo_start(int p[], int N, int R[][21])
// {

// 	for (int i = 0; i < N; i++)
// 	{
// 		for (int j = 0; j < N; j++)
// 		{
// 			R[i][j] = INT_MAX;
// 		}

// 		for (int i = 0; i < N; i++)
// 		{
// 			R[i][i] = 0;
// 		}
// 	}
// 	printf("Minimum number of multiplications is %d ", MCM_MEMO(p, 1, N - 1, R));
// }
// int MCM_MEMO(int p[], int i, int j, int R[][21])
// {
// 	int min, count;
// 	if (i >= j)
// 	{
// 		return 0;
// 	}
// 	if (R[i][j] < INT_MAX)
// 	{
// 		return R[i][j];
// 	}
// 	else
// 	{
// 		min = INT_MAX;
// 		for (int k = i; k < j; k++)
// 		{
// 			count = MCM_MEMO(p, i, k, R) + MCM_MEMO(p, k + 1, j, R) + p[i - 1] * p[k] * p[j];

// 			if (count < min)
// 				min = count;
// 		}
// 		R[i][j] = min;
// 		return R[i][j]; // instead of two line we can also write only 'return min' as like recursive version above but in dp recursive we have to store in arr.
// 	}
// }

// int main()
// {
// 	int p[] = {1, 2, 3, 4, 3};
// 	int N = sizeof(p) / sizeof(p[0]);

// 	MCM_memo_start(p, N, R);

// 	return 0;
// }

// *****************************DP solution*******************

#include <stdio.h>
#include <limits.h>

int S[21][21];

void print_optimal_parenthesis(int i,int j){
int k;
	if(i==j){
		printf("A%d",i);
	}
	else
	{
		k=S[i][j];
		printf("(");
		print_optimal_parenthesis(i,S[i][j]);
		print_optimal_parenthesis(S[i][j]+1,j);
		printf(")");
	}
	
}
void MCM_DP(int p[], int N, int R[][21])
{
	int i, j, length ,k;
	for (i = 1; i <= N; i++)
	{
		R[i][i] = 0;
	}
	for (length = 2; length <= N; length++)
	{
		for (int i = 1; i <N-length+1; i++)
		{
			j = (i+length-1);

			R[i][j] = INT_MAX;
			for ( k = i; i < j - 1; k++)
			{
				int val = R[i][k] + R[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (val < R[i][j])
				{
					R[i][j] = val;
					S[i][j] = k;
					
				}
			}
		}
	}
print_optimal_parenthesis(i,j);
printf("%d",R[1][N]) ;
}
int main()
{
 int N,i,j,result,row,col;
 int p[21],R[21][21];
 printf("enter no of matrices\t");
 scanf("%d",&N);
 for ( i = 1; i <=N; i++)
 {
	printf("\nenter order of A[%d]\t",i);
	scanf("%d%d",&row,&col);
	p[i-1]=row;p[i]=col;
 }
 MCM_DP(p,N,R);
//  printf("minimum number of steps using mcm_dp: %d \n",result);
	return 0;
}


