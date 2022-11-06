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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *pre,*cur;
        pre=cur=head;
        if(!head->next) return nullptr;
        while(cur->next&&cur->next->next)
        {
            pre=pre->next;
            cur=cur->next->next;
        }
        if(!cur->next)
            pre->val=pre->next->val;
        pre->next=pre->next->next;
        return head;
    }
};