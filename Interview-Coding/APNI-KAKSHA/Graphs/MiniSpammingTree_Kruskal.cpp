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

vector< vector<int> > adj;
vector< vector<int> > edges; // w u v


vector<int> parent;
vector<int> ranking;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    ranking[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranking[a] < ranking[b])
            swap(a, b);
        parent[b] = a;
        if (ranking[a] == ranking[b])
            ranking[a]++;
    }
}



signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    int n,v;
    cin>>n>>v;

    int e1,e2,w;
    for(int i=0;i<v;i++){
        cin>>e1>>e2>>w;
        edges.pb({w,e1,e2});
    }

    sort(all(edges));
    
    parent.resize(n+1);
    ranking.resize(n+1);

    for(int i=1;i<=n;i++){
        make_set(i);
    }

    int ind=0;
    while(ind < v){
        
        vector<int> temp = edges[ind];
        if(find_set(temp[1]) != find_set(temp[2])){
            union_sets(temp[1], temp[2]);
            cout<<temp[1]<<" "<<temp[2]<<" "<<temp[0];br;
        }
        
        ind+=1;
    }


}



/* inputs
8 9
1 2 5
2 3 6
1 4 9
4 3 2
3 5 5
5 6 10
6 7 7
5 8 1 
8 7 1
*/