#include "player.h"

point player::attack() {
	//get XY for attack that can be attacked(not miss/hit/-1)
	point attack{0, 0};
	UI::getTurn(this->enemyBoard);
	//set on this->enemyBoard
	return attack;
}

seaField player::getAttacked(point XY) {
	seaField preValue = this->myBoard.getCell(XY), returnable;
	if (preValue == shipBody) {
		this->myBoard.setCell(XY, bodyHit);
		returnable = bodyHit;
		if (this->myShips[shipIndexByXY(XY)].isSunk()) {
			returnable = sunk;
			//surround with misses
		}
	}
	else
		returnable = miss;
	return returnable;
}

bool player::isAlive() {
	
	return true;//temp
}

/*player::player() {

}

player::~player() {

}*/