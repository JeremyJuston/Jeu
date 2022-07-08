#include "Cell.hpp"

Cell::Cell() : character(false) {};
Cell::~Cell() {};

bool Cell::isOccupied() {
	return this->character;
}

void Cell::setOccupied(bool occupied) {
	this->character = occupied;
}