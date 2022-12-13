#include <stdio.h>
#include <iostream>
#include <thread>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#ifdef __cplusplus
# include <lua.hpp>
#else
# include <lua.h>
# include <lualib.h>
# include <lauxlib.h>
#endif

using namespace std;

//VARs
const double PYRSX = 212;
const double PYRSY = 234;
double PYRx = PYRSX;
double PYRy = PYRSY;
double PYRrot = 0.0;
double PYRveloc = 0.0;
double PYRdead = 0;
vector<double> PYRdata;

//may or may not use all of these functions, depends on how graphics are updated in game.cpp

//rotate
int PYR_rotate()
{
	return 1;
}
//shoot
int PYR_shoot()
{
	return 1;
}
//velocity
int PYR_velocity()
{
	return 1;
}
//kill
int PYR_kill()
{
	PYRdead = 1;
	return 1;
}
//data fetch
vector<double> PYR_fetch()
{
	PYRdata.clear();
	PYRdata.push_back(PYRx);
	PYRdata.push_back(PYRy);
	PYRdata.push_back(PYRrot);
	PYRdata.push_back(PYRveloc);
	PYRdata.push_back(PYRdead);
	PYRdata.push_back(PYRSX);
	PYRdata.push_back(PYRSY);
	return PYRdata;
}
//player
int Plyr(){
	//loops while player is alive
	while (PYRdead==0)
	{
		//throttle up
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			PYRveloc++;
			//cout<<"W"<<PYRveloc<<endl;
		}
		//throttle down
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			PYRveloc--;
			//cout<<"S"<<PYRveloc<<endl;
		}
		//rotate left?
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			PYRrot--;
			//cout<<"A"<<PYRrot<<endl;
		}
		//rotate right?
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			PYRrot++;
			//cout<<"D"<<PYRrot<<endl;
		}
		//shoot
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			PYR_shoot();
			//cout<<"p shot"<<endl;
		}
		//kill(testing purposes)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		{
			PYR_kill();
			cout<<"p is ded"<<endl;
		}
	}
	return 1;
}