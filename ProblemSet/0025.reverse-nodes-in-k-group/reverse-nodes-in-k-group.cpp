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
    ListNode* reverse(ListNode* head,ListNode* tail)
    {
        ListNode *pre=nullptr,*cur,*nxt;
        cur=nxt=head;
        while(cur!=tail)
        {
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) // empty list
            return nullptr;
        ListNode *find=head;
        for(int i=0;i<k;i++)
        {
            if(find==nullptr)
                return head; // base case;
            find=find->next;
        }
        ListNode *last=reverse(head,find);
        head->next=reverseKGroup(find,k);
        return last;
    }
};