
## 234. Palindrome Linked List
> Given a singly linked list, determine if it is a palindrome.  
> Follow up:
>Could you do it ==in O(n) time and O(1) space==?
  
 这道题的难度在于，空间复杂度O(1)。借助数组或者栈都需要O(n)或者O(n/2)的空间复杂度  
算法有以下几种：
1. 遍历整个链表，将链表每个节点的值记录在数组中，再判断数组是不是一个回文数组，时间复杂度为O（n），但空间复杂度也为O（n），不满足空间复杂度要求。
2. 利用栈先进后出的性质，将链表前半段压入栈中，再逐个弹出与链表后半段比较。时间复杂度O（n），但仍然需要n/2的栈空间，空间复杂度为O（n）。
3. 反转链表法，将链表后半段原地翻转，再将前半段、后半段依次比较，判断是否相等，时间复杂度O（n），空间复杂度为O（1）满足题目要求。

## 方法一： 数组法
```
class Solution {
public:
    bool isPalindrome(ListNode* head){
        vector<int> tmp;
        while(head!= NULL){
            tmp.push_back(head->val);
            head =head->next;
        }
        for(int i =0;i<tmp.size();i++){
            if(tmp[i]!= tmp[tmp.size()-i-1]) return false;
        }
        return true;
    }
};
```
时间复杂度为O（n），但空间复杂度也为O（n），不满足空间复杂度要求

## 方法二：栈 
==将链表前半段压入栈中，再逐个弹出与链表后半段比较。时间复杂度O（n）==   
但仍然需要n/2的栈空间，空间复杂度为O（n)    
个人感觉这个方法是最好的
## 方法三： 翻转链表法
时间复杂度O（n），空间复杂度为O（1）满足题目要求。
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode *pos = head;
        while(pos != NULL){
            n++;
            pos = pos -> next;
        }
        if(n == 0 || n == 1)
            return true;
        n = n / 2 - ((n % 2) ^ 1);
        pos = head;
        for(int i = 0 ; i < n ; i++){
            pos = pos -> next;
        }
        
        ListNode *list = pos;
        ListNode * tmp = pos -> next;
        while(tmp-> next != NULL){
            ListNode *p = tmp->next;
            tmp -> next = p -> next;
            p -> next = list -> next;
            list -> next = p;
        }
        
        ListNode *h1 = list -> next;
        while(h1 != NULL){
            if(h1 -> val != head -> val){
                return false;
            }
            h1 = h1 -> next;
            head = head -> next;
        }
        return true;
    }
};
```