
/*
    https://leetcode.com/problems/merge-two-sorted-lists/
    合并两个有序链表
*/

#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    暴力算法
    1. 时间复杂度在冒泡算法比较大:O(n^2) 11ms 9%
    2. 空间复杂度好像比较少:O1 15.05Mbit 42%
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *tmp1 = list1;
        ListNode *pre;
        ListNode *begin1;
        ListNode *begin2;
        ListNode *end1;
        ListNode *end2;
        if(tmp1 == nullptr)
        {
            tmp1 = list2;
            if(tmp1 == nullptr)
            {
                return tmp1;
            }
            begin1 = tmp1;
            begin2 = tmp1->next;
            while(tmp1!=nullptr)
            {
                pre = tmp1;
                tmp1 = tmp1->next;
            }
            end1 = pre->next;
        }
        else
        {
            while(tmp1!=nullptr)
            {
                pre = tmp1;
                tmp1 = tmp1->next;
            }
            pre->next = list2;
            tmp1 = list2;
            while(tmp1!=nullptr)
            {
                pre = tmp1;
                tmp1 = tmp1->next;
            }
            end1 = pre->next;
            begin1 = list1;
            begin2 = list1->next;
        }
        // 暴力冒泡排序
        while(end1 != begin1)
        {
            ListNode *begin3 = begin1;
            ListNode *begin4 = begin2;
            while(begin4!=end1)
            {
                if(begin3->val > begin4->val)
                {
                    int valtmp = begin4->val;
                    begin4->val = begin3->val;
                    begin3->val = valtmp;
                }
                begin3 = begin4;
                begin4 = begin4->next;
            }
            end1 = begin3;
        }
        return begin1;
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    _getch();
    return 0;
}