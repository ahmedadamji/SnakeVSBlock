#include "Snake.h"

Snake::Snake()
{

}

Snake::~Snake()
{

}

//The Snake Sprite.
int snake_sprite[3][3] = {
    {0,1,0},
    {1,0,1},
    {0,1,0},
};

void Snake::init(N5110 *lcd)
{
    _lcd = lcd;
    _speed = 1;
    reset = 0; //Variable used to allow a starting location for the player.
}

void Snake::_setLength(int length)
{
    _length = length;
    if(length >= 10) {
        _length = 10;   //to stop the snake length virtually at 10 when it goes past it.
    }
}

void Snake::_setSpeed(int speed)
{
    _speed = speed;
}

void Snake::draw()
{
    if(reset == 0) {

        Vector2D p = {WIDTH/2, HEIGHT - 3};  //Spawns player sprite near the middle of the screen.
        Snake::set_pos(p);

        reset = reset+1;
    }
    //printf("SPRITE %d %d \n", _x[0], _y[0]);

    for(int i=0; i<=_length-1; i++)  {
        _lcd->drawSprite(_x[i],_y[i],3,3,(int *)snake_sprite); //Function used to draw the sprite.
    }
}


void Snake::set_pos(Vector2D p)
{
    _x[0] = p.x;  //Spawns first of the snake sprite near the middle of the screen.
    _y[0] = p.y;  //Spawns first of thesnake sprite near the bottom of the screen.

    for(int i=1; i<=9; i++)  {
        _x[i] = _x[i-1];      //Makes them all get spawned at the same x position initially. (copies the previous snake bead)
        _y[i] = _y[i-1] - 3;  //Makes them all get spawned 3 sprites appart in the y axis initially. (copies the previous snake bead)
    }
}

Vector2D Snake::get_pos(int snakeIndex)
{
    Vector2D snakepos; //Stores the snake position.

    for(int i = snakeIndex; i<=9; i++)  {
        if(_length == (i+1))  {
            snakepos.x = _x[i - snakeIndex]; //Gets the index from SnakevsBlock.cpp which is basically 0 for the top beed, and 9 for the 10th beed
            snakepos.y = _y[i - snakeIndex]; //and saves it in x[?] and y[?] which is 0 for the bottom beed and higher indexes for higher beeds.
            return snakepos;
        }
    }
    if(_length >= 10)  {
        snakepos.x = _x[9 - snakeIndex]; //we know that at length = 10+ the snake doesn't look any longer, so subtracting the index from 9 will imply
        snakepos.y = _y[9 - snakeIndex]; //the top beed is _x[9], _y[9] and the last beed (index 9) is _x[0], _y[0]
        return snakepos;
    }
    snakepos.x = -100; //to make sure these coordinates do not interfere with any collisions as this is a default value if conditions do not satisfy,
    snakepos.y = -100; //(NULL is in range of collisions in this game and is therefore not used.
    return snakepos;
    //printf("snakepos from player = %f %f \n", snakepos.x, snakepos.y);
}

void Snake::update(Direction d, int* immobile_bead_n)
{
    _d = d; //Saves the direction of movement in a private struct _d from the SnakevsBlock.cpp.
    
    Snake::chainSnakeTogether(immobile_bead_n); //chains the snake beads together in hysteresis.

    Snake::moveSnake(immobile_bead_n); //makes the top bead in the snake move according to the user input direction.

    Snake::_setSnakeLimits(); //makes the snake movement limited to the nokia screen and ensure spawn position is where we expected.
}

void Snake::chainSnakeTogether(int* immobile_bead_n)
{
    //this makes all of the snake beeds chained together by making the lower ones drag towards where the top one was in the previous loop
    //the immobile_bead_n[i] makes sure that the snake beed doesn't move if that beed is deactivated by colliding with a barrier. immobile_bead_n[i] also signifies the specific beed number by i.
    for(int i=1; i<=9; i++)  {
        if((_length > i)&&(_x[i-1] != _x[i]))  {
            if ((_x[i-1] > _x[i])&&(immobile_bead_n[i] == 1)&&(immobile_bead_n[i-1] == 1))  {
                _x[i-1]-=_speed;
            }
            if ((_x[i-1] < _x[i])&&(immobile_bead_n[i] == 1)&&(immobile_bead_n[i-1] == 1))  {
                _x[i-1]+=_speed;
            }
        }
    }
}

void Snake::moveSnake(int* immobile_bead_n)
{
    //this makes the controls of W/E directions only exclusive to the top beed in the snake
    for(int i=0; i<=9; i++)  {
        if((_length == i+1)&&(immobile_bead_n[i] == 1))  {

            if (_d == E) {
                _x[i]+= _speed;
            }

            if (_d == W) {
                _x[i]-= _speed;
            }

        }
    }
}

void Snake::_setSnakeLimits()
{
    // the following makes sure that when the length is increased, the snake stays where it was when it ate food.

    for(int i=1; i<=9; i++)  {

        if(_length < (i+1))  {
            _x[i] = _x[i-1];
        }
    }

    //Limits set so that the snake does not travel off the screen.
    for(int i=0; i<=9; i++)  {

        if (_x[i] <= 0) {
            _x[i] = 0;
        }

        if (_x[i] > 81) {
            _x[i] = 81;
        }
    }
}