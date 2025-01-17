#pragma once
/*
* Copyright 2016 Huy Cuong Nguyen
* Copyright 2016 ZXing authors
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include <string>

namespace ZXing {

class BitArray;

namespace Aztec {

class Token
{
public:
	void appendTo(BitArray& bitArray, const std::string& text) const;

	static Token CreateSimple(int value, int bitCount) {
		return {value, -bitCount};
	}
	
	static Token CreateBinaryShift(int start, int byteCount) {
		return {start, byteCount};
	}

private:
	short _value;
	short _count;	// is simple token if negative, 
	
public:
	Token(int value, int count) : _value((short)value), _count((short)count) {}
};

} // Aztec
} // ZXing
