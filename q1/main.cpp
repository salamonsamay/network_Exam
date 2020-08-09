#include <iostream>
#include "fstream"
#include "vector"
#include "prefix_table_opt.cpp"
using namespace std;
//using namespace prefix_table;
using namespace prefix_table_opt;


int main()
{
 
        ifstream MyReadFile("file.txt");
        string myText;
        tree t;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
      string s = myText;
      string command = s.substr(0, s.find(' '));

      int index = s.find(' ');

      string value = s.substr(index + 1);

      if (command == "ADD")
      {
        prefix_ f(value);
        t.add(f);
      }
      else if (command == "FIND")
      {

        t.find(value);
      }
      else if (command == "REMOVE")
      {
        prefix_ f(value);
      }
    }
    // Output the text from the file
   
    MyReadFile.close();
}



// Close the file
