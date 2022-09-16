#ifndef CARD_H
#define CARD

#include <iostream>
#include <stack>

#define MAX_POINTS 21

using namespace std;

typedef struct Card
{
    int suit;
    int value;
};

typedef struct Deck
{
    int suits[4] = {0, 1, 2, 3};
    int values[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    stack<Card> *stack;
};

typedef struct Player
{
    stack<Card *> handStack;
    int points = 0;
    bool canHit = true;
};

bool playerOneTurn = true;
Player winner;

int menu();
void play();
Deck *createDeck();
bool isGameOver(Player, Player);
bool isPlayerOneTurn();
Card *hit(Deck *);
bool pointsIsMoreThanMax(Player);
void changeTurn();
void gameOver(Player, Player);

#endif