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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* ans = head;
        int sum, a = 0, b = 0, remainder = 0;
        while(l1 || l2 || remainder) {
            a = 0, b = 0;
            if(l1){
                a = l1->val;
                l1 = l1->next;
            }
            if(l2){
                b = l2->val;
                l2 = l2->next;
            }
            sum = a + b + remainder;
            head->next = new ListNode(sum%10);
            remainder = sum/10;
            head = head->next;
        }
        ListNode* temp = ans;
        ans = ans->next;
        delete temp;
        return ans;
    }
};

// Runtime: 36 ms, faster than 40.34% of C++ online submissions for Add Two Numbers.
// Memory Usage: 71.5 MB, less than 11.15% of C++ online submissions for Add Two Numbers.
