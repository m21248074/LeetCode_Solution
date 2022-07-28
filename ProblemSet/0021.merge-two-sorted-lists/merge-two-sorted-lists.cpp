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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *i=list1;
        ListNode *j=list2;
        ListNode *dummy=new ListNode();
        ListNode *p=dummy;
        while(i!=nullptr&&j!=nullptr)
        {
            if(i->val<=j->val)
            {
                p->next=new ListNode(i->val);
                p=p->next;
                i=i->next;
            }
            else // i->val>j->val
            {
                p->next=new ListNode(j->val);
                p=p->next;
                j=j->next;
            }
        }
        while(i!=nullptr)
        {
            p->next=new ListNode(i->val);
            p=p->next;
            i=i->next;
        }
        while(j!=nullptr)
        {
            p->next=new ListNode(j->val);
            p=p->next;
            j=j->next;
        }
        return dummy->next;
    }
};