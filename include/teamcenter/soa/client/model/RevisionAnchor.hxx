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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REVISIONANCHOR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REVISIONANCHOR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API RevisionAnchor : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    int get_keep_limit();
    int get_highest_rev();
    const Teamcenter::Soa::Client::ModelObjectVector& get_revisions();
    const std::string& get_rev();
    const std::string& get_id();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_RES_checkout();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RevisionAnchor")

   virtual ~RevisionAnchor();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
