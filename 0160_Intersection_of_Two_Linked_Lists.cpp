// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists

// @1st Approch ( Comparing Size Difference)
 
class Solution {
    int calculateSize(ListNode *head){
        int size=0;
        while(head){
            size++;
            head=head->next;
        }
        return size;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      
        int s1 = this->calculateSize(headA);
        int s2 = this->calculateSize(headB);
        int diff = abs(s1-s2);
      
        for(int i=0;i<diff;i++){
            if(s1 > s2) headA=headA->next;
            else headB=headB->next;
        }

        while(headA != headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};

// @2nd Approch ( Without Size Calculation )

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;

        while(ptr1 != ptr2){
            ptr1 = ptr1 ? ptr1->next : headB;
            ptr2 = ptr2 ? ptr2->next : headA;
        }
        return ptr1;
    }
};
