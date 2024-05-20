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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i=0;
        ListNode *pFirst,*pLast;
        ListNode *cur=list1;
        while(i!=b+1)
        {
            if(i==a-1)
                pFirst=cur;
            cur=cur->next;
            i++;
        }
        pLast=cur;
        pFirst->next=list2;
        cur=list2;
        while(cur->next)
            cur=cur->next;
        cur->next=pLast;
        return list1;
    }
};