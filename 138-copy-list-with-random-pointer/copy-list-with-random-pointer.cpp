/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node*, Node*> map;

        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            map[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            Node* copy = map[temp];
            copy->next = map[temp->next];
            copy->random = map[temp->random];
            temp=temp->next;
        }
        return map[head];
    }
};