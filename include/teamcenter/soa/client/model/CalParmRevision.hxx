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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CALPARMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CALPARMREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ArchitectureRevision.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class User;
                class User;


class TCSOACCDMMODELMNGD_API CalParmRevision : public Teamcenter::Soa::Client::Model::ArchitectureRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<User> get_specialist();
    const std::string& get_comment();
    Teamcenter::Soa::Common::AutoPtr<User> get_controlEngineer();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_userData();
    const std::string& get_parmDescriptor();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CalParmRevision")

   virtual ~CalParmRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
