#include <bits/stdc++.h>
using namespace std;

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    void reverse(ListNode *&head)
    {
        ListNode *right = head->next;
        ListNode *temp = nullptr;

        head->next = nullptr;
        while (right != nullptr)
        {
            temp = right->next;
            right->next = head;
            head = right;
            right = temp;
        }
    }
    void merge(ListNode *&head1, ListNode *&head2)
    {

        ListNode *temp = head1;
        ListNode *curr = head1;
        head1 = head1->next;

        while (head1 != nullptr || head2 != nullptr)
        {
            if (head2)
            {
                curr->next = head2;
                curr = head2;
                head2 = head2->next;
            }

            if (head1)
            {
                curr->next = head1;
                curr = head1;
                head1 = head1->next;
            }
        }
        head1 = temp;
    }

    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        int n = 0;
        ListNode *temp = head;

        while (temp)
        {
            n++;
            temp = temp->next;
        }

        int mid = n / 2;

        temp = head;
        ListNode *prev = nullptr;

        while (mid--)
        {
            prev = temp;
            temp = temp->next;
        }

        ListNode *head1 = head;
        ListNode *head2 = temp;

        prev->next = nullptr;

        reverse(head2);

        merge(head1, head2);
    }
};