//https://www.youtube.com/watch?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&v=f-oTsCUCiXk&feature=youtu.be

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

// CASE 1
void printSubTree(binaryTree *tar, int k){
    if(!tar or k<0){
        return;
    }

    if(k==0){
        cout<<tar->data<<" ";
        return;
    }

    printSubTree(tar->left, k-1);
    printSubTree(tar->right, k-1);
}

//CASE 2
int printAnsDistk(binaryTree *root, binaryTree *tar, int k)           // returning the target node dist from the ancestor
{
    if(!root){
        return -1;
    }

     if(root==tar){
         printSubTree(root, k);
         return 0; // as root == target
     }

     int dl, dr; // left subtree dist
     dl = printAnsDistk(root->left, tar, k);
     if(dl != -1){  // We found our target in left SubTree
        if(dl+1 == k){
            cout<<root->data <<" ";
        }else{
            printSubTree(root->right, k-dl-2);         // not sure where 2 came from
        }
        return 1+dl;
     }


     dr = printAnsDistk(root->right, tar, k);
     if(dr != -1){  // We found our target in left SubTree
        if(dr+1 == k){
            cout<<root->data <<" ";
        }else{
            printSubTree(root->left, k-dr-2);         // not sure where 2 came from
        }
        return 1+dr;
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

    binaryTree *bt=new binaryTree(1);
    bt->left = new binaryTree(2);
    bt->right = new binaryTree(3);
    bt->right->right = new binaryTree(4);
    
    bt->left->left = new binaryTree(7);
    bt->left->right = new binaryTree(5);
    bt->left->right->right = new binaryTree(6);

    bt->left->left->left = new binaryTree(8);
    bt->left->left->left->left = new binaryTree(9);


    int k;
    cin>>k;

    printAnsDistk(bt,bt->left->left, k);

   
    
}