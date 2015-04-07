#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv){
  
  if(argc != 5 || argv[1] == "--help"){
    cout << "\n\n----------Tree Sorter------------\n";
    cout << "\n";
    cout << "Takes an input tree file and inserts\n";
    cout << "a symmetric tree onto every end node\n";
    cout << "and then sorts the end nodes to be in\n";
    cout << "order.\n\n";
    cout << "-----------Commands--------------\n\n";
    cout << "-i <filename>\t Specify the input file\n";
    cout << "-d <depth>\t Specify the depth of symmetric tree to be added\n";
    cout << "--help\t\t Shows this list of commands\n\n";
    return 0;
  }

  int symTreeDepth;
  string filename;
 
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
  }
  

  cout << filename << endl;
  cout << symTreeDepth << endl;
}
