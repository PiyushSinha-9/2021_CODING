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
#define check_ cout<<"yo";

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

const int MV = 1e5+1;

#pragma GCC target("popcnt")

// ##################################################################




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################

    ll testCase;
    cin>>testCase;

    while(testCase--){
      
      int n,v, v2;
      cin>>n>>v;
    v2=v;
      vector<int> arr(n);   
      map<int,int> freq;

      for(int i=0;i<n;i++){
          cin>>arr[i];
          freq[arr[i]]+=1;
      }

      vector<pair<int,int>> val;
      for(auto it: freq){
          val.pb(make_pair(it.first, it.second));
      }

    sort(val.begin(), val.end(), [](auto &left, auto &right) {
        return right.second < left.second;
    });
      
      int sol=0;
      int sol2=0;

      map<int,bool> store; 
        vector<int> store2;
      for(auto it: val){

          sol += it.second;
          sol2 +=it.second;
          store[it.first]=true;
            store2.pb(it.first);
          v-=1;
          
          if(v<0){
              sol2-=it.second;
              break;
          }
      }

      bool flag=true;
      int change=0;

        vector<int> arr2;
      
      for(int i=0;i<n;i++){
        // if(change > v){
        //     flag=false;
        //     break;
        // }
        if( store[arr[i]] ){
            arr2.pb(arr[i]);
        }
      }
    //  br;

      if(v2==1){
          int size2 = arr2.size();
        for(int i=1;i<size2-1;i++){
            if(arr2[i-1] != arr2[i] and arr2[i+1]!=arr2[i]){
                flag=false;
                break;
            }
        }

        if(arr2[0]!= store2[0] or arr2[size2-1] != store2[0]){
            sol2+=1
        }

      }




      if(flag)
        cout<<sol;
      else  
        cout<<sol2;
      br;
         


    }
    
}