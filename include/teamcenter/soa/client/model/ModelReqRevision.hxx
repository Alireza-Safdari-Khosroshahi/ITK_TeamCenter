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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MODELREQREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MODELREQREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Requirement_Revision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ReqExpression;


class TCSOACLIENTMNGD_API ModelReqRevision : public Teamcenter::Soa::Client::Model::Requirement_Revision
{
public:
    const Teamcenter::Soa::Common::DateTime& get_requirement_modified_date();
    size_t count_requirement_expressions();
    Teamcenter::Soa::Common::AutoPtr<ReqExpression> get_requirement_expressions_at( size_t inx );
    const std::string& get_fnd0_req_expression_str();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ModelReqRevision")

   virtual ~ModelReqRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
