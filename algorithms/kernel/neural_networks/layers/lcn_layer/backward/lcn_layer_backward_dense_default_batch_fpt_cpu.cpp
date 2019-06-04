/* file: lcn_layer_backward_dense_default_batch_fpt_cpu.cpp */
/*******************************************************************************
* Copyright 2014-2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

//++
//  Implementation of local contrast normalization calculation functions.
//--


#include "lcn_layer_backward_batch_container.h"
#include "lcn_layer_backward_kernel.h"
#include "lcn_layer_backward_impl.i"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace lcn
{

namespace backward
{
namespace interface1
{
template class neural_networks::layers::lcn::backward::BatchContainer<DAAL_FPTYPE, defaultDense, DAAL_CPU>;
} // interface1
namespace internal
{
template class LCNKernel<DAAL_FPTYPE, defaultDense, DAAL_CPU>;
} // internal
} // backward

}
}
}
}
}
