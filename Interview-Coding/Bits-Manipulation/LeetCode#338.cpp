class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> sol(n+1,0);
        
        for(int i=1;i<n+1;i++){
            if(i%2==0){
                sol[i]=sol[i/2];
            }else{
                sol[i]=sol[i/2]+1;
            }
        }
        
        return sol;
    }
};