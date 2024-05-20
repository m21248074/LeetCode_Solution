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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode *result=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return result;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode *current,*tail;
        current=tail=head=reverseList(head);
        while(current->next)
        {
            current=current->next;
            if(tail->val<=current->val)
            {
                tail->next=current;
                tail=current;
            }
        }
        tail->next=nullptr;
        return reverseList(head);
    }
};