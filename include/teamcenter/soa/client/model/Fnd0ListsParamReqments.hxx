/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

  Auto-generated source from Teamcenter Data Model.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0LISTSPARAMREQMENTS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0LISTSPARAMREQMENTS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/FND_TraceLink.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0ListsParamReqments : public Teamcenter::Soa::Client::Model::FND_TraceLink
{
public:
    const Teamcenter::Soa::Client::StringVector& get_Fnd0parameter();
    const Teamcenter::Soa::Client::StringVector& get_Fnd0value();
    const std::string& get_fnd0SequenceNumber();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ListsParamReqments")

   virtual ~Fnd0ListsParamReqments();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
