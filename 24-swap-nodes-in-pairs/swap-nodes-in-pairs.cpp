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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* point = dummy;
        while(point->next!=NULL && point->next->next!=NULL)
        {
            ListNode* f = point->next;
            ListNode* s = point->next->next;

            f->next = s->next;
            s->next=f;
            point->next = s;
            point = f;
        }
        return dummy->next;
    }
};