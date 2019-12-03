/* file: mse_types.h */
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
//  Implementation of Mean squared error objective function interface.
//--
*/

#ifndef __MSE_TYPES_H__
#define __MSE_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/numeric_table.h"
#include "services/daal_defines.h"
#include "sum_of_functions_types.h"

namespace daal
{
namespace algorithms
{
/**
 * \brief Contains classes for computing the Mean squared error objective function
 */
namespace optimization_solver
{
/**
 * @defgroup mse Mean Squared Error Algorithm
 * \copydoc daal::algorithms::optimization_solver::mse
 * @ingroup objective_function
 * @{
 */
/**
* \brief Contains classes for computing the Mean squared error objective function
*/
namespace mse
{
/**
  * <a name="DAAL-ENUM-ALGORITHMS__OPTIMIZATION_SOLVER__MSE__INPUTID"></a>
  * Available identifiers of input objects of the Mean squared error objective function
  */
enum InputId
{
    argument = (int)sum_of_functions::argument, /*!< Numeric table of size 1 x p with input argument of the objective function */
    data,                                       /*!< Numeric table of size n x p with data */
    dependentVariables,                         /*!< Numeric table of size n x 1 with dependent variables */
    lastInputId = dependentVariables
};

/**
* <a name="DAAL-ENUM-ALGORITHMS__OPTIMIZATION_SOLVER__ITERATIVE_SOLVER__OPTIONALINPUTID"></a>
* Available identifiers of optional input for the iterative solver
*/
enum OptionalInputId
{
    optionalArgument    = lastInputId + 1, /*!< Algorithm-specific input data, can be generated by previous runs of the algorithm */
    lastOptionalInputId = optionalArgument
};

/**
* <a name="DAAL-ENUM-ALGORITHMS__OPTIMIZATION_SOLVER__ITERATIVE_SOLVER__OPTIONALDATAID"></a>
* Available identifiers of optional input for the iterative solver
*/
enum OptionalDataId
{
    weights,    /*!< NumericTable of size 1 x n with samples weights. Applied for all method */
    gramMatrix, /*!< NumericTable of size p x p with last iteration number. Applied for all method */
    lastOptionalData = gramMatrix
};

/**
 * <a name="DAAL-ENUM-ALGORITHMS__OPTIMIZATION_SOLVER__MSE__METHOD"></a>
 * Available methods for computing results of Mean squared error objective function
 */
enum Method
{
    defaultDense = 0 /*!< Default: performance-oriented method. */
};

/**
 * \brief Contains version 1.0 of the Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{
/**
 * <a name="DAAL-STRUCT-ALGORITHMS__OPTIMIZATION_SOLVER__MSE__PARAMETER"></a>
 * \brief %Parameter for Mean squared error objective function     \DAAL_DEPRECATED
 *
 */
struct DAAL_EXPORT Parameter : public sum_of_functions::interface1::Parameter
{
    /**
     * Constructs the parameter of Mean squared error objective function
     * \param[in] numberOfTerms    The number of terms in the function
     * \param[in] batchIndices     Numeric table of size 1 x m where m is batch size that represent
                                   a batch of indices used to compute the function results, e.g.,
                                   value of the sum of the functions. If no indices are provided,
                                   all terms will be used in the computations.
     * \param[in] resultsToCompute 64 bit integer flag that indicates the results to compute
     */
    DAAL_DEPRECATED Parameter(size_t numberOfTerms, data_management::NumericTablePtr batchIndices = data_management::NumericTablePtr(),
                              const DAAL_UINT64 resultsToCompute = objective_function::gradient);

    /**
     * Constructs an Parameter by copying input objects and parameters of another Parameter
     * \param[in] other An object to be used as the source to initialize object
     */
    DAAL_DEPRECATED Parameter(const Parameter & other);
    /**
     * Checks the correctness of the parameter
     *
     * \return Status of computations
     */
    DAAL_DEPRECATED_VIRTUAL virtual services::Status check() const;

    DAAL_DEPRECATED_VIRTUAL virtual ~Parameter() {}
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__OPTIMIZATION_SOLVER__MSE__INPUT"></a>
 * \brief %Input objects for the Mean squared error objective function    \DAAL_DEPRECATED
 */
class DAAL_EXPORT Input : public sum_of_functions::interface1::Input
{
public:
    /** Default constructor */
    DAAL_DEPRECATED Input();

    /** Copy constructor */
    DAAL_DEPRECATED Input(const Input & other);

    /** Destructor */
    DAAL_DEPRECATED_VIRTUAL virtual ~Input() {}

    /**
     * Sets one input object for Mean squared error objective function
     * \param[in] id    Identifier of the input object
     * \param[in] ptr   Pointer to the object
     */
    DAAL_DEPRECATED void set(InputId id, const data_management::NumericTablePtr & ptr);

    /**
     * Returns the input numeric table for Mean squared error objective function
     * \param[in] id    Identifier of the input numeric table
     * \return          %Input object that corresponds to the given identifier
     */
    DAAL_DEPRECATED data_management::NumericTablePtr get(InputId id) const;

    /**
    * Returns optional input of the iterative solver algorithm
    * \param[in] id    Identifier of the optional input data
    * \return          %Input data that corresponds to the given identifier
    */
    DAAL_DEPRECATED algorithms::OptionalArgumentPtr get(OptionalInputId id) const;

