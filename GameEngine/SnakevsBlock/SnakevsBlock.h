#ifndef SNAKEVSBLOCK_H
#define SNAKEVSBLOCK_H

#include "mbed.h"
#include "N5110.h"
#include "FXOS8700CQ.h"
#include "Gamepad.h"
#include "Snake.h"
#include "LengthManager.h"
#include "WinLoose.h"
#include "SnakeFood.h"
#include "Blocks.h"
#include "Barriers.h"
#include "StartScreen.h"
#include "Stats.h"
#include "SDFileSystem.h"

/** SnakevsBlock Class
@brief This class controls the game by detecting collisions, drawing objects and updating game parameters.
@author Ahmed N.Adamjee
@date 8th May 2019
*/
class SnakevsBlock
{
public:
    /** Constructor */
    SnakevsBlock();
    /** Destructor */
    ~SnakevsBlock();

    /** Initialise Game Machine
    *
    *   This function initialises the game machine.
    */
    /** 
    * @brief Initialises all game parameters and objects and therefore configures the start state of the game.
    * @param N5110 *lcd @details pointer to the N5110 object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    * @param Gamepad *pad @details pointer to the gamepad object in main, address of this pointer is saved to make availability to the entire class, without passing address to each function.
    */
    void init(N5110 *lcd, Gamepad *pad);

    /**
    * @brief This function prepares the game machine for the next level.
    */
    void reset( );

    /**
    * @brief This function initialises the objects that are used to functionalise the game.
    */
    void object_initialisations();

    /**
    *  @brief This function obtains numeric data from the gamepads joystick.
    *  @param FXOS8700CQ &device @details The FXOS8700CQ library.
    *  @parm g_mode @details Contains a value that is used to choose between setting the controls based on joystick or motion control.
    */
    void read_input(FXOS8700CQ &device, int g_mode);

    /**
    *  @brief This function reads the angle of tilt required for motion contol and also processes it by reseting the angle buffer if A is pressed.
    *  @param FXOS8700CQ &device @details The FXOS8700CQ library.
    */
    void calculateTilt(FXOS8700CQ &device);

    /**
    * @brief This function ligths the LEDS dependent on the direction of travel.
    */
    void lightTheLEDS();

    /**
    * @brief This function updates length and motion data inside the snake class and also uses the length manager class to update length.
    */
    void updateSnakeLengthAndMovement();

    /**
    * @brief This function contains the draw functions of the other libraries used in the game.
    */
    void draw();

    /**
    * @brief This function contains the update functions of the other libraries used in the game.
    */
    void update();

    /**
    * @brief Function handles level progression and level failure operations by using the class WinLoose.
    * @param SDFileSystem &sd @details The SDFileSystem library.
    */
    int CheckGameProgression(SDFileSystem &sd);

    /**
    * @brief This function contains the Get Position functions of all the class objects used in the game and saves them to use in an array throughout the class.
    */
    void get_pos();
    
    /**
    * @brief this is to stop/move the background (food and blocks), when collision occurs at a length greater than 10.lock.
    * @param srn @details this is the serial number of blocks and tells us which of the 5 blocks we are colliding with
    */
    void _setVelocity(int srn);
    
    /**
    * @brief This function makes the default motion of the snake freemoving before a collision is checked for, to forget the previous collision.
    */
    void MakeDefaultMotionFree();
    
    /**
    * @brief This makes the virtual length -> 10 for the side collision implementation because if the length is fifteen and the last beed collides, it still is the 10th beed on screen.
    */
    void makeVirtualLengthMaxTen();

private:

    /*
    This function checks if the Snake has come into contact with it's food.
    */
    void CheckSnakeFoodCollision();

    /*
    This function automatically detects each combination of collision in the y postion.
    food_sr -> creted in a loop that runs 3 times to detect collision with all the three food objects.
    */
    void CheckSnakeFoodYCollision(int food_sr);

    /*
    This function automatically detects each combination of collision in the x postion.
    food_sr -> creted in a loop that runs 3 times to detect collision with all the three food objects.
    */
    void CheckSnakeFoodXCollision(int food_sr);

    /*
    This function automatically detects which food we are interacting with and increases the snake length accordingly.
    food_sr -> creted in a loop that runs 3 times to detect collision with all the three food objects.
    */
    void ImplementSnakeFoodCollision(int food_sr);

    /*
    * @brief This function checks if the Snake has come into contact with any Block.
    */
    void CheckSnakeBlockCollision();
    
    /*
    This function returns the srn of the block we are colliding with.
    Block -> value of int block which is compared to a preset ranges, to allocate a serial number to the colliding block.
    */
    int CheckCollidingBlock(int Block);

    /*
    This function allows the appropriate maths to take place after every collision.
    */
    void ImplementSnakeBlockCollision();

    /*
    This function checks if the Snake has come into contact with any the sides of the block and stops it moving.
    */
    void CheckSnakeBlockSidesCollision();

    /*
    This function checks if the Snake and blocks collide anywhere in the Y axis.
    i -> is the index of the snake beed and allows to check for all possible collisions with the snake respective to it's length.
    */
    void CheckSnakeBlockSidesYCollision(int i);

