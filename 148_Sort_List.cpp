// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/sort-list

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
    ListNode *findMid(ListNode * head){
        ListNode *once=head;
        ListNode *twice=head->next;
        while(twice && twice->next){
            once = once->next;
            twice = twice->next->next;
        }
        return once;
    }
    ListNode *merge(ListNode *left,ListNode *right){
        if(!left) return right;
        if(!right) return left;

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                left=left->next;
            }else{
                temp->next = right;
                right=right->next; 
            }

            temp=temp->next;

        }

        temp->next=left ? left : right;
        return dummy->next;   
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;

        ListNode *left = head;
        ListNode *mid = findMid(head);
        ListNode *right = mid->next;

        mid->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return this->merge(left,right);

    }
};
