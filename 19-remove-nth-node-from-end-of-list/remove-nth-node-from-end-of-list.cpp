class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

     
        for(int i = 0; i < n; i++){
            fast = fast->next;
        }

        if(fast == nullptr){
            ListNode* delnode = head;
            head = head->next;
            delete delnode;
            return head;
        }

        // move both
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delnode = slow->next;
        slow->next = delnode->next;
        delete delnode;

        return head;
    }
};