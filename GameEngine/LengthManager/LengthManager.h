#ifndef LENGTHMANAGER_H
#define LENGTHMANAGER_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** LengthManager Class
@brief This class calculates the length of the snake at every point during the game and can be used to set length values in other classes using _getLength().
@author Ahmed N.Adamjee
@date 8th May 2019
*/
class LengthManager
{
public:
    /** Constructor */
    LengthManager();
    /** Destructor */
    ~LengthManager();

    /**
    * @brief This function sets the initial length parameters and gets pointers of lcd and pad from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    * @param Gamepad *pad @details pointer to the gamepad object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    @code
        _lcd = lcd;
        _length = 4;
    @endcode
    */
    void init(N5110 *lcd);

    /**
    * @brief This function decrements the length value by 1;
    @code
        _length -= 1;
    @endcode
    */
    void MinusLength();

    /**
    * @brief This function increments the length by one.
    @code
        _length += 1;
    @endcode
    */
    void PlusLength();

    /**
    * @brief This function prints the length on top edge of screen.
    @code
        char bufferscore[14];
        sprintf(bufferscore,"%d",_length);
        _lcd->printString(bufferscore,1,0);
    @endcode
    */
    void print_length_on_screen();

    /**
    * @brief This sends the current length value when called.
    * @returns _length @details This is the length of the snake, which is passed back after any manipulation such as MinusLength() or PlusLength().
    @code
        return _length;
    @endcode
    */
    int _getLength();

    /**
    * @brief This function obtains the length value to be altered for a specific operation.
    * @param length @details This is the length of the snake, which is recieved from the calling function to either initialise this or update this.
    @code
        _length = length;
    @endcode
    */
    void _setLength(int length);

private:
    int _length;
    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;

};
#endif