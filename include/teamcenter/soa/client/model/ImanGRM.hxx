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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_IMANGRM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_IMANGRM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessRule.hxx>

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
                class ImanType;
                class ImanType;


class TCSOACLIENTMNGD_API ImanGRM : public Teamcenter::Soa::Client::Model::BusinessRule
{
public:
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_iman_relation_type();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_primary_object();
    Teamcenter::Soa::Common::AutoPtr<ImanType> get_secondary_object();
    int get_primaryCardinality();
    int get_secondaryCardinality();
    int get_bitwiseConstraints();
    bool get_secured();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ImanGRM")

   virtual ~ImanGRM();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
