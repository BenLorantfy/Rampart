/* ================================================ *
 *											 		*
 * 		FILE 			: Game.cpp 			*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source for game class		*
 *													*
 * ================================================ */

#include <mutex>
#include <utility>
#include <Windows.h>

using namespace std;

#include "Matrix.h"
#include "Block.h"

#include "Console.h"
#include "Cannon.h"
#include "Overlay.h"
#include "WallOverlay.h"
#include "Base.h"

#include "Game.h"

Game::Game(int width, int height){
	grid.width(width);
	grid.height(height);

	this->width = width;
	this->height = height;

	maxPlayer1X = (int)((float)width/2 - 5);
	maxPlayer2X = (int)((float)width/2 + 5);

	wallOverlays.resize(2);
	cannonOverlays.resize(2);
	targetOverlays.resize(2);

	startingBases.push_back(-1);
	startingBases.push_back(-1);

	maxWallTypes = 4;

	RefillNumCannons();

	animate = true;
}

void Game::PlaceBase(int x, int y,int player){
	grid.at(x,y) = "baseTopLeft";
	grid.at(x + 1,y) = "baseTopRight";
	grid.at(x,y + 1) = "baseBottomLeft";
	grid.at(x + 1,y + 1) = "baseBottomRight";
	bases.push_back(Base(x, y, player));
	console.DrawBlock(x,y,grid.at(x,y));
	console.DrawBlock(x + 1,y,grid.at(x + 1,y));
	console.DrawBlock(x,y + 1,grid.at(x,y + 1));
	console.DrawBlock(x + 1,y + 1,grid.at(x + 1,y + 1));

	if(startingBases.at(player) == -1){
		startingBases.at(player) = bases.size() - 1;
	}
}

void Game::RefillNumCannons(void){
	numPlayer1Cannons = 3;
	numPlayer2Cannons = 3;
	UpdateCannonDisplay(0);
	UpdateCannonDisplay(1);
}
		
void Game::NewWallOverlay(int player,int x, int y){
	if(player == 1){
		x = maxPlayer2X + 1;
	}

	wallOverlays.at(player) = WallOverlay(x,y,maxWallTypes);
	DrawWallOverlay(player);
}
bool Game::PlaceWallOverlay(int player){
	int wallX = wallOverlays.at(player).GetX();
	int wallY = wallOverlays.at(player).GetY();

	bool obstructed = false;

	for(int x = 0; x < 6; x++){
		for(int y = 0; y < 6; y++){
			if(wallOverlays.at(player).GetShape().at(x,y) == 1){	
				if(grid.at(wallX + x, wallY + y) != "blank"){
					obstructed = true;
					break;
				}
			}
		}
		if(obstructed){
			break;
		}
	}

	if(!obstructed){
				
		for(int x = 0; x < 6; x++){
			for(int y = 0; y < 6; y++){
				if(wallOverlays.at(player).GetShape().at(x,y) == 1){	
					PlaceBlock(wallX + x, wallY + y,Block("wall"));
				}
			}
		}

		//If new type is too big to be placed where old type was (i.e. it would go out of bounds, find a new type)
		do{
			wallOverlays.at(player).RandomizeType(maxWallTypes);
		}while(CanBeCreated(wallOverlays.at(player)) == false);

		MarkEnclourses();
		DrawWallOverlay(player);
	}

	return obstructed;
			
			
}
void Game::DrawWallOverlay(int player){			
	int wallOverlayX = wallOverlays.at(player).GetX();
	int wallOverlayY = wallOverlays.at(player).GetY();

			
	for(int x = 0; x < 6; x++){
		for(int y = 0; y < 6; y++){
			if(wallOverlays.at(player).GetShape().at(x,y) == 1){	
				Block wallOverlayPart;
				if(grid.at(wallOverlayX + x,wallOverlayY + y) != "blank"){
					wallOverlayPart = "blocked";
				}else{
					wallOverlayPart = "wall";
				}
				console.DrawBlock(wallOverlayX + x,wallOverlayY + y, wallOverlayPart);
			}
		}
	}
			
			

}
void Game::ClearWallOverlay(int player){
	int wallOverlayX = wallOverlays.at(player).GetX();
	int wallOverlayY = wallOverlays.at(player).GetY();
			
	for(int x = 0; x < 6; x++){
		for(int y = 0; y < 6; y++){
			if(wallOverlays.at(player).GetShape().at(x,y) == 1){	
				Block wallOverlayPart = grid.at(wallOverlayX + x,wallOverlayY + y);
				console.DrawBlock(wallOverlayX + x,wallOverlayY + y, wallOverlayPart);
			}
		}
	}			
}

