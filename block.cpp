#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;
class Block
{
private:
    vector<bitset<8> > container;
    void charToBitSet(bitset<8>* p,char c)
    {
        (*p)=c;
    }
    char bitSetToChar(bitset<8>* p)
    {
        char c =(char)(*p).to_ulong();
        return c;
    }
public:
    Block(string s)
    {

        for(int n=0; n<64; n++)
        {
            if(n<s.size())
            {
                container.push_back(s[n]);
            }
            else
            {
                container.push_back(' ');
            }
        }
    }

    bitset<8>* getPointer(int x, int y)
    {
        return &container[x+8*y];
    }
    void invert(int x)
    {
        for(int z=0; z<8; z++)
        {
            for(int y=z+1; y<8; y++)
            {
                int a=(*getPointer(z,y))[x];
                (*getPointer(z,y))[x]=(*getPointer(y,z))[x];
                (*getPointer(y,z))[x]=a;
            }
        }
    }
    void flipBit(int x,int y,int z)
    {
        (*getPointer(x,y)) ^= 1UL << z;
    }
    void polarize(int a)
    {
        for(int x=0;x<8;x++)
        {
            for(int y=0;y<8;y++)
            {
                for(int z=0;z<8;z++)
                {
                    if((x+y+z)%2==a%2)
                    {
                        flipBit(x,y,z);
                    }
                }
            }
        }
    }
    void print()
    {
        string s="";
        for(int n=0; n<64; n++)
        {
            s.push_back(bitSetToChar(&container[n]));
        }
        cout<<s;
    }
};
