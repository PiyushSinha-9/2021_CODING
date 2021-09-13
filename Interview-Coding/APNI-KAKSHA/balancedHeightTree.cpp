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
#define max3(a, b, c) max(c, max(a, b))
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


int sumTree(binaryTree *root){
    if(!root){
        return 0;
    }

    int curVal = sumTree(root->left) + sumTree(root->right) + root->data;
    root->data = curVal;

    return curVal;
}


bool balancedTree(binaryTree *root,int &height){
    if(!root){
        return true;
    }

    int lh=0, rh=0;
    bool lSol = balancedTree(root->left, lh);
    bool rSol = balancedTree(root->right, rh);

    bool curSol;
    if(abs(lh-rh) > 1){
        curSol=false;
    }else{
        curSol=true;
    }

    height =max(lh,rh)+1;

    return (lSol && rSol && curSol);

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
    // bt->right->left = new binaryTree(6);
    // bt->right->right = new binaryTree(7);

    int h=0;
    if(balancedTree(bt, h)){
        cout<<"It is Balanced tree";
    }else{
        cout<<"It is not BT";
    }

    br;
    

   
    
}