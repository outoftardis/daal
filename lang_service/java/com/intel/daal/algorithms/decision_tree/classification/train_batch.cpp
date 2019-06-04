/* file: train_batch.cpp */
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

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>

#include "daal.h"
#include "com_intel_daal_algorithms_decision_tree_classification_training_TrainingBatch.h"
#include "common_helpers.h"

USING_COMMON_NAMESPACES()
namespace dtct = daal::algorithms::decision_tree::classification::training;

/*
* Class:     com_intel_daal_algorithms_decision_tree_classification_training_TrainingBatch
* Method:    cInit
* Signature: (IIJ)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1tree_classification_training_TrainingBatch_cInit
(JNIEnv *env, jobject thisObj, jint prec, jint method, jlong nClasses)
{
    return jniBatch<dtct::Method, dtct::Batch, dtct::defaultDense>::newObj(prec, method, nClasses);
}

/*
* Class:     com_intel_daal_algorithms_decision_tree_classification_training_TrainingBatch
* Method:    cInitParameter
* Signature: (JII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1tree_classification_training_TrainingBatch_cInitParameter
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<dtct::Method, dtct::Batch, dtct::defaultDense>::getParameter(prec, method, algAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_tree_classification_training_TrainingBatch
* Method:    cGetInput
* Signature: (JII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1tree_classification_training_TrainingBatch_cGetInput
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<dtct::Method, dtct::Batch, dtct::defaultDense>::getInput(prec, method, algAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_tree_classification_training_TrainingBatch
* Method:    cGetResult
* Signature: (JII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1tree_classification_training_TrainingBatch_cGetResult
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<dtct::Method, dtct::Batch, dtct::defaultDense>::getResult(prec, method, algAddr);
}

/*
* Class:     com_intel_daal_algorithms_decision_tree_classification_training_TrainingBatch
* Method:    cClone
* Signature: (JII)J
*/
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_decision_1tree_classification_training_TrainingBatch_cClone
(JNIEnv *env, jobject thisObj, jlong algAddr, jint prec, jint method)
{
    return jniBatch<dtct::Method, dtct::Batch, dtct::defaultDense>::getClone(prec, method, algAddr);
}
