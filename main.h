#ifndef MAIN_H
#define MAIN_H

/** @file main.h
 *  @brief Main.cpp's header file that defines all the directives and objects to use along with the definition of it's own function prototypes.
 *  @author Ahmed N.Adamjee
 *  @date 9th May 2019
 */
 
///////////// MAIN.H ////////////////

///////// pre-processor directives ////////
#include "mbed.h"
#include "Gamepad.h"
#include "N5110.h"
#include "FXOS8700CQ.h"
#include "StartScreen.h"
#include "SnakevsBlock.h"
#include "SDFileSystem.h"

#ifdef TEST_SNAKE
# include "tests.h"
#endif

/////////////// objects ///////////////
N5110 lcd(PTC9,PTC0,PTC7,PTD2,PTD1,PTC11);
Gamepad pad;
FXOS8700CQ device(I2C_SDA,I2C_SCL);
StartScreen _start;
Stats _stats;
SnakevsBlock _game;
AnalogIn noisy(PTB0); //This creates a random noise which I can use to seed the random numbers.
// Connections to SD card holder on K64F (SPI interface)
SDFileSystem sd(PTE3, PTE1, PTE2, PTE4, "sd"); // MOSI, MISO, SCK, CS
//Serial serial(USBTX, USBRX);  // for PC debug


//Constants//
int fps = 40;  // frames per second, this will be changed in menu.
int g_mode = 1; //selects between joystick and motion control.
int back; //this allows us to use the back key to exit the game loop;
 
 
///////////// prototypes //////////////
/**
* @brief Initialises main.cpp and all the libraries and classes used.
*/
void init();

/**
* @brief Calls functions using class objects to display menu.
*/
void menu();

/**
* @brief Constantly reads and writes stats from and to the SD card.
*/
void read_write_stats();

/**
* @brief Sets game mode and game speed into snakevsblocks class by reading these from startscreen.
*/
void _set_mode_speed();

/**
* @brief This is executed when the player starts the game.
*/
void gameLoop();

/**
* @brief Refreshes display and draws game objects using snakevsblock class.
*/
void refresh_game();

//void deinit();

#endif