// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1if()


// Recurion + memo

class Solution{

	public:
	
	
	map<int,map<int,int>> dp;
	
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        if(sum==0){
            return 1;
        }
        
        if(n==0){
            return 0;
        }
        
        if(dp[n][sum]!=0){
            return dp[n][sum];
        }
        
        
        if(arr[n-1]<=sum){
            return dp[n][sum] = (perfectSum(arr, n-1, sum-arr[n-1]) + perfectSum(arr, n-1, sum));
        }else{
            return dp[n][sum]= perfectSum(arr, n-1, sum);
        }
        
        
        
	}
	  
};

//////////////////////////  Bottom up Aprroach  (ignore mod while using)

class Solution{

	public:
    
    const int mod = 1e9+7;	
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int dp[n+1][sum+1];
        memset(dp, -1 ,sizeof(dp));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0 and j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                if(i==0){
                    dp[i][j]=0;
                    continue;
                }
                
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                
                
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j]%mod + dp[i-1][j-arr[i-1]]%mod)%mod;
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum]%mod;
	}
	  
};