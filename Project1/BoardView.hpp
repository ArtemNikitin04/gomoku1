#pragma once
#include "Board.hpp"

#include <iostream>

enum class Players { KRESTIK, NOLIK, _COUNT };

class BoardView
{
	Board& board;
	Players current_player;

public:
	BoardView(Board& _board) : board(_board)
	{
		current_player = Players::KRESTIK;
	}

	void run()
	{
		while (board.get_status_game() == WIN_TYPE::NONE)
		{
			system("cls");
			draw();
			input_move();
			current_player = static_cast<Players>((static_cast<int>(current_player)
				+ 1) % static_cast<int>(Players::_COUNT));
		}
		if (board.get_status_game() == WIN_TYPE::CROSS) {
			system("cls");
			draw();
			std::cout << "marta maria won" << std::endl;
			exit(0);
		}
		if (board.get_status_game() == WIN_TYPE::CIRCLE) {
			system("cls");
			draw();
			std::cout << "Mikhail krug won" << std::endl;
			exit(0);
		}
		if (board.get_status_game() == WIN_TYPE::DRAW) {
			system("cls");
			draw();
			std::cout << "Let's do it again" << std::endl;
			exit(0);
		}
		





	}

	void input_move()
	{
		int x, y;
		CELL_TYPE cell_value = CELL_TYPE::NONE;
		do
		{
			
			std::cout << "Enter coords(x,y):" << std::endl;
			std::cin >> y >> x;
			if (current_player == Players::KRESTIK)
				cell_value = CELL_TYPE::CROSS;
			else if (current_player == Players::NOLIK)
				cell_value = CELL_TYPE::CIRCLE;
		} while (board.set_cell(y, x, cell_value) == false);
	}

	void draw()
	{
		int size = board.get_size();
		char cell;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				switch (board.get_cell(i, j))
				{
				case CELL_TYPE::NONE:
					cell = '?';
					break;
				case CELL_TYPE::CROSS:
					cell = 'X';
					break;
				case CELL_TYPE::CIRCLE:
					cell = 'O';
					break;
				default:
					break;
				}
				std::cout << cell;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};