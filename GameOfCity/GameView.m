//
//  GameView.m
//  GameOfLife
//
//  Created by Marco Marchesi on 1/23/15.
//  Copyright (c) 2015 Marco Marchesi. All rights reserved.
//

#import "GameView.h"

@implementation GameView

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    CGContextRef myContext = [[NSGraphicsContext // 1
                               currentContext] graphicsPort];
    // ********** Your drawing code here ********** // 2
    CGContextSetRGBFillColor (myContext, 0, 0, 1, .5);// 5
    CGContextFillRect (myContext, CGRectMake (100, 50, 100, 200));
}

@end
