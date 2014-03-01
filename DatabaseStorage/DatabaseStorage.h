/*
 Copyright (c) 2014, Pierre-Olivier Latour
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 * The name of Pierre-Olivier Latour may not be used to endorse
 or promote products derived from this software without specific
 prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL PIERRE-OLIVIER LATOUR BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <Foundation/Foundation.h>

@interface DatabaseStorage : NSObject
+ (DatabaseStorage*)sharedStorage;
- (id)initWithPath:(NSString*)path;

- (BOOL)writeBackupToPath:(NSString*)path error:(NSError**)error;
- (BOOL)readBackupFromPath:(NSString*)path error:(NSError**)error;

- (void)setValue:(id)value forKey:(NSString*)key;
- (id)valueForKey:(NSString*)key;
- (void)removeValueForKey:(NSString*)key;

- (void)removeAllValues;
@end

@interface DatabaseStorage (Extensions)
- (void)setBool:(BOOL)value forKey:(NSString*)key;
- (BOOL)boolForKey:(NSString*)key;
- (void)setInteger:(NSInteger)value forKey:(NSString*)key;
- (NSInteger)integerForKey:(NSString*)key;
- (void)setDouble:(double)value forKey:(NSString*)key;
- (double)doubleForKey:(NSString*)key;
- (void)setString:(NSString*)value forKey:(NSString*)key;
- (NSString*)stringForKey:(NSString*)key;
- (void)setData:(NSData*)value forKey:(NSString*)key;
- (NSData*)dataForKey:(NSString*)key;
- (void)setObject:(id<NSCoding>)value forKey:(NSString*)key;
- (id<NSCoding>)objectForKey:(NSString*)key;
@end