void Game::WallOverlayLeft(int player){
	if(CanMoveLeft(wallOverlays.at(player))){
		ClearWallOverlay(player);
		wallOverlays.at(player).MinusX();
		DrawWallOverlay(player);
	}

}
void Game::WallOverlayRight(int player){
	if(CanMoveRight(wallOverlays.at(player))){
		ClearWallOverlay(player);
		wallOverlays.at(player).AddX();
		DrawWallOverlay(player);
	}
}
void Game::WallOverlayUp(int player){
	if(CanMoveUp(wallOverlays.at(player))){
		ClearWallOverlay(player);
		wallOverlays.at(player).MinusY();
		DrawWallOverlay(player);
	}
}
void Game::WallOverlayDown(int player){
	if(CanMoveDown(wallOverlays.at(player))){
		ClearWallOverlay(player);
		wallOverlays.at(player).AddY();
		DrawWallOverlay(player);
	}
}
void Game::WallOverlayRotate(int player){
	if(CanRoate(wallOverlays.at(player))){
		ClearWallOverlay(player);
		wallOverlays.at(player).Rotate();
		DrawWallOverlay(player);
	}
}

bool Game::CanRoate(WallOverlay& overlay){
	bool yesYouCan = true;
	overlay.Rotate();

	int maxX = overlay.GetX() + overlay.GetWidth();
	int maxY = overlay.GetY() + overlay.GetHeight();

	if(maxX > width || (maxX > maxPlayer1X && maxX < width/2)){
		yesYouCan = false;
	}
			
	if(maxY > height){
		yesYouCan = false;
	}
	overlay.Rotate(true);
	return yesYouCan;
}

bool Game::CanBeCreated(WallOverlay& overlay){
	bool yesYouCan = true;
	int maxX = overlay.GetX() + overlay.GetWidth();
	int maxY = overlay.GetY() + overlay.GetHeight();

	if(maxX > width || (maxX > maxPlayer1X && maxX < width/2)){
		yesYouCan = false;
	}
			
	if(maxY > height){
		yesYouCan = false;
	}
	return yesYouCan;
}

void Game::NewCannonOverlay(int player,int x,int y){
	if(player == 1){
		x = maxPlayer2X + 1;
	}
	cannonOverlays.at(player) = Overlay(x,y,2,2);
	DrawCannonOverlay(player);
}

bool Game::HasCannons(int player){
	bool hasCannonsToPlace = false;
	if(player == 0){
		if(numPlayer1Cannons > 0){
			hasCannonsToPlace = true;
		}
	}else{
		if(numPlayer2Cannons > 0){
			hasCannonsToPlace = true;
		}
	}
	return hasCannonsToPlace;
}
		
bool Game::PlaceCannonOverlay(int player){
	bool obstructed = false;
	bool hasCannonsToPlace = HasCannons(player);



	int cannonX = cannonOverlays.at(player).GetX();
	int cannonY = cannonOverlays.at(player).GetY();

	if(hasCannonsToPlace){
		if(
			grid.at(cannonX,cannonY) == "blank" && grid.at(cannonX,cannonY).IsEnclosed() && 
			grid.at(cannonX + 1, cannonY) == "blank" && grid.at(cannonX + 1,cannonY).IsEnclosed() && 
			grid.at(cannonX, cannonY + 1) == "blank" && grid.at(cannonX,cannonY + 1).IsEnclosed() && 
			grid.at(cannonX + 1, cannonY + 1) == "blank" && grid.at(cannonX + 1,cannonY + 1).IsEnclosed()
		){
			grid.at(cannonX,cannonY) = "cannonTopLeft";
			grid.at(cannonX + 1, cannonY) = "cannonTopRight";
			grid.at(cannonX, cannonY + 1) = "cannonBottomLeft";
			grid.at(cannonX + 1, cannonY + 1) = "cannonBottomRight";

			if(player == 0){
				numPlayer1Cannons--;					
			}else{
				numPlayer2Cannons--;
			}

			cannons.push_back(Cannon(cannonX,cannonY,player));
			DrawCannonOverlay(player);

			if(HasCannons(player) == false){
				ClearCannonOverlay(player);
			}

			UpdateCannonDisplay(player);

		}else{
			obstructed = true;
		}
	}

	//return true if place, false otherwise
	return (obstructed && hasCannonsToPlace);
}
		

