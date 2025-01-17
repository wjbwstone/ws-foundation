#pragma once
/*
* Copyright 2016 Nu-book Inc.
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

namespace ZXing {

class BitMatrix;

namespace QRCode {

/**
* <p>Encapsulates data masks for the data bits in a QR code, per ISO 18004:2006 6.8. Implementations
* of this class can un-mask a raw BitMatrix. For simplicity, they will unmask the entire BitMatrix,
* including areas used for finder patterns, timing patterns, etc. These areas should be unused
* after the point they are unmasked anyway.</p>
*
* <p>Note that the diagram in section 6.8.1 is misleading since it indicates that i is column position
* and j is row position. In fact, as the text says, i is row position and j is column position.</p>
*
* @author Sean Owen
*/
class DataMask
{
public:
	/**
	* @param reference a value between 0 and 7 indicating one of the eight possible
	* data mask patterns a QR Code may use
	* @return DataMask encapsulating the data mask pattern
	*/
	explicit DataMask(int reference);

	/**
	* <p>Implementations of this method reverse the data masking process applied to a QR Code and
	* make its bits ready to read.</p>
	*
	* @param bits representation of QR Code bits
	* @param dimension dimension of QR Code, represented by bits, being unmasked
	*/
	void unmaskBitMatrix(BitMatrix& bits, int dimension) const;

private:
	bool(*_isMasked)(int, int);
};

} // QRCode
} // ZXing
