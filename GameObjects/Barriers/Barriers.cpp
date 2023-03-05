#include "Barriers.h"

Barriers::Barriers()
{

}

Barriers::~Barriers()
{

}

//Brrier Sprite.
int Barrier[22][1] = {
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
    {1},
};
void Barriers::init(N5110 *lcd)
{
    _lcd = lcd;
    reset = 0;
    _barx = -100; //to make sure these coordinates do not interfere with any collisions as this is a default value if conditions do not satisfy,
    _bary = -100; //(NULL is in range of collisions in this game and is therefore not used.
}


void Barriers::draw(int block_y_pos)
{
    velocity.x = 0;
    velocity.y = 1;

    if((reset == 0)&&(block_y_pos < (_blockgap-14))) {
        switch(rand()%4)  {
            case 0:
                _barx = 19;
                break;
            case 1:
                _barx = 35;
                break;
            case 2:
                _barx = 51;
                break;
            case 3:
                _barx = 67;
                break;
        }
        _bary = -22;
        reset = reset+1; //to stop this if function to keep executing.
    }
    _lcd->drawSprite(_barx,_bary,22,1,(int *)Barrier); //Function to draw the frame at all i coordinates as x.

}

Vector2D Barriers::get_pos() //Obtains the X and Y coordinate of the target.
{
    Vector2D barrierpos = {_barx,_bary};
    //printf("barrierpos is = %f %f \n", barrierpos.x, barrierpos.y);
    return barrierpos;
}

void Barriers::update(int blockgap)
{
    _blockgap = blockgap;
    _barriergap = _blockgap/4;
    if (_barriergap <= 60) { //to make sure that barrier gap doesn't reduce below 60 which would cause flickering on the screen.
        _barriergap = 60;
    }
    // this if function makes sure the block appears at the rate of blockgap.
    if(_bary >= _barriergap) {
        reset = 0;
    }
    _barx += velocity.x;
    _bary += velocity.y;

}


void Barriers::set_pos(Vector2D p)
{
    _barx = p.x;
    _bary = p.y;
}
