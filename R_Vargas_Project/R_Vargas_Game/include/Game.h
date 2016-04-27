#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

struct GameElem{
	std::string title;
	int year;
	GameElem *next;
    GameElem *previous;

    GameElem(){};
	GameElem(std::string in_title)
	{
		title = in_title;
		next = NULL;
		previous = NULL;
	}
};

struct City{
    std::string cityName;
    City *next;
    City *previous;

    City(){}; // default constructor

    City(std::string initName, City *initNext, City *initPrevious)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
    }

};

class Game
{
    public:
        Game();
        ~Game();
		void printInventory();
		void insertItem(std::string name);
		void deleteItem(std::string name);
		void findItem(std::string name);
        void addCity(std::string, std::string);
        void buildNetwork();
        void printNetwork();
        void deleteCity(std::string);
	private:
		int gameSum(std::string x, int s);
		int tableSize = 10;
		GameElem* game[10];
		City *head;
        City *tail;
};

#endif // GAME_H
