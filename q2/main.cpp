
#include <iostream>
#include "fstream"
#include "vector"
#include "string"
#include "bd.hpp"
#include "edf.hpp"

using namespace std;


int main() {
    edf::EDF(4, "file2.txt");
   // bd::Bounded_Delay(4,"file2.txt");
    return 0;
}