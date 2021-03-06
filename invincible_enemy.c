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
 
#include "settings.h"
#include "invincible_enemy.h"

extern unsigned short level;
extern unsigned int loop;

int computeInvincibleCountDown(void)
{
	return 125 - level*5;
}


int computeInvincibleSlowDown(void)
{
	if(loop<1000)
	{
		return 32000 - (level/2+1) * 1000 - loop/2 - 1000;
	}
	else if(loop<11000)
	{
		return 32000 - level * 1000 - loop;
	}
	return 0; // You must die!
}

int computeInvincibleGhostCountTrigger(void)
{
	if(level<=7)
		return level/2 + 1;
	else
		return 5;
}

int computeInvincibleLoopTrigger(void)
{
	if(level==FINAL_LEVEL)
		return 50;
	else if (level==FINAL_LEVEL - 1)
		return 250;
	else if (level==FINAL_LEVEL - 2)
		return 500;
	else
		return 1000 - level*20;
}

