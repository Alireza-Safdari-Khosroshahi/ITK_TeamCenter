/*=============================================================================
  Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
=============================================================================*/
/**
    @file

    The ServiceData class warps the the XML schema classes from the wire
    and provide convienience methods to access the data in them

*/
/*  */


#ifndef TEAMCENTER_SOA_CLIENT_SERVICEDATA_HXX
#define TEAMCENTER_SOA_CLIENT_SERVICEDATA_HXX

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


class TCSOACLIENTMNGD_API ServiceData
{
public:
    ServiceData(): m_createdObjs(), m_updatedObjs(), m_plainObjs(), m_deletedUids(), m_partialErrors() {};
    ~ServiceData(){};

    const std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> >& getCreatedObjs()const;
    const std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> >& getUpdatedObjs()const;
    const std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> >& getPlainObjs()const;

    const std::vector<std::string>& getDeletedUids()const;

    const std::vector<ErrorStack>& getPartialErrors()const;

    SOA_CLASS_NEW_OPERATORS


private:
    friend class ModelManagerImpl;
    friend class DefaultObjectFactory;

    std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> >  m_createdObjs;
    std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> >  m_updatedObjs;
    //std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> > m_childChangeObjs; // this is only exposed in RAC at this time
    std::vector<Teamcenter::Soa::Common::AutoPtr<ModelObject> >  m_plainObjs;
    std::vector<std::string>   m_deletedUids;
    std::vector<ErrorStack>    m_partialErrors;
};
}}} //end namespace
#include <teamcenter/soa/client/SoaClientMngdUndef.h>

#endif
