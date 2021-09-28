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

const int wordRange = 26;
const int poolSize = 1e5;


struct TrieNode{
    char cur;
    int wc;
    TrieNode *child[wordRange];
};

TrieNode nodePool[poolSize];
TrieNode *root;
int poolCount;


void init(){
    poolCount=0;
    root= &nodePool[poolCount++];
    root->cur = '/';
    for(int i=0;i<wordRange;i++){
        root->child[i]=NULL;
    }
}

TrieNode *getNode(char s){
    TrieNode* temp = &nodePool[poolCount++];
    temp->cur=s;
    for(int i=0;i<wordRange;i++){
        temp->child[i]=NULL;
    }
    temp->wc=0;
    return temp;
}


void insert(string s){
    TrieNode* temp = root;
    int n=s.size();
    for(int i=0;i<n;i++){
        int ind = s[i] - 'a';
        if(!temp->child[ind]){
            temp->child[ind] = getNode(s[i]);
        }
        temp->child[ind]->wc+=1;
        temp = temp->child[ind];
    }
}


bool search(string s){
    TrieNode* temp = root;
    int n=s.size();
    for(int i=0;i<n;i++){
        int ind = s[i] - 'a';
        if(!temp->child[ind] and temp->child[ind]->wc==0){
            return false;
        }
        temp = temp->child[ind];
    }
    return true;
}

void deleteTrie(string s){
    if(search(s)){
        TrieNode* temp = root;
        int n=s.size();
        for(int i=0;i<n;i++){
            int ind = s[i] - 'a';
            temp->child[ind]->wc-=1;
            temp = temp->child[ind];
        }
    }
}


int countPrefix(string s)
{
    TrieNode *curr = root;
    int index;
    int n=s.size();
    for(int i=0; i<n; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return 0;   //No string with given prefix is present
        curr = curr->child[index];
    }
    return curr->wc;
}



signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};


    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    cout<<"Deletion...STARTED\n";
    deleteTrie(a);
    deleteTrie(d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    return 0;
    
}
