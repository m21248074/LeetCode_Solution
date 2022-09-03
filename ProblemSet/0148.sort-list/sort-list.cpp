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
    ListNode* merge(ListNode *node1,ListNode *node2)
    {
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        while(node1&&node2)
        {
            if(node1->val<node2->val)
            {
                cur->next=node1;
                node1=node1->next;
            }
            else // node1->val>=node2->val
            {
                cur->next=node2;
                node2=node2->next;
            }
            cur=cur->next;
        }
        if(node1) cur->next=node1;
        else if(node2) cur->next=node2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *slow,*fast,*pre;
        slow=fast=pre=head;
        while(fast&&fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;
        return merge(sortList(head),sortList(slow));
    }
};