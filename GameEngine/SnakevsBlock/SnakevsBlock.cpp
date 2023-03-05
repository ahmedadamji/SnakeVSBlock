#include "SnakevsBlock.h"

SnakevsBlock::SnakevsBlock()
{

}

SnakevsBlock::~SnakevsBlock()
{

}

void SnakevsBlock::init(N5110 *lcd, Gamepad *pad)
{
    //POINTING LCD AND PAD ADDRESSES FROM THE MAIN FUNCTION TO THIS CLASS USING _lcd AND _pad//
    _lcd = lcd;
    _pad = pad;

    ////////////OBJECT INITIALISATIONS////////////
    SnakevsBlock::object_initialisations();

    ////////GAME PARM INIT()////////
    _length = _l._getLength(); //saves the snake length into a private variable.
    _s._setLength(_length); //sets the snake length inside the snake class.
    //The level initialisation and all the other initial information passing will be done here
    level = 1;
    _maxLength = 10; // this makes us go to the next level if if maxLength is achieved;

    //this is to allow the user to change the position of reference for motion control by saving the absolute angle.
    garbage = 0;

    //BLOCK DRAW VARIABLES AND INTERFACE PARAMETERS(send_block_number).//
    _dropbuff = 0; //this makes the food fall at diffrent times when a particular level starts.
    send_block_number = false; //this is 0 when there is no collision, thus block number isn't remembered for next set (which would lead to empty blocks).
    blockgap = 300; //this is the number of itterations the block will reccur after in the first level.

    //To make default motion of the snake free.
    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }
}

void SnakevsBlock::reset()
{
    SnakevsBlock::object_initialisations();
    //This prepares the game for the next level by reseting certain variables.
    _dropbuff = 0;
    if(blockgap >= 60) {
        blockgap -= 10;   //to make progressive levels harder by making the blocks drop more frequently.
    }
    //To make default motion of the snake free.
    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }
}

void SnakevsBlock::object_initialisations()
{
    _wl.init(_lcd, _pad); //Win Loose Object initialisation.
    _l.init(_lcd); //length calc object initialisation.
    _s.init(_lcd); //snake object initialisation.
    _f.init(_lcd); //food 1 object initialisation.
    _ff.init(_lcd); //food 2 object initialisation.
    _fff.init(_lcd); //food 3 object initialisation.
    _b.init(_lcd); //block object initialisation.
    _barA.init(_lcd); //barrier A object initialisation.
    _barB.init(_lcd); //barrier B object initialisation.
}

void SnakevsBlock::read_input(FXOS8700CQ &device, int g_mode)
{
    SnakevsBlock::calculateTilt(device);

    switch (g_mode) {
        case 1:
            _d = _pad->get_direction(); //Obtains Direction pushed towards on Joystick.
            break;
        case 2:
            if (_tiltAngle >= 5) { //obtains tilt angle using SnakevsBlock::calculateTilt(device).
                _d = E;
            } else if (_tiltAngle <= -5) {
                _d = W;
            } else {
                _d = CENTRE;
            }
            break;
    }
    SnakevsBlock::lightTheLEDS(); //This function ligths the LEDS dependent on the direction of travel.
    //printf("%d",g_mode);
    //printf("%f",_tiltAngle);
    //printf("%f",device.get_roll_angle());
}

void SnakevsBlock::calculateTilt(FXOS8700CQ &device) //this just reads the angle of tilt required for motion contol and also resets it if A is pressed.
{
    device.get_values();
    _tiltAngle = -device.get_roll_angle();
    //if button A is pressed then reset that particular position to center
    if (_pad->check_event(Gamepad::A_PRESSED) == true)  {
        garbage = _tiltAngle;
    }
    _tiltAngle = -device.get_roll_angle() - garbage; // makes sure that the tilt angle used for calculations is the one subtracted from reference.

    //device.get_values();
    //printf("%f",_tiltAngle);
    //printf("%f",device.get_roll_angle());
}

