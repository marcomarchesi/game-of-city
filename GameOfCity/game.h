//
//  game.h
//  GameOfLife
//
//  Created by Marco Marchesi on 12/13/14.
//  Copyright (c) 2014 Marco Marchesi. All rights reserved.
//

#ifndef __GameOfLife__game__
#define __GameOfLife__game__

#include <stdio.h>

namespace game{
    static const int WORLD_SIZE = 20;
    static const int RESIDENTIAL = 1;
    static const int SERVICES = 2;
    static const int GREEN = 3;
    static const int INDUSTRY = 4;
    void init(int array[][WORLD_SIZE]);
    void run(int array[][WORLD_SIZE]);
    void draw(int array[][WORLD_SIZE]);
    int explore(int array[][WORLD_SIZE],int x, int y);
    int exploreCity(int array[][WORLD_SIZE],int x, int y);
}

#endif /* defined(__GameOfLife__game__) */
