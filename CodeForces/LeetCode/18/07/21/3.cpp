//https://leetcode.com/problems/zigzag-conversion/submissions/

class Solution {
public:
string convert(string s, int numRows) {
int i=0,j,k=0;
if(numRows==1) return s;
string cat[numRows],ret="";

    for(int x=0;x<numRows;x++) cat[x]="";
    
    while(s[k]!='\0')
    {
        for(j=0;j<numRows && s[k]!='\0';j++)
        {   
            cat[j]+=s[k];
            //cout<<cat[j]<<j<<endl;
            k++;
        }
        //cout<<endl;
        j=j-2;
        i++;
        while(j!=0 && s[k]!='\0')
        {   
            cat[j]+=s[k];
            //cout<<cat[j]<<j;
            j--;
            i++;
            k++;
        }
        //cout<<endl;
        
    }
    for(int x=0;x<numRows;x++) ret+=cat[x];
    
    return ret;
}
};