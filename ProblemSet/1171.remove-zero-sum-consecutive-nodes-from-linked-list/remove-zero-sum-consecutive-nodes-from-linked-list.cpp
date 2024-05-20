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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        cur->next=head;
        unordered_map<int,ListNode*> um;
        int curSum=0;
        while(cur)
        {
            curSum+=cur->val;
            if(um.count(curSum))
            {
                cur=um[curSum]->next;
                int t=curSum+cur->val;
                while(t!=curSum)
                {
                    um.erase(t);
                    cur=cur->next;
                    t+=cur->val;
                }
                um[curSum]->next=cur->next;
            }
            else
                um[curSum]=cur;
            cur=cur->next;
        }
        return dummy->next;
    }
};