    /**
    * Sets optional input for the iterative solver algorithm
    * \param[in] id    Identifier of the input object
    * \param[in] ptr   Pointer to the object
    */
    DAAL_DEPRECATED void set(OptionalInputId id, const algorithms::OptionalArgumentPtr & ptr);

    /**
    * Returns input NumericTable containing optional data
    * \param[in] id    Identifier of the input numeric table
    * \return          %Input numeric table that corresponds to the given identifier
    */
    DAAL_DEPRECATED data_management::NumericTablePtr get(OptionalDataId id) const;

    /**
    * Sets optional input for the algorithm
    * \param[in] id    Identifier of the input object
    * \param[in] ptr   Pointer to the object
    */
    DAAL_DEPRECATED void set(OptionalDataId id, const data_management::NumericTablePtr & ptr);

    /**
     * Checks the correctness of the input
     * \param[in] par       Pointer to the structure of the algorithm parameters
     * \param[in] method    Computation method
     *
     * \return Status of computations
     */
    DAAL_DEPRECATED services::Status check(const daal::algorithms::Parameter * par, int method) const DAAL_C11_OVERRIDE;
};
/** @} */
} // namespace interface1

/**
 * \brief Contains version 1.0 of the Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface2
{
/**
 * <a name="DAAL-STRUCT-ALGORITHMS__OPTIMIZATION_SOLVER__MSE__PARAMETER"></a>
 * \brief %Parameter for Mean squared error objective function
 *
 * \snippet optimization_solver/objective_function/mse_types.h Parameter source code
 */
/* [Parameter source code] */
struct DAAL_EXPORT Parameter : public sum_of_functions::Parameter
{
    /**
     * Constructs the parameter of Mean squared error objective function
     * \param[in] numberOfTerms    The number of terms in the function
     * \param[in] batchIndices     Numeric table of size 1 x m where m is batch size that represent
                                   a batch of indices used to compute the function results, e.g.,
                                   value of the sum of the functions. If no indices are provided,
                                   all terms will be used in the computations.
     * \param[in] resultsToCompute 64 bit integer flag that indicates the results to compute
     */
    Parameter(size_t numberOfTerms, data_management::NumericTablePtr batchIndices = data_management::NumericTablePtr(),
              const DAAL_UINT64 resultsToCompute = objective_function::gradient);

    /**
     * Constructs an Parameter by copying input objects and parameters of another Parameter
     * \param[in] other An object to be used as the source to initialize object
     */
    Parameter(const Parameter & other);
    /**
     * Checks the correctness of the parameter
     *
     * \return Status of computations
     */
    virtual services::Status check() const;

    virtual ~Parameter() {}
    bool interceptFlag;                         /*!< Whether the intercept needs to be computed. Default is true */
    data_management::NumericTablePtr penaltyL1; /*!< L1 regularization coefficients. Default is 0 (not applied) */
    data_management::NumericTablePtr penaltyL2; /*!< L2 regularization coefficients. Default is 0 (not applied) */
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__OPTIMIZATION_SOLVER__MSE__INPUT"></a>
 * \brief %Input objects for the Mean squared error objective function
 */
class DAAL_EXPORT Input : public sum_of_functions::Input
{
public:
    /** Default constructor */
    Input();

    /** Copy constructor */
    Input(const Input & other);

    /** Destructor */
    virtual ~Input() {}

    /**
     * Sets one input object for Mean squared error objective function
     * \param[in] id    Identifier of the input object
     * \param[in] ptr   Pointer to the object
     */
    void set(InputId id, const data_management::NumericTablePtr & ptr);

    /**
     * Returns the input numeric table for Mean squared error objective function
     * \param[in] id    Identifier of the input numeric table
     * \return          %Input object that corresponds to the given identifier
     */
    data_management::NumericTablePtr get(InputId id) const;

    /**
    * Returns optional input of the iterative solver algorithm
    * \param[in] id    Identifier of the optional input data
    * \return          %Input data that corresponds to the given identifier
    */
    algorithms::OptionalArgumentPtr get(OptionalInputId id) const;

    /**
    * Sets optional input for the iterative solver algorithm
    * \param[in] id    Identifier of the input object
    * \param[in] ptr   Pointer to the object
    */
    void set(OptionalInputId id, const algorithms::OptionalArgumentPtr & ptr);

    /**
    * Returns input NumericTable containing optional data
    * \param[in] id    Identifier of the input numeric table
    * \return          %Input numeric table that corresponds to the given identifier
    */
    data_management::NumericTablePtr get(OptionalDataId id) const;

    /**
    * Sets optional input for the algorithm
    * \param[in] id    Identifier of the input object
    * \param[in] ptr   Pointer to the object
    */
    void set(OptionalDataId id, const data_management::NumericTablePtr & ptr);

    /**
     * Checks the correctness of the input
     * \param[in] par       Pointer to the structure of the algorithm parameters
     * \param[in] method    Computation method
     *
     * \return Status of computations
     */
    services::Status check(const daal::algorithms::Parameter * par, int method) const DAAL_C11_OVERRIDE;
};
/* [Parameter source code] */
} // namespace interface2
using interface2::Parameter;
using interface2::Input;

} // namespace mse
} // namespace optimization_solver
} // namespace algorithms
} // namespace daal
#endif