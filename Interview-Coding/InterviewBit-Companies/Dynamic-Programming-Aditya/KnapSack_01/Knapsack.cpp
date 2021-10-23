
// Recursion

int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    
    if(n==0 or W==0){
        return 0;
    }
    
    
    if(wt[n-1] <= W){
        return  max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W,wt,val,n-1));
    }else{
        return knapSack(W,wt,val,n-1);
    }
    
}


// Recursion + Memorization

 map<int,map<int,int>> dp;
    
int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    
    if(n==0 or W==0){
        return 0;
    }
    
    if(dp[W][n] != 0){
        return dp[W][n];
    }
    
    if(wt[n-1] <= W){
        return dp[W][n] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W,wt,val,n-1));
    }else{
        return dp[W][n] = knapSack(W,wt,val,n-1);
    }
    
}


// Bottom-up 

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       int dp[n+1][W+1];
       memset(dp, -1, sizeof(dp));
       
       
       for(int i=0;i<n+1;i++){
           for(int j=0;j<W+1;j++){
               if(i==0 or j==0){
                   dp[i][j] = 0;
                   continue;
               }
               
               if(wt[i-1] <= j){
                   dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j-wt[i-1]]);
               }else{
                   dp[i][j] = dp[i-1][j];
               }
               
           }
       }
       
       return dp[n][W];
      
       
    }

