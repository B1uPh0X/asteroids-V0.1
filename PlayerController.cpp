#include <string>
#include <thread>
#include <vector>
#include "botOne.cpp"
#include "botTwo.cpp"
#include "botThr.cpp"
#include "botFou.cpp"
#include "botFiv.cpp"
#include "botSix.cpp"
#include "Bot.h"
#include "Player.h"

using namespace std;

int startPlayer(string e, int plyr){
    switch (plyr){
    case 1:
        botOne(e);
        break;
    case 2:
        botTwo(e);
        break;
    case 3:
        botThr(e);
        break;
    case 4:
        botFou(e);
        break;
    case 5:
        botFiv(e);
        break;
    case 6:
        botSix(e);
        break;
    default:
        break;
    }
    return 1;
}


/*
    Bot player2;
    thread duo(b_create, e[1], player2);
    Bot player3;
    thread tres(b_create, e[2], player3);
    Bot player4;
    thread quattuor(b_create, e[3], player4);
    Bot player5;
    thread quinque(b_create, e[4], player5);
    Bot player6;
    thread sex(b_create, e[5], player6);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    sex.join();
    return 0;
}
*/

/*
int Mone(string a){
    cout<<"Mone : MXXXXX"<<endl;
    Player player1;
    thread unus(p_create, a, player1);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    return 1;
}
int Mtwo(string a, string b){
    cout<<"Mtwo : MAXXXX"<<endl;
    Player player1;
    thread unus(p_create, a, player1);
    Bot player2;
    thread duo(b_create, b, player2);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    duo.join();
    return 1;
}
int Mthr(string a, string b, string c){
    cout<<"Mthr : MAAXXX"<<endl;
    Player player1;
    thread unus(p_create, a, player1);
    Bot player2;
    thread duo(b_create, b, player2);
    Bot player3;
    thread tres(b_create, c, player3);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    duo.join();
    tres.join();
    return 1;
}
int Mfou(string a, string b, string c, string d){
    cout<<"Mfou : MAAAXX"<<endl;
    Player player1;
    thread unus(p_create, a, player1);
    Bot player2;
    thread duo(b_create, b, player2);
    Bot player3;
    thread tres(b_create, c, player3);
    Bot player4;
    thread quattuor(b_create, d, player4);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    return 1;
}
int Mfiv(string a, string b, string c, string d, string e){
    cout<<"Mfiv : MAAAAX"<<endl;
    Player player1;
    thread unus(p_create, a, player1);
    Bot player2;
    thread duo(b_create, b, player2);
    Bot player3;
    thread tres(b_create, c, player3);
    Bot player4;
    thread quattuor(b_create, d, player4);
    Bot player5;
    thread quinque(b_create, e, player5);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    return 1;
}
int Msix(string a, string b, string c, string d, string e, string f){
    cout<<"Msix : MAAAAA"<<endl;
    Bot player1;
    thread unus(b_create, a, player1);
    Bot player2;
    thread duo(b_create, b, player2);
    Bot player3;
    thread tres(b_create, c, player3);
    Bot player4;
    thread quattuor(b_create, d, player4);
    Bot player5;
    thread quinque(b_create, e, player5);
    Bot player6;
    thread sex(b_create, f, player6);

    bool win_con = false;
    do
    {
        


    } while (win_con==false);

    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    sex.join();
    return 1;
}
*/
//Aone start
int Aone(string a){
    //which game state
    cout<<"Aone : AXXXXX"<<endl;
    //player threads
    thread unus(startPlayer, a, 1);
    //player vector
    vector<vector<double> > pdata;

    //player state game loop
    bool win_con = false;
    do
    {   
        //fetch player data
        pdata.clear();
        pdata.push_back(C_ONE_fetch());
        //read the fetched data
        for(int i=0; i<pdata.size(); i++){
            for(int j=0; j<pdata[i].size(); j++){
            cout<<i<<" : "<<j<<" "<<pdata[i][j]<<endl;
            }
        }
        //check win condition(all players are dead)
        for(int i=0; i<pdata.size(); i++){
            //quick escape, no point in checking the rest of the players if at least one is alive
            if(pdata[i][4]!=0)
                break;
            if(i==pdata.size()-1)
                win_con=true;
        }
    //end loop
    } while (win_con==false);

    //merge threads
    unus.join();
    return 1;
    //Aone end
}
//Atwo start
int Atwo(string a, string b){
    //which game state
    cout<<"Atwo : AAXXXX"<<endl;
    //player threads
    thread unus(startPlayer, a, 1);
    thread duo(startPlayer, b, 2);
    //player vector
    vector<vector<double> > pdata;

    //player state game loop
    bool win_con = false;
    do
    {   
        //fetch player data
        pdata.clear();
        pdata.push_back(C_ONE_fetch());
        pdata.push_back(C_TWO_fetch());
        //read the fetched data
        for(int i=0; i<pdata.size(); i++){
            for(int j=0; j<pdata[i].size(); j++){
            cout<<i<<" : "<<j<<" "<<pdata[i][j]<<endl;
            }
        }
        //check win condition(all players are dead)
        for(int i=0; i<pdata.size(); i++){
            //quick escape, no point in checking the rest of the players if at least one is alive
            if(pdata[i][4]!=0)
                break;
            if(i==pdata.size()-1)
                win_con=true;
        }
    //end loop
    } while (win_con==false);

    //merge threads
    unus.join();
    duo.join();
    return 1;
    //Atwo end
}
//Athr start
int Athr(string a, string b, string c){
    //which game state
    cout<<"Athr : AAAXXX"<<endl;
    //player threads
    thread unus(startPlayer, a, 1);
    thread duo(startPlayer, b, 2);
    thread tres(startPlayer, c, 3);
    //player vector
    vector<vector<double> > pdata;

    //player state game loop
    bool win_con = false;
    do
    {   
        //fetch player data
        pdata.clear();
        pdata.push_back(C_ONE_fetch());
        pdata.push_back(C_TWO_fetch());
        pdata.push_back(C_THR_fetch());
        //read the fetched data
        for(int i=0; i<pdata.size(); i++){
            for(int j=0; j<pdata[i].size(); j++){
            cout<<i<<" : "<<j<<" "<<pdata[i][j]<<endl;
            }
        }
        //check win condition(all players are dead)
        for(int i=0; i<pdata.size(); i++){
            //quick escape, no point in checking the rest of the players if at least one is alive
            if(pdata[i][4]!=0)
                break;
            if(i==pdata.size()-1)
                win_con=true;
        }
    //end loop
    } while (win_con==false);

    //merge threads
    unus.join();
    duo.join();
    tres.join();
    return 1;
    //afou end
}
//Afour start
int Afou(string a, string b, string c, string d){
    //which game state
    cout<<"Afou : AAAAXX"<<endl;
    //player threads
    thread unus(startPlayer, a, 1);
    thread duo(startPlayer, b, 2);
    thread tres(startPlayer, c, 3);
    thread quattuor(startPlayer, d, 4);
    //player vector
    vector<vector<double> > pdata;

    //player state game loop
    bool win_con = false;
    do
    {   
        //fetch player data
        pdata.clear();
        pdata.push_back(C_ONE_fetch());
        pdata.push_back(C_TWO_fetch());
        pdata.push_back(C_THR_fetch());
        pdata.push_back(C_FOU_fetch());
        //read the fetched data
        for(int i=0; i<pdata.size(); i++){
            for(int j=0; j<pdata[i].size(); j++){
            cout<<i<<" : "<<j<<" "<<pdata[i][j]<<endl;
            }
        }
        //check win condition(all players are dead)
        for(int i=0; i<pdata.size(); i++){
            //quick escape, no point in checking the rest of the players if at least one is alive
            if(pdata[i][4]!=0)
                break;
            if(i==pdata.size()-1)
                win_con=true;
        }
    //end loop
    } while (win_con==false);

    //merge threads
    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    return 1;
    //Afou end
}
//Afiv start
int Afiv(string a, string b, string c, string d, string e){
    //which game state
    cout<<"Afiv : AAAAAX"<<endl;
    //player threads
    thread unus(startPlayer, a, 1);
    thread duo(startPlayer, b, 2);
    thread tres(startPlayer, c, 3);
    thread quattuor(startPlayer, d, 4);
    thread quinque(startPlayer, e, 5);
    //player vector
    vector<vector<double> > pdata;

    //player state game loop
    bool win_con = false;
    do
    {   
        //fetch player data
        pdata.clear();
        pdata.push_back(C_ONE_fetch());
        pdata.push_back(C_TWO_fetch());
        pdata.push_back(C_THR_fetch());
        pdata.push_back(C_FOU_fetch());
        pdata.push_back(C_FIV_fetch());
        //read the fetched data
        for(int i=0; i<pdata.size(); i++){
            for(int j=0; j<pdata[i].size(); j++){
            cout<<i<<" : "<<j<<" "<<pdata[i][j]<<endl;
            }
        }
        //check win condition(all players are dead)
        for(int i=0; i<pdata.size(); i++){
            //quick escape, no point in checking the rest of the players if at least one is alive
            if(pdata[i][4]!=0)
                break;
            if(i==pdata.size()-1)
                win_con=true;
        }
    //end loop
    } while (win_con==false);

    //merge threads
    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    return 1;
    //Afiv end
}
//six bots
int Asix(string a, string b, string c, string d, string e, string f){
    //which game state
    cout<<"Asix : AAAAAA"<<endl;
    //player threads
    thread unus(startPlayer, a, 1);
    thread duo(startPlayer, b, 2);
    thread tres(startPlayer, c, 3);
    thread quattuor(startPlayer, d, 4);
    thread quinque(startPlayer, e, 5);
    thread sex(startPlayer, f, 6);
    //player vector
    vector<vector<double> > pdata;

    //player state game loop
    bool win_con = false;
    do
    {   
        //fetch player data
        pdata.clear();
        pdata.push_back(C_ONE_fetch());
        pdata.push_back(C_TWO_fetch());
        pdata.push_back(C_THR_fetch());
        pdata.push_back(C_FOU_fetch());
        pdata.push_back(C_FIV_fetch());
        pdata.push_back(C_SIX_fetch());
        //read the fetched data
        for(int i=0; i<pdata.size(); i++){
            for(int j=0; j<pdata[i].size(); j++){
            cout<<i<<" : "<<j<<" "<<pdata[i][j]<<endl;
            }
        }
        //check win condition(all players are dead)
        for(int i=0; i<pdata.size(); i++){
            //quick escape, no point in checking the rest of the players if at least one is alive
            if(pdata[i][4]!=0)
                break;
            if(i==pdata.size()-1)
                win_con=true;
        }
    //end loop
    } while (win_con==false);

    //merge threads
    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    sex.join();
    return 1;
    //asix end
}

