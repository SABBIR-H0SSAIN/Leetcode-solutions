// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head ) return nullptr;
        if(!head->next) return head;

        ListNode *odd_ptr = head;
        ListNode *even_ptr = head->next;
        ListNode *even_head= head->next;

        while(even_ptr && even_ptr->next){
            odd_ptr->next = even_ptr->next;
            odd_ptr = odd_ptr->next;
            even_ptr->next = odd_ptr->next;
            even_ptr= even_ptr->next;
        }

        odd_ptr->next = even_head;
        return head;

    }
};
