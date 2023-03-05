#include "Stats.h"

Stats::Stats()
{

}

Stats::~Stats()
{

}

FILE *fp; // this is the file pointer
//serial.baud(115200);  // full-speed!

int LevelBoundary[11][25] = {
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},

};

void Stats::init(N5110 *lcd, Gamepad *pad)
{
    _lcd = lcd;
    _pad = pad;
}

void Stats::StatsDisplay()
{
    _lcd->clear();
    wait(0.2);
    //pad.init();
    while (_pad->check_event(Gamepad::BACK_PRESSED) == false) {  //Change this to if button pressed.
        _lcd->printString("Highest Level",3,0);
        _lcd->printString("Reached~",18,1);
        _lcd->drawSprite(32,22,11,25,(int *)LevelBoundary); //Function used to draw the boundary sprite.
        sprintf(_bufferlevel,"%d",_stored_top_level);
        _lcd->printString(_bufferlevel,38,3); //important to draw after boundary because it needs to overlap the sprite from the centre to be seen.
        _lcd->refresh();
    }
    _lcd->clear();
    _pad->tone(1000.0,0.1);
    /////////////////////// Deleting file ////////////////////////

    // comment this line out if I don't want to delete the file!
    //delete_file("/sd/highestlevel.txt");
}

void Stats::write(int level, SDFileSystem &sd)
{
    //////////////////////  writing to file while reading previous state //////////////////////////

    // open file for writing ('w') - creates file if it doesn't exist and overwrites
    // if it does. If you wish to add a score onto a list, then you can
    // append instead 'a'.

    Stats::read(sd);
    fp = fopen("/sd/highestlevel.txt", "w");
    _current_level = level;
    if (_stored_top_level < _current_level)  {
        _top_level = _current_level;
    }

    else {
        _top_level = _stored_top_level;
    }

    if (fp == NULL) {  // if it can't open the file then print error message
        //serial.printf("Error! Unable to open file!\n");
    } else {  // opened file so can write
        //serial.printf("Writing to file....");
        fprintf(fp, "%d",_top_level); // ensure data type matches
        //serial.printf("Done.\n");
        fclose(fp);  // ensure you close the file after writing
    }


}

void Stats::read(SDFileSystem &sd)
{
    ////////////////////// reading from previous state //////////////////////////

    // now open file for reading
    fp = fopen("/sd/highestlevel.txt", "r");
    _stored_top_level = 0;  // To save level 0 as the default value if game has not been played yet.

    if (fp == NULL) {  // if it can't open the file then print error message
        //serial.printf("Error! Unable to open file!\n");
    } else {  // opened file so can write
        fscanf(fp, "%d",&_stored_top_level); // ensure data type matches - note address operator (&)
        //serial.printf("Read %d from file.\n",stored_top_level);
        fclose(fp);  // ensure you close the file after reading
    }
}

void Stats::delete_file(char filename[])
{
    //serial.printf("Deleting file '%s'...",filename);
    FILE *fp = fopen(filename, "r");  // try and open file
    if (fp != NULL) {  // if it does open...
        fclose(fp);    // close it
        remove(filename);  // and then delete
        //serial.printf("Done!\n");
    }
    // if we can't open it, it doesn't exist and so we can't delete it
}