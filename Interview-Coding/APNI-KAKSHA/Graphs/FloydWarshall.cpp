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

int n,v;
const int N = 1e5+3;
const int inf = 1e9+7;

vector<vector<int> > edges;



signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    n=4;
    
    vector< vector<int> > graph = { {0,5,inf,10},
        {inf,0,3,inf},
        {inf,inf,0,1},
        {inf,inf,inf,0}
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                cout<<graph[i][j]<<" ";
        }
        br;
    }

    vector< vector<int> >dist = graph;

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
        }
        br;
    }
}


/*

Input
0 5 1000000007 10 
1000000007 0 3 1000000007 
1000000007 1000000007 0 1 
1000000007 1000000007 1000000007 0 

OutPut
0 5 8 9 
1000000007 0 3 4 
1000000007 1000000007 0 1 
1000000007 1000000007 1000000007 0 



*/