#include <string>
#include <vector>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PlayerController.cpp"
#include "Entity.cpp"
//#include "Player.h"
#include "Player.cpp"
//#include "Asteroid.h"
#include "Asteroid.cpp"
//#include "Entity.h"
#include "Bullet.cpp"

using namespace std;

vector<double> r;
bool over = false;


void gib(vector<double> e){
	r.clear();
	r = e;
}
vector<double> get(){
	return r;
}

void gameover(){
	over = true;
}

int execute(vector<string> q){
	PlayerController(q);
	return 0;
}

int NEWgame(vector<string> selectedPlayers){

	int num = selectedPlayers.size();
	vector<vector<double>> plydata;
	vector<Player> players;
	
	thread p (execute, selectedPlayers);

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

	vector<Bullet> Barrys;

	//window rendering
	sf::RenderWindow window(sf::VideoMode(1024, 768), "AT-Asteroids");
	sf::Texture t;
	t.loadFromFile("./images/space_background.jpg");
	sf::Sprite s(t);
	sf::Event event;
	window.display();
	//any key wait
	/*do{
		if(sf::Event::KeyPressed())
			wait=true;
	}while(wait==false)*/

	plydata.clear();
	plydata = plydatafetch();
	for(int i=0; i<num; i++){
		players[i].x=(int)plydata[i][0];
		players[i].y=(int)plydata[i][1];
		players[i].spawn();
		players[i].create();
		players[i].draw(window);
	}
	
	//while(window.isOpen()){
			cout<<plydata[0][0]<<"X in game Y"<<plydata[0][1]<<endl;
			cout<<player1.x<<" "<<player1.y<<endl;

			window.clear();
			window.draw(s);
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
			{
			window.close();
			}
		}
		
		for (int i=0; i<roids.size();i++){
			if(roids[i].isalive()==false)
				roids[i].spawn();
			roids[i].move();
			roids[i].draw(window);
		}

		plydata.clear();
		plydata = plydatafetch();

		for(int i=0; i<num; i++){
			players[i].alive=(bool)plydata[i][4];
			if(players[i].isalive()==true){
				players[i].rot=plydata[i][2];
				players[i].vel=plydata[i][3];
				players[i].boundaries(window);
				players[i].move();
				players[i].draw(window);
			}
			else{
			}
						cout<<plydata[0][0]<<"X in ewqgame Y"<<plydata[0][1]<<endl;
			cout<<player1.x<<" ewq "<<player1.y<<endl;

		}

		/*for(int i=0; i<Barrys.size(); i++){
			//if(Barrys[i].isAlive()==true){
			//	Barrys[i].move();
			//	i++;
			//}
			//else{
			//	Barrys[i].erase;
			//	i--;
			//}
		}*/
		
			window.display();
	//}
p.join();
return 0;
}