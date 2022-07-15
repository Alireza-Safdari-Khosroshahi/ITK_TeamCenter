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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GMSMAPPINGHOLDER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GMSMAPPINGHOLDER_HXX

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


class TCSOACLIENTMNGD_API GMSMappingHolder : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_parent();
    const std::string& get_child();
    const std::string& get_savedElemId();
    const std::string& get_class();
    const std::string& get_system();
    const Teamcenter::Soa::Client::StringVector& get_attrNames();
    const Teamcenter::Soa::Client::StringVector& get_attrValues();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GMSMappingHolder")

   virtual ~GMSMappingHolder();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
