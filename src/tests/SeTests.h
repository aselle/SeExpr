/*
 SEEXPR SOFTWARE
 Copyright 2011 Disney Enterprises, Inc. All rights reserved
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in
 the documentation and/or other materials provided with the
 distribution.
 
 * The names "Disney", "Walt Disney Pictures", "Walt Disney Animation
 Studios" or the names of its contributors may NOT be used to
 endorse or promote products derived from this software without
 specific prior written permission from Walt Disney Pictures.
 
 Disclaimer: THIS SOFTWARE IS PROVIDED BY WALT DISNEY PICTURES AND
 CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE, NONINFRINGEMENT AND TITLE ARE DISCLAIMED.
 IN NO EVENT SHALL WALT DISNEY PICTURES, THE COPYRIGHT HOLDER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND BASED ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
*/
#ifndef _SeTests_h_
#define _SeTests_h_

#include <iostream>

#define SE_TEST_ASSERT(x) \
    if(!(x)) std::cerr<<"Test "<<#x<<" failed at "<<__FILE__<<":"<<__LINE__<<std::endl;


#define SE_TEST_ASSERT_EQUAL(actual,expected)	\
    if((actual) != (expected)) \
        std::cerr<<"Test failed at "<<__FILE__<<":"<<__LINE__\
                 <<" value expected '"<<(expected)<<" got "<<"'"<<(actual)<<"'"<<std::endl;

#define SE_TEST_ASSERT_VECTOR_EQUAL(actual,expected)			\
    if((actual)[0] != (expected)[0])					\
	std::cerr<<"Test failed at "<<__FILE__<<":"<<__LINE__		\
                 <<" first value expected '"<<(expected)<<" got "<<"'"<<(actual)<<"'"<<std::endl; \
    if((actual)[1] != (expected)[1])					\
	std::cerr<<"Test failed at "<<__FILE__<<":"<<__LINE__		\
                 <<" second value expected '"<<(expected)<<" got "<<"'"<<(actual)<<"'"<<std::endl; \
    if((actual)[2] != (expected)[2])					\
	std::cerr<<"Test failed at "<<__FILE__<<":"<<__LINE__		\
                 <<" third value expected '"<<(expected)<<" got "<<"'"<<(actual)<<"'"<<std::endl; \

#endif
