#ifndef BLOCKS_H
#define BLOCKS_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Blocks Class
@brief This class draws and updates blocks after every collision, and randomly, but logically assigns numbers to the block.
@author Ahmed N.Adamjee
@date 9th May 2019
*/
class Blocks
{
public:
    /** Constructor */
    Blocks();
    /** Destructor */
    ~Blocks();

    /**
    * @brief Initialises the blocks position struct and reset variable and gets pointers of lcd from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd);

    /**
    * @brief This function draws the blocks onto the screen and selects numbers to be stored in them.
    * @param length @details This is the length of the snake, which is recieved from the SnakevsBlocks class to store numbers with relation to it's length.
    */
    void draw(int length);

    /**
    * @brief This function draws the Block's sides onto the screen as the blocks are basically individual boxes without sides.
    */
    void DrawFrame();

    /**
    * @brief This function chooses the correct block using a case structure and draws them onto the screen.
    */
    void ChooseBlocks();

    /**
    * @brief This function updates the position of the Blocks as they move down the screen by reacting to collisions if any.
    * @param blocknum @details saves the numbers inside the block with respect to it's serial number.
    * @param blockgap @details this is the amount in pixels of the gap between blocks and sets the frequency of block fall.
    * @param srn @details sr number of the block we are refering to (1 to 5).
    * @param send_block_number @details makes sure that the block number is only updated when this is at a logic of 1.
    */
    void update(int blocknum, int blockgap, int srn, bool send_block_number);

    /**
    * @brief This function sends the coordinates of the top-left pixel in the Blocks sprites.
    * @returns Vector2D blockpos @details This is a struct that returns the x and y position of the origin of the blocks sprite to be read.
    */
    Vector2D get_pos();

    /**
    * @brief This function sends the number inside the Blocks sprite at a specefic location.
    * @returns caseselect[5] @details The array of all the numbers saved inside the blocks.
    */
    int * get_number();

    /**
    * @brief This function is used to change the position of the sprite to specific coordinates when called.
    * @param Vector2D p @details Stores the values from the struct obtained as the new coordinates of the block.
    */
    void set_pos(Vector2D p);


    double round; //used to save the rounded number to set the value inside the block.
    int caseselect[5]; //The array of all the numbers saved inside the blocks.
    Vector2D velocity; //This is a struct that stores the x and y axis velocities of the blocks.

private:
    int _length; //length of the snake
    int reset; //reset is used to draw a new set of blocks.
    int _bx;  //block x
    int _by;  //block y

    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;

};
#endif