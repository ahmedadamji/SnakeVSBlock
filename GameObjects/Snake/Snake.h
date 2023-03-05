#ifndef SNAKE_H
#define SNAKE_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Snake Class
@brief This class draws and updates snake after every collision, and creates perfect animations of the snake moving.
@author Ahmed N.Adamjee
@date 9th May 2019
*/
class Snake
{
public:
    /** Constructor */
    Snake();
    /** Destructor */
    ~Snake();

    /**
    * @brief Initialises the snakes position struct and reset variable and gets pointers of lcd from int main() to be used privately in the entire class.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd);

    /**
    * @brief This mutator sets the length of the snake directly when called.
    * @param length @details This is the length of the snake, which is recieved from the SnakevsBlocks class or test files to draw snake with relation to it's length.
    */
    void _setLength(int length);
    
    /**
    * @brief This mutator sets the speed of the snake directly when called.
    * @param speed @details This is the x axis speed of the snake, which is recieved from the SnakevsBlocks class or test files to move snake with respect to joystick or motion control input.
    */
    void _setSpeed(int speed);

    /**
    * @brief This function draws the Snake sprite onto the screen at the specified coordinates.
    */
    void draw();

    /**
    * @brief This function sets a position for where the snake should spawn.
    * @param Vector2D p @details This is a struct that saves the x and y position one of the snake beads during the time of initialisation and sets other snake bead coordinates with respect to this.
    */
    void set_pos(Vector2D p);

    /**
    * @brief This function updates the Snake sprite position on screen.
    * @param Direction d @details This struct saves the direction of snake movement.
    * @param immobile_bead_n[10] @details this array is indexed by the beed number of the colliding snake, if immobile_bead_n[2] = 1 the particular bead can move freely.
    */
    void update(Direction d, int* immobile_bead_n);

    /**
    * @brief This function makes all of the snake beeds chained together by making the lower ones drag towards where the top one was in the previous loop.
    * @param immobile_bead_n[10] @details this array is indexed by the beed number of the colliding snake, if immobile_bead_n[2] = 1 the particular bead can move freely.
    */
    void chainSnakeTogether(int* immobile_bead_n);

    /**
    * @brief This function makes the controls of W/E directions only exclusive to the top beed in the snake.
    * @param immobile_bead_n[10] @details this array is indexed by the beed number of the colliding snake, if immobile_bead_n[2] = 1 the particular bead can move freely.
    */
    void moveSnake(int* immobile_bead_n);

    /**
    * @brief This function makes sure that the snake stays where it is when it ate food and does not travel off the screen.
    */
    void _setSnakeLimits();

    /**
    * @brief This function returns the coordinate of the top-left pixel in the Snake sprite of each bead which is reffered to by snakeIndex.
    * @param int snakeIndex @details This is the index of the snake bead of which the position needs to be returned.
    * @returns Vector2D snakepos @details This is a struct that returns the x and y position of the snake bead that is being referred to by the snakeIndex.
    */
    Vector2D get_pos(int snakeIndex);

    int reset;  //reset is used to re position the snake after each level..
    int immobile_bead_n[10];  //each element in this array represents the beed number in the snake.

private:
    int _speed;  //this is the speed of the snake flowing in the x axis.
    int _x[10];  //each element in this array represents the x position of each beed in the snake.
    int _y[10];  //each element in this array represents the y position of each beed in the snake.
    int _length; //stores thee length of snake to be drawn or managed in terms of structure.
    Direction _d; //Stores the direction the snake moves in.

    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;

};
#endif