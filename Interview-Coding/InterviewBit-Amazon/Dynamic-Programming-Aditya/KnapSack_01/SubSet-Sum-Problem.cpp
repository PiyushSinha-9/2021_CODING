
// Bottom-up 

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        
        bool dp[N+1][sum+1];
        memset(dp,false, sizeof(dp));
        
        for(int i=0;i<N+1;i++){
            for(int j=0;j<sum+1;j++){
                
                
                if(j==0 and i==0){
                    dp[i][j] = true;
                    continue;
                }
                
                if(j==0){
                    dp[i][j]=true;
                    continue;
                }
                
                if(i==0){
                    dp[i][j]=false;
                    continue;
                }
                
                
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
                
                
            }
        }
        
        
        return dp[N][sum];
        
    }
};


// Recursion + memorization

const int sumSize = 1e5+2;
int dp[102][sumSize];
    
class Solution{   
public:
    
    bool solve(int n, int arr[], int sum){
        if(sum == 0) return true;
        
        if( n==0 ) return false;
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        if(arr[n-1] <= sum){
            return dp[n][sum] = (solve(n-1,arr,sum-arr[n-1]) or solve(n-1,arr,sum));
        }else{
            return dp[n][sum] = solve(n-1,arr,sum);
        }
    }
    

    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        
        memset(dp,-1,sizeof(dp));
        
        return solve(n,arr, sum);
    }
};
