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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_AM_ACL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_AM_ACL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API AM_ACL : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_ACL_Name();
    bool get_acl_loaded();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ACE_Ids();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ACE_Ids_togo();
    const std::string& get_ACL_Flag();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AM_ACL")

   virtual ~AM_ACL();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
