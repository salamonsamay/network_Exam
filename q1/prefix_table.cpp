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
        string action, decimal_prefix, binary_prefix;
        prefix_ *left0 = nullptr, *right1 = nullptr;
        int type, prefixSize = 0;
        //type=0 is prefix road ,type=1 is prefix with action ,type=2 is ip address with 32 bits;

        prefix_(string dp = "") : decimal_prefix(dp)
        {
            if (dp == "")
            {
                setType(0);
                return;
            }
            setType(1);
            int i = dp.find('/');
            int j = dp.find(' ');
            string prefix_size = dp.substr(i + 1, j - i);

            int size = convertToInt(prefix_size);
            setPrefixSize(size);
            setAction(dp.substr(j + 1));
            string temp = "";
            /////////////////////////////////////////////////////////////////////////////////////////
            int start = 0;
            int end = dp.find('.');
            string octeta1 = dp.substr(start, end);

            ////////////////////////////////////////////////////////////////////////////////////////////
            temp = dp.substr(end + 1);
            start = end + 1;
            end = temp.find('.');
            string octeta2 = temp.substr(0, end);

            ///////////////////////////////////////////////////////////////////////////////////////////
            temp = temp.substr(end + 1);
            start = end + 1;
            end = temp.find('.');
            string octeta3 = temp.substr(0, end);

            //////////////////////////////////////////////////////////////////////////////////////////////////////
            temp = temp.substr(end + 1);
            start = end + 1;
            end = temp.find('/');
            string octeta4 = temp.substr(0, end);

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
            string prefix = convertToBnary2(octeta1) + convertToBnary2(octeta2) + convertToBnary2(octeta3) + convertToBnary2(octeta4);
            setBinaryPrefix(prefix.substr(0, getPrefixSize()));
        }
        ////////////255.255.255.255 to 11111111.11111111.11111111.11111111////////////////////
        string convertToBnary2(string s)
        {

            int num = convertToInt(s);
            string binary = "";

            while (num > 0)
            {
                binary = convertToString(num % 2) + binary;
                num /= 2;
            }

            while (binary.size() != 8)
            {
                binary = "0" + binary;
            }
            return binary;
        }

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
        void operator=(prefix_ &address)
        {
            this->action = address.action;
            this->binary_prefix = address.binary_prefix;
            this->decimal_prefix = address.decimal_prefix;
            this->type = address.type;
        }
        bool operator==(prefix_ pref)
        {
            if (this->action == pref.action && this->binary_prefix == pref.binary_prefix && this->decimal_prefix == pref.decimal_prefix && this->type == pref.type)
            {
                return true;
            }
            return false;
        }

        void setBinaryPrefix(string s)
        {
            this->binary_prefix = s;
        }

        void setPrefixSize(int n)
        {
            this->prefixSize = n;
        }
        void setAction(string a)
        {
            this->action = a;
        }
        void setType(int n)
        {
            this->type = n;
        }

        int getPrefixSize()
        {
            return this->prefixSize;
        }

        string getBinaryPrefix()
        {
            return binary_prefix;
        }
         string getDecimalPrefix(){
            return decimal_prefix;
        }
        string getAction()
        {
            return action;
        }
        int getType()
        {
            return type;
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
        prefix_ *pointer = nullptr;
        bool flage = true;

        void add(prefix_ &address)
        {
            int index = 0;
            pointer = root;
            string prefix = address.getBinaryPrefix();
            for (int i = 0; i < prefix.size(); i++)
            {
                if (prefix.at(i) == '0')
                {
                    if (pointer->left0 == nullptr)
                    {
                        pointer->left0 = new prefix_();
                    }
                    pointer = pointer->left0;
                }
                if (prefix.at(i) == '1')
                {
                    if (pointer->right1 == nullptr)
                    {
                        pointer->right1 = new prefix_();
                    }
                    pointer = pointer->right1;
                }
                index++;
            }

            *pointer = address;
            cout << "Added " << pointer->decimal_prefix << " at the depth " << index << " total nodes " << pointer->getBinaryPrefix() << " Found " << endl;
        }

        void find(string ip)
        {
            string temp = ip;
            ////////////////////////////////////////////////////////////////////
            string octeta1 = temp.substr(0, temp.find('.'));
            temp = temp.substr(temp.find('.') + 1);

            string octeta2 = temp.substr(0, temp.find('.'));
            temp = temp.substr(temp.find('.') + 1);

            string octeta3 = temp.substr(0, temp.find('.'));
            temp = temp.substr(temp.find('.') + 1);

            string octeta4 = temp;
            octeta1 = pointer->convertToBnary2(octeta1);
            octeta2 = pointer->convertToBnary2(octeta2);
            octeta3 = pointer->convertToBnary2(octeta3);
            octeta4 = pointer->convertToBnary2(octeta4);
            string bin = octeta1 + octeta2 + octeta3 + octeta4;
            /////////////////////////////////////////////////////////////////////////////////////
            pointer = root;
            find(bin, *pointer, ip);
            pointer = nullptr;
        }

        void find(string &binary, prefix_ &root, string &ip)
        {
            if (binary.size() > 0)
            {

                if (binary.at(0) == '0')
                {

                    string s = binary.substr(1);
                    if (root.left0 != nullptr)
                    {
                        find(s, *root.left0, ip);
                    }
                    if (root.getType() == 1 && flage)
                    {
                        cout << "Found " << ip << "-->" << root.getAction() << " at the depth "
                             << root.getPrefixSize() << endl;
                        flage = false;
                    }
                }
                else if (binary.at(0) == '1')
                {

                    string s = binary.substr(1);
                    if (root.right1 != nullptr)
                    {
                        find(s, *root.right1, ip);
                    }
                    if (root.getType() == 1 && flage)
                    {
                        cout << "Found " << ip << "-->" << root.getAction() << " at the depth "
                             << root.getPrefixSize() << endl;
                        flage = false;
                    }
                }
            }
        }

        void remove(prefix_ &pref)
        {
            string path = pref.getBinaryPrefix();
            pointer = root;
            for (int i = 0; i < path.size(); i++)
            {
                if (path.at(i) == '0')
                {
                    pointer = pointer->left0;
                }
                else if (path.at(i) == '1')
                {
                    pointer = pointer->right1;
                }
            }
            

            if (pref == *pointer)
            {

                pointer->setType(0);
                pointer->setAction("");
                pointer->setBinaryPrefix("");
            }
            cout << "Removed " << pref.decimal_prefix << " at the depth " << pref.prefixSize << " nodes " << pref.getBinaryPrefix() << endl;
            pointer = nullptr;
        }
        void print()
        {
            pointer = root;
            print(*pointer);
        }
        void print(prefix_ &pref)
        {

            if (pref.left0 != nullptr)
            {
                print(*pref.left0);
            }
            if (pref.right1 != nullptr)
            {
                print(*pref.right1);
            }
            if (pref.getType() == 1)
                cout << pref.decimal_prefix << endl;
        }
    };
} // namespace prefix_table