void SnakevsBlock::lightTheLEDS() //This function ligths the LEDS dependent on the direction of travel.
{
    if (_d == E)  {
        for(int led = 4; led <= 6; led++) {  //Lights 3 LEDs on, on the gamepad from the Right.
            _pad->led(led,1);
        }
    } else if (_d == W)  {
        for(int led = 1; led <= 3; led++) {  //Lights 3 LEDs on, on the gamepad from the Left.
            _pad->led(led,1);
        }
    } else {
        for(int led = 1; led <= 6; led++) {  //Lights all LEDs off, on the gamepad.
            _pad->led(led,0);
        }
    }
}
//This function updates length and motion data inside the snake class and also uses the length manager class to update length.
void SnakevsBlock::updateSnakeLengthAndMovement()
{
    SnakevsBlock::MakeDefaultMotionFree(); //this makes the default motion of the snake freemoving before a collision is checked for, to forget the previous collision.
    _length = _l._getLength(); //saves the snake length into a private variable.
    _s._setLength(_length);
}

void SnakevsBlock::draw()
{
    _s.draw(); //Draws the Snake and sends the value of length to the snake class, which is capped at 10.
    if(_dropbuff >= 0)  {
        _f.draw(); //Draws the first food after a loop delay of 0.
    }
    if(_dropbuff >= 50)  {
        _ff.draw(); //Draws the first food after a loop delay of 50.
    }
    if(_dropbuff >= 80) {
        _fff.draw(); //Draws the first food after a loop delay of 80.
    }
    if(_dropbuff >= 22) {
        _barA.draw(b_pos.y); //Draws the first set of blocks after a loop delay of 8.
    }
    if(_dropbuff >= 45) {
        _barB.draw(b_pos.y); //Draws the first set of blocks after a loop delay of 8.
    }
    if(_dropbuff >= 8) {
        _b.draw(_length); //Draws the first set of blocks after a loop delay of 8.
    }
    _dropbuff +=1;
    //Code to print length of snake on nokia screen.
    _l.print_length_on_screen();
}

void SnakevsBlock::update() //Updates objects on screen.
{
    send_block_number = false;  //this is for the game to decide wether to send the number on the block for the current itteration to the blaocks class.
    //we dont need to remember if it has already gone past the screen. The saved number in this changes if the snake collides with the block in CheckSnakeBlockCollision.

    SnakevsBlock::makeVirtualLengthMaxTen(); //stops the length at 10 for collision and drawing purposes.

    SnakevsBlock::CheckSnakeFoodCollision(); //Function checks for when the snake collides with it's food.
    SnakevsBlock::CheckSnakeBlockCollision(); //Function checks for when the snake collides with any of the blocks.
    SnakevsBlock::CheckSnakeBlockSidesCollision(); //Function checks for when the snake collides with any of the blocks' sides.
    SnakevsBlock::CheckSnakeBarrierCollision(0); //Function checks for when the snake collides with barrier A.
    SnakevsBlock::CheckSnakeBarrierCollision(1); //Function checks for when the snake collides with barrier B.

    _s.update(_d, immobile_bead_n); //_d is the direction of joystick and immobile_bead_n controls the motion of a section of the snake relative to obstruction
    _f.update();
    _ff.update();
    _fff.update();
    _b.update(blocknum, blockgap, srn, send_block_number);
    _barA.update(blockgap);
    _barB.update(blockgap);

}

int SnakevsBlock::CheckGameProgression(SDFileSystem &sd)
{
    //Function handles level progression and level failure operations by using the class WinLoose.
    if(_length == 0)  {
        _wl.GameOver();
    }
    if((_pad->check_event(Gamepad::BACK_PRESSED))||(_length == 0)) { //Waits for Back button to be pressed or the length to reach 0.
        back = 1;
        SnakevsBlock::init(_lcd, _pad);
    } else {
        back = 0;
    }
    //printf("%d\n",_length);
    if(_length >= _maxLength)  {
        _maxLength++; //this statement increases the difficulty of each level by increasing the max length required to achieve to reach the next level.
        level = _wl.LevelComplete(level);
        _Setstats.write(level, sd);
        //_statset.read(sd); //to read the currently stored value.
        SnakevsBlock::reset(); //reset prepares the game for the next level.
    }
    //_statset.read(sd); //to read the currently stored value.
    return back;
}

