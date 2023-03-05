#include "WinLoose.h"

WinLoose::WinLoose()
{

}

WinLoose::~WinLoose()
{

}

void WinLoose::init(N5110 *lcd, Gamepad *pad)
{
    _lcd = lcd;
    _pad = pad;
}

int WinLoose::LevelComplete(int level)
{
    level += 1;
    _lcd->clear();
    _lcd->printString("Level Complete",0,1);
    _lcd->printString("Press Start",10,3);
    _lcd->printString("to Proceed",12,4);
    _lcd->refresh();
    wait(0.05); //to avoid race condition of skipping the following while loop.
    while ((_pad->check_event(Gamepad::START_PRESSED) == false)&&(_pad->check_event(Gamepad::A_PRESSED) == false)) {
        _pad->leds_on();
        _pad->tone(rand()%1001,0.1); //helps to set max freq for random sound
        wait(0.1);
        _pad->leds_off();
        wait(0.1);
    }
    WinLoose::displayLevel(level);
    return level;
}

void WinLoose::displayLevel(int level)
{
    _lcd->clear();
    sprintf(bufferlevel,"%d",level);
    _lcd->printString("Level:",25,1);
    _lcd->printString(bufferlevel,40,3);
    _lcd->refresh();
    wait(2);
}

void WinLoose::GameOver()
{
    //_pad->init();
    while ((_pad->check_event(Gamepad::BACK_PRESSED) == false)) {
        _lcd->clear();
        _lcd->printString("Game",33,1);
        _lcd->printString("Over",33,3);
        _lcd->printString("Press Back",14,5); //Function used to promt the user to Restart.
        _lcd->refresh();
        wait(0.1);
    }
    _lcd->clear();
    //NVIC_SystemReset(); //Software Reset.
}