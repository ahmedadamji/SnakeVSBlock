#include "StartScreen.h"

int titleSprite[48][84] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,0,0,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,0,0,1,0,0,0,1,1,1,0,0,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,0,1,1,0,0,1,1,0,0,1},
    {1,0,1,1,0,0,0,0,0,1,1,1,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1},
    {1,0,0,0,1,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,1,1,0,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,1,1,0,0,0,0,1,1,0,1,1,0,0,0,1},
    {1,0,1,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,1,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1},
    {1,0,0,1,1,1,0,0,0,1,1,0,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,1,1,0,0,1,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

};

int arrow[7][9] = {
    {0,0,0,0,1,0,0,0,0},
    {0,0,0,1,1,0,0,0,0},
    {0,0,1,1,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,0,0,0,0},
    {0,0,0,1,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0},
};

int motionControl[12][21] = {
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    {1,1,1,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,1,1,1},
    {1,1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,1,1},
    {1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1},
    {0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0},
    {0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
};

int joystick[13][48] = {
    {0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0},
    {0,0,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0},
    {0,1,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,1,0},
    {1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1},
    {0,1,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,1,0},
    {0,0,1,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,1,1,0,0},
    {0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
};

int navL[13][8] = {
    {0,0,0,0,0,0,1,1},
    {0,0,0,0,0,1,1,0},
    {0,0,0,0,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,1,1,0,0,0,0},
    {0,1,1,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {0,1,1,0,0,0,0,0},
    {0,0,1,1,0,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,1,1,0,0},
    {0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,1,1},
};

int navR[13][8] = {
    {1,1,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0},
    {0,0,1,1,0,0,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,1,1,0,0},
    {0,0,0,0,0,1,1,0},
    {1,1,1,1,1,1,1,1},
    {0,0,0,0,0,1,1,0},
    {0,0,0,0,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,1,1,0,0,0,0},
    {0,1,1,0,0,0,0,0},
    {1,1,0,0,0,0,0,0},
};

StartScreen::StartScreen()
{

}

StartScreen::~StartScreen()
{

}

void StartScreen::init(N5110 *lcd, Gamepad *pad)
{
    _lcd = lcd;
    _pad = pad;
    StartScreen::object_initialisations();
    fps = 15; //sets the default frames per second to a certain value.
    menu_index = 16; //main menu selection arrow position
    g_mode = 1; //game mode selection (joystick/motion control).
    speed_index = 2; //game speed page selection index.
    showCredits = 1; //this helps in wether ot not to show credits to the user.
    controlSensitivity = 5; //sensitivity of control speed of menu options.
}


void StartScreen::object_initialisations()
{
    _stats.init(_lcd, _pad); //Stats object initialisation.
    _settings.init(_lcd, _pad); //Settings object initialisation.
    _tutorial.init(_lcd, _pad); //Tutorial object initialisation.
}


void StartScreen::titleScreen()
{
    //this saves the Theme song I want to play at the start.
    int song[18] = {441,494,439,372,392,370,330,246,329,331,370,555,555,495,440,392,392,370};
    _pad->leds_on();

    for(int ani = -51; ani <= 0; ani+=3)  {
        _lcd->clear();
        _lcd->drawSprite(0,ani,48,84,(int *)titleSprite); //Function used to draw the titleSprite
        _lcd->refresh();
        _pad->tone(song[(ani+48)/3],0.1); //This plays all the tones saved in song unless it is skipped by pressing start or A.

        //This Allows us to skip/play the animation before the menu screen
        if (StartScreen::checkStartorAPressed()) {
            return;    //if StartorA is pressed, the while loop is escaped.
        } else {
            wait(0.2);
        }
    }
    wait(0.3);
    _pad->leds_off();
    _lcd->clear();

    StartScreen::instruct(); //after the screen_saver is displayed we need to send in instructions of how to preoceed to menu.
}

void StartScreen::instruct()
{
    //_pad->init();
    wait(1/controlSensitivity); //to avoid race condition of the following while loop being skipped.
    while ((_pad->check_event(Gamepad::START_PRESSED) == false)&&(_pad->check_event(Gamepad::A_PRESSED) == false)&&(_startPressed == false)) {
        //Start_Pressed is 1 if start is already pressed during animation in titleScreen();
        _lcd->printString("Please Press",5,1); //Function used to promt the user to start.
        _lcd->printString("Start",25,3);
        _lcd->printString("to Begin",15,5);
        _lcd->refresh();
        _pad->leds_on();
        wait(0.1);
        _pad->leds_off();
        wait(0.1);
    }
    if (_startPressed == false) {//dont wait anymore if start is pressed. (this is to allow for quick skip towards menu)
        _pad->tone(1000.0,0.1);
    }
    _lcd->clear();
    _pad->leds_off();
}

void StartScreen::credits()
{
    _lcd->clear();
    if(showCredits)  { //Only shows the credits to the player if it had been kept enabled in settings.
        _lcd->printString("Created BY",8,1);
        _lcd->printString("Ahmed",24,3);
        _lcd->printString("Adamjee",20,4);
        _lcd->printString("201161436",15,5);
        _lcd->refresh();
        wait(2);
    }
    _lcd->clear();
}

void StartScreen::read_stats(SDFileSystem &sd) //to read the data from the SD card at the start of the game to be able to display before starting game.
{
    _stats.read(sd);
}

bool StartScreen::checkBackPressed()
{
    //This is a very important process, this helps the code to not get stuck in  menu loop but also allow to toggle between diffrent menu screens.
    if (_pad->check_event(Gamepad::BACK_PRESSED) == true) {
        _pad->tone(1000.0,0.1);
        _backPressed = true;
    } else {
        _backPressed = false;
    }
    return _backPressed; //returns true if back is pressed, returns false otherwise.
}


bool StartScreen::checkStartorAPressed()
{
    //This Allows us to skip/play the animation before the menu screen
    if((_pad->check_event(Gamepad::START_PRESSED) == true)||(_pad->check_event(Gamepad::A_PRESSED) == true)) { //to allow the gamer to skip the long starting animation if they are not a fan.
        _pad->tone(1000.0,0.1);
        _startPressed = true;
    } else {
        _startPressed = false;
    }
    return _startPressed; //returns true if start/A is pressed, returns false otherwise.
}

void StartScreen::menu()
{
    _lcd->clear();
    //StartScreen::init();
    //_pad->init();
    while ((_pad->check_event(Gamepad::A_PRESSED) == false)&&(_pad->check_event(Gamepad::START_PRESSED) == false)) {
        //This menu loop won't be skipped unless the player decides to press START/A.
        _lcd->clear();
        StartScreen::mainMenu();
        _lcd->refresh();

    }
    _pad->tone(1000.0,0.1);
    StartScreen::nextMenu(); //after all main menu operations have been completed, this function allows us to get to the next menu.
}

void StartScreen::mainMenu() //Displays the main menu contents, and then allows the user to select the next menu using the selection arrow.
{
    StartScreen::drawSelectionArrow(); //draws arrow to select menu option.

    _lcd->printString("Snake vs Block",0,0);
    _lcd->printString("Play",0,2);
    _lcd->printString("Settings",0,3);
    _lcd->printString("Stats",0,4);
    _lcd->printString("Tutorial",0,5);
}

void StartScreen::drawSelectionArrow()
{
    wait(1/controlSensitivity);
    Direction d = _pad->get_direction();
    if(((d==N)||(_pad->check_event(Gamepad::L_PRESSED) == true))&&(menu_index>16))  {
        menu_index=menu_index-8; // menu_index is the position of the selection arrow in menu and also the index of the case structure to select the next menu in StartScreen::NextMenu().
    }
    if(((d==S)||(_pad->check_event(Gamepad::R_PRESSED) == true))&&(menu_index<40))  {
        menu_index=menu_index+8; // menu_index is the position of the selection arrow in menu and also the index of the case structure to select the next menu in StartScreen::NextMenu().
    }
    _lcd->drawSprite(60,menu_index,7,9,(int *)arrow); // menu_index is the postion of where the arrow will be drawn and is determined by the above if command using joystick.
}

//////////////////////////////DECIDES THE NEXT MENU PAGE//////////////////////////////

void StartScreen::nextMenu()
{
    switch (menu_index) { //this menu_index saves the value from the coordinates of arrow in main menu, and allows us to select the next menu accordingly.
        case 16:
            game_mode(); //calls game mode after play has been pressed.
            game_speed(); //calls game speed after the game mode has been selected.
            return; //This forces us out of the menu class and back into int main().
        case 24:
            float *cs_sc;
            cs_sc = _settings.Implement(controlSensitivity);
            controlSensitivity = cs_sc[0]; //saves the number in controlSensitivity which controls the control speed of the menu oftions (basically the wait time of between reading joystick input).
            showCredits = cs_sc[1]; //saves the logic in showCredits which decides weather or not to show credits when game starts.
            menu(); //to return to main_menu if back is pressed
            break;
        case 32:
            _stats.StatsDisplay();
            menu(); //to return to main_menu if back is pressed
            break;
        case 40:
            _tutorial.Implement();
            menu(); //to return to main_menu if back is pressed
            break;
    }
}


//////////////////////////////GAME MODE SELECTION//////////////////////////////

void StartScreen::game_mode()
{
    _lcd->clear();
    //_pad->init();
    while ((_pad->check_event(Gamepad::A_PRESSED) == false)&&(_pad->check_event(Gamepad::START_PRESSED) == false)) {  //Change this to if button pressed.

        _lcd->clear();
        StartScreen::selectMode(); //displays to the user what are the mode options
        _lcd->refresh();

        if (StartScreen::checkBackPressed()) {
            break;    //if back is pressed, the while loop is escaped.
        }

    }
    _pad->tone(1000.0,0.1);

    if(_backPressed) { //if back was pressed in the while loop, the previous menu is called.
        StartScreen::menu();
    }
}

void StartScreen::selectMode()
{
    StartScreen::scrollModeSelection();  //the mode is selected by moving joystick in this function.
    switch (g_mode) {
        case 1:
            _lcd->printString("Joystick",18,1);
            _lcd->drawSprite(17,22,13,48,(int *)joystick); //Function used to draw the sprite.
            _lcd->refresh();
            break;
        case 2:
            _lcd->drawSprite(10,22,13,8,(int *)navL); //Function used to draw the sprite.
            _lcd->drawSprite(65,22,13,8,(int *)navR); //Function used to draw the sprite.
            _lcd->printString("Motion Control",1,1);
            _lcd->drawSprite(32,22,12,21,(int *)motionControl); //Function used to draw the sprite.
            break;
    }

}

void StartScreen::scrollModeSelection()
{
    Direction d = _pad->get_direction();
    wait(1/controlSensitivity);//to make the joystick selection's speed inversely proportional to controlSensitivity.
    if(((d==E)||(d==W)||(_pad->check_event(Gamepad::R_PRESSED) == true)||(_pad->check_event(Gamepad::L_PRESSED) == true))&&(g_mode==1))  {
        g_mode=2;
    }

    else if(((d==E)||(d==W)||(_pad->check_event(Gamepad::R_PRESSED) == true)||(_pad->check_event(Gamepad::L_PRESSED) == true))&&(g_mode==2))  {
        g_mode=1;
    }
}

//////////////////////////////INSTRUCTIONS FOR MOTION CONTROL//////////////////////////////

void StartScreen::motionControlInstructions()
{
    _lcd->clear();
    _lcd->printString("While playing the",5,0); //Function used to promt the user to start.
    _lcd->printString("game, press",9,1);
    _lcd->printString("A to centre",8,2);
    _lcd->printString("the snake at",9,3);
    _lcd->printString("prefered angle",0,4);
    _lcd->refresh();
    wait(2);
}


//////////////////////////////GAME SPEED SELECTION//////////////////////////////

void StartScreen::game_speed()
{
    _lcd->clear();
    //_pad->init();
    while ((_pad->check_event(Gamepad::A_PRESSED) == false)&&(_pad->check_event(Gamepad::START_PRESSED) == false)) {  //Change this to if button pressed.

        _lcd->clear();
        StartScreen::selectSpeed(); //this displays all the speed options and saves the data obtained (fps) for use in main().
        _lcd->refresh();

        if (StartScreen::checkBackPressed()) {
            break;    //if back is pressed, the while loop is escaped.
        }
    }
    _pad->tone(1000.0,0.1);

    if(_backPressed) { //if back was pressed in the while loop, the previous menu is called.
        StartScreen::menu(); //To go back to Menu if back is pressed.
    }

}

void StartScreen::selectSpeed() //decrease code size.
{
    StartScreen::scrollSpeedSelection(); //this swipes through the speed pages, dependent on the joystick input.
    _lcd->drawSprite(10,22,13,8,(int *)navL); //Function used to draw the sprite.
    _lcd->drawSprite(65,22,13,8,(int *)navR); //Function used to draw the sprite.
    _lcd->printString("Game Speed",10,1);
    switch (speed_index) {
        case 1:
            _lcd->printString("SNAKE",28,3);
            fps = 15;
            break;
        case 2:
            _lcd->printString("HUMAN",28,3);
            fps = 22;
            break;
        case 3:
            _lcd->printString("HORSE",28,3);
            fps = 26;
            break;
        case 4:
            _lcd->printString("CHEETHA",21,3);
            fps = 30;
    }

}

void StartScreen::scrollSpeedSelection()
{
    Direction d = _pad->get_direction();
    wait(1/controlSensitivity);//to make the joystick selection's speed inversely proportional to controlSensitivity.
    if(((d==E)||(_pad->check_event(Gamepad::R_PRESSED) == true))&&(speed_index==4))  {
        speed_index=1;
    } else if(((d==W)||(_pad->check_event(Gamepad::L_PRESSED) == true))&&(speed_index==1))  {
        speed_index=4;
    } else if(((d==E)||(_pad->check_event(Gamepad::R_PRESSED) == true))&&(1<=speed_index<=3))  {
        speed_index=speed_index+1;
    } else if(((d==W)||(_pad->check_event(Gamepad::L_PRESSED) == true))&&(2<=speed_index<=4))  {
        speed_index=speed_index-1;
    }
}
