// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
 
//  @1st approch using extra O(n) space 
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>nodes;
        ListNode *temp=head;
        int maxsum=0;

        while(temp){
            nodes.push_back(temp->val);
            temp=temp->next;
        }

        int l=0,r=nodes.size()-1;
        while(l<r){
            maxsum=max(maxsum,nodes[l++]+nodes[r--]);
        }
        return maxsum;

    }
};

// @2nd approch with O(1) space
class Solution {
    ListNode *findMid(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head){
        ListNode *reversed=nullptr;
        
        while(head){
            ListNode *temp=head->next;
            head->next=reversed;
            reversed=head;
            head=temp;
        }
        return reversed;
    }

public:
    int pairSum(ListNode* head) {
        ListNode *mid=findMid(head);
        ListNode *right=reverseList(mid);
        ListNode *left=head;
        int maxsum=0;

        while(left && right){
            maxsum=max(maxsum,left->val+right->val);
            left=left->next;
            right=right->next;
        }
     
        return maxsum;

    }
};
