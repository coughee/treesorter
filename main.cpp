#include <iostream>		
#include <cstdlib>
#include <string>
#include <iostream>

#include "TreeSorter.h"

using namespace std;

int main(int argc, char** argv){
  
  if(argc != 7 || argv[1] == "--help"){ 
    cout << "\n\n----------Tree Sorter------------\n";
    cout << "\n";
    cout << "Takes an input tree file and inserts\n";
    cout << "a symmetric tree onto every end node\n";
    cout << "and then sorts the end nodes to be in\n";
    cout << "order.\n\n";
    cout << "------------Usage----------------\n\n";
    cout << argv[0] << " -i <inputfile> -o <outputfile> -d <treedepth>\n\n";
    cout << "-----------Commands--------------\n\n";
    cout << "-i <filename>\t Specify the input file\n";
    cout << "-o <filename>\t Specify the output file\n";
    cout << "-d <depth>\t Specify the depth of symmetric tree to be added\n";
    cout << "--help\t\t Shows this list of commands\n\n";
    return 0;
  }

  int symTreeDepth = 0;
  string filename;
  string outputFile;
 
  //Command line input
  for(int i = 1; i < argc; ++i){
    string arg = argv[i];
    //cout << argv[i] << endl;
    if(arg == "-i"){
      filename = argv[i++ + 1];
    }
    else if(arg == "-d"){
      symTreeDepth = atoi(argv[i++ + 1]);
    }
    else if(arg == "-o"){
      outputFile = argv[i++ + 1];
    }
  }
  if(filename == ""){
    cout << "ERROR: You must specify and input file. Exiting\n";
    return 1;
  }
  if(outputFile == ""){
    cout << "ERROR: You must specify an output file name. Exiting\n";
  }
  if(symTreeDepth == 0){
    cout << "ERROR: symTreeDepth not specified or set to zero. Exiting\n";
  }
  
  cout << "\n\n------TreeSorter-----\n\n";
  TreeSorter treeSort = TreeSorter();
  treeSort.makeSymTree(symTreeDepth);
  treeSort.readTree((char*)filename.c_str());
  //treeSort.createTestTree(4);

  treeSort.findEndNodes();
  treeSort.insertSymTree(1);

  treeSort.findOrderedEndNodeList();

  treeSort.sortTree();
  treeSort.setValues(3.0);
  treeSort.tree.writeTreeFile((char*)outputFile.c_str());
  
}
