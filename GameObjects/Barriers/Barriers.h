#ifndef BARRIERS_H
#define BARRIERS_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Barriers Class
@brief This class helps to draw barriers in the game which are obstacles the snake has no effect to but stops it's x axis motion.
@author Ahmed N.Adamjee
@date 9th May 2019
*/
class Barriers
{
public:
    /** Constructor */
    Barriers();
    /** Destructor */
    ~Barriers();
    
    /** 
    * @brief Initialises barrier position and reset variable and gets pointers of lcd from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd);

    /**
    * @brief This function draws the Barriers onto the screen.
    * @param block_y_pos @details This is the y axis position of the blocks sprites.
    */
    void draw(int block_y_pos);

    /**
    * @brief This function updates the position of the Barriers as they move down the screen.
    * @param blockgap @details this is the amount in pixels of the gap between blocks
    */
    void update(int blockgap);

    /**
    * @brief This function returns the coordinates of the top-left pixel in the Barriers sprites.
    * @returns Vector2D barrierpos @details this is a struct that returns the x and y psition of the origin of the barriers sprite to be read.
    */
    Vector2D get_pos();

    /**
    * @brief This function is used to change the position of the barrier to specific coordinates when called.
    * @param Vector2D p @details this is a struct that saves the x and y psition of the origin of the barriers sprite to be set.
    */
    void set_pos(Vector2D p);


    Vector2D velocity; //This is a struct that stores the x and y axis velocities of the barrier.

private:
    int reset; //reset is used to draw a new set of barriers.
    int _barx;  //barrier x
    int _bary;  //barrier y
    int _barriergap; //gap between barriers falling
    int _blockgap; //gap between blocks falling.

    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;

};
#endif