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

 // @2nd Approch (Using Vector Array)

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        vector<int> arr;
        ListNode *temp = head;

        while(temp){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        for(int i=0;i*2<arr.size();i++){
            if(arr[i] != arr[arr.size()-i-1]) return false;
        }
        return true;
    }
};
