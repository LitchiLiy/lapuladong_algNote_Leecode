
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

class Solution1 {
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
/*
    dummy虚拟节点算法
    1. 时间复杂度: 最差list1和list2两个一样长为n, 那On 8ms 20%
    2. 空间复杂度: 存在着一个总体列表为On 15.22Mbit 12%

    由于总列表的存在, 导致内存比我的垃圾暴力算法更大, 有一点没有注意到, 连个来源列表都是已经排好序的了, 无需重新再排
*/

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1), *p = dummy;
        ListNode* p1 = list1, *p2 = list2;
        while(p1!=nullptr && p2!=nullptr)
        {
            if(p1->val > p2->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            else
            {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }
        if(p1 == nullptr)
        {
            p->next = p2;
        }
        if(p2 == nullptr)
        {
            p->next = p1;
        }
        return dummy->next;
    }
};
/*
    递归算法
    1. 时间复杂度: On 5ms 57%
    2. 空间复杂度: On 15.11Mbit 22%%

    递归算法太强了, 结构太完美了, 如果使用递归, 先处理最后的结果在前面, 先想到递归到最后应该怎么返回
*/

class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
        {
            return list2;
        }
        if(list2 == nullptr)
        {
            return list1;
        }
        if(list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    _getch();
    return 0;
}