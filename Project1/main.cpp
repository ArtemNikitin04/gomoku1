#include <exception>

#include "Board.hpp"
#include "BoardView.hpp"

int main()
{
	try
	{
		int n;
		std::cin >> n;
		Board board(n);
		BoardView board_view(board);
		board_view.run();
	}
	catch (const std::exception& ex)
	{
		// logging
	}
	catch (...)
	{
		// logging unknown exception
	}
	return 0;
}