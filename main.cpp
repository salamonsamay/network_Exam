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
#include "prefix_table.cpp"
using namespace std;
using namespace prefix_table;
//using namespace solver;
// struct prefix
// {
//   string binary_prefix = "";
//   string decimal_prefix="";
//   string action = "";
//   prefix *right_1 = nullptr;
//   prefix *left_0 = nullptr;
//   int depth=0;
//   bool isprefix = false;

//   prefix(string address=""){
//     init(address);
//   }

//   string init(string address)
//   {
//     decimal_prefix=address.substr(0,address.size()-1);

//     int x = 0;
// //count the prefix size//////////////////////////////
//     bool isIp=true;
//     for (int i = 1; i < address.size(); i++)
//     {
//       if (address.at(i - 1) == '/') //255.255.255.0/24 A    convert 24 to int
//       {
//         isIp=false;
//         action = address.substr(i + 3);
//         string str = address.substr(i, 2);
//         stringstream geek(str);
//         x = 0;
//         geek >> x;
//       }
//     }
//     if(isIp){
//       x=address.size();
//       cout<<"x="<<x<<endl;
//       }
// /////////////////////////////////////////////////////////////////

//     string prefix = "";
//     for (int i = 0; i < x / 8; i++)
//     {
//       string octeta = address.substr(i * 3 + i, 3);
//       prefix += convertToBinary(octeta);
//       if (i + 1 < x / 8)
//       {
//         prefix += ".";

//       }
//     }
//     ///////////add last octeta//////////////
//     int n=x%8;
//     // if(n>0){
//     //   cout<<"the address is "<<prefix<<endl;
//     //  string octeta=address.substr(x+1,n);
//     // cout<<"the octeta is "<<octeta<<endl;
//     // }

//   //////////////////////////////////////////

//     binary_prefix = prefix;

//     return prefix;
//   }

//   string &convertToBinary(string &s_)
//   {
//     stringstream geek(s_);
//     int n = 0;
//     geek >> n;

//     string s = "";
//     while (n != 0)
//     {
//       int k = n % 2;
//       stringstream ss;
//       ss << k;
//       string str = ss.str();
//       s = str + s;
//       n /= 2;
//     }

//     s_ = s;
//     return s_;
//   }
// };

// class tree
// {
// public:
//   prefix *root = new prefix();
//   int size = 0;
//   prefix *pointer=nullptr;

//   tree() {}

//   void add(prefix p)
//   {

//     string s=p.binary_prefix;

//     if (size++ == 0)
//     {
//       root = new prefix();
//     }

//     pointer = root;
//     string dot="";
//     for (int i = 0; i < s.size(); i++)
//     {
//       if (s.at(i) == '0')
//       {
//         if (pointer->left_0 == nullptr)
//         {
//           pointer->left_0 = new prefix();
//           pointer->left_0->binary_prefix = pointer->binary_prefix +dot+ "0";
//           pointer->left_0->depth=pointer->depth+1;
//           dot="";
//         }
//         pointer = pointer->left_0;
//       }
//       else if (s.at(i) == '1')
//       {
//         if (pointer->right_1 == nullptr)
//         {
//           pointer->right_1 = new prefix();

//           pointer->right_1->binary_prefix = pointer->binary_prefix +dot+ "1";
//            pointer->right_1->depth=pointer->depth+1;
//           dot="";
//         }
//         pointer = pointer->right_1;
//       }
//       else if(s.at(i)=='.'){
//         dot=".";
//         continue;
//       }

//     }
//     pointer->binary_prefix += "*";
//     pointer->action=p.action;
//     pointer->isprefix = true;
//     cout<<"ADD "<<p.binary_prefix<<"  at the depth "<<pointer->depth<<" total node "<<p.decimal_prefix<<endl;
//   }
//   friend ofstream &operator<<(ofstream &o, const tree &t);

//   void print(prefix &n)
//   {
//     if (n.isprefix)
//     {
//       cout <<"print :"<< n.binary_prefix <<"-->"<<n.action <<endl;
//     }
//     if (n.left_0 != nullptr)
//     {

//       print(*n.left_0);
//     }
//     if (n.right_1 != nullptr)
//     {

//       print(*n.right_1);
//     }
//   }
//    string find(prefix address){
//      pointer=root;
//      string binary=address.binary_prefix;
//       for(int i=0;i<binary.size();i++){
//          if(binary.at(i)=='0'){
//            pointer=pointer->left_0;
//          }
//           if(binary.at(i)=='1'){
//            pointer=pointer->right_1;
//          }
//          if(pointer->isprefix){
//            cout<<"the action is :"<< pointer->action<<endl;
//            return pointer->action;
//          }
//          if(pointer==nullptr){
//            cout<<"the ip not found"<<endl;
//            return "not found";
//          }
//       }
//       return "not found";
//    }
// };
//   ofstream& operator<<(ofstream &o ,const tree &t){

//  }
// int packet_table(ifstream &file)
// {
// }

int main()
{
 prefix_ p3("2.5.2.0/21 C");
  prefix_ p("2.5.2.0/20 A");
 
   prefix_ p2("23.5.122.0/12 B");
  tree t;
  t.add(p);

  t.add(p2);
  t.add(p3);
  t.print();

  // t.add(p4);
  // t.add(p5);

   t.find("23.15.2.14");
  

    //  t.remove(p2);

  // t.print();

  // tree t;
  // string s2 = "111111.11";
  // // string s3 = "255.225.255.0/22 A";
  // prefix f1("255.255.255.0/24 A");
  // cout<<"binary :"<<f1.binary_prefix<<endl;

  // prefix f2("255.255.255.0/24 B");
  // // f1.init("255.225.255.0/24 B");
  //  prefix f3("255.255.255.255");
  //  cout<<f3.binary_prefix<<endl;
  //   t.add(f1);
  //   t.add(f2);
  // t.print(*t.root);
  //    t.find(f3);

  // string s = "100";
  // convertToBinary(s);
  ////////////////////////////////////////////////////////////////////

  // string myText;
  // // Read from the text file
  // ifstream MyReadFile("file.txt");

  // // Use a while loop together with the getline() function to read the file line by line
  // while (getline(MyReadFile, myText))
  // {
  //   string s=myText;
  //   cout<<s.substr(0,s.find(' '))<<endl;
  //   // Output the text from the file
  //   cout << myText << endl;
  //   ;
  // }

  // // Close the file
  // MyReadFile.close();

  ///////////////////////////////////////////////////////////////////
  // vector<int> v = {100, 3, 1, 9, 11};
  // //int x=5;
  // int x = 6;

  // sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
};