int PlayerController(string e[5]){

    const string X = "X";
    const string M = "M";
    int i=0;
    bool end=false;

    do{
        if((e[i]==X)||(i==6))
            end=true;
        else
           i++;
    }while(end==false);

    if(e[0]==M){
        switch (i)
        {
        case 1 :
            //Mone(e[0]);
            break;
        case 2 :
            //Mtwo(e[0],e[1]);
            break;
        case 3 :
            //Mthr(e[0],e[1],e[2]);
            break;
        case 4 :
            //Mfou(e[0],e[1],e[2],e[3]);
            break;
        case 5 :
            //Mfiv(e[0],e[1],e[2],e[3],e[4]);
            break;  
        default:
            //Msix(e[0],e[1],e[2],e[3],e[4],e[5]);
            break;
        }
    }
    else{
        switch (i)
        {
        case 1 :
            Aone(e[0]);
            break;
        case 2 :
            Atwo(e[0],e[1]);
            break;
        case 3 :
            Athr(e[0],e[1],e[2]);
            break;
        case 4 :
            Afou(e[0],e[1],e[2],e[3]);
            break;
        case 5 :
            Afiv(e[0],e[1],e[2],e[3],e[4]);
            break;  
        default:
            Asix(e[0],e[1],e[2],e[3],e[4],e[5]);
            break;
        }
    }


    /*
    
    thread unus(execute, player1);
    thread duo(execute, player2);
    thread tres(execute, player3);
    thread quattuor(execute, player4);
    thread quinque(execute, player5);
    thread sex(execute, player6);


    unus.join();
    duo.join();
    tres.join();
    quattuor.join();
    quinque.join();
    sex.join();
    */
    return 0;
}