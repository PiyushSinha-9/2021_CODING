//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<long long,long long> pll;



#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<"\n"
#define mod 1000000007
#define pb(a) push_back(a)
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()
#define check_ cout<<"yo\n";

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

const int MV = 1e5+1;

#pragma GCC target("popcnt")

// ##################################################################



 int toggleBits(int N , int L , int R) {
        // code here
        
      int val =0;
      int powval = 0;
      int ind = 1;
      int mask=1;
      
      for(int i=0;i<32;i++){
          
          
          if(ind>=L and ind<=R){
              if((mask & N)==0){
                  val+= pow(2,powval);
              }
          }else{
              if((mask & N)>0){
                  val+= pow(2,powval);
              }
          }
          
          ind+=1;
          powval+=1;
          mask<<=1;
          
      }
      
      return val;
    }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

    int testCase;
    cin>>testCase;

    while(testCase--){
        
    }
   
    
}

/*

Input:
N = 17 , L = 2 , R = 3
Output:
23
Explanation:
(17)10 = (10001)2.  After toggling all
the bits from 2nd to 3rd position we get
(10111)2 = (23)10


*/