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
        // base condition
        if(head==0 || head->next==0 || k==0) return head;

        // find the length and the last node
        int n = 1;
        ListNode* tail = head;
        while(tail -> next != NULL){
            tail = tail -> next;
            n++;
        }

        k = k % n;
        if(k==0) return head;

        // make it circular linked list
        tail -> next = head;

        // find new tail 
        int x = n - k;
        ListNode* newTail = head;
        while(--x){
            newTail = newTail -> next;
        }

        // break the cycle
        ListNode* newHead = newTail -> next;
        newTail -> next = NULL;

        return newHead;
    }
};