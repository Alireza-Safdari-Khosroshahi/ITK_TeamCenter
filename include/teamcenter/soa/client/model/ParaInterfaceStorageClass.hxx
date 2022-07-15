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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARAINTERFACESTORAGECLASS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARAINTERFACESTORAGECLASS_HXX

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


class TCSOACLIENTMNGD_API ParaInterfaceStorageClass : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_Name();
    const std::string& get_Description();
    const std::string& get_Type();
    const std::string& get_Status();
    const std::string& get_Unit();
    const std::string& get_Value();
    const std::string& get_Formula();
    const std::string& get_Parent_Part();
    const Teamcenter::Soa::Common::DateTime& get_Modified_Date();
    const Teamcenter::Soa::Client::StringVector& get_fnd0sync_checksums();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParaInterfaceStorageClass")

   virtual ~ParaInterfaceStorageClass();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
