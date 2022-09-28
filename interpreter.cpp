#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <cassert>
#include <vector>

using namespace std;

void interpreter(string x)
{

    vector< vector<string> > vec;
    vector<string> v1;
    vector<string> v2;

    string infile;
    string str;

    int lct, wct;

    cout<<"Loading file..."<<endl;
    infile = x;

    ifstream inStream;

    inStream.open(infile.data());
    assert(inStream.is_open());
    cout<<"File Loaded"<<endl;


    while (inStream>>str)
    {
        if (str=="#START"){
            v1.push_back(str);
            lct++;
        }
        else if(str=="#END"){
            vec.push_back(v1);
            v1.clear();
            v1.push_back(str);
            vec.push_back(v1);
            lct++;
        }
        else if(str.at(0)=='!'){
            vec.push_back(v1);
            v1.clear();
            v1.push_back(str);
            lct++;
            wct=0;
        }
        else
            v1.push_back(str);
    }
    
    cout<<"running"<<endl;

    int i=0;
    int j=0;
    string e;

    do { 
            e=vec[i][0];

            if(e=="!OUT"){
                cout<<vec[i][1]<<endl;
            }
            else if(e=="!ADD"){
                int a = stoi(vec[i][1]);
                int b = stoi(vec[i][2]);
                int c = a + b;
                cout<<c<<endl;
            }
        i++;
    } while (i<vec.size());
}