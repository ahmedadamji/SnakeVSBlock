#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** SnakeFood Class
@brief This class draws and updates snake food sprites after every collision.
@author Ahmed N.Adamjee
@date 9th May 2019
*/
class SnakeFood
{
public:
    /** Constructor */
    SnakeFood();
    /** Destructor */
    ~SnakeFood();

    /**
    * @brief Initialises the snake food position struct and reset variable and gets pointers of lcd from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd);

    /**
    * @brief This function draws the SnakeFood sprite onto the screen.
    */
    void draw();

    /**
    * @brief This function updates the position of the SnakeFood as it moves down the screen.
    */
    void update();

    /**
    * @brief This function obtains the coordinates of the top-left pixel in the SnakeFood sprite.
    * @returns Vector2D snakefoodpos @details This is a struct that returns the x and y position of the origin of the snake food sprite to be read.
    */
    Vector2D get_pos();

    /**
    * @brief This function is used to change the position of the sprite to specific coordinates when called.
    * @param Vector2D p @details Stores the values from the struct obtained as the new coordinates of the food.
    */
    void set_pos(Vector2D p);
    
    Vector2D velocity; //This is a struct that stores the x and y axis velocities of the snakefood.

private:
    int reset; //reset is used to draw a new set of food.
    int _fx;  //food x
    int _fy;  //food y
    
    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;

};
#endif