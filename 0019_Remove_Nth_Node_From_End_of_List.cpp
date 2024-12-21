// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list

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

 //@1st Approch (Using Size Calculation )

class Solution {
public:
    int size(ListNode* head) {

        int size = 0;
        ListNode* temp = head;

        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = this->size(head);
        if (n == length) return head->next;
        ListNode* temp = head;

        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        if (temp->next) temp->next = temp->next->next;

        return head;
    }
};

// Optimized approch ( Without Size Calculations )

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy= new ListNode(-1,head);
        ListNode *temp=dummy;
        for(int i=0;i<n;i++) head=head->next;

        while(head){
            head=head->next;
            temp=temp->next;
        }

        temp->next = temp->next->next;
        return dummy->next;
    }
};
