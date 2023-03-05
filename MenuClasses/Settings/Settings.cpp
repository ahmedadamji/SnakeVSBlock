#include "Settings.h"

Settings::Settings()
{

}

Settings::~Settings()
{

}

int naviL[13][8] = {
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

int naviR[13][8] = {
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

int screenContrast[13][13] = {
    {0,0,0,0,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,1,0,0,0},
    {0,0,1,0,0,1,1,1,0,0,1,0,0},
    {0,1,0,1,1,0,0,1,1,1,0,1,0},
    {1,0,0,1,0,0,0,1,1,1,0,0,1},
    {1,0,1,1,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,1,1,1,0,1},
    {1,0,0,1,0,0,0,1,1,1,0,0,1},
    {0,1,0,1,1,0,0,1,1,1,0,1,0},
    {0,0,1,0,0,1,1,1,0,0,1,0,0},
    {0,0,0,1,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,1,1,1,1,1,0,0,0,0},
};

int brightness[15][15] = {
    {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
    {0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},
    {0,0,1,0,0,1,0,1,0,1,0,0,1,0,0},
    {1,0,0,1,0,0,1,1,1,0,0,1,0,0,1},
    {0,1,0,0,1,1,0,0,0,1,1,0,0,1,0},
    {0,0,1,0,1,0,0,0,0,0,1,0,1,0,0},
    {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
    {1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
    {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,1,0,1,0,0,0,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,0,1,1,0,0,1,0},
    {1,0,0,1,0,0,1,1,1,0,0,1,0,0,1},
    {0,0,1,0,0,1,0,1,0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},
    {0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
};

void Settings::init(N5110 *lcd, Gamepad *pad)
{
    _lcd = lcd;
    _pad = pad;
    cs_sc[0] = 4; //to initialise the control speeds
    cs_sc[1] = 1; //to set show credits to a default of 1.
    settingsIndex = 1; //an index for settings
}

float * Settings::Implement(float controlSensitivity)
{
    Settings::info();
    wait(1/controlSensitivity); //to avoid a race condition of the following while loop being skipped.
    //_pad->init();
    while (_pad->check_event(Gamepad::BACK_PRESSED) == false) {  //if button pressed.
        Direction d = _pad->get_direction();
        wait(1/controlSensitivity);
        _lcd->clear();

        if((d==E)&&(settingsIndex==4))  {
            settingsIndex=1;
        }

        else if((d==W)&&(settingsIndex==1))  {
            settingsIndex=4;
        }

        else if((d==E)&&(1<=settingsIndex<=3))  {
            settingsIndex=settingsIndex+1;
        }

        else if((d==W)&&(2<=settingsIndex<=4))  {
            settingsIndex=settingsIndex-1;
        }

        Settings::CallFunctions(settingsIndex);
    }
    _pad->tone(1000.0,0.1);
    return cs_sc;
}

void Settings::info()
{
    _lcd->clear();
    _pad->leds_on();
    _lcd->printString("For selecting",0,0);//Function used to promt the user to how to use settings.
    _lcd->printString("from settings",0,1);
    _lcd->printString("available, use",0,2);
    _lcd->printString("Joystick in <>",0,3);
    _lcd->printString("directions",0,4);
    _lcd->refresh();
    wait(2);
    _lcd->clear();
    _lcd->printString("For adjusting",0,0);
    _lcd->printString("the parameters,",0,1);
    _lcd->printString("use the pot",0,2);
    _lcd->printString("by rotating",0,3);
    _lcd->printString("Press Back",0,4);
    _lcd->printString("to confirm",0,5);
    _lcd->refresh();
    wait(2);
    _pad->leds_off();
}

void Settings::CallFunctions(int settingsIndex)
{
    _lcd->clear();
    _lcd->drawSprite(5,22,13,8,(int *)naviL); //Function used to draw the sprite.
    _lcd->drawSprite(71,22,13,8,(int *)naviR); //Function used to draw the sprite.
    switch (settingsIndex) {
        case 1:
            Settings::controlSensitivity();
            break;
        case 2:
            Settings::brigntness();
            break;
        case 3:
            Settings::contrast();
            break;
        case 4:
            Settings::showCredits();
            break;
    }
    _lcd->refresh();
}

void Settings::controlSensitivity()
{
    _lcd->printString("Control Speeds",0,0);
    cs_sc[0] = _pad->read_pot()*5+1;
    _lcd->drawRect(15,22,54,13,FILL_TRANSPARENT);
    _lcd->drawRect(15,22,_pad->read_pot()*54,13,FILL_BLACK);
    _pad->leds_on();
}

void Settings::brigntness()
{
    _lcd->drawSprite(35,2,15,15,(int *)brightness); //Function used to draw the sprite.
    float pot;
    pot = _pad->read_pot();
    _lcd->drawRect(15,22,54,13,FILL_TRANSPARENT);
    _lcd->drawRect(15,22,_pad->read_pot()*54,13,FILL_BLACK);
    _lcd->setBrightness(pot);
    _pad->leds_on();
}

void Settings::contrast()
{
    _lcd->drawSprite(36,3,13,13,(int *)screenContrast); //Function used to draw the sprite.
    float pot;
    pot = ((_pad->read_pot()+3.8)/8);
    _lcd->drawRect(15,22,54,13,FILL_TRANSPARENT);
    _lcd->drawRect(15,22,_pad->read_pot()*54,13,FILL_BLACK);
    _lcd->setContrast(pot);
    _pad->leds_on();
}

void Settings::showCredits()
{
    _lcd->printString("Show Credits?",5,0);
    float pot;
    pot = _pad->read_pot();

    if(((0.1<=pot)&&(pot<=0.2))||((0.3<=pot)&&(pot<=0.4))||((0.5<=pot)&&(pot<=0.6))||((0.7<=pot)&&(pot<=0.8))||((0.9<=pot)&&(pot<=1)))  {
        _lcd->printString("NO",36,3);
        cs_sc[1] = 0;
    }

    else  {
        _lcd->printString("YES",33,3);
        cs_sc[1] = 1;
    }

    _pad->leds_on();
}