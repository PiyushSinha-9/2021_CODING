

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
//dfs(1, adj ,vis, visted);

vector<ll> adj[10100];
vector<ll> vis(10100);
vector<ll> sol;

void dfs(ll start, ll &visted){
    vis[start]= 1;
    visted+=1;
    sol.pb(start);
    for(ll i : adj[start]){
        if(vis[i]==0){
            dfs(i,visted);
        }
    }
}



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
         vector<ll> in(n+2, 0);
         vector<ll> tempstart;

         ll tempstartlen=0;

      for(ll i=0;i<n+10;i++){
          adj[i].clear();
          vis[i]=0;
      }

        ll temp;
       for(ll i=0;i<n;i++){
           cin>>temp;
           if(temp==0){
               adj[i+1].pb(n+1);
               in[n+1]+=1;
           }else{
               adj[n+1].pb(i+1);
               in[i+1]+=1;
           }
       }

       for(ll i=0;i<n-1;i++){
           adj[i+1].pb(i+2);
           in[i+2]+=1;
       }

        ll start;
       // vector<ll> in(n+2, 0);

       // vector<ll> tempstart;
        for(ll i=1;i<n+2;i++){
            if(in[i]==0){
                tempstart.pb(i);
                tempstartlen+=1;

                if(tempstartlen>1){
                    break;
                }
             //   cout<<i<<" ";
            }
        }

        //br;

        if(tempstartlen>1){
            cout<<-1;br;
           // check_;
            continue;
        }

        ll starting;
        if(tempstartlen==1){
            starting=tempstart[0];
        }
        else{
            starting=1;
        }

        ll visted=0;
        sol.clear();
       dfs(starting , visted);
 
       if(visted==n+1){
           for(auto i: sol){
               cout<<i<<" ";
           }
       }else{
           cout<<-1;
       }
       br;
    }
    
    return 0;
}