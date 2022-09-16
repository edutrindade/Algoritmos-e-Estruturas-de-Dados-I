#include "functions.hpp"

int menu()
{
    int option;
    do
    {
        system("cls");
        cout << "Bem vindo ao 21\n";
        cout << "1 - Jogar\n";
        cout << "2 - Sair\n";
        cin >> option;
    } while (option < 1 || option > 2);
    return option;
}

void play()
{
    Deck *deck = createDeck();
    Player player1, player2;

    while (!isGameOver(player1, player2))
    {
        Player *actualPlayer;
        actualPlayer = (isPlayerOneTurn() ? &player1 : &player2);

        bool canHit = actualPlayer->canHit;

        if (canHit)
        {
            int option;
            do
            {
                system("cls");
                cout << "Pontos atuais: " << actualPlayer->points << "\n";
                cout << "1 - Hit\n";
                cout << "2 - Stand\n";
                cin >> option;
            } while (option < 1 || option > 2);

            switch (option)
            {
            case 1:
            {
                Card *card = hit(deck);
                if (card != NULL)
                {
                    actualPlayer->handStack.push(card);
                    actualPlayer->points += card->value;
                }
                break;
            }
            case 2:
            {
                actualPlayer->canHit = false;
                changeTurn();
                break;
            }
            }
        }
    }
    gameOver(player1, player2);
}

Deck *createDeck()
{
    Deck *deck = new Deck;
    deck->stack = new stack<Card>;

    for (auto suit : deck->suits)
    {
        for (auto value : deck->values)
        {
            Card card;
            card.suit = suit;
            card.value = value;
            deck->stack->push(card);
        }
    }

    return deck;
}

bool isGameOver(Player player1, Player player2)
{
    return pointsIsMoreThanMax(player1) || pointsIsMoreThanMax(player2) || (!player1.canHit && !player2.canHit);
}

bool isPlayerOneTurn()
{
    return playerOneTurn;
}

Card *hit(Deck *deck)
{
    int suitsSize = sizeof(deck->suits) / sizeof(deck->suits[0]);
    int valuesSize = sizeof(deck->values) / sizeof(deck->values[0]);

    Card *foundedCard = NULL;

    while (foundedCard == NULL)
    {
        int suit = deck->suits[rand() % suitsSize];
        int value = deck->values[rand() % valuesSize];

        cout << suit << endl;
        cout << value << endl;

        stack<Card *> stackAux;

        while (!deck->stack->empty())
        {
            foundedCard = &deck->stack->top();
            deck->stack->pop();
            if (foundedCard->suit == suit && foundedCard->value == value)
            {
                break;
            }
            else
            {
                stackAux.push(foundedCard);
                foundedCard = NULL;
            }
        }

        while (!stackAux.empty())
        {
            Card *auxCard = stackAux.top();
            stackAux.pop();
            deck->stack->push(*auxCard);
        }
    }

    return foundedCard;
}

bool pointsIsMoreThanMax(Player player)
{
    return player.points > MAX_POINTS;
}

void changeTurn()
{
    playerOneTurn = !playerOneTurn;
}

void gameOver(Player player1, Player player2)
{
    if (pointsIsMoreThanMax(player1) && pointsIsMoreThanMax(player2))
    {
        cout << "Empate\n";
    }
    else if (!pointsIsMoreThanMax(player1) && !pointsIsMoreThanMax(player2))
    {
        if (player1.points > player2.points)
        {
            cout << "Player 1 Ganhou!\n";
        }
        else if (player1.points < player2.points)
        {
            cout << "Player 2 Ganhou\n";
        }
        else
        {
            cout << "Empate\n";
        }
    }
    else if ((pointsIsMoreThanMax(player1)))
    {
        cout << "Player 2 Ganhou!\n";
    }
    else
    {
        cout << "Player 1 Ganhou!\n";
    }
    cout << "Player 1: " << player1.points << "\n";
    cout << "Player 2: " << player2.points << "\n";
}