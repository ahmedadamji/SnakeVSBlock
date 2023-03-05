#ifndef SNAKE_TEST_H
#define SNAKE_TEST_H

/** @file Snake-test.h
 *  @brief Used to check response of the snake to different kinds of inputs.
 */
 
///////////// prototypes //////////////
 /**
 * @brief Checks that Snake object goes to correct position when moved and/ when collides.
 * @returns true if all the tests passed.
 */
bool Snake_test_movement();

 /**
 * @brief Checks if that the snake gets initialised properly.
 * @returns true if the test passed.
 */
bool check_initialisation();

 /**
 * @brief Checks that when the snake moves west, it updates as expected.
 * @returns true if the test passed.
 */
bool check_west_movement();

 /**
 * @brief Checks that when the snake moves east, it updates as expected.
 * @returns true if the test passed.
 */
bool check_east_movement();

 /**
 * @brief Checks that the snake properly freezes when the immobile_bead_n is disabled for all of them.
 * @returns true if the test passed.
 */
bool check_freeze_movement();

 /**
 * @brief Checks that the snake properly exhibits chain reaction.
 * @returns true if the test passed.
 */
bool check_chain_reaction();

 /**
 * @brief Checks that the snake length reduces accordingly when a block collision is simulated
 * @returns true if the test passed.
 */
bool check_block_collision_and_relative_movement();

 /**
 * @brief Checks that the snake length increases accordingly when a food collision is simulated
 * @returns true if the test passed.
 */
bool check_food_collision_and_relative_movement();

/////////////// objects ///////////////
Snake snake;

//GLOBALS//
Direction d; //represents the direction of movement of the snake.
int immobile_bead_n[10];  //each element in this array represents the beed number in the snake.
bool success_flag; //stores success / failure from a test.


bool Snake_test_movement()
{
    success_flag = true;

    success_flag = check_initialisation();
    success_flag = check_west_movement();
    success_flag = check_east_movement();
    success_flag = check_freeze_movement();
    success_flag = check_chain_reaction();
    success_flag = check_block_collision_and_relative_movement();
    success_flag = check_food_collision_and_relative_movement();

    return success_flag;
}

bool check_initialisation()
{

    // Change Snake to a length of 15, and x axis speed of 2.
    snake._setLength(15);
    snake._setSpeed(2);

    // Set the position to WIDTH/2, HEIGHT - 3

    Vector2D initial_pos = {WIDTH/2, HEIGHT - 3};  //Spawns player sprite near the middle of the screen.
    snake.set_pos(initial_pos);

    // Read the position
    Vector2D read_pos_1 = snake.get_pos(0);
    printf("%f, %f\n", read_pos_1.x, read_pos_1.y);

    // Fail the test if the initial position is wrong
    if (read_pos_1.x != WIDTH/2 || read_pos_1.y != 18) { //18 because I'm testing the position of the first snake beed, from the top.
        success_flag = false;
    }
    return success_flag;
}

bool check_west_movement()
{

    // Set the direction to W and set snake motion free by setting immobile_bead_n as 1;
    d = W;

    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }

    // Update the snake position
    snake.update(d, immobile_bead_n);

    // Read the position
    Vector2D read_pos_2 = snake.get_pos(0); //getting the position of the first beed
    printf("%f, %f\n", read_pos_2.x, read_pos_2.y);

    // Fail the test if the final position after moving West is wrong
    if (read_pos_2.x != ((WIDTH/2)-2) || read_pos_2.y != 18) { //18 because I'm testing the position of the first snake beed, from the top and ((WIDTH/2)-2) because speed is set to 2.
        success_flag = false;
    }
    return success_flag;
}

bool check_east_movement()
{

    // Set the direction to E and set snake motion free by setting immobile_bead_n as 1;
    d = E;

    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }

    // Update the snake position
    snake.update(d, immobile_bead_n);

    // Read the position
    Vector2D read_pos_3 = snake.get_pos(0); //getting the position of the first beed
    printf("%f, %f\n", read_pos_3.x, read_pos_3.y);

    // Fail the test if the final position after moving East is wrong
    if (read_pos_3.x != ((WIDTH/2)) || read_pos_3.y != 18) { //18 because I'm testing the position of the first snake beed, from the top and ((WIDTH/2)) because speed is set to 2
        //and it moves back from its previous position.
        success_flag = false;
    }
    return success_flag;
}

