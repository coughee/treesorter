#ifndef TREESORTER_H_INCLUDE
#define TREESORTER_H_INCLUDE
#include "Tree.h"
#include <vector>
#include <cmath>

class TreeSorter {
public:
  Tree tree;
  Tree symmTree;
  
  double rootRadius;
  double bifurcationExponent;
  std::vector<int> endNodes;
  std::vector<int> endNodesInOrder;
  
  TreeSorter();

  //Sorting and merging Symmetric Tree.
  void sortTree();
  void findEndNodes();
  void findEndNodesInOrder(int i);
  void findOrderedEndNodeList();
  void extendTree();
  void insertSymTree(int endNode);
  void makeSymTree(int depth);
  int findInEndNodeList(int i);

  void setValues(double bifurcationExponent);

  //Testing
  void createTestTree(int depth);
  

  //Input and Output
  void outputTree(char* outputfilename);
  void readTree(char* filename);


private:

};
#endif
