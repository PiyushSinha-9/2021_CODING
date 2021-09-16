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


int countNodes(binaryTree *root){
    if(!root){
        return 0;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return left +right + 1;
}


void subTreeSum(binaryTree *root, int &sum ){
    if(!root){
        sum=0;
        return;
    }

    int lsum=0, rsum=0;
    subTreeSum(root->left, lsum);
    subTreeSum(root->right, rsum);

    root->data += (lsum +rsum);
    sum=root->data;

    return;

}


int height(binaryTree *root){
    if(!root){
        return 0;
    }

    int lhei, rhei;
    lhei = height(root->left);
    rhei = height(root->right);

    return max(lhei, rhei) + 1;

}


void diameter(binaryTree *root, int &height, int &bestSol){
    if(!root){
        height=0;
        return;
    }

    int lefth=0, righth=0;
    diameter(root->left, lefth, bestSol);
    diameter(root->right, righth, bestSol);

    height = max(lefth,righth) +1;
    int curDia = lefth + righth + 1; 
    bestSol = max(curDia, bestSol);

    return;
}


bool heightBal(binaryTree *root, int &height){
    if(!root){
        height=0;
        return true;
    }

    int lhei = 0 ,rhei =0;
    
    if(!heightBal(root->left, lhei)){
        return false;
    }

    if(!heightBal(root->right, rhei)){
        return false;
    }

    if(abs(lhei - rhei) > 1){
        return false;
    }

    height = max(lhei,rhei)+1;
    return true;
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

    int height=0;
    cout<<heightBal(bt,height);

   
    
}