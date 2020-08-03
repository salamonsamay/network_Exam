#include <iostream>
#include <sstream>

using namespace std;
/*
 type = 0 is prefix  that created only in add method to put  other prefix in his place
  its just created  to put the other prefix in his place
  example if the tree is empty and we  want to add the prefix 10001*->A
  the tree look like    ()->(1)->(10)->(100)->(1000)->(10001)  all the prefix is type 0 without the last 

   type = 1 is prefix  that created only in add method to put  other prefix in owen place
  example if the tree is empty and we  want to add the prefix 10001*->A
  the tree look like    ()->(1)->(10)->(100)->(1000)->(10001)  all the prefix is type 0 without the last  

  type 2 it ip 
*/
namespace prefix_table
{
    struct prefix_
    {
        string action, decimal_prefix, binary_prefix, path,subnetMask;
        prefix_ *left0 = nullptr, *right1 = nullptr;
        int type, subentSize = 0;
        //type=0 is prefix road ,type=1 is prefix with action ,type=2 is ip address with 32 bits;

        prefix_(string dp = "") : decimal_prefix(dp)
        {
            setType(2);
            if (dp.size() == 0)
            { //its a road that creat in add method
                setType(0);
            }

            for (int i = 0; i < dp.size(); i++)
            {
                if (dp.at(i) == '/')
                {
                    string suffix = dp.substr(i + 1);
                    string num = dp.substr(i + 1, suffix.find(' '));
                    subentSize = convertToInt(num);
                    setType(1);
                    break;
                }
            }

            init(dp);
        }
        ////////////255.255.255.255 to 11111111.11111111.11111111.11111111////////////////////
        string convertToBinary(string decimal_prefix)
        {
            string binary = "";
            int start = 0;
            int size = decimal_prefix.size();
            for (int i = 0; i < size; i++)
            {
                if (decimal_prefix.at(i) == '.' || i == size - 1)
                {
                    string octeta = decimal_prefix.substr(start, i);
                    start = i + 1;
                    int num = convertToInt(octeta);
                    string str = "";
                    while (num > 0)
                    {

                        str = convertToString(num % 2) + str;
                        num /= 2;
                    }
                    ///if is the last octeta we dont add dot
                    if (i == size - 1)
                    {
                        while (str.size() < 8)
                        {
                            str = '0' + str;
                        }
                        binary += str;
                    }
                    else
                    {
                        while (str.size() < 8)
                        {
                            str = '0' + str;
                        }
                        str += ".";

                        binary += str;
                    }
                }
            }
            //binary += decimal_prefix.substr(start);
            //   cout<<"|||||||"<<endl;
            //  cout<<binary<<endl;
            //    cout<<"|||||||"<<endl;
            return binary;
        }
        bool contain(string ip){
             string str=convertToBinary(ip);
            int k=0;
            for(int i=0;i<getSubnetSize();i++){
                if(str.at(i)=='.'){
                    k++;
                    cout<<k<<endl;
                }

            }
             str=convertToBinary(ip).substr(0,getSubnetSize()+k);
            string str2=getbinaryPrefix().substr(0,getSubnetSize()+k);
            // cout<<str<<endl;
            // cout<<str2<<endl;
            if(str==str2){
                cout<<"true"<<endl;
                return true;}

            return false;
           
        }
        string getAction() { return action; }
        string getdecimalPrefix() { return decimal_prefix; }
        string getbinaryPrefix() { return binary_prefix; }
        string getPath() { return path; }
        int getType() { return type; }
        int getSubnetSize() { return subentSize; }
        void operator=(prefix_ const &other)
        {
            this->action = other.action;
            this->decimal_prefix = other.decimal_prefix;
            this->binary_prefix = other.binary_prefix;
            this->path = other.path;
            this->left0 = other.left0;
            this->right1 = other.right1;
            this->type = other.type;
            this->subentSize = other.subentSize;
        }
        void setAction(string a) { this->action = a; }
        void setdecimalPrefix(string dp) { this->decimal_prefix = dp; }
        void setbinaryPrefix(string bp) { this->binary_prefix = bp; }
        void setPath(string p) { this->path = p; }
        void setType(int t) { 
            if(t==0){
                 setAction("");
                 setdecimalPrefix("");
                 setbinaryPrefix("");
             
            }
            this->type = t; }

