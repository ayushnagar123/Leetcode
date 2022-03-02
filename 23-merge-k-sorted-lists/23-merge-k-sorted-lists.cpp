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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* temp = new ListNode(-1);
        ListNode* new_head = temp;
        ListNode* curr = temp;
        ListNode* min = new ListNode(INT_MAX);
        int index=0;
        do {
            min = new ListNode(INT_MAX);
            for(int i=0;i<lists.size();i++){
                if(lists[i]){
                    if(min->val > lists[i]->val){
                        min = lists[i];
                        index = i;
                    }
                }
            }
            if(lists[index]){
                curr->next = min;
                lists[index] = lists[index]->next;
                curr = curr->next;
            }
        }while(min->val!=INT_MAX);
        return new_head->next;
    }
};