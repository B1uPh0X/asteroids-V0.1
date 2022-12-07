#include <string>
#include <vector>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PlayerController.cpp"
#include "Player.h"
#include "Player.cpp"
#include "Asteroid.h"
#include "init.h"

using namespace std;
vector<double> r;
void gib(vector<double> e){
	r.clear();
	r = e;
}
vector<double> get(){
	return r;
}

int NEWgame(vector<string> selectedPlayers){

	int num = selectedPlayers.size();
	vector<double> plydata;
	vector<Player> players;

	Player player1;
	Player player2;
	Player player3;
	Player player4;
	Player player5;
	Player player6;

	players.push_back(player1);
	players.push_back(player2);
	players.push_back(player3);
	players.push_back(player4);
	players.push_back(player5);
	players.push_back(player6);

	vector<Asteroid> roids;

	Asteroid asteroid1;
	Asteroid asteroid2;
	Asteroid asteroid3;
	Asteroid asteroid4;
	Asteroid asteroid5;
	Asteroid asteroid6;

	roids.push_back(asteroid1);
	roids.push_back(asteroid2);
	roids.push_back(asteroid3);
	roids.push_back(asteroid4);
	roids.push_back(asteroid5);
	roids.push_back(asteroid6);

	//vector<double> Barrys;



	bool wait=false;

	//window rendering
	sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Asteroids");
	sf::Texture t;
	t.loadFromFile("./images/space_background.jpg");
	sf::Sprite s(t);
	sf::Event event;
	//any key wait
	/*do{
		if(sf::Event::KeyPressed())
			wait=true;
	}while(wait==false)*/

	for(int i=0; i<num; i++){
		//players[i].spawn();
	}
	while(window.isOpen()){

		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		for (int i=0; i<roids.size();i++){
			//if(roids[i].alive()=false)
			//	roids[i].makeAlive();
			//roids[i].move();
		}

		plydata.clear();
		plydata = get();

		for(int i=0; i<num; i++){
			players[i].alive=plydata[4];
			//if(players[i].alive()){
			//	players[i].rot=plydata[2];
			//	players[i].vel=plydata[3];
			//	players[i].move();
			//}
			//else{}//kill?

		}

		/*for(int i=0; i<Barrys.size(); i++){
			if(Barrys[i].isAlive()==true){
				Barrys[i].move();
				i++;
			}
			else{
				Barrys[i].erase;
				i--;
			}
		}*/

	}
return 0;
}