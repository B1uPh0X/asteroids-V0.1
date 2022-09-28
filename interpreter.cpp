#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <cassert>
#include <vector>

using namespace std;

//main interperter function, reads file, stores contents of file in a 2d vector, runs specified commands
void interpreter(string x)
{
    //var declerations

    //vectors
    vector< vector<string> > vec;
    vector<string> v1, v2;

    //strings
    string infile, str, e;

    //ints
    int lct, wct;
    int i, j = 0;

    //loads up the file into the filestream
    cout<<"Loading file..."<<endl;
    infile = x;

    ifstream inStream;

    inStream.open(infile.data());
    assert(inStream.is_open());
    cout<<"File Loaded"<<endl;

    //reads file contents
    while (inStream>>str)
    {   
        //initial vector push for sof
        if (str=="#START"){
            v1.push_back(str);
            lct++;
        }
        //final vector push for eof
        else if(str=="#END"){
            vec.push_back(v1);
            v1.clear();
            v1.push_back(str);
            vec.push_back(v1);
            lct++;
        }
        //vector push for the start of a new command
        else if(str.at(0)=='!'){
            vec.push_back(v1);
            v1.clear();
            v1.push_back(str);
            lct++;
            wct=0;
        }
        //vector push for anything else, parameters for commands
        else
            v1.push_back(str);
    }
    
    //begins exection of the commands
    cout<<"running"<<endl;

    do { 
            //pulls the command for the current line
            e=vec[i][0];

            //check what command is and do something

            //if e is OUT command
            if(e=="!OUT"){
                //prints command param
                cout<<vec[i][1]<<endl;
            }
            //if e is ADD command
            else if(e=="!ADD"){
                //adds two params and prints result
                int a = stoi(vec[i][1]);
                int b = stoi(vec[i][2]);
                int c = a + b;
                cout<<c<<endl;
            }
        //iterate to the next line
        i++;
        //finish loop when i is greater than size of outer vector
    } while (i<vec.size());
}