//
//
// Created by Steffen Itterheim on 28.09.12.
//
//

#ifndef KoboldKitLibrary_KTTypes_h
#define KoboldKitLibrary_KTTypes_h

/** @file KKTypes.h */

#import "CGPointExtension.h"

/** gid (globally unique tile index) is an unsigned int (32 bit) value */
typedef uint32_t        gid_t;

#if TARGET_OS_IPHONE
typedef UIEvent         KTEvent;
typedef UITouch         KTTouch;
typedef UIView          KTCocoaView;
typedef UIWindow        KTCocoaWindow;
typedef UIResponder		KKResponder;
typedef UIApplication   KTApplication;

#else
typedef NSEvent         KTEvent;
typedef NSTouch         KTTouch;
typedef NSView          KTCocoaView;
typedef NSWindow        KTCocoaWindow;
typedef NSResponder		KKResponder;
typedef NSApplication   KTApplication;
#endif // TARGET_OS_MAC

/** Converts a string to a CGPoint. Same as CGPointFromString/NSPointFromString but works on both platforms. */
static inline CGPoint pointFromString(NSString* pointString)
{
#if TARGET_OS_IPHONE
	return CGPointFromString(pointString);
#else
	return NSPointFromString(pointString);
#endif
}

/** Converts a string to a CGSize. Same as CGSizeFromString/NSSizeFromString but works on both platforms. */
static inline CGSize sizeFromString(NSString* pointString)
{
#if TARGET_OS_IPHONE
	return CGSizeFromString(pointString);
#else
	return NSSizeFromString(pointString);
#endif
}

/** Converts a string to a CGRect. Same as CGRectFromString/NSRectFromString but works on both platforms. */
static inline CGRect rectFromString(NSString* pointString)
{
#if TARGET_OS_IPHONE
	return CGRectFromString(pointString);
#else
	return NSRectFromString(pointString);
#endif
}

#endif
