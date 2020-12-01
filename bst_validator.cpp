/******************************
Pseudocode:
Formation function
  Allocates origin to a new Tree
  Sets right of origin to NULL
  Sets left of origin to NULL
  Sets value of origin to value
  Returns origin

Ammend function
  If value is less than or equal to value of parent
    Sets left of parent to the Ammend function
    Returns parent
  Else
    Sets right of parent to the Ammend function
    Returns parent

BSTValidator function
  If the parent is NULL
    Returns false
  If the value of parent is less than minimum and more than maximum
    Returns false
  Returns the BSTValidator function twice for the left and right branches

main function
  Initializes parent to NULL
  Initializes minimum to -500
  Initializes maximum to 500
  Initializes bool result to false
  Initializes int array[]
  For loop to Ammend each parent
  Prints the result
******************************/

#include <iostream>
#include <vector>

struct Tree  {
  int value;
  Tree* right;
  Tree* left;
};

Tree* Formation(Tree* origin, int value)  {
  Tree* origin = new Tree();

  origin->right = NULL;
  origin->left = NULL;
  origin->value = value;
  
  return origin;
}

Tree* Ammend(Tree* parent, int value)  {

  if(value <= parent->value)  {
    parent->left = Ammend(parent->left, value);
    return parent;
  }

  else  {
    parent->right = Ammend(parent->right, value);
    return parent;
  }
}

bool BSTValidator(Tree* parent, int minimum, int maximum)  {

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
  int minimum = -500;
  int maximum = 500;
  bool result = false;
  int array[] = {10,5,15,2,7, 11, 25, 1};

  for (int y = 0; y < (sizeof(array)/sizeof(array[0])); y++)  {
    parent = Ammend(parent, array[y]);
  }

  result = BSTValidator(parent, minimum, maximum);
  std::cout << "Is this a BST?" << std::endl;
  std::cout << result << std::endl;
}