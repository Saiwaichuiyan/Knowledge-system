#pragma once
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(nullptr) {}
};
class List
{
public:
    /*
            给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
        为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
        如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
        说明：不允许修改给定的链表。
    */
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast, *slow;
        int x = 0, y = 0;
        fast = slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            x += 2;
            y++;
            slow = slow->next;
            fast = fast->next;
            if (fast == slow) {
                ListNode *t = slow;
                ListNode *t1 = head;
                while (t1 != t) {
                    t = t->next;
                    t1 = t1->next;
                }
                return t1;
            }

        }

        return nullptr;
    }
};

class ListTest {
public:
    bool detectCycleTest() {
        List list;
        ListNode* head, *next,*temp;
        next = head = new ListNode(1);
        temp = next->next = new ListNode(88);
        next = next->next;
        for (int i = 0; i < 5; i++) {
            next->next = new ListNode(i);
            next = next->next;
        }
        next->next = temp;
        auto result = list.detectCycle(head);
        std::cout << result->val << std::endl;
        return true;
    }

    void run() {
        std::cout << "dettect cycle test " << detectCycleTest() <<std::endl;
    }
};
