#include<bits/stdc++.h>
using namespace std;
int parent[1000001];
int find(int a)
{
    if(parent[a]<0)
    return a;
    return parent[a]=find(parent[a]);
}
void merge(int a,int b)
{
    parent[a]=b;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=n;i++)
        parent[i]=-1;
        vector<pair<int,int>>v;
        while(k--)
        {
            int x1,x2;
            string r;
            cin>>x1>>r>>x2;
            if(r=="=")
            {
                x1=find(x1);
                x2=find(x2);
                if(x1!=x2)
                merge(x1,x2);
            }
            else
            {
                v.push_back({x1,x2});
            }
        }
        int f=0;
        for(int i=0;i<v.size();i++)
        {
            int x=v[i].first;
            int y=v[i].second;
            x=find(x);
            y=find(y);
            if(x==y)
            {
                f=1;
                break;
            }
        }
        if(f)
        cout<<"NO"<<"\n";
        else
        cout<<"YES"<<"\n";
    }
return 0;
}