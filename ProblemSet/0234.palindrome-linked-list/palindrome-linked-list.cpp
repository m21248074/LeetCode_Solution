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
    ListNode *left;
public:
    bool traversal(ListNode* right)
    {
        if(right==nullptr)
            return true;
        bool result=traversal(right->next);
        result=result&&(left->val==right->val);
        left=left->next;
        return result;
    }
    bool isPalindrome(ListNode* head) {
        left=head;
        return traversal(head);
    }
};