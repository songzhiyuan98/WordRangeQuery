#include <iostream>
#include <fstream>
#include <string>
#include "wordrange.h"

//AVL Tree Define
AVLNode::AVLNode(std::string k) : key(k), min(k), max(k), height(2), size(1), left(nullptr), right(nullptr) {}

//Helper Function
//Return the Node Height
int getHeight(AVLNode* node){
  if (node == nullptr) return 0;
  return node->height;
}

//Return the Node Size
int getSize(AVLNode* node){
  if (node == nullptr) return 0;
  return node->size;
}

//Calculate the Balance
int getBalance(AVLNode* node){
  if (node == nullptr) return 0;
  return getHeight(node->left) - getHeight(node->right); //calculate the balance by left subtree height minus right subtree height
}

//update the node's height, size, min, max
void updateNode(AVLNode* node){
  node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));//node's height equal one plus left or right height
  node->size = 1 + getSize(node->left) + getSize(node->right);//node's size equal one plus sum of left and right size

  //update node's min
  node->min = (node->left ? node->left->min : node->key);
  if (node->left) node->min = std::min(node->min, node->key);
  //update node's max
  node->max = (node->right ? node->right->max : node->key);
  if (node->right) node->max = std::max(node->max, node->key);
}

//Rotate Operation
//rightRotate Operation
AVLNode* rightRotate(AVLNode* y){
  AVLNode* x = y->left;
  AVLNode* T2 = x->right;

  x->right = y;
  y->left = T2;

  updateNode(y);
  updateNode(x);
  return x;
}

//leftRotate Opertaion
AVLNode* leftRotate(AVLNode* x){
  AVLNode* y = x->right;
  AVLNode* T2 = y->left;

  y->left = x;
  x->right = T2;

  updateNode(x);
  updateNode(y);
  return y;
}

//insert Operation
AVLNode* insert(AVLNode* node, std::string key){
  //insert data by BST
  if (node == nullptr){
    return new AVLNode(key);//if AVL not exist yet, create a AVL tree
  }

  if (key < node->key){
    node->left = insert(node->left, key); //if key less than node's key, recusive left subtree
  }else if (key > node->key){
    node->right = insert(node->right, key); //if key greater than node's key, recusive right subtree
  }else{
    return node;//the value has already exist, return
  }

  updateNode(node);//update node

  //adjustment AVL tree by balance
  int balance = getBalance(node);

  //Left Left Case
  if (balance > 1 && key < node->left->key){
    return rightRotate(node);
  }

  //Right Right Case
  if (balance < -1 && key > node->right->key){
    return leftRotate(node);
  }

  //Left Right Case
  if (balance > 1 && key > node->left->key){
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  //Right Left Case
  if (balance < -1 && key < node->right->key){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

//using size, min and max property to range query(optimization)
int rangeQuery(AVLNode* node, std::string low, std::string high){
  if (!node) return 0;

  //check if current node in the range
  if (node->min >= low && node->max <= high){
    return node->size; //if whole subtree in the range, return the size of the node
  }

  int count = 0;

  //if current node in range, count current node
  if (node->key >= low && node->key <= high){
    count = 1;
  }

  //recursive check left subtree, if the max of left subtree greater or equal than the low
  if (node->left && node->left->max >= low){
    count += rangeQuery(node->left, low, high);
  }

  //recursive check right subtree, if the min of right subtree less or equal than the high
  if (node->right && node->right->min <= high){
    count += rangeQuery(node->right, low, high);
  }

  return count;
}

//main function
int main(int argc, char** argv){
  //check the number of parameter
  if (argc < 3){
    std::cerr << "Usage: " << argv[0] << " <inputfile> <outfile>" << std::endl;
    return 1;
  }

  std::ifstream infile(argv[1]);//get input file
  std::ofstream outfile(argv[2]);//get output file 

  //check if the inputfile getting correct
  if (!infile){
    std::cerr << "Error opening input file." << std::endl;
    return 1;
  }

  //check if the outputfile getting correct
  if (!outfile){
    std::cerr << "Error opening output file." << std::endl;
    return 1;
  }

  AVLNode* root = nullptr;//AVL tree's root
  std::string line;

  //insert or range query operation
  while (getline(infile, line)){
    //if command i, insert operation
    if (line[0] == 'i'){
      std::string key = line.substr(2);
      root = insert(root, key);
    }else if(line[0] == 'r'){ //if command r, range query operation
      size_t firstSpace = line.find(' ', 2);//get the first space since the index 2
      std::string low = line.substr(2, firstSpace - 2);//get the first string 
      std::string high = line.substr(firstSpace + 1);//get the second string
      int count = rangeQuery(root, low, high);//range query operation
      outfile << count << std::endl;//writing data into output file
    }
  }

  //close files
  infile.close();
  outfile.close();

  return 0;
}