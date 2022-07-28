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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1=new ListNode();
        ListNode* dummy2=new ListNode();
        ListNode* current1=dummy1;
        ListNode* current2=dummy2;
        ListNode* current=head;
        while(current!=nullptr)
        {
            if(current->val<x)
            {
                current1->next=current;
                current1=current1->next;
            }
            else
            {
                current2->next=current;
                current2=current2->next;
            }
            ListNode* temp=current->next;
            current->next=nullptr;
            current=temp;
        }
        current1->next=dummy2->next;
        return dummy1->next;
    }
};