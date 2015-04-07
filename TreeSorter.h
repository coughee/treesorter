#ifndef TREESORTER_H_INCLUDE
#define TREESORTER_H_INCLUDE
#include "Tree.h"
#include <vector>

class TreeSorter {
public:
  Tree tree;
  Tree symTree;

  std::vector<int> endNodes;
  std::vector<int> endNodesInOrder;
  
  TreeSorter();

  //Sorting and merging Symmetric Tree.
  void sortTree();
  void findEndNodes();
  void findEndNodesInOrder();
  void extendTree();
  void insertSymTree(int endNode);
  

  //Input and Output
  void outputTree();
  void readTree(char* filename);


private:

};
#endif
