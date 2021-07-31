//https://www.codechef.com/LTIME98B/problems/ARRT/

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

      vector<ll> arr1(n), arr2(n);
      for(ll i=0;i<n;i++){
        cin>>arr1[i];
        arr1[i]= arr1[i]%n;
      }
      ll ind=0,mini=LLONG_MAX;
      for(ll i=0;i<n;i++){
        cin>>arr2[i];
       arr2[i]=arr2[i]%n;
        mini = min((arr2[i]+arr1[0])%n,mini);
      }

      

      vector<ll> sol1(n), sol2(n);
      bool empty=true, flag=true;
      ll overall=0;
      for(ll i=0;i<n;i++){
       // if((arr2[i]+arr1[0])%n==mini){
          flag=true;
          sol2.resize(n,0);
          if(empty){
              ll tempn=n;
              ll ind1=0;
              ll ind2=i;
              while(tempn--){
                  sol1[ind1] = (arr1[ind1] + arr2[ind2])%n;
                  sol2[ind1] = (arr1[ind1] + arr2[ind2])%n;
                  ind1+=1;
                  ind2+=1;
                  if(ind2==n)
                  ind2=0;
              }
          }else{
              ll tempn=n;
              ll ind1=0;
              ll ind2=i;
              overall=0;
              while(tempn--){
                  sol2[ind1] = (arr1[ind1] + arr2[ind2])%n;

                  // cout<<sol2[ind1]<<" "<<sol1[ind1];br;
                  if(overall==0){
                    if(sol2[ind1] > sol1[ind1]){
                      overall=2;
                      break;
                    }else if(sol2[ind1] < sol1[ind1]){
                      overall=1;
                    }
                  }

                  ind1+=1;
                  ind2+=1;
                  if(ind2==n)
                  ind2=0;
              }
          }
          // cout<<i;br;
          // for(ll i:sol1){
          //   cout<<i<<" ";
          // }
          // br;
          // for(ll i:sol2){
          //   cout<<i<<" ";
          // }
          // br;br;


          if(overall==1 or empty){
            for(ll i=0;i<n;i++){
              sol1[i]=sol2[i];
            }
            empty=false;
          }

      //  }
      }

      for(ll i: sol1){
        cout<<i<<" ";
      }
      br;
    }
    
}