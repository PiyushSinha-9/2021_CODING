/* Auther -: Piyush Sinha */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i=0; i<(n); i++)
#define repa(i, a, n) for(int i=(a); i<=(n); i++)
#define br cout<<"\n"
#define print(x) for(auto iuiuiuiuiui:x){ cout<<iuiuiuiuiui<<" ";}br;
#define print_array(array,size) for(ll i=0;i<size;i++){ cout<<array[i]<<" ";}br;
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define FILE_READ freopen("input.txt","r",stdin), freopen("output.txt","w",stdout), freopen("error.txt","w",stderr);


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
#define dbg(x...)
#endif


//############################################################

// #define int long long

// BIT Tree
vector<int> BIT(100005, 0);

//O(log n) operation
int get(int val) {
    int sum = 0;
    for (int j = val+1;j>0;j -= j & (-j)) {
        sum += BIT[j];
    }
    return sum;
}

// O(log n) operation
void update(int index, int val) {
    for (int j = index+1;j<100005;j += j & (-j)) {
        BIT[j] += val;
    }
}

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.first > b.second.first) {
        return true;
    } else if (a.second.first == b.second.first) {
        return a.second.second >= b.second.second;
    } else {
        return false;
    }
}

vector<int> solve(int n, vector<pair<int, int>> chocolates, int q, vector<pair<int, pair<int, int>>> queries) {
    // sorted both chocolates, queries in the descending order
    sort(chocolates.begin(), chocolates.end(), greater<pair<int, int>>());
    sort(queries.begin(), queries.end(), comp);
    vector<int> result(q, 0);
    
    // using 2 pointer approach between the chocolates, queries
    int i = 0, j = 0;
    while(i<n && j<q) {
        if (chocolates[i].first > queries[j].second.first) {
            update(chocolates[i].second, 1);
            result[queries[j].first] = max(result[queries[j].first] , (i+1) - get(queries[j].second.second));
            i++;
        }else if (chocolates[i].first <= queries[j].second.first) {
            j++;
        }
    }
    
    while (j<q) {
        result[queries[j].first] = max(result[queries[j].first] , n - get(queries[j].second.second));
        j++;
    }
    return result;
}


signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ
    #endif

    //######################

   	int n;
	cin >> n;
	int sweetness[n];
    int expiretime[n];
    vector<pair<int, int>> chocolates;
	for (int i=0;i<n;i++) {
	    cin >> sweetness[i];
	}
	
	for (int i=0;i<n;i++) {
	    cin >> expiretime[i];
	    chocolates.push_back({sweetness[i], expiretime[i]});
	}
    
    int q;
    cin >> q;
    
    vector<pair<int, pair<int, int>>> queries;
    for(int i=0;i<q;i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({i,{a, b}});
    }
    
    vector<int> res = solve (n, chocolates, q, queries); 
    for(int i=0;i<q;i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
	return 0;
    
}