void SnakevsBlock::get_pos()
{
    //printf("player pos = %f %f \n", player_pos.x, player_pos.y); //top left of player sprite
    // 81.000000 0.000000 top right
    // 0.000000 0.000000 is top left
    // 81.000000 45.000000 bottom right
    snakex = _s.get_pos(0).x; //this could be snake_pos[0].x or simply snake_pos[0] to represent both x&y but as it is used the most, it improves readability.
    snakey = _s.get_pos(0).y; //this could be snake_pos[0].y or simply snake_pos[0] to represent both x&y but as it is used the most, it improves readability.
    //printf("snakexy in GAME = %d %d \n", snakex, snakey);
    //Obtains all required coordinates.
    food_pos[0] = _f.get_pos();
    food_pos[1] = _ff.get_pos();
    food_pos[2] = _fff.get_pos();
    //obtains origin cordinates of block.
    b_pos = _b.get_pos();
    //this saves the positions of each snake beed (the first to the last) in a single array. Element[0] is the top beed and soo on.
    for(int i = 0; i <= 9; i++)  {
        snake_pos[i] = _s.get_pos(i); //gets the position of the each beed from the snake class and saves in array.
    }
    bar_pos[0] = _barA.get_pos(); //gets the position of the barrier A's origin from barriers class and saves in array.
    bar_pos[1] = _barB.get_pos(); //gets the position of the barrier B's origin from barriers class and saves in array.
}


void SnakevsBlock::CheckSnakeFoodCollision()
{
    //If statements check if the snake sprite has collided with any
    //of the three food sprites, if so then the food location is reset and
    //length of the snake is increased using the length variable.

    for(int food_sr=0; food_sr<=2; food_sr++)  {    //this loop runs 3 times to detect collision with all the three food objects.
        SnakevsBlock::CheckSnakeFoodYCollision(food_sr);
    }

    _f.set_pos(food_pos[0]); //to reset the food position after collision
    _ff.set_pos(food_pos[1]); //to reset the food position after collision
    _fff.set_pos(food_pos[2]); //to reset the food position after collision
}

void SnakevsBlock::CheckSnakeFoodYCollision(int food_sr)
{
    for(int y=0; y<=2; y++)  {    //this loop automatically detects for each collision of food and snake in the y axis.

        if(
            ((snakey + y == food_pos[food_sr].y) ||
             (snakey + y == food_pos[food_sr].y + 1) ||
             (snakey + y == food_pos[food_sr].y + 2))
        ) {
            SnakevsBlock::CheckSnakeFoodXCollision(food_sr); //checks X collision only if Y collisison satisfies.
        }
    }

}

void SnakevsBlock::CheckSnakeFoodXCollision(int food_sr)
{

    for(int x=0; x<=2; x++)  {  //this loop automatically detects for each collision of food and snake in the x axis.
        if(
            ((snakex + x == food_pos[food_sr].x) ||
             (snakex + x == food_pos[food_sr].x + 1) ||
             (snakex + x == food_pos[food_sr].x + 2))
        ) {
            SnakevsBlock::ImplementSnakeFoodCollision(food_sr);
        }

    }

}

void SnakevsBlock::ImplementSnakeFoodCollision(int food_sr)
{
    //printf("snake feast working \n");
    //audio feedback
    _pad->tone(786.0,0.1);
    _l.PlusLength();

    ////////////RESET FOOD POSITION////////////
    food_pos[food_sr].x = (rand() % 82);  //this makes the food pop up at a random, unspecified location in the x axis.
    food_pos[food_sr].y = -3;

}

void SnakevsBlock::CheckSnakeBlockCollision()
{
    //Obtains the numbers inside the block.
    b_number = _b.get_number();
    //If statements check if the snake sprite has collided with any
    //of the blocks which are a maximum of 5, if so then the snake length reduces and the block number reduces
    //the block has to move slower and come down after every 2/3 iterations(dependent on the snake size.(think about this)
    for(int block=0; block<=83; block+=1)  {    //this loop automatically detects for each section of block and each combination of collision
        if (
            ((snakey == b_pos.y + 11)||
             (snakey == b_pos.y + 10)||
             (snakey == b_pos.y + 9)||
             (snakey == b_pos.y + 8))&&
            (snakex + 1 == b_pos.x + block)
        )  {
            //the or for the block's y position is due to the fact the exact y co-ordinate might not be collided if the snake's length has increased in the same itteration.
            //printf("snake collision working \n");
            //audio feedback
            srn = CheckCollidingBlock(block);  //this tells us which of the 5 blocks we are colliding with
            blocknum = b_number[srn]; //this saves the number inside the colliding block into blocknum.
            ImplementSnakeBlockCollision(); //this implements the collision once the conditions are met.
            SnakevsBlock::_setVelocity(srn); //sets the block and foods free or frezes them depending on snake length.
        }
    }
}

