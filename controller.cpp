
#include <iostream>
#include "block.cpp"
#include <vector>
#include <stdlib.h>
using namespace std;
class Controller
{
    private:
        vector<Block>* bc = new vector<Block>();
    public:
        Controller(string s, string k)
        {
            int a=s.size();
            int b=0;
            while(a>b)
            {
                (*bc).push_back(Block(s.substr(b,b+64)));
                b=b+64;
            }
            (*bc)[0].polarize(3);
            (*bc)[0].polarize(3);
        }
        void print()
        {
            for(int n=0;n<(*bc).size();n++)
            {
                (*bc)[n].print();
            }
            cout<<"\n";
        }
};
