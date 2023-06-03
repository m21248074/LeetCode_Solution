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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode *cur=head;
        while(cur!=nullptr)
        {
            n++;
            cur=cur->next;
        }
        if(k==n-k+1)
            return head;
        ListNode *a,*b;
        cur=head;
        for(int i=1;i<=n;i++,cur=cur->next)
        {
            if(i==k)
                a=cur;
            else if(i==n-k+1)
                b=cur;
        }
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
        return head;
    }
};