bool check_freeze_movement()
{

    // Set the direction to W, length and speed both to 10 and set snake motion stopped by setting immobile_bead_n as 0 (simulates block sides collision) ;
    d = W;
    snake._setLength(10);
    snake._setSpeed(10);

    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 0;
    }

    // Update the snake position
    snake.update(d, immobile_bead_n);

    // Read the position
    Vector2D read_pos_4 = snake.get_pos(0); //getting the position of the first beed
    printf("%f, %f\n", read_pos_4.x, read_pos_4.y);

    // Fail the test if the final position after moving West but stopping motion using immobile_bead_n[i] = 0; is wrong.
    if (read_pos_4.x != ((WIDTH/2)) || read_pos_4.y != 18) { //18 because I'm testing the position of the first snake beed, from the top and ((WIDTH/2)) because it is not meant to move.
        success_flag = false;
    }
    return success_flag;
}

bool check_chain_reaction()
{

    // Set the direction to W, length to 20 and speed to 2 and set snake motion free by setting immobile_bead_n as 1;
    d = W;
    snake._setLength(20);
    snake._setSpeed(2);

    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }

    // Update the snake position 3 times because i want to read the position of the third bead that only moves with a chain reaction.
    snake.update(d, immobile_bead_n);
    snake.update(d, immobile_bead_n);
    snake.update(d, immobile_bead_n);

    // Read the position
    Vector2D read_pos_5 = snake.get_pos(2); //getting the position of the third beed
    printf("%f, %f\n", read_pos_5.x, read_pos_5.y);

    // Fail the test if the final position of the third beed after moving West and after 3 itterations; is wrong.
    if (read_pos_5.x != ((WIDTH/2)-2) || read_pos_5.y != 24) { //24 because I'm testing the position of the third snake beed, from the top and ((WIDTH/2)) because it is not meant to move.
        success_flag = false;
    }
    return success_flag;
}

bool check_block_collision_and_relative_movement()
{

    // Set the direction to E, length to 8 and set snake motion free by setting immobile_bead_n as 1;
    d = E;
    snake._setLength(8);

    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }

    // Update the snake position 2 times and then reduce length to 7 (this can simulate block collision of number 1).
    snake.update(d, immobile_bead_n);
    snake.update(d, immobile_bead_n);

    snake._setLength(7);
    d = E;//now direction is set to east as it continues to move after collision and then update snake object again.
    snake.update(d, immobile_bead_n);

    // Read the position
    Vector2D read_pos_6 = snake.get_pos(0); //getting the position of the first beed
    printf("%f, %f\n", read_pos_6.x, read_pos_6.y);

    // Fail the test if the final position of the first beed after moving East 3 times and colliding with block numbered 1; is wrong.
    if (read_pos_6.x != ((WIDTH/2)+2) || read_pos_6.y != 27) { //27 because I'm testing the position of the first snake beed of length 8, from the top
        // and colliding once with a block numbered 1, read_pos_6.x = ((WIDTH/2)+2) because the 7th beed from bottom moved only 2 times in effect.
        success_flag = false;
    }
    return success_flag;
}

bool check_food_collision_and_relative_movement()
{

    // Set the direction to W, length to 7 and set snake motion free by setting immobile_bead_n as 1;
    d = W;
    snake._setLength(7);

    for(int i=0; i<=9; i++)  {
        immobile_bead_n[i] = 1;
    }

    // Update the snake position 2 times (2 game  loops) and then increase length to 9 (this can simulate food collision of 2 times).
    snake.update(d, immobile_bead_n);
    snake.update(d, immobile_bead_n);

    snake._setLength(9);
    d = W;//now direction is set to west as it continues to move after food collision and then update snake object again.
    snake.update(d, immobile_bead_n);

    // Read the position
    Vector2D read_pos_7 = snake.get_pos(0); //getting the position of the first beed
    printf("%f, %f\n", read_pos_7.x, read_pos_7.y);

    // Fail the test if the final position of the first beed after moving East 3 times and colliding with block numbered 1; is wrong.
    if (read_pos_7.x != ((WIDTH/2)-4) || read_pos_7.y != 21) { //21 because I'm testing the position of the first snake beed of length 9, from the top
        // and colliding twice with food, read_pos_7.x = ((WIDTH/2)-4) because the current top beed moved same number of times to the top beed before it ate food.
        success_flag = false;
    }
    return success_flag;

}

#endif