/*
 * Copyright 2022 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "experimental/graphite/src/Sampler.h"

namespace skgpu::graphite {

Sampler::Sampler(const Gpu* gpu) : Resource(gpu, Ownership::kOwned) {}

Sampler::~Sampler() {}

} // namespace skgpu::graphite
