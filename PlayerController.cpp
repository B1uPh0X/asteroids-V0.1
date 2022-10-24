#include <string>
#include <thread>
#include "Player.h"
#include "Bot.h"

using namespace std;


void p_create(){
    Player player1;
    player1.create();
}

void b_create(string file){

}


int PlayerController(string e[5]){

    if(e[0]=="MANUAL")
        thread unus(p_create);
    else
        thread unus(b_create, e[0], 1);
    
    thread duo(b_create, e[1], 2);
    thread tres(b_create, e[2], 3);
    thread quattuor(b_create, e[3], 4);
    thread quinque(b_create, e[4], 5);
    thread sex(b_create, e[5], 6);

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


