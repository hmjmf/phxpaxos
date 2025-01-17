/*
Tencent is pleased to support the open source community by making 
PhxPaxos available.
Copyright (C) 2016 THL A29 Limited, a Tencent company. 
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may 
not use this file except in compliance with the License. You may 
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software 
distributed under the License is distributed on an "AS IS" basis, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
implied. See the License for the specific language governing 
permissions and limitations under the License.

See the AUTHORS file for names of contributors. 
*/

#include "benchmark/bench_sm.h"

using namespace phxpaxos;

namespace bench
{

BenchSM :: BenchSM(const phxpaxos::nodeid_t llMyNodeID, const int iGroupIdx)
    : m_llMyNodeID(llMyNodeID), m_iGroupIdx(iGroupIdx)
{
}

bool BenchSM :: Execute(const int iGroupIdx, const uint64_t llInstanceID, 
        const std::string & sPaxosValue, SMCtx * poSMCtx)
{
    //bench sm do nothing
    return true;
}

const int BenchSM :: GetGroupIdx() const
{
    return m_iGroupIdx;
}

}


