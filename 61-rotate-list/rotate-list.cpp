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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int len=1;
        ListNode* temp=head;
        // .count length 
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        k=k%len;
        if(k==0){
            return head;
        }
    //    last wale ko head se connext karo 
        temp->next=head;
        int rem=len-k;
        ListNode* newhead=head;
        
        for(int i=1;i<rem;i++){
            newhead=newhead->next;
        }
        // toodooo
        ListNode* head1=newhead->next;
        newhead->next=NULL;
        return head1;
    }
};