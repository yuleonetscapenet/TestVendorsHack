//
//  QMNative.h
//  QMNative
//
//  Copyright © 2017 Quantum Metric. All rights reserved.
//
//    See the accompanying ATTRIBUTIONS file for open source attributions
//


#import <Foundation/Foundation.h>
@import UIKit;

/**
 * The entry point of the Quantum Metric Native SDK.
 *
 * To get started, import the header file, and call `[QMNative initializeWithSubscription:@"yoursubscription" uid:@"youruid"];`. This method should always be called first. If you're not sure what your subscription name or UID are, contact us.
 *
 * After setup, you can access the QMNative object with `-sharedInstance`, and call other API methods on it. For example: `[[QMNative sharedInstance] sendEventWithID:4 value:@"test value"];`
 */

@interface QMNative : NSObject

/// Your subscription name (i.e., yourcompany.quantummetric.com). Note that you should not modify this value after you've initialized QMNative.
@property(nonatomic, strong) NSString *subscription;
/// Your UID
@property(nonatomic, strong) NSString *uid;

/**
 Access the QMNative singleton object.
 */
+ (id)sharedInstance;

/**
 Call this in the beginning of your `application:didFinishLaunchingWithOptions:` method in your application delegate to initialize Quantum Metric.
 
 @param subscription The subscription name, visible in your Quantum Metric Dashboard.
 @param uid The UID assigned to you in your Quantum Metric Dashboard.
 */
+ (void)initializeWithSubscription:(NSString*)subscription uid:(NSString*)uid;

/**
 For testing your iOS configuration settings before going live, set this to true just after calling `initializeWithSubscription`.
 
 @param testing If this is true, the test configuration will be used. False will use the production configuration.
 */
-(void)enableTestConfig:(BOOL)testing;
+(void)enableTestConfig:(BOOL)testing;

/**
 Send an event
 
 @param eventID The ID of the event to be logged to the server
 @param value The value of the event to be logged to the server
 
 This is the same as calling the below method with flags:0
 */
-(void)sendEventWithID:(NSInteger)eventID value:(NSString*)value;
+(void)sendEventWithID:(NSInteger)eventID value:(NSString*)value;

/**
 Send an event, with a flag
 
 @param eventID The ID of the event to be logged to the server
 @param value The value of the event to be logged to the server
 @param flags The flags for the event to be logged. Only used for special occasions.
 */
-(void)sendEventWithID:(NSInteger)eventID value:(NSString*)value flags:(int)flags;
+(void)sendEventWithID:(NSInteger)eventID value:(NSString*)value flags:(int)flags;

/**
 Send an error
 
 @param errorID The ID of the error to be logged to the server
 @param value The value of the error to be logged to the server
 */
-(void)sendErrorWithID:(NSInteger)errorID value:(NSString*)value;
+(void)sendErrorWithID:(NSInteger)errorID value:(NSString*)value;

/**
 Ties passed in user information to this session.
 
 @param firstName First Name of the user
 */
-(void)setUserFirstName:(NSString*)firstName;
+(void)setUserFirstName:(NSString*)firstName;

/**
 Ties passed in user information to this session.
 
 @param lastName Last Name of the user
 */
-(void)setUserLastName:(NSString*)lastName;
+(void)setUserLastName:(NSString*)lastName;

/**
 Ties passed in user information to this session.
 
 @param email Email address of the user
 */
-(void)setUserEmail:(NSString*)email;
+(void)setUserEmail:(NSString*)email;

/**
 Updates the cart value for this session
 
 @param newCartValueCents The new cart value, in cents, as an NSInteger. A value of 10000 would be $100.00, or 100.00 of whatever currency is associated with that session.
 */
-(void)updateCartValue:(NSInteger)newCartValueCents;
+(void)updateCartValue:(NSInteger)newCartValueCents;


