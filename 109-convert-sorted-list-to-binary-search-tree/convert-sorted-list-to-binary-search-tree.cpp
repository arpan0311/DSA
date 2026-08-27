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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find_len(ListNode* head){
        int cnt=0;
        while(head!=nullptr){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
     TreeNode* build_tree(ListNode* head1, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        ListNode* temp=head1;
        int mid = (left + right) / 2;
        int cnt=0;
        while(head1->next!=nullptr&&cnt!=mid){
            cnt++;
            head1=head1->next;
        }
        TreeNode* head = new TreeNode(head1->val);
        head->left = build_tree(temp, left, mid - 1);
        head->right = build_tree(temp, mid + 1, right);
        return head;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // without extra space using same linkedlist...
        if(head==nullptr){
            return  nullptr;
        }
        int len=find_len(head);
        return build_tree(head,0,len-1);
    }
};