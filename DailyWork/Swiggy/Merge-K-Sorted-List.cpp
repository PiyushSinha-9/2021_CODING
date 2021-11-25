class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        priority_queue<int,vector<int>, greater<int>> priority;
        //make dummy node to start the list
        ListNode *solution = new ListNode(0);
        for(int i = 0; i < lists.size(); i++){
            while(lists[i] != NULL){
                priority.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        
        ListNode *newList = solution;
        
        while(!priority.empty()){
            ListNode *newNode = new ListNode(priority.top());
            newList->next = newNode;
            newList = newList->next;
            priority.pop();
        }
        
        //return the node next to the dummy node
        return solution->next;
    }
};