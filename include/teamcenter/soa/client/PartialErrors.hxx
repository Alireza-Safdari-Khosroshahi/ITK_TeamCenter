/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/**
    @file

    The PartialErrors class provides convienience methods to access error stacks

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_PARTIALERRORS_HXX
#define TEAMCENTER_SOA_CLIENT_PARTIALERRORS_HXX

#include <string>
#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>

#include <teamcenter/soa/client/ErrorStack.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {



class TCSOACLIENTMNGD_API PartialErrors
{
public:
    const std::vector<ErrorStack>& getPartialErrors() const;

    SOA_CLASS_NEW_OPERATORS


private:
    friend class ModelManagerImpl;
    friend class DefaultObjectFactory;

    std::vector<ErrorStack> m_partialErrors;
};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
