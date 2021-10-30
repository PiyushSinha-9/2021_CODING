//https://www.codechef.com/LTIME98B/problems/BUTYPAIR/

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
      
      ll n;
      cin>>n;

      vector<ll> arr(n);

      map<ll,ll> freq;
      for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]+=1;
      }
      
      ll past=0;
      ll sol =0;
      auto itr = freq.begin();
      while(itr != freq.end()){
        sol += 2* freq[itr->first] * past;
        past+=freq[itr->first];
        itr++;
      }
      cout<<sol;br;

    }
    
}