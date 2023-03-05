#include "SnakeFood.h"

SnakeFood::SnakeFood()
{

}

SnakeFood::~SnakeFood()
{

}

//SnakeFood Sprite.
int food_sprite[3][3] = {
    {0,1,0},
    {1,0,1},
    {0,1,0},
};

void SnakeFood::init(N5110 *lcd) //Delete Int
{
    _lcd = lcd;
    reset = 0;
    _fx = -100; //to make sure these coordinates do not interfere with any collisions as this is a default value if conditions do not satisfy,
    _fy = -100; //(NULL is in range of collisions in this game and is therefore not used.
}


void SnakeFood::draw()
{
    velocity.x = 0;
    velocity.y = 1;
    //add sideways velocity incase I want to make it dodgy.

    //Resets SnakeFood position if it reaches the bottom of the screen.
    if(reset == 0) {
        _fx = (rand() % 82);  //this makes the food pop up at a random, unspecified location in the x axis.
        _fy = -3;
        reset = reset+1;
    }

    _lcd->drawSprite(_fx,_fy,3,3,(int *)food_sprite); //Function to draw the food.
}

Vector2D SnakeFood::get_pos() //Obtains the X and Y coordinate of the target.
{
    Vector2D snakefoodpos = {_fx,_fy};
    //printf("snakefoodpos from food = %f %f \reset", snakefoodpos.x, snakefoodpos.y);
    return snakefoodpos;
}


void SnakeFood::update()
{
    //uses draw() to reset snake position after snake has gone past the screen.
    if(_fy >= 48) {
        reset = 0;
    }
    _fx += velocity.x;
    _fy += velocity.y;
}


void SnakeFood::set_pos(Vector2D p)
{
    _fx = p.x;
    _fy = p.y;
}
