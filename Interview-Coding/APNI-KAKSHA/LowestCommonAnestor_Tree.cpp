//Brute + Good Approach

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


bool getPath(binaryTree *root, int val, vector<int> &path){
    if(!root){
        return false;
    }

    path.push_back(root->data);
    
    if(root->data==val) 
        return true;

    if(getPath(root->left,val,path)){
        return true;
    }

    if(getPath(root->right,val,path)){
        return true;
    }

    path.pop_back();
    return false;

}


int lowComAns(binaryTree *root, int n1,int n2){
    
    vector<int> lPath, rPath;
    if(!getPath(root,n1,lPath) or !getPath(root,n2,rPath)){
        return -1;  // soluion do not exist
    }

    print(lPath);
    print(rPath);

    int pc=0;
    int path1Size = lPath.size();
    int path2Size = rPath.size();
    while(pc<path1Size and pc<path2Size){
        if(lPath[pc]!=rPath[pc]){
            break;
        }
        pc+=1;
    }

    return lPath[pc-1];

}


binaryTree *LCA(binaryTree *root, int n1, int n2){              // n1 and n2 we are prefusing that they both exist
    if(!root){
        return NULL;
    }

    if(root->data==n1 or root->data==n2){
        return root;
    }

    binaryTree *lNode = LCA(root->left,n1,n2);
    binaryTree *rNode = LCA(root->right,n1,n2);

    if(lNode and rNode){
        return root;
    }

    if(lNode){
        return lNode;
    }

    return rNode;

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
    bt->right->left->left = new binaryTree(8);

    // cout<<lowComAns(bt, 6, 7);br;
    // cout<<lowComAns(bt, 6, 4);br;
    // cout<<lowComAns(bt, 6 , 7);br;
    // cout<<lowComAns(bt , 5, 6);br;
    // cout<<lowComAns(bt, 19, 6);br;

    // cout<<lowComAns(bt, 8, 7);br;
    // cout<<lowComAns(bt, 1, 8);br;


    //binaryTree *sol =  LCA(bt, 6, 7);
    // if(sol!=NULL)
    //     cout<<sol->data;
    // else{
    //     cout<<"WTF";
    // }
    // br;
    // sol =  LCA(bt, 6, 4);
    // if(sol!=NULL)
    // cout<<sol->data;
    // else{
    //     cout<<"WTF";
    // }
    // br;
    // sol =  LCA(bt, 6 , 7);
    // if(sol!=NULL)
    //     cout<<sol->data;
    // else{
    //     cout<<"WTF";
    // }
    // br;
    // sol =  LCA(bt , 5, 6); 
    // if(sol!=NULL)
    // cout<<sol->data;
    // else{
    //     cout<<"WTF";
    // }
    // br;
    // sol =  LCA(bt, 19, 6);
    // if(sol!=NULL)
    // cout<<sol->data;
    // else{
    //     cout<<"WTF";
    // }
    // br;
    // sol =  LCA(bt, 8, 7);
    // if(sol!=NULL)
    // cout<<sol->data;
    // else{
    //     cout<<"WTF";
    // }
    // br;
    // sol =  LCA(bt, 1, 8);
    // if(sol!=NULL)
    // cout<<sol->data;
    // else{
    //     cout<<"WTF";
    // }
    // br;


    binaryTree *sol =  LCA(bt, 19, 6);
    if(sol!=NULL)
    cout<<sol->data;
    else{
        cout<<"WTF";
    }
    
}