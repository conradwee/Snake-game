#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
int key = 0;
int life = 0;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls"); //system("clear");
    for (int j = 0; j < width + 2; j++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (j == 0)

                cout << "#";

            if (j == width)

            {
                cout << "#\n";

            }
            else if (i == y && j == x) {
                cout << "O";
            }

            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }

            else
            {

                cout << " ";

            }
        }
    }

    {for (int j = 0; j < width + 2; j++) {
        cout << "#";
    }
    cout << endl; }
    cout << endl;
    cout << "score: " << score << endl;
    cout << "number of life(s) left " << 3 - life << endl;
}

void Input() {
    if (_kbhit())
    {
        key = _getch();
        if (key == 'a')
            dir = LEFT;
        if (key == 'd')
            dir = RIGHT;
        if (key == 'w')
            dir = UP;
        if (key == 's')
            dir = DOWN;

    }

};

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;

    }


    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x > width || x<0 || y> height || y < 0)
    {
        life++;
        x = width/2;
        y = height/2;
        dir = STOP;

    }
    if (life > 2)
    {
        gameOver = true;
    }

    if (x == fruitX && y == fruitY) {
        score++;
        nTail++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}



void Sleep() {};
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(10); //sleep(10);
    }
    system("cls");
    cout << "This game has ended" << endl;
    cout << "Your Score is " << score << endl;
    cout << "Game is made by Conrad" << endl;

    return 0;
}

