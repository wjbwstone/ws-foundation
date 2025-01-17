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

#include "GlobalHistogramBinarizer.h"

namespace ZXing {

/**
* This class implements a local thresholding algorithm, which while slower than the
* GlobalHistogramBinarizer, is fairly efficient for what it does. It is designed for
* high frequency images of barcodes with black data on white backgrounds. For this application,
* it does a much better job than a global blackpoint with severe shadows and gradients.
* However it tends to produce artifacts on lower frequency images and is therefore not
* a good general purpose binarizer for uses outside ZXing.
*
* This class extends GlobalHistogramBinarizer, using the older histogram approach for 1D readers,
* and the newer local approach for 2D readers. 1D decoding using a per-row histogram is already
* inherently local, and only fails for horizontal gradients. We can revisit that problem later,
* but for now it was not a win to use local blocks for 1D.
*
* This Binarizer is the default for the unit tests and the recommended class for library users.
*
* @author dswitkin@google.com (Daniel Switkin)
*/
class HybridBinarizer : public GlobalHistogramBinarizer
{
public:
	explicit HybridBinarizer(const std::shared_ptr<const LuminanceSource>& source, bool pureBarcode = false);
	~HybridBinarizer() override;

	std::shared_ptr<const BitMatrix> getBlackMatrix() const override;
	std::shared_ptr<BinaryBitmap> newInstance(const std::shared_ptr<const LuminanceSource>& source) const override;

private:
	struct DataCache;
	std::unique_ptr<DataCache> _cache;
};

} // ZXing
