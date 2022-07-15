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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_METAENUM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_METAENUM_HXX

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
                class MetaEnumLiteral;


class TCSOACLIENTMNGD_API MetaEnum : public Teamcenter::Soa::Client::Model::GeneratedDataType
{
public:
    size_t count_metaEnumLiterals();
    Teamcenter::Soa::Common::AutoPtr<MetaEnumLiteral> get_metaEnumLiterals_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MetaEnum")

   virtual ~MetaEnum();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
