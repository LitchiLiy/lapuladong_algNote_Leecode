#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct ListNode;
ListNode *rec(vector<int>::iterator ibeg, vector<int>::iterator iend);

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode(-1), *list1begin = list1;
        ListNode* list2 = new ListNode(-1), *list2begin = list2;
        while(head!=nullptr)
        {
            if(head->val < x)
            {
                list1->next = head;
                list1 = list1->next;
            }
            else
            {
                list2->next = head;
                list2 = list2->next;
            }
            head = head->next;
        }
        list1->next = list2begin->next;
        return list1begin->next;
    }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    vector<int> a{1, 2, 1, 1, 5, 8, 3, 8, 0, 4, 6, 3, 1, 99};
    int b = 6;
    ListNode *root = rec(a.begin(), a.end());
    _getch();
    return 0;
}

ListNode* rec(vector<int>::iterator ibeg, vector<int>::iterator iend)
{
    if(ibeg == iend)
    {
        return nullptr;
    }
    ListNode *head = new ListNode(*ibeg, rec(ibeg+1, iend));
    return head;
}