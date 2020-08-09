
#include <iostream>
#include "fstream"
#include "vector"
#include "string"
using namespace std;

namespace bd{

struct packet
{
    int packet_slack;
    int packet_value;
    packet(int ps, int pv) :packet_slack(ps), packet_value(pv) {};

};

int convertToInt(string s)
{
    int myint1 = stoi(s);
    int x = myint1;
    return x;
}

void decreas(vector<packet> &v){
   for (int i=0;i<v.size();i++)
        {
            v[i].packet_slack-=1;
            if (v[i].packet_slack==0)
            {
               // cout<<"remove "<<"("<<v[i].packet_slack<<","<<v[i].packet_value<<")"<<endl;
                v.erase(v.begin()+i, v.begin()+i+1);
            }

        }
}



int  arrival_phase(string &myText, vector<packet> &v, int queue_size, int &arrive) {
    int drop=0;
    while (myText.size()!=0)
    {

        int amount, p_s, p_v;

        int k=myText.find(',');
        amount=convertToInt(myText.substr(1, k-1));
        myText=myText.substr(k+1);
        arrive+=amount;

        k=myText.find(',');
        p_s=convertToInt(myText.substr(0, k));
        myText=myText.substr(k+1);

        k=myText.find(')');
        p_v=convertToInt(myText.substr(0, k));
        myText=myText.substr(k+1);

        packet *pack=new packet(p_s, p_v);
        for (int i=0;i<amount;i++)
        {
          // cout<<v.size()<<endl;
            if (v.size()<queue_size)
            {
                v.insert(v.begin()+i, *pack);
                 
               // cout<<"("<<v[i].packet_slack<<","<<v[i].packet_value<<")"<<endl;
            }
            else {
                drop++;
                int min_pv=v[0].packet_value;
                int index=0;
                for (int j=1;j<queue_size;j++)
                {
                    if (v[j].packet_value<min_pv)
                    {
                        min_pv= v[j].packet_value;
                        index=j;

                    }
                }
                if (pack->packet_value>min_pv)
                {
                     
                     // cout<<"drop the packe("<<v[index].packet_slack<<","<<v[index].packet_value<<")"<<endl;
                    v[index]=*pack;
                    //   cout<<"add the packe("<<v[index].packet_slack<<","<<v[index].packet_value<<")"<<endl;
                }
            }
        }
    }
    return drop;
}

int processing_phase(vector<packet> &v)
{
    int transimt_value=0;
     int max_value=v[0].packet_value;
        int index=0;
        for (int i=1;i<v.size();i++)
        {
            if (v[i].packet_value>max_value)
            {
                max_value=v[i].packet_value;
                index=i;
            }

        }
        transimt_value+=v[index].packet_value;
        //transimt_packet+=1;

                //cout<<"prcecesing "<<v[index].packet_slack<<","<<v[index].packet_value<<endl;
        v.erase(v.begin()+index, v.begin()+index+1);

        return transimt_value;
}

void Bounded_Delay(int queue_size,string file) {

    int drop=0;
    int arrive=0;
    int transimt_packet=0;
    int transimt_value=0;
    string myText;

    vector<packet> v;

    // Read from the text file 
    ifstream MyReadFile(file);
    while (getline(MyReadFile, myText))
    {

        ///////////////new time slot////////////////////////////////////////////////////////
       drop+=arrival_phase(myText,v,queue_size,arrive);
        /////////////end time slot///////////////////////////////////////////////////////////  
        //decreas alll slack
       decreas(v);
        //מעבד את הסלק הקטן
   
        transimt_value+=processing_phase(v);
        transimt_packet+=1;

    }

while(v.size()>1){
    decreas(v);  
    
        transimt_value+=processing_phase(v);
        transimt_packet+=1;

    //////
}

    
    cout<<"Total arrived packets "<<arrive<<", total dropped packets "<<drop<<", total transmitted packets "<<transimt_packet<<" total transmitted value "<<transimt_value<<endl;
}





};

