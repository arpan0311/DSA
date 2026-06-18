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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        int cnt = 0;
        while (cnt < n) {
            fast = fast->next;
            cnt++;
        }
        if (fast == NULL) {
            return head->next;
        }
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete (temp);
        return head;
    }
};