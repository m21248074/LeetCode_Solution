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
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head=head;
    }
    int getRandom() {
        random_device rd;
        default_random_engine gen=default_random_engine(rd());
        int i=0;
        int result=0;
        ListNode* p=head;
        while(p)
        {
            i++;
            uniform_int_distribution dis(0,i-1);
            if(0==dis(gen))
                result=p->val;
            p=p->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */