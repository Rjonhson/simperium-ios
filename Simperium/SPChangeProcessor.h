//
//  SPChangeProcessor.h
//  Simperium
//
//  Created by Michael Johnston on 11-11-15.
//  Copyright (c) 2011 Simperium. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SPProcessorNotificationsNames.h"

@class SPBucket;

@interface SPChangeProcessor : NSObject {
    NSMutableDictionary *changesPending;
    NSMutableSet *keysForObjectsWithMoreChanges;
    NSString *instanceLabel;
}

@property (copy) NSString *instanceLabel;

extern NSString * const CH_KEY;
extern NSString * const CH_ADD;
extern NSString * const CH_REMOVE;
extern NSString * const CH_MODIFY;
extern NSString * const CH_OPERATION;
extern NSString * const CH_VALUE;
extern NSString * const CH_START_VERSION;
extern NSString * const CH_END_VERSION;
extern NSString * const CH_LOCAL_ID;


- (id)initWithLabel:(NSString *)label;
- (void)reset;
- (BOOL)processRemoteResponseForChanges:(NSArray *)changes bucket:(SPBucket *)bucket;
- (void)processRemoteChanges:(NSArray *)changes bucket:(SPBucket *)bucket clientID:(NSString *)clientID;
- (void)processLocalChange:(NSDictionary *)change key:(NSString *)key;
- (NSDictionary *)processLocalObjectWithKey:(NSString *)key bucket:(SPBucket *)bucket later:(BOOL)later;
- (NSDictionary *)processLocalDeletionWithKey:(NSString *)key;
- (int)numChangesPending;
- (int)numKeysForObjectsWithMoreChanges;
- (NSArray *)processPendingChanges:(SPBucket *)bucket onlyQueuedChanges:(BOOL)onlyQueuedChanges;
- (NSArray *)processKeysForObjectsWithMoreChanges:(SPBucket *)bucket;
@end
