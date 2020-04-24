/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode  *head = NULL;
        ListNode  *curr,*temp;
        int n = lists.size();
        // min heap 
        // pair {val,row,col}
        priority_queue<pair<int,pair<int,ListNode*>>,std::vector<pair<int,pair<int,ListNode*>>>,std::greater<pair<int,pair<int,ListNode*>>>>pq;
        // pushing the first element of every LL
        for(int i=0; i<n; i++){
            if(lists[i]!=NULL)
              pq.push({lists[i]->val,{i,lists[i]}});
        }
        while(pq.size()!=0){
            pair<int,pair<int,ListNode*>>top = pq.top();
            pq.pop(); 
            int row = top.second.first;
            ListNode *col_pointer = top.second.second;
            int min_val = top.first;
            // creating new LL
            if(head==NULL){
                temp = new ListNode();
                temp->val = min_val ;
                temp->next=NULL;
                head=temp;
                curr=temp;
            }
           else{
               temp = new ListNode();
               temp->val = min_val;
               temp->next=NULL;
               curr->next=temp;
               curr=temp;
           }
           // if you have not reached the NULL, then you can push the next element of the row where you have found the min element
           col_pointer = col_pointer->next;
           if(col_pointer !=NULL){
               pq.push({col_pointer->val,{row,col_pointer}}); 
           }
        }
        return head; 
    }
        
};