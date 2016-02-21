//
//  game.cc
//  GameOfLife
//
//  Created by Marco Marchesi on 12/13/14.
//  Copyright (c) 2014 Marco Marchesi. All rights reserved.
//

#include "game.h"
#include <iostream>

#include <opencv2/opencv.hpp>

namespace game{
    
    void init(int array[][WORLD_SIZE]){
        for(int i = 0;i<WORLD_SIZE;++i){
            for(int j=0;j<WORLD_SIZE;++j){
                array[i][j] = 0;
            }
        }
        array[2][3] = SERVICES;
        array[1][4] = RESIDENTIAL;
        array[3][3] = RESIDENTIAL;
        array[3][2] = RESIDENTIAL;
        array[3][4] = GREEN;
        array[2][5] = INDUSTRY;
        
        array[10][11] = RESIDENTIAL;
        array[9][12] = RESIDENTIAL;
        array[11][12] = RESIDENTIAL;
        array[10][13] = RESIDENTIAL;

        game::draw(array);
        cv::waitKey();
    }
    void run(int array[][WORLD_SIZE]){
        int next_array[WORLD_SIZE][WORLD_SIZE];
        int time = 0;
        do{
            for(int i = 0;i<WORLD_SIZE;++i){
                for(int j=0;j<WORLD_SIZE;++j){
                    next_array[i][j] = explore(array,i,j);
                }
            }
            
            for(int i = 0;i<WORLD_SIZE;++i){
                for(int j=0;j<WORLD_SIZE;++j){
                    array[i][j] = next_array[i][j];
                }
            }
            game::draw(array);
//            cv::waitKey();
          cvWaitKey(20);
            time++;
        }while(time < 100000);
        std::cout<< "GAME OVER!" << std::endl;
    }
    
    void draw(int array[][WORLD_SIZE]){
        
        std::vector<cv::Scalar> colors;
        int cell_typology[5] = {0,0,0,0,0};
        
        cv::Scalar null_color = cv::Scalar(0,0,0);
        colors.push_back(null_color);
        cv::Scalar residential_color = cv::Scalar(0,201,238);    //gold
        colors.push_back(residential_color);
        cv::Scalar services_color = cv::Scalar(128,128,0); //teal
        colors.push_back(services_color);
        cv::Scalar green_color = cv::Scalar(0,205,0); //green
        colors.push_back(green_color);
        cv::Scalar industry_color = cv::Scalar(0,0,238); //red
        colors.push_back(industry_color);

        
        
        cv::Mat bg = cv::Mat::zeros(600, 600, CV_8UC3);
        
        for(int i = 0;i<WORLD_SIZE;++i){
            for(int j=0;j<WORLD_SIZE;++j){
                cv::rectangle(bg, cv::Point((600/WORLD_SIZE)*i,(600/WORLD_SIZE)*j), cv::Point((600/WORLD_SIZE)*(i+1),(600/WORLD_SIZE)*(j+1)), colors[array[i][j]],-1,0);
                //counter
                cell_typology[array[i][j]]++;
            }
        }
        std::cout << "R:" << cell_typology[1] << " S:" << cell_typology[2] << " G:" << cell_typology[3] << " I:" << cell_typology[4] << std::endl;
        cv::imshow("Game of Life v1", bg);
    }
    
    int explore(int array[][WORLD_SIZE],int x, int y){
        
        int live_counter = 0;
        
        if(array[x-1][y-1] == 1)
            live_counter++;
        if(array[x-1][y] == 1)
            live_counter++;
        if(array[x-1][y+1] == 1)
            live_counter++;
        if(array[x][y-1] == 1)
            live_counter++;
        if(array[x+1][y-1] == 1)
            live_counter++;
        if(array[x+1][y] == 1)
            live_counter++;
        if(array[x][y+1] == 1)
            live_counter++;
        if(array[x+1][y+1] == 1)
            live_counter++;
        
        if(array[x][y] == 1){   //cell is alive
            if(live_counter>1 && live_counter<4)
                return 1;
            else
                return 0;
        }else{  //cell is dead
            if(live_counter>2)
                return 1;
        }
        return 0;
    }
    
}
