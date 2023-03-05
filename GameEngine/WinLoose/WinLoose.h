#ifndef WINLOOSE_H
#define WINLOOSE_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** WinLoose Class
@brief This class encompasses level transitions, loosing screen and level display.
@author Ahmed N.Adamjee
@date 8th May 2019
*/
class WinLoose
{
public:
    /** Constructor */
    WinLoose();
    /** Destructor */
    ~WinLoose();

    /** 
    * @brief Gets pointers of lcd and pad from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    * @param Gamepad *pad @details pointer to the gamepad object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd, Gamepad *pad);

    /**
    * @brief This function prepares the game for the next level and initialises WinLoose and obtains required class addresses to use in other functions.
    * @param level @details stores the value of the current level.
    */
    int LevelComplete(int level);

    /**
    * @brief Displays the level on screen.
    * @param level @details stores the value of the current level.
    */
    void displayLevel(int level);

    /**
    * @brief This function displays a loosing screen on the lcd display.
    */
    void GameOver();

private:
    char bufferlevel[14];  //this helps me print the level on screen.

    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;



};
#endif