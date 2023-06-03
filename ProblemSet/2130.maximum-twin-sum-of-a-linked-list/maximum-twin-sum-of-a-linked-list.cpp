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
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre=nullptr;
        while(head!=nullptr)
        {
            ListNode *next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    int pairSum(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        ListNode *p1=head,*p2=slow->next;
        int result=0;
        while(p1!=nullptr&&p2!=nullptr)
        {
            result=max(result,p1->val+p2->val);
            p1=p1->next;
            p2=p2->next;
        }
        return result;
    }
};