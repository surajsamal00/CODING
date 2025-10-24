#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {

        Node* slow = head;
        Node* fast = head;

        while(fast!= nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast!= nullptr){
                fast = fast->next;
            }
            if(slow == fast){
                break;
            }
        }
        if(fast == nullptr) {
            return 0; // no cycle
        }
        
        slow = head;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        Node* common = slow; //junction in singly linked list

        int cnt = 0;

        do{
            cnt++;
            slow = slow->next;
        } while(slow != common);
        
        return cnt;
    }
};