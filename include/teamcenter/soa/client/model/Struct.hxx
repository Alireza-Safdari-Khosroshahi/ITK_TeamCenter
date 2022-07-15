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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_STRUCT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_STRUCT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GeneratedDataType.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class StructElement;


class TCSOACLIENTMNGD_API Struct : public Teamcenter::Soa::Client::Model::GeneratedDataType
{
public:
    size_t count_structElements();
    Teamcenter::Soa::Common::AutoPtr<StructElement> get_structElements_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Struct")

   virtual ~Struct();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
