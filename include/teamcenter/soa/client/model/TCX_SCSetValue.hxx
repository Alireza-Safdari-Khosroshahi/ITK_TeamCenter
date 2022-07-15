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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TCX_SCSETVALUE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TCX_SCSETVALUE_HXX

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


class TCSOACLIENTMNGD_API TCX_SCSetValue : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_SC_Value();
    const std::string& get_SC_Container();
    const std::string& get_SC_Item_revision_id();
    const std::string& get_SC_Item_id();
    const std::string& get_SC_Attribute();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TCX_SCSetValue")

   virtual ~TCX_SCSetValue();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