int SnakevsBlock::CheckCollidingBlock(int block)
{
//This gets the value of int block from the loop in SnakevsBlock::CheckSnakeBlockCollision() and compares it to some preset ranges, and sees which sr num
//should be allocated to it concidering there are 5 blocks numbered 0-4 from right to left, and this identifies the relevant block due to its x axis positions.
    int srn;
    if((block>=0)&&(block<=18))  {
        srn = 0;
    }
    if((block>=19)&&(block<=34))  {
        srn = 1;
    }
    if((block>=35)&&(block<=50))  {
        srn = 2;
    }
    if((block>=51)&&(block<=66))  {
        srn = 3;
    }
    if((block>=67)&&(block<=83))  {
        srn = 4;
    }
    return srn;
}

void SnakevsBlock::_setVelocity(int srn)
{
    if((_length>=10)&&(b_number[srn]>0)) { //this makes the block stop moving down if it's length is more than 10 and still collides.
        velocity = 0; //the block and food have to stop as if length of snake is 15 and it reaches 10 one by one, it stays at the same place, as max virtual length
    } else {          //is 10.
        velocity = 1;
    }
    //Send velocities set to related classes.
    _b.velocity.y = velocity;
    _f.velocity.y = velocity;
    _ff.velocity.y = velocity;
    _fff.velocity.y = velocity;
    _barA.velocity.y = velocity;
    _barB.velocity.y = velocity;
}

void SnakevsBlock::ImplementSnakeBlockCollision()
{
    send_block_number = true;
    if(blocknum > 0)  {  // to make sure that snake doesn't decrease in _length if number on the block is less than 1;
        _l.MinusLength(); //instructs the length manager class to subtract the length by 1.
        _pad->tone(432.0,0.1);
        wait(0.04); //The wait here makes the player feel that they have enough time to slide away and avoid collision.
    }
    blocknum-=1;
}

void SnakevsBlock::CheckSnakeBlockSidesCollision()
{
    //If statements check if the snake sprite has collided with any
    //of the blocks' sides and then stop the snake moving in x axis

    for(int i=0; i<=9; i++)  {  //i creats indexes for all possible collisions with the snake respective to it's length.
        SnakevsBlock::CheckSnakeBlockSidesYCollision(i); //checks if the snake and the block are at the same position in y axis.
    }

}

void SnakevsBlock::MakeDefaultMotionFree()  //this makes the default motion of the snake freemoving before a collision is checked for, to forget the previous collision.
{
    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }
}

void SnakevsBlock::CheckSnakeBlockSidesYCollision(int i)  //i is the index of the snake beed and checks for all possible collisions with the snake respective to it's length.
{
    //This code checks if the snake and the block overlap in the Y axis.
    for(int Y=0; Y<=10; Y++)  { //this carries out the next stage if the Y axis collision criterion is met.
        if (
            (snake_pos[i].y == b_pos.y + Y) ||
            (snake_pos[i].y + 1 == b_pos.y + Y) ||
            (snake_pos[i].y + 2 == b_pos.y + Y))  {

            SnakevsBlock::CheckSnakeBlockSidesXCollision(i); //checks if the snake and the block are at the same position in x axis.

        }
    }
}

void SnakevsBlock::CheckSnakeBlockSidesXCollision(int i)  //i is the index of the snake beed and checks for all possible collisions with the snake respective to it's length.
{
    for(int X=3; X<=83; X+=16)  { //this creates a loop in which each barrier is checked for in each loop using the following functions, by running loops
        //in relation to where the sides of the blocks are situated in the X axis.

        SnakevsBlock::CheckSnakeBlockSidesEastWestCollision(X, i); //checks if the colliding wall is on east side or west side.
        //X is sent because every barrier is in a diffrent position and W/E collision happen at either side of these and therefore cannot have a common X collision.
    }
}

