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
struct cmp {
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode();
        ListNode* current=dummy;
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            ListNode* p=temp;
            while(p!=nullptr)
            {
                pq.push(p);
                p=p->next;
            }
        }
        while(!pq.empty())
        {
            ListNode* temp=pq.top();
            pq.pop();
            temp->next=nullptr;
            current->next=temp;
            current=current->next;
        }
        return dummy->next;
    }
};