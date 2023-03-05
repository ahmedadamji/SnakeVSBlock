#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Tutorial Class
@brief Class for allowing the user to know more about the game using sprites, texts and interactive controls..
@author Ahmed N.Adamjee
@date 8th May 2019
*/
class Tutorial
{
    public:

    /** Constructor */
    Tutorial();
    /** Destructor */
    ~Tutorial();
    
    /** 
    * @brief Gets pointers of lcd and pad from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    * @param Gamepad *pad @details pointer to the gamepad object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd, Gamepad *pad);
    
    /** 
    * @brief Used to call all Tutorial functions and go forth and exit the tutorial functions.
    */
    void Implement();

    /** 
    * @brief Checks BACK if button pressed in a loop, can be used to exit it and also remember if true/false and used for various conditions.
    * @returns _backPressed @details True if the BACK pressed, else False.
    */
    bool checkBackPressed();
    
    /** 
    * @brief Introduces how to use the gamepad to the user for this tutorial.
    */
    void gamePad();
    
    /** 
    * @brief Shows how to control parameters in settings.
    */
    void settings();
    
    /** 
    * @brief Shows how to scroll through menu.
    */
    void controlsToNavigateInMenu();
    
    /** 
    * @brief Shows how to scroll through Game Mode and Game Speed Menus.
    */
    void controlsToNavigateGameModeSpeed();
    
    /** 
    * @brief Shows how to move the snake in the game.
    */
    void controlsToPlayGame();
    
    /** Shows how to start/end the game and also go to the next/previous menu.*/
    void controlsForPreviousOrNext();
    
    /** 
    * @brief Takes us to tutorial of why to avoid the blocks.
    */
    void BlockTutorialA();
    
    /** 
    * @brief Explains to the user what the block does.
    */
    void BlockTutorialB();
    
    /** 
    * @brief Conveys to the user that they can still slide away after colliding.
    */
    void BlockTutorialC();
    
    /** 
    * @brief Displays to the user how to react to food in way of our game.
    */
    void FoodTutorial();
    
    /** 
    * @brief Takes us to tutorial of what the barrier does in our game.
    */
    void BarrierTutorial();
    
    /** 
    * @brief Talks us through some general information about the game.
    */
    void GeneralInfo();
    
    
private:
    bool _backPressed; //remembers if back is pressed.
    
    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;
    
};
#endif