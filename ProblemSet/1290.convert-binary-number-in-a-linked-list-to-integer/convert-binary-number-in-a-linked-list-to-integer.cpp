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
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* last=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return last;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* last=reverse(head);
        int base=1;
        int sum=0;
        while(last!=nullptr)
        {
            if(last->val==1)
                sum+=base;
            base*=2;
            last=last->next;
        }
        return sum;
    }
};