void Game::DrawCannonOverlay(int player){
	Block cannonTopLeft;
	Block cannonTopRight;
	Block cannonBottomLeft;
	Block cannonBottomRight;

	int cannonX = cannonOverlays.at(player).GetX();
	int cannonY = cannonOverlays.at(player).GetY();

	cannonTopLeft = (grid.at(cannonX,cannonY) != "blank") ? "blocked" : "cannonTopLeft";
	cannonTopRight = (grid.at(cannonX + 1,cannonY) != "blank") ? "blocked" : "cannonTopRight";
	cannonBottomLeft = (grid.at(cannonX,cannonY + 1) != "blank") ? "blocked" : "cannonBottomLeft";
	cannonBottomRight = (grid.at(cannonX + 1,cannonY + 1) != "blank") ? "blocked" : "cannonBottomRight";
			
	console.DrawBlock(cannonX,cannonY, cannonTopLeft);
	console.DrawBlock(cannonX + 1,cannonY, cannonTopRight);
	console.DrawBlock(cannonX,cannonY + 1, cannonBottomLeft);
	console.DrawBlock(cannonX + 1,cannonY + 1, cannonBottomRight);
			
}

void Game::ClearCannonOverlay(int player){
	int cannonX = cannonOverlays.at(player).GetX();
	int cannonY = cannonOverlays.at(player).GetY();

	console.DrawBlock(cannonX,cannonY,grid.at(cannonX,cannonY));
	console.DrawBlock(cannonX + 1,cannonY,grid.at(cannonX + 1,cannonY));
	console.DrawBlock(cannonX,cannonY + 1,grid.at(cannonX,cannonY + 1));
	console.DrawBlock(cannonX + 1,cannonY + 1,grid.at(cannonX + 1,cannonY + 1));
}



void Game::CannonOverlayLeft(int player){
	if(CanMoveLeft(cannonOverlays.at(player))){
		ClearCannonOverlay(player);
		cannonOverlays.at(player).MinusX();
		DrawCannonOverlay(player);
	}
}
void Game::CannonOverlayRight(int player){
	if(CanMoveRight(cannonOverlays.at(player))){
		ClearCannonOverlay(player);
		cannonOverlays.at(player).AddX();
		DrawCannonOverlay(player);
	}
}
void Game::CannonOverlayUp(int player){
	if(CanMoveUp(cannonOverlays.at(player))){
		ClearCannonOverlay(player);
		cannonOverlays.at(player).MinusY();
		DrawCannonOverlay(player);
	}
}
void Game::CannonOverlayDown(int player){
	if(CanMoveDown(cannonOverlays.at(player))){
		ClearCannonOverlay(player);
		cannonOverlays.at(player).AddY();
		DrawCannonOverlay(player);
	}
}

void Game::MarkEnclourses(void){
	vector<pair<int,int> > oldEnclosedBlocks;

	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			if(grid.at(x,y).IsEnclosed()){
				oldEnclosedBlocks.push_back(make_pair(x,y));
			}
			if(grid.at(x,y) != "wall"){
				grid.at(x,y).SetEnclosed();
			}
					
		}
	}

	for(int i = 0; i < width; i++){
		MarkBlock(i,0);
		MarkBlock(i,height - 1);
	}

	for(int y = 0; y < height; y++){
		MarkBlock(0,y);
		MarkBlock(width - 1,y);
	}
			
	for(int i = 0; i < oldEnclosedBlocks.size(); i++){
		int x = oldEnclosedBlocks.at(i).first;
		int y = oldEnclosedBlocks.at(i).second;
		if(grid.at(x,y) == "blank" && grid.at(x,y).IsEnclosed() == false){
			console.DrawBlock(x,y,grid.at(x,y));
		}
				
	}
			
	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			if(grid.at(x,y).IsEnclosed()){
				console.DrawBlock(x,y,grid.at(x,y));
			}
		}
	}

			
}

