// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         string n1="", n2="";
        
//         ListNode * temp = l1;
//         while(temp!=NULL){
//             n1+=to_string(temp->val);
//             temp= temp->next;
//         }
        
//         temp = l2;
//         while(temp!=NULL){
//             n2+=to_string(temp->val);
//             temp= temp->next;
//         }
        
//         reverse(n1.begin(), n1.end());
//         reverse(n2.begin(), n2.end());
        
        
//         stringstream geek1(n1);
//         stringstream geek2(n2);
//         long long  n11;
//         geek1 >> n11;
//         long long  n22 ;
//         geek2 >> n22;
    
        
//         long long  sol = n11+n22;
//         if(sol==0){
//             return new ListNode(0);
//         }
        
//         string ssol=to_string(sol);
//       //  reverse(ssol.begin(), ssol.end());
        
//         ListNode* ans=NULL;
        
//         while(ssol!=""){
//             temp= new ListNode(ssol[0]-'0', temp);
//             ssol = ssol.substr(1);
//         }
        
        
//         return temp;
//     }
    
    int Length(ListNode *temp)
{
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


ListNode *addTwoNumbers(ListNode *L1, ListNode *L2)
{
    int n1 = Length(L1);
    int n2 = Length(L2);

    int carry = 0;
    if (n1 < n2)
    {
        ListNode *temp = L1;
        L1 = L2;
        L2 = temp;
    }
    ListNode *pre = NULL;
    ListNode *temp = L1;
    while (L2 != NULL)
    {
        pre = L1;
        int sum = (L1->val + L2->val) + carry;

        L1->val = sum % 10;

        if (sum > 9)
            carry = 1;
        else
            carry = 0;
        L1 = L1->next;
        L2 = L2->next;
    }

    while (L1 != NULL)
    {
        int sum = L1->val + carry;
        L1->val = sum % 10;

        if (sum > 9)
            carry = 1;
        else
            carry = 0;

        pre = pre->next;
        L1 = L1->next;
    }

    if (carry == 1)
        pre->next = new ListNode(1);
    return temp;
}
};