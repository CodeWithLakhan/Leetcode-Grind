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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* pn = NULL;
        while(temp!=NULL){
            ListNode* knode = findknode(temp,k);
            if(knode==NULL)
            {
                pn->next=temp;
                break;
            }
            ListNode* nn = knode->next;
            knode->next=NULL;
            reverse(temp);
            if(temp==head)
            {
                head=knode;
            }
            else
            {
                pn->next = knode;
            }
            pn = temp;
            temp = nn;
        }
        return head;
    }
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next=prev;
            prev = temp;
            temp=front;
        }
        return prev;
    }
    ListNode* findknode(ListNode* temp, int k){
        k=k-1;
        while(k>0 && temp!=NULL){
            k--;
            temp=temp->next;
        }
        return temp;
    }
};