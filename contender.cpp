#include <iostream>
#include <string>
#include <contender.h>

using namespace std;

class Contender
{
    string data;
    
    public:
        int getState();       
};

int Contender::getState()
{
    cout<<"state got: "<<data<<endl;
    return 1;
}

class Manual: public Contender {
    public:
};

class Automaton: private Contender {

    int start(){

    }
    
};
