/* file: zscore_parameter_v2_fpt.cpp */
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

/*
//++
//  Implementation of zscore algorithm and types methods.
//--
*/

#include "zscore_types_v2.h"

using namespace daal::data_management;
using namespace daal::services;

namespace daal
{
namespace algorithms
{
namespace normalization
{
namespace zscore
{

namespace interface2
{
    /** Constructs z-score normalization parameters */
    template<typename algorithmFPType>
    DAAL_EXPORT Parameter<algorithmFPType, defaultDense>::Parameter(const SharedPtr<low_order_moments::BatchImpl> &moments) : BaseParameter(), moments(moments) {};

    /** Constructs z-score normalization parameters */
    template<typename algorithmFPType>
    DAAL_EXPORT Parameter<algorithmFPType, sumDense>::Parameter() : BaseParameter() {};

    /**
    * Check the correctness of the %Parameter object
    */
    template<typename algorithmFPType>
    DAAL_EXPORT Status Parameter<algorithmFPType, defaultDense>::check() const
    {
        DAAL_CHECK(moments.get() != 0, ErrorNullParameterNotSupported);
        return Status();
    }

    template DAAL_EXPORT Parameter<DAAL_FPTYPE, defaultDense>::Parameter(const SharedPtr<low_order_moments::BatchImpl> &moments);
    template DAAL_EXPORT Parameter<DAAL_FPTYPE, sumDense>::Parameter();
    template DAAL_EXPORT Status Parameter<DAAL_FPTYPE, defaultDense>::check() const;

}// namespace interface2

}// namespace zscore
}// namespace normalization
}// namespace algorithms
}// namespace daal
