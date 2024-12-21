// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/design-browser-history 

// @1st Approch (using DoublyLinkedList)

class BrowserHistory {
   struct Node{
        string url;
        Node *next=nullptr;
        Node *prev=nullptr;
        Node(string link):url(link){};
    };

    Node *cur=nullptr;

public:
    BrowserHistory(string homepage) {
        cur = new Node(homepage);
    }
    
    void visit(string url) {
        Node *newNode = new Node(url);
        cur->next = newNode;
        newNode->prev = cur;
        cur=cur->next;
    }
    
    string back(int steps) {
        while(cur->prev && steps--){
            cur=cur->prev;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while(cur->next && steps--){
            cur=cur->next;
        }
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
