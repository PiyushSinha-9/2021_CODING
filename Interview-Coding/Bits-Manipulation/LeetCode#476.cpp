class Solution {
public:
    int findComplement(int num) {
        int val=0;
        int ind=0;
        
        while(num){
            if((num & 1)==0){
                val+=pow(2,ind);
            }
            num>>=1;
            ind+=1;
        }
           
        return val;
        
    }
};