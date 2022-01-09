#pragma once
#include <vector>

enum class CELL_TYPE { NONE, CROSS, CIRCLE };

enum class WIN_TYPE { NONE, CROSS, CIRCLE, DRAW };

class Board
{

	const int size;
	std::vector<std::vector<CELL_TYPE>> field;
	WIN_TYPE game_status;

public:

	Board(int _size) : size(_size)
	{
		field.resize(size);
		for (int i = 0; i < size; ++i)
		{
			field[i].resize(size, CELL_TYPE::NONE);
		}
		game_status = WIN_TYPE::NONE;
	}

	int get_size() const { return size; }

	CELL_TYPE get_cell(int i, int j) const
	{
		return field[i][j];
	}

	bool set_cell(unsigned int i, unsigned int j, CELL_TYPE cell_value)
	{
		if (i < size && j < size && field[i][j] == CELL_TYPE::NONE)
		{
			field[i][j] = cell_value;
			return true;
		}
		else
			return false;
	}
	WIN_TYPE check_win_type()
{
int cnt_any = 0;

int cnt_lx = 0;
int cnt_l0 = 0;
for (int i = 0; i < size; ++i) {
for (int j = 0; j < size; ++j) {
if (get_cell(i, j) == CELL_TYPE::CROSS) {
++cnt_lx;
++cnt_any;
}
else if (get_cell(i, j) == CELL_TYPE::CIRCLE) {
++cnt_l0;
++cnt_any;
}
else {
cnt_lx = 0;
cnt_l0 = 0;
continue;
}

if (j == size-1) {
if (cnt_lx == size)
return WIN_TYPE::CROSS;
else if (cnt_l0 == size)
return WIN_TYPE::CIRCLE;
else if (cnt_any == size*size)
return WIN_TYPE::DRAW;
else {
cnt_lx = 0;
cnt_l0 = 0;
}
}
}
}

cnt_lx = 0;
cnt_l0 = 0;
for (int i = 0; i < size; ++i) {
for (int j = 0; j < size; ++j) {
if (get_cell(j, i) == CELL_TYPE::CROSS)
++cnt_lx;
else if (get_cell(j, i) == CELL_TYPE::CIRCLE)
++cnt_l0;
else {
cnt_lx = 0;
cnt_l0 = 0;
continue;
}

if (j == size-1) {
if (cnt_lx == size)
return WIN_TYPE::CROSS;
else if (cnt_l0 == size)
return WIN_TYPE::CIRCLE;
else {
cnt_lx = 0;
cnt_l0 = 0;
}
}
}
}

cnt_lx = 0;
cnt_l0 = 0;
for (int i = 0; i < size; ++i) {
for (int j = 0; j < size; ++j) {
if (i == j) {
if (get_cell(i, j) == CELL_TYPE::CROSS)
++cnt_lx;
else if (get_cell(i, j) == CELL_TYPE::CIRCLE)
++cnt_l0;
else
continue;
}
}

if (i == size-1) {
if (cnt_lx == size)
return WIN_TYPE::CROSS;
else if (cnt_l0 == size)
return WIN_TYPE::CIRCLE;
}
}

cnt_lx = 0;
cnt_l0 = 0;
for (int i = 0; i < size; ++i) {
for (int j = 0; j < size; ++j) {
if (i == size-j-1) {
if (get_cell(i, j) == CELL_TYPE::CROSS)
++cnt_lx;
else if (get_cell(i, j) == CELL_TYPE::CIRCLE)
++cnt_l0;
else
continue;
}
}

if (i == size-1) {
if (cnt_lx == size)
return WIN_TYPE::CROSS;
else if (cnt_l0 == size)
return WIN_TYPE::CIRCLE;
}
}

return WIN_TYPE::NONE;
}


	WIN_TYPE get_status_game()
	{
		return check_win_type();
	}


};