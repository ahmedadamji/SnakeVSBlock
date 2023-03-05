#ifndef Stats_H
#define Stats_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "SDFileSystem.h"

/** Stats Class
@brief Class for saving the highest level achived and displaying when asked.
@author Ahmed N.Adamjee
@date 8th May 2019
*/
class Stats
{
public:

    /** Constructor */
    Stats();
    /** Destructor */
    ~Stats();

    /** 
    * @brief Gets pointers of lcd and pad from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    * @param Gamepad *pad @details pointer to the gamepad object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd, Gamepad *pad);

    /** 
    * @brief Used to display saved stats onto the screen.
    */
    void StatsDisplay();

    /**
     * @brief Used to write stats to the SD card.
     * @param level @details level is as the name implies, the current game level while playing.
     * @param SDFileSystem &sd @details The SDFileSystem library.
     */
    void write(int level, SDFileSystem &sd);

    /** 
    * @brief Used to read data from the file
     * @param SDFileSystem &sd @details The SDFileSystem library.
    */
    void read(SDFileSystem &sd);

    /** Allows us to delete the file if required.
    * @brief not used in the working version but used when i need to delete data from the sd card.
    * @param filename[] @details saves the name of the file we want to delete.
    */
    void delete_file(char filename[]);
    


private:
    int _stored_top_level; //stores the old top level from what is read from file.
    int _current_level; //stores the current level.
    int _top_level; //stores the new top level after comparison.
    char _bufferlevel[14];  //this helps me print the highest level on screen.

    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;


};
#endif