    /*
    This function checks if the Snake and blocks collide anywhere in the X axis.
    i -> is the index of the snake beed and allows to check for all possible collisions with the snake respective to it's length.
    */
    void CheckSnakeBlockSidesXCollision(int i);

    /*
    Checks if the colliding wall is on east side or west side and then calls ImplementBarrierCollision(i) to carry out the required task.
    X -> is just the X axis coordinate of the nokia screen.
    i -> is the index of the snake beed and allows to check for all possible collisions with the snake respective to it's length.
    */
    void CheckSnakeBlockSidesEastWestCollision(int X, int i);

    /*
    This function checks if the Snake has come into contact with any the sides of the barriers and stops it moving in the X axis if true.
    bar_sr_no -> is the index of which barrier collision we are detecting.
    */
    void CheckSnakeBarrierCollision(int bar_sr_no);

    /*
    This function checks if the Snake and blocks collide anywhere in the Y axis.
    i -> is the index of the snake beed and allows to check for all possible collisions with the snake respective to it's length.
    bar_sr_no -> is the index of which barrier collision we are detecting.
    */
    void CheckSnakeBarrierYCollision(int i, int bar_sr_no);  //i is the index of the snake beed and checks for all possible collisions with the snake respective to it's length.
    
    /*
    * Checks if the colliding barrier's side is on east side or west side of snake and then calls ImplementBarrierCollision(i) to carry out the required task.
    * i -> is the index of the snake beed and allows to check for all possible collisions with the snake respective to it's length.
    * bar_sr_no -> is the index of which barrier collision we are detecting.
    */
    void CheckSnakeBarrierEastWestCollision(int i, int bar_sr_no); //i checks for all possible collisions with the snake respective to it's length.

    /*
    This function implements the sides collision by making the x axis speed of the particular snake beed 0.
    i -> is the index of the snake beed and allows to check for all possible collisions with the snake respective to it's length.
    */
    void ImplementBarrierCollision(int i);

    //OBJECT DECLARATIONS.
    Snake _s;
    LengthManager _l;
    WinLoose _wl;
    SnakeFood _f;
    SnakeFood _ff;
    SnakeFood _fff;
    Blocks _b;
    Barriers _barA;
    Barriers _barB;
    Stats _Setstats;

    //Pointer to the game pad object pad.
    Gamepad *_pad;
    //Pointer to the N5110 object lcd.
    N5110 *_lcd;

    //OBJECT POSITIONS ON SCREEN.
    int snakex; //x position of top beed
    int snakey; //y position of top beed
    Vector2D snake_pos[10]; //saves the position of all the snake beeds in an array for ease of collision processing.
    Vector2D food_pos[3]; //saves the position of all 3 snake food on the screen in a single array for ease of collision processing.
    Vector2D b_pos; //saves the origin of the blocks on the screen (this is the top left corner of the block row).
    Vector2D bar_pos[2]; //saves the origin of the barrier on the screen (this is the top left corner of the barrier).

    //LEVEL PROGRESSION, FAILURE AND STATISTICS PARAMETERS.
    int level; // this is diffrent to int _length as this stops at 10 to not complicate collisions as the snake doesn't grow longer than 10 visually.
    char bufferlevel[14];  //this helps me print the level on screen.
    int back; //enables the player to go back on main menu if back is pressed.
    int _maxLength; // this makes us go to the next level if if maxLength is achieved;

    //Block, Food and Barrier Y AXIS VELOCITY, SNAKE LENGTH ,MAX VIRTUAL LENGTH AND VARABLE THAT ALLOWS FREE MOTION OF A SPECIFIC BEED NUMBER OF THE SNAKE.
    int velocity; //this is to stop/move the background (food and blocks), when collision occurs at a length greater than 10.
    int _length; //this is diffrent to the _virtualLength as this saves the length of the snake, for collision detection relative to it's length and calculations.
    int _virtualLength; //saves the length of the snake, for collision detection relative to it's Max screen length.
    int immobile_bead_n[10]; //this array is indexed by the beed number of the colliding snake, if beed 3 from top was colliding with any obstruction, immobile_bead_n[2] will be 1.

    //TURN DIRECTION, TILT ANGLE AND ANGLE RESET BUFFER (GARBAGE).
    Direction _d; //This struct saves the direction of snake movement.
    float _tiltAngle; //saves the angle of tilt.
    int garbage; //to save the angle at the point button A is pressed.

    //BLOCK NUMBERS, BLOCK DROP GAP, BLOCK DETECTION SRN AND VARIABLE TO SEND/NOT BLOCK NUMBER TO BLOCK CLASS
    int *b_number; //pointer to save the numbers inside the block.
    int blocknum; // saves the number inside the specific colliding block, for calculations.
    int blockgap; //to change frequency of fall
    int srn; //sr number of the block we are colliding with (1 to 5)
    bool send_block_number; //makes sure that the block number is only updated when send is activated.

    //INITIAL FOOD AND BLOCK DROP GAP.
    int _dropbuff;  //this makes food 1,2,and 3 come at seperate times
};
#endif