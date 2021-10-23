////////////////////////////////////////////  Nice Recurion + Memorization Approach (TLE THOU ;-(  )  ))
const int INF = INT_MAX;
const int SIZE = 501;

int dp[SIZE][SIZE];
class Solution {
public:
    int n;
    
    int solve(vector<int> arr, int i, int j){
        
        if(i==j){
            
            int tempSol = arr[i];
            if(i!=0){
               tempSol*=arr[i-1];
            }
            if(i!=n){
               tempSol*=arr[i+1];
            }
            
            return tempSol;
        }
        
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int val = 0;
        
        for(int k=i;k<=j;k++){
            
            int tempSol = arr[k];
            if(i!=0){
               tempSol*=arr[i-1];
            }
            if(j!=n){
               tempSol*=arr[j+1];
            }
            
            int temp = solve(arr,i,k-1) + solve(arr, k+1,j) + tempSol;
            val = max(temp, val);
        }
        
        return dp[i][j] = val;
        
    }
    
    
    int maxCoins(vector<int>& nums) {
        n=nums.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(nums, 0, n);
    }
};