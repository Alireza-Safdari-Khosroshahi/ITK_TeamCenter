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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GENERATEDDATATYPE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GENERATEDDATATYPE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DataType.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ServiceInterface;


class TCSOACLIENTMNGD_API GeneratedDataType : public Teamcenter::Soa::Client::Model::DataType
{
public:
    bool get_isPublished();
    Teamcenter::Soa::Common::AutoPtr<ServiceInterface> get_scope();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GeneratedDataType")

   virtual ~GeneratedDataType();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
