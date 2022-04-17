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
    bool hasCycle(ListNode *head) {
        if(!head){return false;}
        ListNode* slow;
        ListNode* fast;
        if(head->next){
            slow = head->next;
        }
        if(head->next && head->next->next){
            fast= head->next->next;
        }
        while(fast!=NULL && slow!=NULL && fast!=slow){
            if(!slow->next){
                return false;
            }
            if(!fast->next || !fast->next->next){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if(!fast || !slow){
            return false;
        }
        return true;
    }
};