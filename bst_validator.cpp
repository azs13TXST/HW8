#include <iostream>
#include <vector>
#include <string>

struct Tree  {
  int value;
  Tree* right;
  Tree* left;
};

Tree* Formation(int value)  {
  Tree* origin = new Tree();

  origin->value = value;
  origin->right = NULL;
  origin->left = NULL;
  
  return origin;
}

Tree* Ammend(Tree* parent, int value)  {
  if(parent == NULL)  {
    parent = Formation(value);
  }

  else if(value <= parent->value)  {
    parent->left = Ammend(parent->left, value);
  }

  else  {
    parent->right = Ammend(parent->right, value);
  }

  return parent;
}

bool BSTValidator(Tree* parent, int minimum, int maximum)  {
  std::cout << parent->left->value << std::endl;

  if(parent == NULL)  {
    return false;
  }

  if(parent->value < minimum || parent->value > maximum)  {
    return false;
  }

  return BSTValidator(parent->left, minimum, parent->value-1) && BSTValidator(parent->right, maximum, parent->value+1);
}

int main()  {
  Tree* parent = NULL;
  int minimum = -694206669;
  int maximum = 694206669;
  bool result = false;
  
  int array[] = {10,5,15,2,7, 11, 25, 1};

  for (int y = 0; y < (sizeof(array)/sizeof(array[0])); y++)  {
    parent = Ammend(parent, array[y]);
  }

  result = BSTValidator(parent, minimum, maximum);
  std::cout << result << std::endl;
}