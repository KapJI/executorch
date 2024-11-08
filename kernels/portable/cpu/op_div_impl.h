/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <executorch/kernels/portable/cpu/scalar_utils.h>
#include <executorch/kernels/portable/cpu/util/elementwise_util.h>
#include <executorch/kernels/portable/cpu/util/math_util.h>
#include <executorch/runtime/kernel/kernel_includes.h>
#include <executorch/runtime/platform/assert.h>

namespace torch {
namespace executor {
namespace native {

Tensor& div_out_impl(
    KernelRuntimeContext& ctx,
    const Tensor& a,
    const Tensor& b,
    Tensor& out);

Tensor& div_out_mode_impl(
    KernelRuntimeContext& ctx,
    const Tensor& a,
    const Tensor& b,
    exec_aten::optional<exec_aten::string_view> mode,
    Tensor& out);

Tensor& div_scalar_out_impl(
    KernelRuntimeContext& ctx,
    const Tensor& a,
    const Scalar& b,
    Tensor& out);

Tensor& div_scalar_mode_out_impl(
    KernelRuntimeContext& ctx,
    const Tensor& a,
    const Scalar& b,
    exec_aten::optional<exec_aten::string_view> mode,
    Tensor& out);
} // namespace native
} // namespace executor
} // namespace torch
