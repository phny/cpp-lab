#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int data;
  struct ListNode *next;
};

/// @brief 判断链表是否有环
bool HaveCycle(struct ListNode *head) {
  struct ListNode *slow = head;
  struct ListNode *fast = head;
  while (slow != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}

/// @brief 查找环的位置
struct ListNode *DetectCycle(struct ListNode *head) {
  struct ListNode *slow = head;
  struct ListNode *fast = head;
  while (slow != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }

  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;
}

/// @brief 寻找无环单链表的中点位置
struct ListNode *FindMiddle(struct ListNode *head) {
  struct ListNode *slow = head;
  struct ListNode *fast = head;
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

/// @brief 寻找单链表的倒数第k个元素
struct ListNode *FindKNode(struct ListNode *head, int k) {
  struct ListNode *slow = head;
  struct ListNode *fast = head;
  while (k-- > 0) {
    fast = fast->next;
  }
  while (fast != nullptr) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

///------------------------------------------------------------
/// @brief 左右指针：二分查找算法

int BinarySearch(const std::vector<int> &array, int target) {
  int left = 0;
  int right = array.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (array[mid] == target) {
      return mid;
    } else if (array[mid] < target) {
      left = mid + 1;
    } else if (array[mid] > target) {
      right = mid - 1;
    }
  }
  return -1;
}

/// @brief 两数之和
std::vector<int> TwoSum(const std::vector<int> &array, int target) {
  int left = 0;
  int right = array.size() - 1;
  while (left < right) {
    int sum = array[left] + array[right];
    if (sum == target) {
      return std::vector<int>{left, right};
    } else if (sum < target) {
      left++;
    } else if (sum > target) {
      right--;
    }
  }
  return std::vector<int>{-1, -1};
}

/// @brief 翻转数组
void Reverse(std::vector<int> &array) {
  int left = 0;
  int right = array.size() - 1;
  while (left < right) {
    int tmp = array[left];
    array[left] = array[right];
    array[right] = tmp;
    left++;
    right--;
  }
}

int main(int argc, char *argv[]) { return 0; }