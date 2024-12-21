// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list

// @1st Approch (Using Size Calculation )

class Solution {
public:
    int size(ListNode *head){
        
        int size=0;
        ListNode *temp = head;

        while(temp){
            size++;
            temp=temp->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = this->size(head);
        ListNode *temp = head;
        if(length == n) return head->next;

        for(int i=1;i<length-n;i++){
            temp=temp->next;
        }

        temp->next=temp->next->next;
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
