#include "pch.h"
#include <iostream>
#include "Board.h"
#include "Player.h"

Board board;
Player player;

int main()
{
    ::srand(static_cast<unsigned>(time(nullptr)));
    board.Init(25, &player);
    player.Init(&board);

    uint64 lastTick = 0;
    while (true)
    {
#pragma region 프레임 관리
        const uint64 currentTick = ::GetTickCount64();
        const uint64 deltaTick = currentTick - lastTick;
        // if (deltaTick < 프레임) continue; // 특정 프레임 이하로 막을 거라면
        lastTick = currentTick;
#pragma endregion

        // 입력

        // 로직
        player.Update(deltaTick);

        // 렌더링
        board.Render();
    }
}