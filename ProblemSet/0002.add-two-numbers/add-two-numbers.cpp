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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1=l1;
        ListNode* p2=l2;
        ListNode* result=new ListNode();
        ListNode* cur=result;
        bool isCarry=false;
        while(p1!=nullptr&&p2!=nullptr)
        {
            int val=p1->val+p2->val;
            if(isCarry)
                val++;
            cur->next=new ListNode(val%10);
            isCarry=(val>=10)?true:false;
            cur=cur->next;
            p1=p1->next;
            p2=p2->next;
        }
        ListNode* p=(p1!=nullptr)?p1:p2;
        while(p!=nullptr)
        {
            int val=p->val;
            if(isCarry)
                val++;
            cur->next=new ListNode(val%10);
            isCarry=(val>=10)?true:false;
            cur=cur->next;
            p=p->next;
        }
        if(isCarry)
            cur->next=new ListNode(1);
        return result->next;
    }
};