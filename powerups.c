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
#include "powerups.h"


extern unsigned short level;

int powerUpReached(Character * hunterPtr, Character* preyPtr)
{
	return(areCharctersAtSamePosition(hunterPtr, preyPtr));
}


void computePowerUp(unsigned int *coolDownDecreasePtr, unsigned int *powerUpInitialCoolDownPtr)
{
	*coolDownDecreasePtr = 200-(level/2-1)*10;
	*powerUpInitialCoolDownPtr = 200+(level/2-1)*10;
}

int computeGunInitialCoolDown(void)
{
	if(level<=4)
		return 250; // TODO: fix this
	else
		return 250 + level * 10;
}