/**
 Indicates that a conversion happened, with the given cart value.
 
 @param convertedCartValueCents The converted cart value, in cents, as an NSInteger. Same as updateCartValue:, but call this after a conversion happened.
 */
-(void)convertedCartValue:(NSInteger)convertedCartValueCents;
+(void)convertedCartValue:(NSInteger)convertedCartValueCents;

/**
 Enables encrption with the given public key. You should call this right after initializeWithSubscription:uid:
 
 @param encryptionKey Public key for encryption.
 */
-(void)enableEncryptionWithKey:(NSString*)encryptionKey;
+(void)enableEncryptionWithKey:(NSString*)encryptionKey;

/**
 Marks a view as private, we don't want the personal data in that view, or any subviews, to leave the device. Note this is a static method, so call [QMNative maskView:yourCoolView];
 
 @param view The view to be masked. It's important to note that this method should be called before the view is added to the visible view hierarchy, otherwise the information in that view will have already been captured.
 */
+(void)maskView:(UIView*)view;

/**
 Marks all views of a certain class as private, we don't want the personal data in that view, or any subviews, to leave the device. Similar to above. An example call might look like [QMNative maskView:[QMAwesomeView class]];
 
 @param viewClass The view class to be masked. It's important to note that this method should be called before any views of this class are added to the visible view hierarchy. A suitable place to call this might be right afer the QMNative init method in your App Delegate.
 */
+(void)maskViewClass:(Class)viewClass;


/**
 Returns this version of the QMNative library
 
 @return Library version in the format of major.minor.patch, like @"1.4.2"
 */
-(NSString*)libraryVersionString;
+(NSString*)libraryVersionString;


/**
 Stops Quantum Metric session recording, if it's already been started
 */
-(void)stopQM;
+(void)stopQM;

/**
 Restarts Quantum Metric session recording, if it's been stopped, with the same session
 */
-(void)restartQM;
+(void)restartQM;

/**
 Ends the current session and starts a new session
 */
-(void)newSession:(BOOL)resetUser;
+(void)newSession:(BOOL)resetUser;

/**
 Opts this user out of Quantum Metric. Note that this opt-out is for this install of the app, if they delete and reinstall, they might have to opt-out again. If your app has some way of keeping track of user opt-out preferences across devices/installs, and you want to insure this setting persists across devices/installs, be sure to call this method if you detect a fresh install (also, you can always check the users opt-in/out status with the userOptStatus method below.
 */
-(void)optUserOut;
+(void)optUserOut;

/**
 Opts this user back into Quantum Metric. Note that you do not need to call this to enable QM in the first place, it's enabled by default. Only call this if a user was previously opted out. On the next app launch, QM will run it's magic.
 */
-(void)optUserBackIn;
+(void)optUserBackIn;

/**
 Returns the current status for user opt in/out. True means that QM is enabled for this user, false means not enabled (false means they opted out).
 */
-(BOOL)userOptStatus;
+(BOOL)userOptStatus;

/**
 Enables you to pass a block that gets called with the QM session cookie and QM user string when a session starts. The callback block will be called on the main thread.
 */
-(void)gotSessionCookieCallback:(void (^)(NSString *sessionCookie, NSString *userString))callback;
+(void)gotSessionCookieCallback:(void (^)(NSString *sessionCookie, NSString *userString))callback;

/**
 By default, your app's name will be used as the browser name in Quantum Metric. If you'd like to customize this, to more easily keep track of variations of an app (i.e. add "production", "dev", "beta") you can do that here. This must be called directly after initializeWithSubscription:uid:
 */
-(void)setBrowserString:(NSString*)browserString;
+(void)setBrowserString:(NSString*)browserString;


/**
 By default, Quantum Metric sets itself as the default crash handler (if QM has started, based on your sampling settings). If you'd like to disable this, call this method right after `initializeWithSubscription`.
 */
-(void)disableCrashReporting;
+(void)disableCrashReporting;


@end