void Game::MarkBlock(int x, int y){
	if(x >= 0 && x <= width - 1 && y >= 0 && y <= height - 1){
		if(grid.at(x,y) != "wall"){
			if(grid.at(x,y).IsEnclosed()){ 
				grid.at(x,y).SetNotEnclosed(); 
			}
			if(y != 0){
				if(grid.at(x, y - 1).IsEnclosed()){ 
					MarkBlock(x, y - 1); 
				}
			}
			if(y != 0 && x != width - 1){
				if(grid.at(x + 1, y - 1).IsEnclosed()){ 
					MarkBlock(x + 1, y - 1); 
				}
			}
			if(x != width - 1){
				if(grid.at(x + 1, y).IsEnclosed()){
					MarkBlock(x + 1, y); 
				}
			}
			if(x != width - 1 && y != height - 1){
				if(grid.at(x + 1, y + 1).IsEnclosed()){
					MarkBlock(x + 1, y + 1); 
				}
			}
			if(y != height - 1){
				if(grid.at(x, y + 1).IsEnclosed()){
					MarkBlock(x, y + 1); 
				}
			}
			if(x != 0 && y != height - 1){
				if(grid.at(x - 1, y + 1).IsEnclosed()){ 
					MarkBlock(x - 1, y + 1); 
				}
			}
			if(x != 0){
				if(grid.at(x - 1, y).IsEnclosed()){ 
					MarkBlock(x - 1, y); 
				}
			}

			if(x != 0 && y != 0){
				if(grid.at(x - 1, y - 1).IsEnclosed()){ 
					MarkBlock(x - 1, y - 1); 
				}
			}
					
					
					
		}
	}

}



void Game::NewTargetOverlay(int player, int x, int y){
	if(player == 0){
		x = maxPlayer2X + 1;
	}
	targetOverlays.at(player) = Overlay(x,y);
	DrawTargetOverlay(player);
}
		
void Game::TargetOverlayLeft(int player){
	if(CanMoveLeft(targetOverlays.at(player))){
		ClearTargetOverlay(player);
		targetOverlays.at(player).MinusX();
		DrawTargetOverlay(player);
	}
}

void Game::TargetOverlayRight(int player){
	if(CanMoveRight(targetOverlays.at(player))){
		ClearTargetOverlay(player);
		targetOverlays.at(player).AddX();
		DrawTargetOverlay(player);
	}
}

void Game::TargetOverlayUp(int player){
	if(CanMoveUp(targetOverlays.at(player))){
		ClearTargetOverlay(player);
		targetOverlays.at(player).MinusY();
		DrawTargetOverlay(player);
	}
}

void Game::TargetOverlayDown(int player){
	if(CanMoveDown(targetOverlays.at(player))){
		ClearTargetOverlay(player);
		targetOverlays.at(player).AddY();
		DrawTargetOverlay(player);
	}
}

void Game::ClearTargetOverlay(int player){
	int targetX = targetOverlays.at(player).GetX();
	int targetY = targetOverlays.at(player).GetY();

	console.DrawBlock(targetX,targetY,grid.at(targetX,targetY));
}

void Game::DrawTargetOverlay(int player){
	int targetX = targetOverlays.at(player).GetX();
	int targetY = targetOverlays.at(player).GetY();

	console.DrawBlock(targetX,targetY,Block("target"));
}



bool Game::CanMoveLeft(Overlay& overlay){
	return (overlay.GetX() - 1 != maxPlayer2X && overlay.GetX() > 0);
}

bool Game::CanMoveRight(Overlay& overlay){
	return (overlay.GetX() + overlay.GetWidth() != maxPlayer1X && overlay.GetX() + overlay.GetWidth() < width);
}

bool Game::CanMoveUp(Overlay& overlay){
	return (overlay.GetY() > 0);
}

bool Game::CanMoveDown(Overlay& overlay){
	return (overlay.GetY() + overlay.GetHeight() < height);
}

void Game::FireCannon(int player){
	int targetX = targetOverlays.at(player).GetX();
	int targetY = targetOverlays.at(player).GetY();

	for(int i = 0; i < cannons.size(); i++){
		if(cannons.at(i).GetFiring() == false && cannons.at(i).GetPlayer() == player && cannons.at(i).GetEnabeled()){
			cannons.at(i).Aim(targetX,targetY);
			cannons.at(i).SetFiring(true);
			break;
		}
	}
}

