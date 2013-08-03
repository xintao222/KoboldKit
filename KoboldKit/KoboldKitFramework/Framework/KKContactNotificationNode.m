//
//  KKContactNotificationNode.m
//  KoboldKit
//
//  Created by Steffen Itterheim on 02.08.13.
//  Copyright (c) 2013 Steffen Itterheim. All rights reserved.
//

#import "KKContactNotificationNode.h"
#import "SKNode+KoboldKit.h"
#import "KKPhysicsContactEventDelegate.h"
#import "KKTilemapNode.h"

@implementation KKContactNotificationNode

-(void) didMoveToParent
{
	[self createController];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationNotSet:) name:@"<missing notification>" object:self];
}

-(void) willMoveFromParent
{
	[[NSNotificationCenter defaultCenter] removeObserver:self];
}

-(void) notificationNotSet:(NSNotification*)notification
{
	[NSException raise:NSInternalInconsistencyException format:@"contact notification node (%@) received a '<missing notification>' notification (%@)", self, notification];
}

-(void) postNotification
{
	[[NSNotificationCenter defaultCenter] postNotificationName:_notification object:self];
}

-(SKPhysicsBody*) physicsBodyWithTilemapObject:(KKTilemapObject*)tilemapObject
{
	return [self physicsBodyWithRectangleOfSize:tilemapObject.size];
}

-(void) didBeginContact:(SKPhysicsContact*)contact otherBody:(SKPhysicsBody*)otherBody
{
	[self postNotification];
	
	if (_notifyRepeatedly == NO)
	{
		[self removeFromParent];
	}
}

@end