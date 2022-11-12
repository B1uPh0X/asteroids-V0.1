#ifndef ASTEROIDS_GAME_BOT_H
#define ASTEROIDS_GAME_BOT_H
#include <SFML/Graphics.hpp>

class Contender {
public:
        Contender (string a) : data(a) {}
        void set (string a)
            {
                data=a;
                cout<<data<<endl;
            }
        void init (auto x)
            {cout<<"init: "<<x<<endl;}
        void setVelocity(auto x)
            {cout<<"veloc: "<<x<<endl;}
        void setThrottle(auto x)
            {cout<<"throt: "<<x<<endl;}
        void rotate(auto x)
            {cout<<"rot: "<<x<<endl;}
        void shoot(auto x)
            {cout<<"shot: "<<x<<endl;}
        void kill(auto x)
            {cout<<"ded: "<<x<<endl;}
        void isAlive(auto x)
            {cout<<"liv: "<<x<<endl;}
        void run(auto x)
            {cout<<"walk: "<<x<<endl;}
};

#endif //ASTEROIDS_GAME_BOT_H