
// Copyright (c) 2015 Pierre MOULON.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "openMVG/matching_image_collection/Matcher.hpp"

namespace openMVG {
namespace matching_image_collection {

/**
 * @brief Compute putative matches between a collection of pictures.
 *
 * Spurious correspondences are discarded by using the
 * a threshold over the distance ratio of the 2 nearest neighbours.
 *
 * @note: Cascade hashing tables are computed once and used for all the regions.
 * @warning: all descriptors are loaded in memory. You need to ensure that it can fit in RAM.
 */
class ImageCollectionMatcher_CascadeHashing : public IImageCollectionMatcher
{
  public:
  ImageCollectionMatcher_CascadeHashing
  (
    float dist_ratio
  );

  /// Find corresponding points between some pair of view Ids
  void Match(
    const sfm::SfM_Data & sfm_data,
    const features::RegionsPerView& regionsPerView,
    const Pair_Set & pairs,
    features::EImageDescriberType descType,
    matching::PairwiseMatches & map_PutativesMatches // the pairwise photometric corresponding points
  ) const;

  private:
  // Distance ratio used to discard spurious correspondence
  float f_dist_ratio_;
};

} // namespace openMVG
} // namespace matching_image_collection
