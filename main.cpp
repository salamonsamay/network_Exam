#include <iostream>
#include "a.hpp"
#include "vector"
#include "iterator"
#include "map"
#include "algorithm"
#include "iterator"
#include <sstream>

#include "fstream"
#include "string"
//#include "prefix_table.cpp"
#include "prefix_table.cpp"
using namespace std;
//using namespace prefix_table;
using namespace prefix_table;


int main()
{


  

  tree t;
  string s2 = "111111.11";
  // string s3 = "255.225.255.0/22 A";
  prefix_ f1("24.2.255.1/15 A");
  prefix_ f2("24.0.255.2/15 A");
  prefix_ f3("225.25.0.4/22 C");

  t.add(f1);
  t.add(f2);
  t.add(f3);
  t.opt();
  //t.remove(f2);
  t.print();
  cout<<f1.getBinaryPrefix()<<endl;
   cout<<f2.getBinaryPrefix()<<endl;
 

  
  
};
