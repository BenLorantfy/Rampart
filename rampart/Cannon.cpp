/* ================================================ *
 *											 		*
 * 		FILE 			: Cannon.cpp				*
 * 		PROJECT 		: project					*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-03-01 				*
 * 		DESCRIPTION		: Source for cannon class	*
 *													*
 * ================================================ */

#include <utility> 



using namespace std;

#include "Cannon.h"

Cannon::Cannon(int x, int y, int player){
	this->x = x;
	this->y = y;
	this->player = player;
	firing = false;
	hit = false;
	enabled = true;
}
void Cannon::Aim(int x, int y){
	int cannonX = this->x;
	int cannonY = this->y;

	ballX = cannonX;
	ballY = cannonY;

	destinationX = x;
	destinationY = y;

	distanceX = abs(destinationX - cannonX);
	distanceY = abs(destinationY - cannonY);

	if(distanceX > distanceY){
		step = abs((int)((float)distanceX/(float)(distanceY + 1) + 0.5));
		if(step == 1){
			step = abs((int)((float)distanceX/(float)(distanceY) + 0.5));
		}
	}else if(distanceX == distanceY){
		step = 1;
	}else{
		step = abs((int)((float)distanceY/(float)(distanceX + 1) + 0.5));
		if(step == 1){
			step = abs((int)((float)distanceY/(float)(distanceX) + 0.5));
		}
	}

	StepRemaining = step;
}

pair<int,int> Cannon::NextFrame(void){
	if(distanceX > distanceY){
		StepRemaining--;
		if(StepRemaining == 0){
			StepRemaining = step;
			if(ballY < destinationY){
				ballY++;
			}else if(ballY > destinationY){
				ballY--;
			}
		}
		if(ballX < destinationX){
			ballX++;
		}else if(ballX > destinationX){
			ballX--;
		}else{
			ballY = destinationY;
		}
	}else if(distanceX == distanceY){
		if(ballY < destinationY){
			ballY++;
		}else if(ballY > destinationY){
			ballY--;
		}
		if(ballX < destinationX){
			ballX++;
		}else if(ballX > destinationX){
			ballX--;
		}
	}else{
		StepRemaining--;
		if(StepRemaining == 0){
			StepRemaining = step;
			if(ballX < destinationX){
				ballX++;
			}else if(ballX > destinationX){
				ballX--;
			}
		}
		if(ballY < destinationY){
			ballY++;
		}else if(ballY > destinationY){
			ballY--;
		}else{
			ballX = destinationX;
		}		
	}

	hit = (ballY == destinationY && ballX == destinationX);

	return make_pair(ballX,ballY);
}

bool Cannon::GetFiring(void){
	return firing;
}

void Cannon::SetFiring(bool firing){
	this->firing = firing;
}

bool Cannon::GetHit(void){
	return hit;
}

void Cannon::SetHit(bool hit){
	this->hit = hit;
}

int Cannon::GetBallX(void){
	return ballX;
}

int Cannon::GetBallY(void){
	return ballY;
}

int Cannon::GetPlayer(void){
	return player;
}
	
void Cannon::SetEnabled(bool enabled){
	this->enabled = enabled;
}

int Cannon::GetX(void){
	return x;
}

int Cannon::GetY(void){
	return y;
}

bool Cannon::GetEnabeled(void){
	return enabled;
}
