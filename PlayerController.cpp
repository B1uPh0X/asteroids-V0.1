#include <string>
#include <thread>
#include <vector>
#include "Plyr.cpp"
#include "botOne.cpp"
#include "botTwo.cpp"
#include "botThr.cpp"
#include "botFou.cpp"
#include "botFiv.cpp"
#include "botSix.cpp"
#include "Player.h"

using namespace std;

//player vector
vector<vector<double> > pdata;


int startPlayer(string e, int plyr){
	switch (plyr){
	//manual player
	case 0:
		Plyr();
		break;
	//bot one
	case 1:
		botOne(e);
		break;
	//bot two
	case 2:
		botTwo(e);
		break;
	//bot three
	case 3:
		botThr(e);
		break;
	//bot four
	case 4:
		botFou(e);
		break;
	//bot five
	case 5:
		botFiv(e);
		break;
	//bot six
	case 6:
		botSix(e);
		break;
	//default
	default:
		break;
	}
	return 1;
}

//MANUAL game states
//Mone start
int Mone(string a){
    //which game state
	cout<<"Mone : MXXXXX"<<endl;
    //player threads
    thread unus(startPlayer, a, 0);


    //player state game loop
    bool win_con = false;
    do
    {   
        //fetch player data
        pdata.clear();
        pdata.push_back(PYR_fetch());
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

//Mtwo start
int Mtwo(string a, string b){
	cout<<"Mtwo : MAXXXX"<<endl;
	//player threads
	thread unus(startPlayer, a, 0);
	thread duo(startPlayer, b, 2);
	
	

	//player state game loop
	bool win_con = false;
	do
	{   
		//fetch player data
		pdata.clear();
		pdata.push_back(PYR_fetch());
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
	//Mtwo end
}
//Mthr
int Mthr(string a, string b, string c){
	//which game state
	cout<<"Mthr : MAAXXX"<<endl;
	//player threads
	thread unus(startPlayer, a, 0);
	thread duo(startPlayer, b, 2);
	thread tres(startPlayer, c, 3);
	
	

	//player state game loop
	bool win_con = false;
	do
	{   
		//fetch player data
		pdata.clear();
		pdata.push_back(PYR_fetch());
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
	//Mthr end
}
//Mfou start
int Mfou(string a, string b, string c, string d){
	//which game state
	cout<<"Msix : MAAAXX"<<endl;
	//player threads
	thread unus(startPlayer, a, 0);
	thread duo(startPlayer, b, 2);
	thread tres(startPlayer, c, 3);
	thread quattuor(startPlayer, d, 4);
	
	

	//player state game loop
	bool win_con = false;
	do
	{   
		//fetch player data
		pdata.clear();
		pdata.push_back(PYR_fetch());
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
	//Mfou end
}
//Mfiv start
int Mfiv(string a, string b, string c, string d, string e){
	//which game state
	cout<<"Mfiv : MAAAAX"<<endl;
	//player threads
	thread unus(startPlayer, a, 0);
	thread duo(startPlayer, b, 2);
	thread tres(startPlayer, c, 3);
	thread quattuor(startPlayer, d, 4);
	thread quinque(startPlayer, e, 5);
	
	

	//player state game loop
	bool win_con = false;
	do
	{   
		//fetch player data
		pdata.clear();
		pdata.push_back(PYR_fetch());
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
	//Mfiv end
}
//Msix start
int Msix(string a, string b, string c, string d, string e, string f){
	//which game state
	cout<<"Msix : MAAAAA"<<endl;
	//player threads
	thread unus(startPlayer, a, 0);
	thread duo(startPlayer, b, 2);
	thread tres(startPlayer, c, 3);
	thread quattuor(startPlayer, d, 4);
	thread quinque(startPlayer, e, 5);
	thread sex(startPlayer, f, 6);
	
	

	//player state game loop
	bool win_con = false;
	do
	{   
		//fetch player data
		pdata.clear();
		pdata.push_back(PYR_fetch());
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
	//Msix end
}
//AUTO game states
//Aone start
int Aone(string a){
	//which game state
	cout<<"Aone : AXXXXX"<<endl;
	//player threads
	thread unus(startPlayer, a, 1);
	
	

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
//playercontroller start
int PlayerController(string e[5]){
	//constant values for manual and empty player slots
	//No player selected
	const string X = "X";
	//manual player selected(can only be in player 1 slot)
	const string M = "M";
	//vars used for player calculation(see below)
	int i=0;
	bool end=false;
	//figure out number of player slots filled
	//higher player slots cant be used unless all of the lower slots are populated
	//i.e. For player 4 to be populated, player slots 1,2 & 3 need to be filled.
	//If player slot 5 is empty, then player slot 6 is also empty
	do{
		if((e[i]==X)||(i==6))
			end=true;
		else
		   i++;
	}while(end==false);
	//if player 1 is set to the manual tag, then select the appropriate manual game state
	if(e[0]==M){
		//switch case to select game state the game game corresponding to the number of players selected
		switch (i)
		{
		//one player (MXXXXX)
		case 1 :
			Mone(e[0]);
			break;
		//two players (MAXXXX)
		case 2 :
			Mtwo(e[0],e[1]);
			break;
		//three players (MAAXXX)
		case 3 :
			Mthr(e[0],e[1],e[2]);
			break;
		//four players (MAAAXX)
		case 4 :
			Mfou(e[0],e[1],e[2],e[3]);
			break;
		//five players (MAAAAX)
		case 5 :
			Mfiv(e[0],e[1],e[2],e[3],e[4]);
			break; 
		//Six players (MAAAAA)
		default:
			Msix(e[0],e[1],e[2],e[3],e[4],e[5]);
			break;
		}
	}
	//else player 1 is a bot(player 1 can never be empty)
	else{
		switch (i)
		{
		//one player (AXXXXX)
		case 1 :
			Aone(e[0]);
			break;
		//two players (AAXXXX)
		case 2 :
			Atwo(e[0],e[1]);
			break;
		//three players (AAAXXX)
		case 3 :
			Athr(e[0],e[1],e[2]);
			break;
		//four players (AAAAXX)
		case 4 :
			Afou(e[0],e[1],e[2],e[3]);
			break;
		//five players (AAAAAX)
		case 5 :
			Afiv(e[0],e[1],e[2],e[3],e[4]);
			break;
		//six players (AAAAAA) 
		default:
			Asix(e[0],e[1],e[2],e[3],e[4],e[5]);
			break;
		}
	}
	return 0;
	//end of playercontroller
}