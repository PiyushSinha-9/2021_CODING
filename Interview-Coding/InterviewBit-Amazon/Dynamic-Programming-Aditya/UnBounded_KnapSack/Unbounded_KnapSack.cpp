class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        
        
        int dp[n+1][w+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(wt[i-1]<=j){
                    dp[i][j] = max(dp[i][j-wt[i-1]] + val[i-1], dp[i-1][j] );
                }else{
                    dp[i][j] = dp[i-1][j] ;
                }
                
            }
        }
        
        
        return dp[n][w];
        
    }
};