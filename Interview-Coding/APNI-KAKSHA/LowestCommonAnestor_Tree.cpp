//BinaryTree Building and traversal

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

//define bt root

class binaryTree{
    public:
    
    int data;
    binaryTree *left;
    binaryTree *right;

    binaryTree(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


void preorder(binaryTree *root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(binaryTree *root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(binaryTree *root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int lowComAns(binaryTree *root, int n1,int n2){
    
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    FILE_READ_IN
    FILE_READ_OUT
    #endif

    //######################

    binaryTree *bt=new binaryTree(1);
    bt->left = new binaryTree(2);
    bt->right = new binaryTree(3);
    bt->left->left = new binaryTree(4);
    bt->left->right = new binaryTree(5);
    bt->right->left = new binaryTree(6);
    bt->right->right = new binaryTree(7);

    cout<<lowComAns(bt, 6, 7);br;
    cout<<lowComAns(bt, 16, 4);br;
    cout<<lowComAns(bt,16 , 7);br;
    cout<<lowComAns(bt,5,6);


   
    
}