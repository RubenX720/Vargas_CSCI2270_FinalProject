#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <queue>
#include <limits.h>
#include <algorithm>
#include "Game.h"

using namespace std;

Game::Game(){
    head = NULL;
    tail = NULL;
    for(int i = 0; i < 10; i++){
            game[i] = NULL;
   }
}

void Game::insertItem(std::string name){
    GameElem* newItem = new GameElem(name);
    int position = gameSum(name, 10);
    if(game[position] == NULL){
            game[position] = newItem;
    newItem->next = NULL;
    }
    else{
            GameElem* currentNode = game[position];
    while(currentNode->next != NULL){
            currentNode = currentNode->next;
    }
    currentNode->next = newItem;
    newItem->next = NULL;
    }
}

void Game::deleteItem(std::string name){
    int position = gameSum(name, 10);
    if(game[position] != NULL){
        GameElem* currentNode = game[position];
    if(currentNode->title == name){
            game[position] = currentNode->next;
    delete currentNode;
    }
    else{
            bool gameFound = false;
    while(currentNode->next != NULL){
            if(currentNode->next->title == name){
                gameFound = true;
    break;
            }
            currentNode = currentNode->next;
    }
    if(gameFound){
            GameElem* nextNode = currentNode->next->next;
    delete currentNode->next;
    currentNode->next = nextNode;
    }
    }
    }
}

void Game::findItem(std::string name){
    int position = gameSum(name, 10);
    if(game[position] != NULL){
            GameElem* currentNode = game[position];
    if(currentNode->title == name){
            cout<<position<<":"<<currentNode->title<<endl;
    return;
    }
    else{
            bool gameFound = false;
    while(currentNode->next != NULL){
            if(currentNode->next->title == name){
                gameFound = true;
    break;
    }
    currentNode = currentNode->next;
    }
    if(gameFound){
            cout<<position<<":"<<currentNode->next->title<<endl;
    return;
    }
    }
    }
    cout<<"not found"<<endl;
    return;
}

void Game::printInventory(){
    bool tableEmpty = true;
    for(int i = 0; i < 10; i++){
            if(game[i] != NULL){
                GameElem* currentNode = game[i];
    while(currentNode->next != NULL){
            cout<<currentNode->title<<endl;
    currentNode = currentNode->next;
    }
    cout<<currentNode->title<<endl;
    tableEmpty = false;
            }
    }
    if(tableEmpty)
        cout<< "Nothing" <<endl;
}

int Game::gameSum(std::string title, int arraySize){
    int sum = 0;
    for(int i = 1; i < title.length(); i++){
            sum = sum + title.c_str()[i];
    sum = sum % arraySize;
    }
    return sum;
}

void Game::addCity(string previousCity, string cityName){
    if(previousCity == "First")
    {
        City *c = new City(cityName, head, NULL);
        head = c;
    }else{
        City * tmp = head;
        while(tmp->cityName != previousCity && tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        City * newCity = new City(cityName, tmp->next, tmp);
        tmp->next = newCity;
    }
}
void Game::buildNetwork(){
    string cityArray[6] = {"Hyrule", "Coruscant", "Paraiso Verde", "Alberia", "El Infierno", "Secret Location"};
    int numCities = 6;
    City *cityAdded;
    City *currentCity;
    for(int i = 0; i < numCities; i++){
        if(head == NULL){
            cityAdded = new City(cityArray[i], NULL, NULL);
            currentCity = cityAdded;
            head = currentCity;
        }else{
            cityAdded = new City(cityArray[i], NULL, currentCity);
            currentCity->next = cityAdded;
            currentCity = cityAdded;
        }
    }
    tail = currentCity;
}

void Game::printNetwork(){
    cout << "=====Pending Destinations=====" << endl;
    if (head == NULL)
        cout << "NULL" << endl;
    else
    {
        City *current = head;
        cout<<" Begin <- ";
        while (current->next != NULL)
        {
            cout << current->cityName << " <-> ";
            current = current->next;
        }
        cout << current->cityName << " -> ";
        cout << "End" << endl;
    }
    cout << "==============================" << endl;
}

void Game::deleteCity(string cityNameIn){
    City *delCity = NULL;
    City *searchCity = head;
    bool found = false;
    while(!found and searchCity != NULL){
        if(searchCity->cityName == cityNameIn){
            found = true;
        }else{
            searchCity = searchCity->next;
        }
    }
    if(found == true){
        if(searchCity == head){
            delCity = head;
            head = head->next;
            head->previous = NULL;
            delete delCity;
        }else{
            searchCity->previous->next = searchCity->next;
            searchCity->next->previous = searchCity->previous;
            delete searchCity;
        }
    }else{
        cout<<cityNameIn<<"not found"<<endl;
    }
}

Game::~Game(){
    for(int i = 0; i < 10; i++){
           delete game[i];
}
}
