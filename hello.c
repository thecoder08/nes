/*
** Fancy hello world program using cc65.
**
** Ullrich von Bassewitz (ullrich@von-bassewitz.de)
**
*/



#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <joystick.h>



/*****************************************************************************/
/*                                   Data                                    */
/*****************************************************************************/



static const char Text [] = "Hello world!";



/*****************************************************************************/
/*                                   Code                                    */
/*****************************************************************************/



int main (void)
{
    unsigned char XSize, YSize;

    /* Set screen colors */
    (void) textcolor (COLOR_WHITE);
    (void) bordercolor (COLOR_RED);
    (void) bgcolor (COLOR_BLUE);

    /* Clear the screen, put cursor in upper left corner */
    clrscr ();

    /* Ask for the screen size */
    screensize (&XSize, &YSize);
    
    /* Write the greeting in the mid of the screen */
    gotoxy ((XSize - strlen (Text)) / 2, YSize / 2);
    cprintf ("%s", Text);

#if defined(__NES__) || defined(__PCE__) || defined(__GAMATE__) || defined(__ATARI5200__)

    /* Wait for the user to press a button */
    joy_install (joy_static_stddrv);
    while (!joy_read (JOY_1)) ;
    joy_uninstall ();

#else

    /* Wait for the user to press a key */
    cgetc ();

#endif

    /* Clear the screen again */
    clrscr ();

    /* Done */
    return EXIT_SUCCESS;
}