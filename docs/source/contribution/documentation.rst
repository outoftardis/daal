.. ******************************************************************************
.. * Copyright 2020 Intel Corporation
.. *
.. * Licensed under the Apache License, Version 2.0 (the "License");
.. * you may not use this file except in compliance with the License.
.. * You may obtain a copy of the License at
.. *
.. *     http://www.apache.org/licenses/LICENSE-2.0
.. *
.. * Unless required by applicable law or agreed to in writing, software
.. * distributed under the License is distributed on an "AS IS" BASIS,
.. * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
.. * See the License for the specific language governing permissions and
.. * limitations under the License.
.. *******************************************************************************/

.. highlight:: RST

Documentation Guidelines
========================

.. contents::
    :local:
    :depth: 2

Writing Guidelines
******************

Markup Conventions
******************

Templates
*********

Batch Processing
----------------

The template for the description of the batch computation mode:

::

    Batch Processing
    ================

    .. contents::
        :local:
        :depth: 1

    Algorithm Input
    ***************

    [...] algorithm accepts the input described below.
    Pass the ``Input ID`` as a parameter to the methods that provide input for your algorithm.
    For more details, see :ref:`algorithms`.

    .. list-table::
        :widths: 10 60
        :header-rows: 1

        * - Input ID
          - Input
        * -
          - 

    Algorithm Parameters
    ********************

    [...] algorithm has the following parameters:

    .. list-table::
        :widths: 10 10 60
        :header-rows: 1

        * - Parameter
          - Default Valude
          - Description
        * -
          -
          - 

    Algorithm Output
    ****************

    [...] algorithm calculates the result described below. 
    Pass the ``Result ID`` as a parameter to the methods that access the results of your algorithm.
    For more details, see :ref:`algorithms`.

    .. list-table::
        :widths: 10 60
        :header-rows: 1

        * - Result ID
          - Result
        * -
          - 

Multiple Computation Modes
--------------------------

When you store descriptions of each computation mode in a separate file:

::

    Computation
    ***********

    The following computation modes are available:

    .. toctree::
        :maxdepth: 1
    
        computation-batch.rst
        computation-online.rst
        computation-distributed.rst

Links to Examples
-----------------

::

    Examples
    ********

    .. tabs::

        .. tab:: DPC++

            Batch Processing:
            
            - :ref:`file.cpp`

        .. tab:: C++
        
            Batch Processing:

            -  :cpp_example:`file.cpp <folder/file`
            -  :cpp_example:``

        .. tab:: Java*
        
            Batch Processing:

            -  :java_example:`File.java <folder/File.java>`
            -  :java_example:``

        .. tab:: Python*

            Batch Processing:

            -  :daal4py_example:`file.py`
            -  :daal4py_example:`sycl/file.py`

Templates for Tables
********************

For input:

::

    .. list-table::
        :widths: 10 60
        :header-rows: 1

        * - Input ID
          - Input
        * -
          - 

For output:

::

    .. list-table::
        :widths: 10 60
        :header-rows: 1

        * - Result ID
          - Result
        * -
          - 

For algorithm parameters:

::

    .. list-table::
        :widths: 10 10 60
        :header-rows: 1

        * - Parameter
          - Default Valude
          - Description
        * -
          -
          - 

For algorithm paramters that depend on the ``method`` parameter:

::

    .. list-table::
        :header-rows: 1
        :widths: 10 10 10 60   
        :align: left

        * - Parameter
          - method
          - Default Value
          - Description
        * -
          -
          - 
          - 

