#include "Tree.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
//Swap the positions of two nodes with positions i and j.
void Tree::swap(int id1, int id2){
  if(id1 == id2){
    return;
  }
  //Separate cases:
  // same parent - don't do anything to internal state of any node except those involved in the swap (swap all variables)
  // different parent - same as above except now must change the internal state of the parent node and two child nodes (update reference)
  // one is parent of the other - 
  if(nodes[id1].isEndNode){
    int temp = id2;
    id2 = id1;
    id1 = temp;
    
  }
  int p1 = nodes[id1].parent;
  int c11 = nodes[id1].child1;
  int c12 = nodes[id1].child2;

  int p2 = nodes[id2].parent;
  int c21 = nodes[id2].child1;
  int c22 = nodes[id2].child2;
  if(nodes[id1].parent == nodes[id2].parent){
    //child id's of the id1 node
    if(!nodes[id1].isEndNode){
    nodes[c11].parent = id2;
    nodes[c12].parent = id2;
    }
    
  }
  else if(nodes[id2].parent == id1 && !nodes[id1].isEndNode){
    if(nodes[id1].child1 == id2){
      nodes[id1].child1 = id1;
    }
    else{
      nodes[id1].child2 = id1;
    }
    nodes[c11].parent = id2;
    nodes[c12].parent = id2;
    
    if(nodes[p1].child1 == id1){
      nodes[p1].child1 = id2;
    }
    else{
      nodes[p1].child2 = id2;
    }

  }
  else{
    //id1
 
    if(nodes[p1].child1 == id1){
      nodes[p1].child1 = id2;
    }
    else{
      nodes[p1].child2 = id2;
    }

    if(!nodes[p1].isEndNode){   
      nodes[c11].parent = id2;
      nodes[c12].parent = id2;
    }
    //id2
    if(nodes[p2].child1 == id2){
      nodes[p2].child1 = id1;
    }
    else{
      nodes[p2].child2 = id1;
    }
 
  }
  singleNodeSwap(id1,id2);
  
}

void Tree::singleNodeSwap(int id1, int id2){
  Node temp;
  temp.x = nodes[id1].x;
  temp.y = nodes[id1].y;
  temp.z = nodes[id1].z;
  temp.radius = nodes[id1].radius;
  temp.parent = nodes[id1].parent;
  temp.child1 = nodes[id1].child1;
  temp.child2 = nodes[id1].child2;
  temp.isEndNode = nodes[id1].isEndNode; 
  
  nodes[id1].x = nodes[id2].x;
  nodes[id1].y = nodes[id2].y;
  nodes[id1].z = nodes[id2].z;
  nodes[id1].radius = nodes[id2].radius;
  nodes[id1].parent = nodes[id2].parent;
  nodes[id1].child1 = nodes[id2].child1;
  nodes[id1].child2 = nodes[id2].child2;
  nodes[id1].isEndNode = nodes[id2].isEndNode; 


  nodes[id2].x = temp.x;
  nodes[id2].y = temp.y;
  nodes[id2].z = temp.z;
  nodes[id2].radius = temp.radius;
  nodes[id2].parent = temp.parent;
  nodes[id2].child1 = temp.child1;
  nodes[id2].child2 = temp.child2;
  nodes[id2].isEndNode = temp.isEndNode; 

}


int Tree::size(){
  return nodes.size();
}

void Tree::readTree(char* filename){
  cout << "-- Loading Tree from file: ";
  cout << filename << "...";
  nodes.clear();
  double fs;
  int i = 2;
  char *inname = filename;
  Node temp;
  double x, y, z;
  ifstream infile(inname);
  double numnodes;
  infile >> fs;
  infile >> fs;
  numnodes = 500;
  flow = fs;
  while (infile >> fs) {
    if (i == 1) {
      i++;
    } else if (i == 2) {
      temp.parent = (int) fs;
      i++;
    } else if (i == 3) {
      temp.child1 = (int) fs;
      i++;
    } else if (i == 4) {
      temp.child2 = (int) fs;
      i++;
    } else if (i == 5) {
      temp.isEndNode = (bool)fs;
      i++;
    } else if (i == 6) {
      temp.radius = (double)fs;
      i++;
    } else if (i == 7) {
      temp.x = (double)fs;
      i++;
    } else if (i == 8) {
      temp.y = (double)fs;
      i++;
    } else if (i == 9) {
      temp.z = (double)fs;
      temp.added = false;
      i++;
      nodes.push_back(temp);
      i = 2;
    } 
  }
  cout << "Complete\n";
}

void Tree::writeTreeFile(char* outputfilename){
  cout << "--Writing new tree to file ";
  cout << outputfilename << "...";
  std::ofstream output;
  output.open(outputfilename);
  output << nodes.size() << endl;
  output << flow << endl;
  for (long int i = 0; i < nodes.size(); i++) {
    output << nodes[i].parent << endl;
    output << nodes[i].child1 << endl;
    output << nodes[i].child2 << endl;
    output << nodes[i].isEndNode << endl;
    output << nodes[i].radius << endl;
    output << nodes[i].x << endl;
    output << nodes[i].y << endl;
    output << nodes[i].z << endl;
  }
  output.close();
  cout << "Complete\n";
}

void Tree::print(){
  cout << "\n\n------Printing Tree Contents------\n\n";
  for(int i = 0; i < nodes.size(); i++){
    cout << "Node " << i << ": ";
    nodes[i].print();
  }
  cout << "\n-----------Done-----------\n\n\n";
}

void Tree::setRadii(int id){
  if(nodes[id].added){
    nodes[id].radius = pow(2.0,-1.0/bifurcationExponent)*nodes[nodes[id].parent].radius;
    if(nodes[id].isEndNode){
      return;
    }
  }
  setRadii(nodes[id].child1);
  setRadii(nodes[id].child2);
}

void Tree::setPositions(int id){
  int pid = nodes[id].parent;
  if(nodes[id].added){
    nodes[id].x = nodes[pid].x + 0.1*nodes[id].radius;
    nodes[id].y = nodes[pid].y;
    nodes[id].z = nodes[pid].z;
  }
  if(nodes[id].isEndNode){
    return;
  }
  setPositions(nodes[id].child1);
  setPositions(nodes[id].child2);
}
