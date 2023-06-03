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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* cur=head;
        ListNode* temp;

        while(cur!=nullptr&&cur->next!=nullptr)
        {
            temp=cur->next->next;
            cur->next->next=cur;
            pre->next=cur->next;
            cur->next=temp;

            pre=cur;
            cur=cur->next;
        }
        return dummy->next;
    }
};