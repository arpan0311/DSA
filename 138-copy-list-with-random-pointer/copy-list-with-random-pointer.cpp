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
       
        
        Node* temp=head;
        unordered_map<Node*,Node*>hash;
        while(temp!=NULL){
           Node* newnode=new Node(temp->val);
           hash[temp]=newnode;
           temp=temp->next;
        }

        temp=head;
        while(temp!=nullptr){
           Node* copynode = hash[temp];
            copynode->next = hash[temp->next];
            copynode->random = hash[temp->random];;
            temp=temp->next;
        }
         return hash[head];
    }
};