//wordrange.h
#ifndef WORDRANGE_H
#define WORDRANGE_H

#include <string>

struct AVLNode {
  std::string key;//Node Key
  std::string min, max; //Node Min and Max
  int height;//Node Height
  int size;//Node Size
  AVLNode *left, *right;//Node left and right subtree

  AVLNode(std::string k);
};

int getHeight(AVLNode* node);//return the height of target node
int getSize(AVLNode* node);//return the size of the target node
int getBalance(AVLNode* node);//return the balance factor of target node
void updateNode(AVLNode* node);//update the node's height, size, min, max

AVLNode* rightRotate(AVLNode* y);//right rotate the certain node
AVLNode* leftRotate(AVLNode* x);//left rotate the certain node

AVLNode* insert(AVLNode* node, std::string key);//insert the key to target AVL tree
int rangeQuery(AVLNode* node, std::string low, std::string high);//return the number of elements in certain range

#endif // WORDRANGE_H