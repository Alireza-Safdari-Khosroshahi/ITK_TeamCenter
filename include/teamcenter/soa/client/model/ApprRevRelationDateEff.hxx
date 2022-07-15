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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_APPRREVRELATIONDATEEFF_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_APPRREVRELATIONDATEEFF_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ApprRevRelation.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ApprRevRelationDateEff : public Teamcenter::Soa::Client::Model::ApprRevRelation
{
public:
    const Teamcenter::Soa::Common::DateTimeVector& get_date_effectivity();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ApprRevRelationDateEff")

   virtual ~ApprRevRelationDateEff();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
