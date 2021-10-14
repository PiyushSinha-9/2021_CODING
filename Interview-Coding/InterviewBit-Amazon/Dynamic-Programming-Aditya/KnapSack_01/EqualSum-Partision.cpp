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

    int equalPartition(int N, int arr[])
    {
        // code here
        
        int totalSum =0;
        for(int i=0;i<N;i++){
            totalSum+=arr[i];
        }
        
        if(totalSum % 2 !=0){
            return false;
        }
        
        return isSubsetSum(N,arr,totalSum/2);
        
    }
};