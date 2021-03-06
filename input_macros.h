/*****************************************************************************/
/*                                                                           */
/*                                		                                     */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2017      Fabrizio Caruso                                  		     */
/*                					                                         */
/*              				                                             */
/* EMail:        Fabrizio_Caruso@hotmail.com                                 */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/

#include <conio.h>
#include <joystick.h>

#define IF_KEYBOARD_HIT if(kbhit())
	
#define GET_CHAR() cgetc();

#define WAIT_JOY1_OR_KEY_PRESS() 	while(!kbhit() && !joy_read(JOY_1)) {if(kbhit()) cgetc();} 

#define WAIT_JOY1_PRESS() while(!joy_read(JOY_1)){}

#define WAIT_JOY2_PRESS() while(!joy_read(JOY_2)){}

#define WAIT_KEY_PRESS() {while(!kbhit()){}; cgetc();};


#if defined (__ATMOS__) || defined(__NES__) 
	#define WAIT_PRESS()
	// TODO: Implement some input support
#elif defined(__C64__) || defined(__C128__) || defined(__VIC20__) 
	#define WAIT_PRESS() WAIT_JOY1_OR_KEY_PRESS();
#elif defined (__PLUS4__) || defined(__C16__) 
	#define WAIT_PRESS() WAIT_KEY_PRESS();
#elif defined(__ATARI__) || defined(__APPLE2__)
	#define WAIT_PRESS() WAIT_JOY1_OR_KEY_PRESS();
#else
	#define WAIT_PRESS() WAIT_KEY_PRESS();
#endif


#define JOY_INSTALL() { joy_load_driver (joy_stddrv); joy_install(joy_static_stddrv); }

#define GET_JOY1() joy_read (JOY_1);

#define GET_JOY2() joy_read (JOY_2);
