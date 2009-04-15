// Copyright (c) 2009 Imageshack Corp.
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 

#import <Foundation/Foundation.h>
#import "TwitterConnectionProtocol.h"
#import "yFrogImageUploader.h"
#import "MGConnectionWrap.h"

@class MGTwitterEngine;
@class MessageUploader;


@protocol MessageUploaderDelegate<NSObject>

- (void)MessageUploadFinished:(BOOL)uploaded  sender:(MessageUploader *)sender;

@end


@interface MessageUploader : NSObject <TwitterConnectionProtocol
													, ImageUploaderDelegate
													, MGConnectionDelegate
										>
{
	BOOL			wasCanceled;
	MGTwitterEngine *_twitter;
	
	NSString* _body;
	int _replyTo;
	NSData* _imageData;	

	id <MessageUploaderDelegate>  _delegate;
	id <TwitterConnectionProtocol>  _connection;
}

- (void)cancel;
- (BOOL)wasCanceled;
- (id)initWithText:(NSString*)text image:(UIImage*)image replayTo:(int)replayTo delegate:(id <MessageUploaderDelegate>)delegate; //call initWithText:imageJPEGData:replayTo:delegate:
- (id)initWithText:(NSString*)text imageJPEGData:(NSData*)JPEGData replayTo:(int)replayTo delegate:(id <MessageUploaderDelegate>)delegate;

- (void) send;

- (void)uploadedImage:(NSString*)yFrogURL sender:(ImageUploader*)sender;

@property (nonatomic, retain) NSString* _body;
@property (nonatomic, retain) NSData* _imageData;

@property (nonatomic, retain) id <TwitterConnectionProtocol> _connection;
@property (nonatomic, retain) id <MessageUploaderDelegate> _delegate;

@end