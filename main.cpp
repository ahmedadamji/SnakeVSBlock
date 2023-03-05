/*
ELEC2645 Embedded Systems Project
School of Electronic & Electrical Engineering
University of Leeds
Name: Ahmed Nomaan Adamjee
Username: el17ana
Student ID Number: 201161436
Date: 07/03/2019
*/

#include "main.h"
/** @file main.cpp
 *  @brief This file is designated to start the program by calling all the necessary functions in a sequential manner.
 */

///////////// MAIN.CPP ////////////////
int main()
{
#ifdef TEST_SNAKE
    int number_of_failures = run_all_tests();

    if(number_of_failures > 0) return number_of_failures;
#endif

    init();
    _start.titleScreen();
    while(1)  { //This loop is created for Play/Continue configuration

        menu(); //pops up the menu by calling the StartScreen Classes.

        // start the game
        _start.credits(); // this is after the menu to allow us to hide credits if we want to play the game without wasting any time.
        wait(1.0f/fps);
        // snakeVSblock game loop - detect input respect to the menu options, and update data and refresh screen
        gameLoop();
    }
}

//MAIN_FUNCTIONS

//INIT
void init()
{
    // need to initialise LCD and Gamepad
    lcd.init(); //init for the N5110 Library.
    device.init(); //init for the FXOS8700CQ Library.
    pad.init(); //init for the Gamepad Library.
    _start.init(&lcd, &pad); //init for the Menu Class --> StartScreen.
    _game.init(&lcd, &pad); //init for the SnakeVSBlock Class.
    srand(100000*noisy.read_u16()); //seeds the random number generator with a random noise from the K64F.
}

//MENU
void menu()
{
    read_write_stats(); //inside menu because used in a menu function for displaying the highest level saved.
    _start.menu();  // this takes us to main menu inside startscreen, and connects automatically to all other menu functions.
    _set_mode_speed(); //takes all the data collected from the menu to configure the game.
}

//READ AND WRITE STATS.
void read_write_stats()
{
    _start.read_stats(sd); //this is to save the current highest level in the stats class that can be used in menu.
    _stats.write(1, sd); //this tells the stats class that the game has started from level 1;
}

//SET MODE AND SPEED.
void _set_mode_speed()
{
    fps = _start.fps; // sets the frames per second required, selected from the game speed menu.
    g_mode = _start.g_mode;// allows us to pass this information on to the snakevsblock class, to set the controls to either joystick or motion control.

    if (g_mode == 2) {  //show instructions to handle motion control.
        _start.motionControlInstructions();    //this only comes up on the screen is the user selects motion control from menu options.
    }
}

//GAME LOOP.
void gameLoop()
{
    while (1) {
        refresh_game();
        _game.read_input(device, g_mode); //this reads the angle or joystick direction, on the condition of either of them being selected.
        _game.get_pos(); //takes the game object coordinates and saves it privately to use later for implementing collisions.
        _game.update(); //updates the game screen and checks for any collisions.

        //the int back stores the value 1 if back is pressed inside the update function of snakevsblock,
        //This function also handles level progression and level failure operations by using the class WinLoose.
        back = _game.CheckGameProgression(sd); //and also sends relevant data to the sd card to implement stats functionality.

        if(back)  {
            break;    //and this allows us to return to main menu by using the keyword break.
        }

        wait(1.0f/fps);
    }
}

//REFRESH GAME.
void refresh_game()
{
    lcd.clear();  //clears the N5110 screen for the next frame
    _game.updateSnakeLengthAndMovement(); //updates snake length data and makes motion free by default.
    _game.draw(); //draws the next game frame
    lcd.refresh();  //refreshes the N5110 screen to display the frame.
}


/*
void deinit()
{
    // need to deinitialise to quit.
    lcd.~N5110(); //deinit for the N5110 Library.
    pad.~Gamepad(); //deinit for the Gamepad Library.
    device.~FXOS8700CQ(); //deinit for the FXOS8700CQ Library.

}
*/