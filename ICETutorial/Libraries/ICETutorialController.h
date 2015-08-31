//
//  ICETutorialController.h
//  ICETutorial
//
//  Created by Patrick Trillsam on 25/03/13.
//  Copyright (c) 2014 https://github.com/icepat/ICETutorial. All rights reserved.
//

@import UIKit;
#import "ICETutorialPage.h"
#import "ICETutorialStyle.h"

@class ICETutorialController;

#define TUTORIAL_LABEL_TEXT_COLOR               [UIColor whiteColor]
#define TUTORIAL_LABEL_HEIGHT                   45
#define TUTORIAL_TITLE_FONT                     [UIFont fontWithName:@"Helvetica-Bold" size:17.0f]
#define TUTORIAL_TITLE_LINES_NUMBER             1
#define TUTORIAL_TITLE_OFFSET                   180
#define TUTORIAL_SUB_TITLE_FONT                 [UIFont fontWithName:@"Helvetica" size:15.0f]
#define TUTORIAL_SUB_TITLE_LINES_NUMBER         2
#define TUTORIAL_SUB_TITLE_OFFSET               150

// Scrolling state.
typedef NS_OPTIONS(NSUInteger, ScrollingState) {
    ScrollingStateAuto      = 1 << 0,
    ScrollingStateManual    = 1 << 1,
    ScrollingStateLooping   = 1 << 2,
};

typedef void (^ButtonBlock)(UIButton * __nonnull button);

@protocol ICETutorialControllerDelegate <NSObject>

@optional

- (void)tutorialController:(ICETutorialController * __nonnull)tutorialController
    scrollingFromPageIndex:(NSUInteger)fromIndex
               toPageIndex:(NSUInteger)toIndex;

- (void)tutorialControllerDidReachLastPage:(ICETutorialController * __nonnull)tutorialController;

- (void)tutorialController:(ICETutorialController * __nonnull)tutorialController
      didClickOnLeftButton:(UIButton * __nonnull)sender;

- (void)tutorialController:(ICETutorialController * __nonnull)tutorialController
     didClickOnRightButton:(UIButton * __nonnull)sender;

@end

@interface ICETutorialController : UIViewController <UIScrollViewDelegate>

@property (nonatomic, assign, readwrite) BOOL autoScrollEnabled;
@property (nonatomic, weak, readwrite, nullable) id<ICETutorialControllerDelegate> delegate;

// Buttons
@property (nonatomic, strong, readwrite, nonnull) UIButton *leftButton;
@property (nonatomic, strong, readwrite, nonnull) UIButton *rightButton;

#pragma mark - Initialize

- (nonnull instancetype)initWithPages:(NSArray * __nonnull)pages;
- (nonnull instancetype)initWithPages:(NSArray * __nonnull)pages
                     delegate:(id<ICETutorialControllerDelegate> __nullable)delegate;
- (nonnull instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder;

#pragma mark - Setup

// Pages management.
- (void)setPages:(NSArray * __nonnull)pages;
- (NSUInteger)numberOfPages;

// Scrolling.
- (void)startScrolling;
- (void)stopScrolling;

// State.
- (ScrollingState)getCurrentState;

#pragma mark - IBAction

/**
 *  Override this method in order to catch button 1 on click event
 *
 *  @param sender An instance of UIButton class
 */
- (IBAction)didClickOnButton1:(UIButton * __nonnull)sender;

/**
 *  Override this method in order to catch button 2 on click event
 *
 *  @param sender An instance of UIButton class
 */
- (IBAction)didClickOnButton2:(UIButton * __nonnull)sender;

@end
