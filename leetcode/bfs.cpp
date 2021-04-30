/*************************************************************************
        > File Name: bfs.cpp
        > Author:
        > Mail:
        > Created Time: 2021年03月13日 星期六 14时17分17秒
 ************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};

/// @brief find Tree min depth
/// @param[in] root Tree root pointer
/// @return Tree min depth
int MinDepth(struct TreeNode *root) {
  if (root == nullptr)
    return 0;
  std::queue<struct TreeNode *> queue;
  queue.push(root);
  int depth = 1;
  while (!queue.empty()) {
    int qsize = queue.size();
    for (size_t i = 0; i < qsize; i++) {
      struct TreeNode *node = queue.front();
      queue.pop();
      if (node->left == nullptr && node->right == nullptr)
        return depth;
      if (node->left != nullptr)
        queue.push(node->left);
      if (node->right != nullptr)
        queue.push(node->right);
    }
    depth++;
  }
}

int main(int argc, char *argv[]) { return 0; }
