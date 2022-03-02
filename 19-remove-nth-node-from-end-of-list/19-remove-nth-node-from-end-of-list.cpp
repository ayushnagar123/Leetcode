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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode* new_head = new ListNode(-1);
        
        ListNode* temp1 = new_head;
        ListNode* temp2 = new_head;
        new_head->next = head;
        
        for(int i=0;i<n;i++){
            temp1 = temp1->next;
        }
        
        while(temp1->next){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        ListNode* del = temp2->next;
        temp2->next = temp2->next->next;
        
        delete del;
        return new_head->next;
    }
};