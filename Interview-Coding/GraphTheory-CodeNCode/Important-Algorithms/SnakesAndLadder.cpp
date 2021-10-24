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
 const int N = 1e5+3;
 const int inf = 1e9+7;

  vector<int> lad(N), snake(N);

signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################


    vector<bool> vis(101, false);
    int l, s;
    cin>>l;

    while(l--){
        int e1,e2;
        cin>>e1>>e2;
        lad[e1] =e2;
    }

    cin>>s;
    while(s--){
        int e1,e2;
        cin>>e1>>e2;
        snake[e1] =e2;
    }


    queue<int> q;
    q.push(1);
    vis[1]=true;
    bool reached = false;
    int count=1, level=0;

    while(!q.empty() and !reached)
    {
        int sz = count;
        count=0;
        while(sz--){
             int top=q.front();
             q.pop();
            for(int dice=1;dice<=6;dice++){
                if(top+dice <=100 and !vis[lad[top+dice]] and lad[top+dice]>0){
                    vis[lad[top+dice]] = true;
                    if(lad[top+dice]==100){
                        reached=true;
                        break;
                    }
                    q.push(lad[top+dice]);
                    count+=1;
                }else if(top+dice <=100 and !vis[snake[top+dice]] and snake[top+dice]>0){
                    vis[snake[top+dice]] = true;
                    if(snake[top+dice]==100){
                        reached=true;
                        break;
                    }
                    q.push(snake[top+dice]);
                    count+=1;
                }else if(top+dice <=100 and !vis[top+dice] and !snake[top+dice] and !lad[top+dice]){
                    vis[top+dice]=true;
                    if(top+dice==100){
                        reached=true;
                        break;
                    }
                    q.push(top+dice);
                    count+=1;
                }
            }
        }

         level+=1;

    }


    if(reached){
        cout<<level;
    }else{
        cout<<-1;
    }



}

/*

ladder and snakes
 
2 ladders and 3 snakes

2
3 90
56 76
3
99 10
30 20
20 5


*/