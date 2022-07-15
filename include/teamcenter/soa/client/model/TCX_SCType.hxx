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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TCX_SCTYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TCX_SCTYPE_HXX

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
                class ImanType;


class TCSOACLIENTMNGD_API TCX_SCType : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_SC_Property();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_SC_Type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TCX_SCType")

   virtual ~TCX_SCType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
