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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPINTERFACETYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPINTERFACETYPE_HXX

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
                class ImanType;
                class PSViewType;
                class Tool;
                class TransferMode;
                class TransferMode;


class TCSOACLIENTMNGD_API AppInterfaceType : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_name();
    const std::string& get_desc();
    bool get_isICrequired();
    bool get_isUsedForIDC();
    size_t count_objectTypes();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_objectTypes_at( size_t inx );
    size_t count_viewTypes();
    Teamcenter::Soa::Common::AutoPtr<PSViewType> get_viewTypes_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Tool> get_tool();
    Teamcenter::Soa::Common::AutoPtr<TransferMode> get_tm_export();
    Teamcenter::Soa::Common::AutoPtr<TransferMode> get_tm_import();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AppInterfaceType")

   virtual ~AppInterfaceType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
