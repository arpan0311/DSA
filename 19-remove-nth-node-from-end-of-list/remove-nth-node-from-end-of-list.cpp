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
        ListNode* temp = head;
        int len = 0;
        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }
        int reach = len - n;
        if (reach == 0) {
            ListNode* newHead = head->next;
            delete head; // use delete not free (C++ object)
            return newHead;
        }
        int i = 0;
        ListNode* curr = head;
        ListNode* curr_head = curr;
        while (i != reach-1) {
            curr = curr->next;
            i++;
        }

        ListNode* del = curr->next;
        if (del != nullptr) {
            curr->next = del->next; // del->next could be nullptr — that's fine!
            delete del;
        }
        return curr_head;
    }
};