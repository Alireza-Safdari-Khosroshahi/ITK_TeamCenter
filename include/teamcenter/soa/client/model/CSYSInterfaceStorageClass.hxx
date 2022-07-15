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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CSYSINTERFACESTORAGECLASS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CSYSINTERFACESTORAGECLASS_HXX

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


class TCSOACLIENTMNGD_API CSYSInterfaceStorageClass : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_Name();
    const std::string& get_Description();
    const std::string& get_Type();
    const std::string& get_Status();
    const std::string& get_Parent_Part();
    const Teamcenter::Soa::Common::DateTime& get_Modified_Date();
    const std::string& get_GCS_Index();
    const Teamcenter::Soa::Client::StringVector& get_fnd0sync_checksums();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CSYSInterfaceStorageClass")

   virtual ~CSYSInterfaceStorageClass();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
