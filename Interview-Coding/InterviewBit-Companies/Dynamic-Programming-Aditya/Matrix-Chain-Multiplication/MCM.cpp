
///////////////////  Recursion + Memorization
const int SIZE = 1e3+10;
int dp[SIZE][SIZE];
class Solution{
public:
    
    int solve(int arr[], int i, int j){
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
            
        int val = INT_MAX;
        
        for(int k=i;k<j;k++){
            int temp = solve(arr, i, k) + solve(arr, k+1,j) 
                        + arr[i-1]*arr[k]*arr[j];
                        
            val = min(temp, val);
        }
        
        return dp[i][j] = val;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i=1;
        int j=N-1;
        memset(dp,-1,sizeof(dp));
        
        return solve(arr, i, j);
        
    }
};