void Game::StartAnimations(void){
			
	for(int i = 0; i < cannons.size(); i++){
		int cannonX = cannons.at(i).GetX();
		int cannonY = cannons.at(i).GetY();
				
		cannons.at(i).SetEnabled(grid.at(cannonX,cannonY).IsEnclosed());
	}
			
	animate = true;
}

void Game::FinishAnimations(void){
	animate = false;	
}

void Game::AnimateCannons(void){
	int numFiring = 0;


	//Coordinates of a cannonball at a certain frame in an animation timeline
	int frameX = -1;
	int frameY = -1;

	while(numFiring > 0 || animate){
				
		numFiring = 0;

		for(int j = 0; j < cannons.size(); j++){
			if(cannons.at(j).GetHit()){
				cannons.at(j).SetFiring(false);
				frameX = cannons.at(j).GetBallX();
				frameY = cannons.at(j).GetBallY();
						
				cannons.at(j).SetHit(false);

				if(grid.at(frameX,frameY) == "wall"){
					grid.at(frameX,frameY) = "blank";	
				}

						
				console.DrawBlock(frameX,frameY,grid.at(frameX,frameY));
						
				MarkEnclourses();
			}
			if(cannons.at(j).GetFiring()){
				numFiring++;
			}
		}



		//For each cannon
		for(int i = 0; i < cannons.size(); i++){
			//If cannon is currently being fired, go to next animation frame
			if(cannons.at(i).GetFiring()){
						
				//Clears the block where the cannon ball currently is
				frameX = cannons.at(i).GetBallX();
				frameY = cannons.at(i).GetBallY();
				console.DrawBlock(frameX,frameY,grid.at(frameX,frameY));

				//Gets animation coordinates of next frame of cannon ball
				pair<int,int> frame = cannons.at(i).NextFrame();
				frameX = frame.first;
				frameY = frame.second;

				//Draws the cannonball at the new location
				console.DrawBlock(frameX,frameY,Block("cannonBall"));

				if(animate){
					if(targetOverlays.at(0).GetX() == frameX && targetOverlays.at(0).GetY() == frameY){
						console.DrawBlock(targetOverlays.at(0).GetX(),targetOverlays.at(0).GetY(),Block("target"));
					}

					if(targetOverlays.at(1).GetX() == frameX && targetOverlays.at(1).GetY() == frameY){
						console.DrawBlock(targetOverlays.at(1).GetX(),targetOverlays.at(1).GetY(),Block("target"));
					}
				}


			}
		}

		Sleep(100);


	}

}
	
void Game::ToggleBase(int player){
	int newBase = -1;

	ClearStartBase(startingBases.at(player));

	for(int i = startingBases.at(player) + 1; i < bases.size(); i++){
		if(bases.at(i).GetPlayer() == player){
			newBase = i;
			break;
		}
	}

	if(newBase == -1){
		for(int j = 0; j < bases.size(); j++){
			if(bases.at(j).GetPlayer() == player){
				newBase = j;
				break;
			}
		}
	}


	startingBases.at(player) = newBase;
	DrawStartBase(newBase);
			
}

void Game::DrawFirstStartBase(int player){
	DrawStartBase(startingBases.at(player));
}

void Game::DrawStartBase(int base){
	int x = bases.at(base).GetX();
	int y = bases.at(base).GetY();
			
	int boxX = x - 3;
	int boxY = y - 3;

	for(int i = 0; i < 8; i++){
		grid.at(boxX + i,boxY) = "wall";
		console.DrawBlock(boxX + i,boxY,Block("wall"));

		grid.at(boxX + i,boxY + 7) = "wall";
		console.DrawBlock(boxX + i,boxY + 7,Block("wall"));

		grid.at(boxX,boxY + i) = "wall";
		console.DrawBlock(boxX,boxY + i,Block("wall"));

		grid.at(boxX + 7,boxY + i) = "wall";
		console.DrawBlock(boxX + 7,boxY + i,Block("wall"));
	}

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			grid.at(boxX + 1 + i, boxY + 1 + j).SetEnclosed();
			console.DrawBlock(boxX + 1 + i, boxY + 1 + j,grid.at(boxX + 1 + i, boxY + 1 + j));
		}
	}
}

