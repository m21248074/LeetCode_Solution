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
    void reorderList(ListNode* head) {
        if(!head->next||!head->next->next)
            return;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode *cur=slow->next;
        ListNode *pre=nullptr;
        slow->next=nullptr;
        while(cur!=nullptr)
        {
            ListNode *next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        ListNode *p1,*p2;
        while(head!=nullptr&&pre!=nullptr)
        {
            p1=head->next;
            p2=pre->next;
            head->next=pre;
            pre->next=p1;
            head=p1;
            pre=p2;
        }
    }
};