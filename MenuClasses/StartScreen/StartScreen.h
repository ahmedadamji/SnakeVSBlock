#ifndef StartScreen_H
#define StartScreen_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Settings.h"
#include "Stats.h"
#include "SDFileSystem.h"
#include "Tutorial.h"

/** StartScreen Class
@brief Class for displaying the menu, calling all the classes that follow the menu (eg: Settings) and the animation when the game starts.
@author Ahmed N.Adamjee
@date 8th May 2019
*/
class StartScreen
{
public:

    /** Constructor */
    StartScreen();
    /** Destructor */
    ~StartScreen();

    /** 
    * @brief Initialises all parameters of the Game Interface, assigns some default values and calls other init() functions.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    * @param Gamepad *pad @details pointer to the gamepad object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd, Gamepad *pad);
    
    /**
    * @brief This function initialises the class objects that are the diffrent parts of the game (Eg: SnakeFood Class).
    */
    void object_initialisations();

    /** 
    * @brief Draws the Title Sprite onto the screen and plays theme song.
    */
    void titleScreen();

    /** 
    * @brief Instructs the user about how to progress after the title screen has been displayed.
    */
    void instruct();

    /** 
    * @brief Shows who the author of the game is before starting the game. This function's functionality can be hidden using settings.
    */
    void credits();

    /** 
    * @brief Reads stored statistics using the Stats class in the sd card and saves it for displaying in the menu.
    *@param SDFileSystem &sd @details The SDFileSystem library.
    @code
        _stats.read(sd);
    @endcode
    */
    void read_stats(SDFileSystem &sd);

    /** 
    * @brief Checks BACK if button pressed in a loop, can be used to exit it and also remember if true/false and used for various conditions.
    * @returns _backPressed @detalis True if the BACK pressed, else False.
    */
    bool checkBackPressed();

    /** 
    * @brief Checks if START or A buttons are pressed in a loop, can be used to terminate it and also remember if true/false and used for various conditions.
    * @returns _startPressed @details True if the START or A pressed, else False.
    */
    bool checkStartorAPressed();

    /** 
    * @brief Waits for the user to select a menu option and calls a related function.
    */
    void menu();

    /** 
    * @brief Displays all the Main Menu contents to the player and allows the user to navigate using drawSelectionArrow().
    */
    void mainMenu();

    /** 
    * @brief Draws an arrow to aid the selection of main menu options.
    */
    void drawSelectionArrow();

    /** 
    * @brief Calls the next menu item dependent on the input in mainMenu().
    */
    void nextMenu();

    /** 
    * @brief Obtains the user input on the game mode they would like to play on (Joystick or Motion Control).
    */
    void game_mode();

    /** 
    * @brief Value of g_mode is changed in this function that allows the choice between joystick/motion control.
    */
    void selectMode();

    /** 
    * @brief Changes the page displayed in the game mode menu
    */
    void scrollModeSelection();

    /** 
    * @brief Promts the user to press A to centre position their angle during the game if Motion Control is selected.
    */
    void motionControlInstructions();

    /** 
    * @brief Obtains the user input on the game speed to be used later in the SnakevsBlock class.
    */
    void game_speed();

    /** 
    * @brief Value of fps is changed in this function that will be used as frames per second in my game loop in main.cpp.
    */
    void selectSpeed();

    /** 
    * @brief Changes the page displayed in the game speed menu
    */
    void scrollSpeedSelection();


    //SETTING THE GAME SPEED AND GAME MODE.
    int fps; // this sends over the game speed
    int g_mode; //this helps to select between joystick and motion control.
    int speed_index;

    //MENU OPTIONS INDEX.
    int menu_index;

    //VARIABLE USED TO DECIDE WEATHER TO SHOW CREDITS.
    int showCredits;

    //VARIABLE USED TO DECIDE THE WAIT TIME OF THE MENU PAGES.
    float controlSensitivity;

private:

    //OBJECT DECLARATIONS
    Stats _stats;
    Settings _settings;
    Tutorial _tutorial;
    
    //VARIABLES TO TOGGLE BACK AND FORTH BETWEEN MENU OPTIONS.
    bool _backPressed; //remembers if back is pressed.
    bool _startPressed; //remembers if start is pressed.

    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;



};
#endif