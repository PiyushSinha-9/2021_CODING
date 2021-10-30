#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;

#define pi (3.141592653589)
#define mod 1000000007
#define F first
#define S second
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define br cout<<endl
#define pb push_back
#define mp(asd,fgh) make_pair(asd,fgh)
#define all(c) c.begin(),c.end()
#define ff first
#define ss second
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);

#define INF LONG_LONG_MAX
#define N_INF LONG_LONG_MIN

#pragma GCC target("popcnt")

//############################################################

map<int, map<int,bool>> dp;
bool flag;
int n;

void dfs(int x, int y){
    if(dp[x][y]){
        return;
    }

    if(x==n and y==n){
        flag=true;
        return;
    }

    if(flag){
        return;
    }

    if(x>n or y>n or x<1 or y<1){
        return ;
    }

    dfs(x+1,y);
    dfs(x, y+1);
    
}

signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int testCase;
    cin>>testCase;


    while(testCase--){
        cin>>n;
        dp.clear();
        vector<pair<int,int>> store;
        for(int i=0;i<n;i++){
            int t1,t2;
            cin>>t1>>t2;
            dp[t1][t2] = true;
            store.pb({t1,t2});
        }
        
        flag =true;

        sort(all(store));

        pair<int,int> temp1 = store[0];
        int t1 = temp1.first, t2=temp1.second;
        for(int i=1;i<n;i++){
    
            pair<int,int> temp = store[i];
            int k1 = temp.first;
            int k2 = temp.second;

            if(k2!=t2 and k2!=(t2+1) and k2!=(t2-1)){
                flag=false;
                break;
            }
            t1=k1;
            t2=k2;

            if(t2==1){
                break;
            }
        }


        if(flag){
            cout<<"NO";
            br;
            continue;
        }

        reverse(all(store));

         flag=true;
        temp1 = store[0];
         t1 = temp1.first, t2=temp1.second;
        for(int i=1;i<n;i++){
            pair<int,int> temp = store[i];
            int k1 = temp.first;
            int k2 = temp.second;

            if(k2!=t2 and k2!=(t2+1) and k2!=(t2-1)){
                flag=false;
                break;
            }
            t1=k1;
            t2=k2;

            if(t2==n){
                break;
            }
        }


        if(flag){
            cout<<"NO";
            br;
            continue;
        }


        cout<<"YES";br;






    }
}
