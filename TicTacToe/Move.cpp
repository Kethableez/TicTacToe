#include "Move.h"

std::istream& operator >> (std::istream& stream, Move& move) {
	std::cout << "Move row: ";
	stream >> move.row;
	if (!stream) {
		stream.setstate(std::ios::failbit);
		return stream;
	}

	std::cout << "Move col: ";
	stream >> move.col;
	if (!stream) {
		stream.setstate(std::ios::failbit);
		return stream;
	}

	return stream;
}

std::ostream& operator << (std::ostream& stream, Move& move) {
	stream << "Row: " << move.row << " \nCol: " << move.col << "\n";
	return stream;
}