        void init(string address)
        {

            if (getType() == 0)
                return;

            if (getType() == 1) //if address its a type of xxx.xxx.xxx.xxx xxx.xxx.xxx.x/num A
            {
                int index = address.find('/');
                setbinaryPrefix(convertToBinary(address.substr(0, index)));
                string suff = address.substr(index);
                int index2 = address.find(' ');
                setAction(address.substr(index2 + 1));
            }
            if (getType() == 2)
            { //if address its a type of xxx.xxx.xxx.xxx
                setbinaryPrefix(convertToBinary(address));
            }
            //////////////////update path////////////////////////
            string path = "";

            for (int i = 0; i < getbinaryPrefix().size(); i++)
            {
                if (getbinaryPrefix().at(i) != '.')
                {
                    path += getbinaryPrefix().at(i);
                }
                if (path.size() == getSubnetSize() && getType() == 1)
                {
                    break;
                }
            }
            setPath(path);
            ///////////////////////////////////////////////////////
        }

        int convertToInt(string s)
        {

            int myint1 = stoi(s);
            int x = myint1;
            return x;
        }

        string convertToString(int num)
        {

            string s;
            stringstream out;
            out << num;
            s = out.str();

            return s;
        }
    };

    class tree
    {
    public:
        prefix_ *root = new prefix_();
        prefix_ *pointer;
        int size = 0;

        void add(prefix_ &address)
        {
            size++;
            prefix_ *pointer = root;
            string path = address.getPath();
            for (int i = 0; i < path.size(); i++)
            {
                if (path.at(i) == '0')
                {
                    if (pointer->left0 == nullptr)
                    {
                        pointer->left0 = new prefix_();
                        pointer->left0->setPath(path.substr(0, i + 1));
                        //pointer->left0->setType(0);
                       
                    }
                    pointer = pointer->left0;
                }
                if (path.at(i) == '1')
                {
                    if (pointer->right1 == nullptr)
                    {
                        pointer->right1 = new prefix_();
                        pointer->right1->setPath(path.substr(0, i + 1));
                        //  pointer->right1->setType(0);
                    }
                    pointer = pointer->right1;
                }
            }

            *pointer = address; //copy all the data from address
            cout << " Added  " << pointer->getdecimalPrefix() << " at the depth " << pointer->getSubnetSize() << " total nodes " << pointer->getbinaryPrefix() << endl;
        }

        void find(string ip)
        {
            prefix_ *pref = new prefix_(ip);
            find(*pref, *root, pref->getPath());
        }

        void find(prefix_ &ip, prefix_ & root, string path)
        {
            
            if (root.getType() == 1 && root.contain(ip.getbinaryPrefix()))
            {
                this->pointer=&root;
               cout << "Found " << ip.getdecimalPrefix() << " " << root.getAction() << " at the depth " << root.getSubnetSize() << endl;
                return;
            }
            if(path.size()==0){
                return;
            }
            if (path.at(0) == '0')
            {
                string s = path.substr(1);
                find(ip, *(root.left0), s);
            }
            if (path.at(0) == '1')
            {
                string s = path.substr(1);
                find(ip, *(root.right1), s);
            }
        }

        void remove(prefix_ &pref)
        {
           remove(pref,*root,pref.getPath());
           cout<<"Removed "<<pointer->getdecimalPrefix() <<" at the depth "<<pointer->getSubnetSize()<<
           " total nodes " <<pointer->getbinaryPrefix()<<endl;
           this->pointer->setType(0);
        }
        void  remove(prefix_ &ip, prefix_ & root, string path){

            if (root.getType() == 1)
            {
                this->pointer=&root;
                return;
            }
            if(path.size()==0){
                return;
            }
            if (path.at(0) == '0')
            {
                string s = path.substr(1);
                find(ip, *(root.left0), s);
            }
            if (path.at(0) == '1')
            {
                string s = path.substr(1);
                find(ip, *(root.right1), s);
            }
        }
    

        void print()
        {
            print(*root);
        }
        void print(prefix_ &prefix)
        {

            if (prefix.getType() != 0)
            {
                cout << prefix.getdecimalPrefix() << endl;
            }
            if (prefix.left0 != nullptr)
            {
                print(*(prefix.left0));
            }
            if (prefix.right1 != nullptr)
            {
                print(*(prefix.right1));
            }
        }
    };
} // namespace prefix_table
