

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




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
	#endif

    //######################


    ll testcase;
    cin>>testcase;
    while(testcase--){
       ll n;
       cin>>n;

       vector<ll> arr(n);
       for(ll i=0;i<n;i++){
           cin>>arr[i];
       }

       map<ll,ll> freq;
        ll maxi = LONG_MIN, sol; 
       for(ll i=0; i<n;i++){
           arr[i] =  arr[i] & arr[n-1-i];
           freq[arr[i]]+=1;
           if(maxi==freq[arr[i]]){
               if(sol > arr[i]){
                   sol = arr[i];
               }
           }else if(max(maxi,freq[arr[i]]) == freq[arr[i]]){
                maxi=freq[arr[i]];
                sol = arr[i];
            }
           // cout<<arr[i]<<" ";
       }
       cout<<sol;br;
      // br;
        
    }
    

     

    return 0;
}