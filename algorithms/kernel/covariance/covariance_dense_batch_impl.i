/* file: covariance_dense_batch_impl.i */
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
//  Covariance matrix computation algorithm implementation in batch mode
//--
*/

#ifndef __COVARIANCE_CSR_BATCH_IMPL_I__
#define __COVARIANCE_CSR_BATCH_IMPL_I__

#include "covariance_kernel.h"
#include "covariance_impl.i"

#include "service_numeric_table.h"

namespace daal
{
namespace algorithms
{
namespace covariance
{
namespace internal
{

template<typename algorithmFPType, Method method, CpuType cpu>
services::Status CovarianceDenseBatchKernel<algorithmFPType, method, cpu>::compute(
    NumericTable *dataTable,
    NumericTable *covTable,
    NumericTable *meanTable,
    const Parameter *parameter)
{
    algorithmFPType nObservations = 0.0;

    const size_t nFeatures  = dataTable->getNumberOfColumns();
    const size_t nVectors   = dataTable->getNumberOfRows();
    const bool isNormalized = dataTable->isNormalized(NumericTableIface::standardScoreNormalized);

    DEFINE_TABLE_BLOCK( ReadRows,      dataBlock,          dataTable );
    DEFINE_TABLE_BLOCK( WriteOnlyRows, sumBlock,           meanTable );
    DEFINE_TABLE_BLOCK( WriteOnlyRows, crossProductBlock,  covTable  );

    algorithmFPType *sums          = sumBlock.get();
    algorithmFPType *crossProduct  = crossProductBlock.get();
    algorithmFPType *data          = const_cast<algorithmFPType *>(dataBlock.get());

    services::Status status;

    status |= prepareSums<algorithmFPType, method, cpu>(dataTable, sums);
    DAAL_CHECK_STATUS_VAR(status);

    status |= prepareCrossProduct<algorithmFPType, cpu>(nFeatures, crossProduct);
    DAAL_CHECK_STATUS_VAR(status);

    status |= updateDenseCrossProductAndSums<algorithmFPType, method, cpu>(isNormalized, nFeatures,
        nVectors, data, crossProduct, sums, &nObservations);
    DAAL_CHECK_STATUS_VAR(status);

    status |= finalizeCovariance<algorithmFPType, cpu>(
        nFeatures, nObservations, crossProduct, sums, crossProduct, sums, parameter);

    return status;
}

} // internal
} // covariance
} // algorithms
} // daal

#endif
