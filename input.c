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

#include "character.h"
#include "settings.h"
#include <joystick.h>
#include "display_macros.h"
#include "invincible_enemy.h"

#include "input.h"

extern unsigned short invincibleXCountDown;
extern unsigned short invincibleYCountDown;
extern unsigned short playerDirection;
extern unsigned short playerFire;
extern unsigned short level;

void movePlayerByKeyboard(Character *playerPtr, char kbInput)
{
	if((kbInput=='W') || (kbInput=='w'))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		--playerPtr->_y;
		invincibleYCountDown = computeInvincibleCountDown();
		playerDirection = UP;
	}
	else if((kbInput=='S') || (kbInput=='s'))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		++playerPtr->_y;
		invincibleYCountDown = computeInvincibleCountDown();
		playerDirection = DOWN;
	}
	else if((kbInput=='A') || (kbInput=='a'))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		--playerPtr->_x;
		invincibleXCountDown = computeInvincibleCountDown();
		playerDirection = LEFT;
	}
	else if((kbInput=='D') || (kbInput=='d'))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		++playerPtr->_x;
		invincibleXCountDown = computeInvincibleCountDown();
		playerDirection = RIGHT;
	}
	else 	
	if(kbInput==' ')
	{
		playerFire = 1;
	}

	#ifdef _TRAINER
	else if((kbInput=='Z') || (kbInput=='z'))
	{
		ghostCount = 0;
		SET_TEXT_COLOR(PLAYER_COLOR);
		displayCharacter(playerPtr);
		SET_TEXT_COLOR(TEXT_COLOR);
	}
	#endif // TRAINER
	SET_TEXT_COLOR(PLAYER_COLOR);
	DRAW_PLAYER(playerPtr->_x, playerPtr->_y, playerPtr->_imagePtr);
	SET_TEXT_COLOR(TEXT_COLOR);
}

void movePlayerByJoystick(Character *playerPtr, unsigned char joyInput)
{
	if(JOY_BTN_UP(joyInput))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		--playerPtr->_y;
		invincibleYCountDown = computeInvincibleCountDown();
		playerDirection = UP;
	}
	else if(JOY_BTN_DOWN(joyInput))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		++playerPtr->_y;
		invincibleYCountDown = computeInvincibleCountDown();
		playerDirection = DOWN;
	}
	else if(JOY_BTN_LEFT(joyInput))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		--playerPtr->_x;
		invincibleXCountDown = computeInvincibleCountDown();
		playerDirection = LEFT;
	}
	else if(JOY_BTN_RIGHT(joyInput))
	{
		DELETE_PLAYER(playerPtr->_x,playerPtr->_y,playerPtr->_imagePtr);
		++playerPtr->_x;
		invincibleXCountDown = computeInvincibleCountDown();
		playerDirection = RIGHT;
	}
	else if(JOY_BTN_FIRE(joyInput))
	{
		playerFire = 1;
	}
	SET_TEXT_COLOR(PLAYER_COLOR);
	DRAW_PLAYER(playerPtr->_x, playerPtr->_y, playerPtr->_imagePtr);
	SET_TEXT_COLOR(TEXT_COLOR);
}



