//
//  AppDelegate.m
//  GoLf
//
//  Created by Marco Marchesi on 12/13/14.
//  Copyright (c) 2014 Marco Marchesi. All rights reserved.
//

#import "AppDelegate.h"
#import "game.h"


@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    int game_array[game::WORLD_SIZE][game::WORLD_SIZE];
    game::init(game_array);
    game::run(game_array);
    
}
- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

@end
