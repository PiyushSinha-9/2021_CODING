//

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

#define WORD_RANGE 26
#define TRIE_POOLSIZE 100000

struct trieNode{
    char a;
    int wc;
    trieNode *child[WORD_RANGE];
};
trieNode triepool[TRIE_POOLSIZE];
trieNode *root;
int poolind;


void init(){
    poolind=0;
    root = &triepool[poolind++];
    root->a = '/';
    for(int i=0;i<WORD_RANGE;i++){
        root->child[i] = NULL;
    }
}

trieNode *getNode(char a){
    trieNode *cur= &triepool[poolind++];
    cur->a = a;
    cur->wc = 0;
    for(int i=0;i<WORD_RANGE;i++){
        cur->child[i] = NULL;
    }
    return cur;
}

void insert(string a){
    trieNode *cur= root;
    int strlen =a.size();
    int ind;
    for(int i=0;i<strlen;i++){
        ind = a[i] - 'a';
        if(!cur->child[ind]){
            cur->child[ind] = getNode(a[i]);
        }
        cur->child[ind]->wc+=1;
        cur = cur->child[ind];
    }
}


int countPrefix(string a){
    trieNode *cur= root;
    int strlen =a.size();
    int ind;
    for(int i=0;i<strlen;i++){
        ind = a[i] - 'a';
        if(!cur->child[ind]){
            return 0;
        }
        cur = cur->child[ind];
    }
    return cur->wc;
}


bool search(string a){
    trieNode *cur= root;
    int strlen =a.size();
    int ind;
    for(int i=0;i<strlen;i++){
        ind = a[i] - 'a';
        if(cur->child[ind]==NULL or cur->child[ind]->wc <= 0){
            return false;
        }
        cur = cur->child[ind];
    }
    return cur!=NULL and cur->wc > 0;
}

void deleteTrie(string a){
    if(search(a)){
        trieNode *cur= root;
        int strlen =a.size();
        int ind;
        for(int i=0;i<strlen;i++){
            ind = a[i] - 'a';
            cur = cur->child[ind];
            cur->wc-=1;  
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

     init();
    string a ="ababc";
    string b="abaxy";
    string c= "abcd";
    string d= "adb";


    insert(a);
    insert(b);
    insert(c);
    insert(d);


    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("aba"));
    printf("No of strings with given prefix = %d\n",countPrefix("a"));

}