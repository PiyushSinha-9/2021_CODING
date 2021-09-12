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
#define pb(a) push_back(a)
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

void InfixToPostfix(string &s){
    stack<char> sta;
    string ans="";

    map<char,int> pri;
    pri['^'] = 1;
    pri['/'] = 2;
    pri['*'] = 2;
    pri['+'] = 3;
    pri['-'] = 3;
    // BODMAS 

    for(char c:s){
        if(sta.empty()){
            sta.push(c);
        }else{
            //open bracket
            if(c=='('){
                sta.push(c);
                continue;
            }

            //close bracket
            if(c==')'){
                //cout<<ans;br;
                while(!sta.empty() and sta.top()!='('){
                    ans+=sta.top();
                    sta.pop();
                }
                //cout<<ans;br;
                sta.pop();
                continue;

            }

            //chars
            if(c>='a' and c<='z'){
                ans+=c;
                continue;
            }

            //symbols
            while(!sta.empty() and sta.top() != '(' and pri[c] > pri[sta.top()]){
                ans+=sta.top();
                sta.pop();
            }
            sta.push(c);
        }
    }

    while(!sta.empty()){
        ans+=sta.top();
        sta.pop();
    }

    s=ans;
}


signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    string s;
    cin>>s;

    InfixToPostfix(s);

    cout<<s;
}
