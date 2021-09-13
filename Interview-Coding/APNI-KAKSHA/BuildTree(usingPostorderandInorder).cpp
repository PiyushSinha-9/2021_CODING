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


class tree{
    public: 

    int data;
    tree *left;
    tree *right;

    tree(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void displayRoot(tree *root){
    if(!root){
        return;
    }
    displayRoot(root->left);
    displayRoot(root->right);
    cout<<root->data<<" ";
}


void inorderRoot(tree *root){
    if(!root){
        return;
    }
    displayRoot(root->left);
    cout<<root->data<<" ";
    displayRoot(root->right);
}

void preorderRoot(tree *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    displayRoot(root->left);
    displayRoot(root->right);
}


int n;
static int ind;


int search(vector<int> in, int start, int end, int val){
    for(int i=start; i<=end;i++){
        if(in[i]==val){
            return i;
        }
    }
    return -1;
}


tree *solve(vector<int> pre, vector<int> in, int start, int end){
    if(start > end){
        return NULL;
    }
    int val = pre[ind];
    ind+=1;
    tree *node = new tree(val);

    if(start==end){     // leaf cond
        return node;
    }

    int tempInd = search(in, start, end, val); // -1 means not avilable 
    node->left= solve(pre,in,start, tempInd-1);
    node->right= solve(pre,in,tempInd+1, end);

    return node;

}



signed main() {
    fast
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    cin>>n;


    vector<int> preorder(n), inorder(n);

    for(int &i:preorder){
        cin>>i;
    }

    for(int &i:inorder){
        cin>>i;
    }

    ind=0;

    tree *root = solve(preorder, inorder, 0, n-1);

    displayRoot(root);br;
    inorderRoot(root);br;
    preorderRoot(root);
    br;

}