void Game::ClearStartBase(int base){
	int x = bases.at(base).GetX();
	int y = bases.at(base).GetY();
			
	int boxX = x - 3;
	int boxY = y - 3;

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(grid.at(boxX + i,boxY + j) == "wall"){
				grid.at(boxX + i,boxY + j) = "blank";
			}
			grid.at(boxX + i,boxY + j).SetNotEnclosed();
			console.DrawBlock(boxX + i,boxY + j,grid.at(boxX + i,boxY + j));
		}
	}

}

bool Game::IsPlayerSafe(int player){
	bool safe = false;
	for(int i = 0; i < bases.size(); i++){
		if(bases.at(i).GetPlayer() == player){
			int x = bases.at(i).GetX();
			int y = bases.at(i).GetY();

			if(grid.at(x,y).IsEnclosed()){
				safe = true;
				break;
			}
		}
	}
	return safe;
}
	
void Game::DrawRiver(void){
	for(int i = 0; i < height; i++){
		PlaceBlock(maxPlayer1X,i,Block("leftRiverBank"));
		PlaceBlock(maxPlayer2X,i,Block("rightRiverBank"));
		PlaceBlock(maxPlayer1X + 2,i,Block("river"));
		PlaceBlock(maxPlayer1X + 3,i,Block("river"));
		PlaceBlock(maxPlayer1X + 4,i,Block("river"));
		PlaceBlock(maxPlayer1X + 5,i,Block("river"));
		PlaceBlock(maxPlayer1X + 6,i,Block("river"));
		PlaceBlock(maxPlayer1X + 7,i,Block("river"));
		PlaceBlock(maxPlayer1X + 8,i,Block("river"));
	}
}
		
void Game::DrawTopBar(void){
	console.MoveCursor(0,4);
	for(int i = 0; i < width*2; i++){
		if(i == maxPlayer1X*2 || i == maxPlayer2X*2 + 1){
			printf("%c",197);
		}else{
			printf("%c",196);
		}
				
	}
			
	for(int j = 0; j < 4; j++){
		console.MoveCursor(maxPlayer1X*2,j);
		printf("%c%*s%c",179,20,"",179);
	}

	int player2Origin = maxPlayer2X*2 + 2;

	console.Print(1,1,"Player 1");
	console.Print(player2Origin + 1,1,"Player 2");

	console.Print(1,2,"Territory:");
	console.Print(player2Origin + 1,2,"Territory:");

	console.Print(18,1,"Cannons:");
	console.Print(player2Origin + 18,1,"Cannons:");


	console.Print(width - 4,1,"Time Left:");
			
			
}

void Game::PrintTime(int time){
	int numberWidth = 1;
	int halfNumberWidth = 1;
	char timeString[50] = "";

	if(time > 9){
		numberWidth = 2;
	}
	if(time > 99){
		numberWidth = 3;
	}
	if(time > 999){
		numberWidth = 4;
	}
	halfNumberWidth = (int)(((float)numberWidth)/2);			
	sprintf(timeString,"%*s%d%*s",10 - halfNumberWidth,"",time,5,"");
	console.Print(maxPlayer1X*2 + 1,2,timeString);
}

void Game::UpdateCannonDisplay(int player){
	int start = 0;
	int numCannons = 0;
	int i = 0;
	if(player == 0){
		start = 18;
		numCannons = numPlayer1Cannons;
	}else{
		start = maxPlayer2X*2 + 20;
		numCannons = numPlayer2Cannons;
	}

	console.Print(start,2,"   ");
			
	for(i = 0; i < numCannons; i++){
		console.Print(start + i,2,"C");
	}
}

void Game::WriteStage(string stage){
	console.Print(1,2,"               ");
	console.Print(1,2,stage);

	console.Print(maxPlayer2X*2 + 3,2,"               ");
	console.Print(maxPlayer2X*2 + 3,2,stage);
}

void Game::SetNumWallTypes(int num){
	maxWallTypes = num;
}

void Game::PlaceBlock(int x, int y, Block& block){
	grid.at(x,y) = block;
	console.DrawBlock(x,y,block);
}