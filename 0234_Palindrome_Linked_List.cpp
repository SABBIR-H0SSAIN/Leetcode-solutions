// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/palindrome-linked-list

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

// @1st Approch ( Using Stack )

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode *temp = head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            int top = st.top();
            st.pop();
            if(top != temp->val) return false;
            temp=temp->next;
        }
        return st.empty();
    }
};
