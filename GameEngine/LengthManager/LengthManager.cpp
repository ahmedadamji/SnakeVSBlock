#include "LengthManager.h"

LengthManager::LengthManager()
{

}

LengthManager::~LengthManager()
{

}



void LengthManager::init(N5110 *lcd)
{
    _lcd = lcd;
    _length = 4;
}

void LengthManager::MinusLength()
{
    _length -= 1;
}
    
void LengthManager::PlusLength()
{
    _length += 1;
}

void LengthManager::print_length_on_screen()
{
    char bufferscore[14];
    sprintf(bufferscore,"%d",_length);
    _lcd->printString(bufferscore,1,0); 
}

int LengthManager::_getLength()
{
    return _length;
}

void LengthManager::_setLength(int length)
{
    _length = length;
}
