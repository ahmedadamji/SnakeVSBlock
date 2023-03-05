#ifndef SETTINGS_H
#define SETTINGS_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Settings Class
@brief Class for selecting "Game comfort parameters" like brightness, contrast, control speeds and also features an hide option for credits.
@author Ahmed N.Adamjee
@date 8th May 2019
*/
class Settings
{
public:

    /** Constructor */
    Settings();
    /** Destructor */
    ~Settings();

    /** 
    * @brief Gets pointers of lcd and pad from int main() and initialises variables used in the class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    * @param Gamepad *pad @details pointer to the gamepad object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd, Gamepad *pad);

    /**
     * @brief Used to select between various settings functions using user input.
     * @param controlSensitivity @details is the value that determines the wait time between performing menu tasks.
     * @returns cs_sc @details values of controlSensitivity and showCredits are saved in an array called cs_sc which is returned to the StartScreen class as a pointer.
     */
    float * Implement(float controlSensitivity);

    /** 
    * @brief Shows the information for using settings.
    */
    void info();

    /** 
    * @brief Calls the respective settings menu as per the joystick entry by the user.
    * @param settingsIndex @details is the value that is used to select the relevant settings page.
    */
    void CallFunctions(int settingsIndex);

    /** 
    * @brief Enables the user to select the sensitivity of the game controls and saves it in cs_sc[0]
    */
    void controlSensitivity();

    /** 
    * @brief Allows the user to set the screen brightness.
    */
    void brigntness();

    /** 
    * @brief Allows the user to set the contrast of the screen.
    */
    void contrast();

    /** 
    * @brief Allows the user to set the volume of the speaker.
    */
    void volume();

    /** 
    * @brief Allows the user to hide/show credits.
    */
    void showCredits();

private:
    float cs_sc[2]; //this array helps to return Control speeds and Show credits parameters.
    int settingsIndex; //an index for selecting from settings functions.
    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;


};
#endif