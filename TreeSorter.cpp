#include "TreeSorter.h"
#include <iostream>

using namespace std;

TreeSorter::TreeSorter(){

};

void TreeSorter::sortTree(){
  //First find the ordered list of end nodes.
  int firstIndex = tree.size() - endNodesInOrder.size();
  int curEndNode = 0;
  cout << "\n\n------Starting End Node Sorting-----" << endl << endl;
  //Then loop over the tree nodes and swap with the end node.
  double total = endNodesInOrder.size();
  double divisor = 100;
  double currentGoal = total/divisor;
  double increment = currentGoal;
  int percentageComplete = 100/divisor;
  for(long int i = firstIndex; i < tree.size(); i++){

    if(curEndNode > currentGoal){
      cout  << percentageComplete << "% Complete\n";
      currentGoal += increment;
      percentageComplete += (int)100/divisor;
    }
    if( endNodesInOrder[curEndNode] > tree.size() - 1){
      cout << endNodesInOrder[curEndNode] << endl;
      cout << "Error: Index too big (tree)" << endl;
    }
    if(curEndNode > endNodesInOrder.size() - 1){
      cout << "Error: Index too big (end node list) - " << curEndNode << endl;
    }
    curEndNode = i - firstIndex;
    tree.swap(i,endNodesInOrder[curEndNode]);
    if(tree.nodes[i].isEndNode){
      //update end Node positions.
      int position = findInEndNodeList(i);
      endNodesInOrder[position] = endNodesInOrder[curEndNode];
    } 
  }
  cout << "\n--------Finished---------\n\n";
}

int TreeSorter::findInEndNodeList(int i){
  for(int j = 0; j < endNodesInOrder.size(); j++){
    if(endNodesInOrder[j] == i){
      return j;
    }
  }
}

void TreeSorter::findEndNodes(){
  cout << "Finding list of end Nodes...";
  endNodes.clear();
  for(int i = 0; i < tree.size(); i++){
    if(tree.nodes[i].isEndNode){
      endNodes.push_back(i);
    }
  }
  cout << "Complete\n";
}

void TreeSorter::findOrderedEndNodeList(){
  cout << "Finding ordered List of End Nodes...";
  findEndNodesInOrder(0);
  cout << "Complete - List size: ";
  cout << endNodesInOrder.size() << endl;
}
void TreeSorter::findEndNodesInOrder(int id){
  //Recursive algorithm
  if(tree.nodes[id].isEndNode){
    endNodesInOrder.push_back(id);
    return;
  }
  else{
    findEndNodesInOrder(tree.nodes[id].child1);
    findEndNodesInOrder(tree.nodes[id].child2);
  }
}

void TreeSorter::extendTree(){
  findEndNodes();
  for(int i = 0; i < endNodes.size(); i++){
    insertSymTree(endNodes[i]);
  }
}

void TreeSorter::insertSymTree(int endNode){
  cout << "Inserting Symmetric Tree at each end Node...";
  int currentSize = tree.size() - 1;
  
  for(int i = 0; i < symmTree.size(); i++){
    symmTree.nodes[i].parent += currentSize;
    symmTree.nodes[i].child1 += currentSize;
    symmTree.nodes[i].child2 += currentSize;
  }
  for(int i = 0; i < endNodes.size(); i++){
    tree.nodes[endNodes[i]].isEndNode = false;
    tree.nodes[endNodes[i]].child1 = tree.size();
    tree.nodes[endNodes[i]].child2 = tree.size() + 1;
    symmTree.nodes[1].parent = endNodes[i];
    symmTree.nodes[2].parent = endNodes[i];
    for(int j = 1; j < symmTree.size(); j++){
      tree.nodes.push_back(symmTree.nodes[j]);
      symmTree.nodes[j].parent += symmTree.size() - 1;
      symmTree.nodes[j].child1 += symmTree.size() - 1;
      symmTree.nodes[j].child2 += symmTree.size() - 1;
    }
    


  }
  
  cout << "Complete\n";
}

void TreeSorter::createTestTree(int depth){
  cout << "-- Building test tree of depth: ";
  cout << depth << "\n";
  Node temp;
  double size = (int)pow(2, depth) - 1;
  int tempP = 0, tempC1 = 0, tempC2 = 0;

  bool tempIsBlocked, tempIsEndNode = false;
  tree.nodes.resize(size);

  for(int i = 0; i < size; i++){
    tempC1 = 2*i + 1;
    tempC2 = 2*i + 2;
    tempP = (int)floor((i - 1) / 2);
    tempIsBlocked = false;
    if(i < floor((size - 1)/2)){
      tempIsEndNode = false;

    }
    else{
      tempIsEndNode = true;
    }
    tree.nodes[i].x = 0;
    tree.nodes[i].y = 0;
    tree.nodes[i].z = 0;
    tree.nodes[i].parent = tempP;
    tree.nodes[i].child1 = tempC1;
    tree.nodes[i].child2 = tempC2;
    tree.nodes[i].isEndNode = tempIsEndNode;
  }

  int count = 0;
  for(int i = 0; i < tree.size(); i++){
    if(tree.nodes[i].isEndNode){
      count++;
    }
  }
  double tempRadius = pow(pow(rootRadius, bifurcationExponent)/(double)count,1.0/bifurcationExponent);

  for(int i = 0; i < tree.size(); i++){
    if(tree.nodes[i].isEndNode){
      tree.nodes[i].radius = tempRadius;
    }
  }
  cout << "-- Complete\n";
  
}
void TreeSorter::makeSymTree(int depth){
  cout << "-- Building symmetric Tree of depth: ";
  cout << depth << "\n";
  Node temp;
  double size = (int)pow(2, depth) - 1;
  int tempP = 0, tempC1 = 0, tempC2 = 0;

  bool tempIsBlocked, tempIsEndNode = false;
  symmTree.nodes.resize(size);

  for(int i = 0; i < size; i++){
    tempC1 = 2*i + 1;
    tempC2 = 2*i + 2;
    tempP = (int)floor((i - 1) / 2);
    tempIsBlocked = false;
    if(i < floor((size - 1)/2)){
      tempIsEndNode = false;

    }
    else{
      tempIsEndNode = true;
    }
    symmTree.nodes[i].x = 0;
    symmTree.nodes[i].y = 0;
    symmTree.nodes[i].z = 0;
    symmTree.nodes[i].parent = tempP;
    symmTree.nodes[i].child1 = tempC1;
    symmTree.nodes[i].child2 = tempC2;
    symmTree.nodes[i].isEndNode = tempIsEndNode;
    symmTree.nodes[i].added = true;
  }

  int count = 0;
  for(int i = 0; i < symmTree.size(); i++){
    if(symmTree.nodes[i].isEndNode){
      count++;
    }
  }
  double tempRadius = pow(pow(rootRadius, bifurcationExponent)/(double)count,1.0/bifurcationExponent);

  for(int i = 0; i < symmTree.size(); i++){
    if(symmTree.nodes[i].isEndNode){
      symmTree.nodes[i].radius = tempRadius;
    }
  }
  cout << "-- Complete\n";

}

//Input and Output
void TreeSorter::outputTree(char* outputfilename){
  tree.writeTreeFile(outputfilename);
}

void TreeSorter::readTree(char* filename){
  tree.readTree(filename);
}

void TreeSorter::setValues(double bifurcationExponent){
  tree.bifurcationExponent = bifurcationExponent;
  cout << "--Setting radii for new nodes...";
  tree.setRadii(0);
  cout << "Complete\n";
  
  cout << "--Setting positions for new nodes...";
  tree.setPositions(0);
  cout << "Complete\n";
}