void SnakevsBlock::CheckSnakeBlockSidesEastWestCollision(int X, int i) //i checks for all possible collisions with the snake respective to it's length.
{
    //For West side of walls
    if(
        ((snake_pos[i].x == X + 1) ||  //W
         (snake_pos[i].x + 1 == X + 1))&&(_d != E)&&(_virtualLength > i) //W
    ) {
        SnakevsBlock::ImplementBarrierCollision(i);
    }
    //for East side of walls
    else if (
        ((snake_pos[i].x + 1 == X - 1) ||  //E
         (snake_pos[i].x + 2 == X - 1))&&(_d != W)&&(_virtualLength > i) //E
    ) {
        SnakevsBlock::ImplementBarrierCollision(i);
    }
}


void SnakevsBlock::CheckSnakeBarrierCollision(int bar_sr_no) //bar_sr_no is the index of which barrier collision we are detecting.
{
    //If statements check if the snake sprite has collided with any
    //of the barrier's sides and then stop the snake moving in x axis

    for(int i=0; i<=9; i++)  { //i creats indexes for all possible collisions with the snake respective to it's length.
        SnakevsBlock::CheckSnakeBarrierYCollision(i, bar_sr_no); //checks if the snake and the block are at the same position in y axis.
    }

}

void SnakevsBlock::CheckSnakeBarrierYCollision(int i, int bar_sr_no)  //i is the index of the snake beed and checks for all possible collisions with the snake respective to it's length.
{
    //This code checks if the snake and the block overlap in the Y axis.
    for(int Y=0; Y<=21; Y++)  { //this runs for 22 itterations because the barrier is 22 pixels long and we want to check for each pixel.
        if (
            (snake_pos[i].y == bar_pos[bar_sr_no].y + Y) ||
            (snake_pos[i].y + 1 == bar_pos[bar_sr_no].y + Y) ||
            (snake_pos[i].y + 2 == bar_pos[bar_sr_no].y + Y)
        )  {
            SnakevsBlock::CheckSnakeBarrierEastWestCollision(i, bar_sr_no); //checks if the colliding barrier is on east side or west side.

        }
    }
}

void SnakevsBlock::CheckSnakeBarrierEastWestCollision(int i, int bar_sr_no) //i checks for all possible collisions with the snake respective to it's length.
{
    //bar_pos[0].x and bar_pos[1].x are used to confirm collision of snake with the barriers in the X axis.
    //For West side of walls
    if(
        ((snake_pos[i].x == bar_pos[bar_sr_no].x + 1) ||  //W
         (snake_pos[i].x + 1 == bar_pos[bar_sr_no].x + 1))&&(_d != E)&&(_virtualLength > i) //W
    ) {
        SnakevsBlock::ImplementBarrierCollision(i);
    }
    //for East side of walls
    else if (
        ((snake_pos[i].x + 1 == bar_pos[bar_sr_no].x - 1) ||  //E
         (snake_pos[i].x + 2 == bar_pos[bar_sr_no].x - 1))&&(_d != W)&&(_virtualLength > i) //E
    ) {
        SnakevsBlock::ImplementBarrierCollision(i);
    }
}


////////////////////////////USED FOR BOTH BLOCK SIDES COLLISION AND BARRIER COLLISION////////////////////////////

//Also used to send length to snake class as the max length drawn must also be 10
void SnakevsBlock::makeVirtualLengthMaxTen()
{
    //this makes the virtual length -> 10 for the side collision implementation because if the length is fifteen and the last beed collides, it still is the 10th beed
    //on screen.
    _virtualLength = _length;
    if(_length >= 10) {
        _virtualLength = 10;   //to stop the snake length virtually at 10 when it goes past it.
    }
}
//Implements both SnakeBlockSides and SnakeBarrier Collisions.
void SnakevsBlock::ImplementBarrierCollision(int i) //i is the index of the snake beed and checks for all possible collisions with the snake respective to it's length.
{
    //code makes sure that the colliding part doesn't move in x axis.
    for(int snake_beed_num=0; snake_beed_num<=10; snake_beed_num++)  {
        if(_virtualLength == snake_beed_num + i)  {
            immobile_bead_n[snake_beed_num - 1] = 0;
        }
    }
}