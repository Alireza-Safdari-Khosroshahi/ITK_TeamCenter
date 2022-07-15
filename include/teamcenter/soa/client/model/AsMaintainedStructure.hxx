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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ASMAINTAINEDSTRUCTURE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ASMAINTAINEDSTRUCTURE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PhysicalStructure.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class AsMaintainedStructureData;


class TCSOAASMAINTAINEDMODELMNGD_API AsMaintainedStructure : public Teamcenter::Soa::Client::Model::PhysicalStructure
{
public:
    const Teamcenter::Soa::Common::DateTime& get_unInstallationTime();
    bool get_isInstalled();
    size_t count_historicalData();
    Teamcenter::Soa::Common::AutoPtr<AsMaintainedStructureData> get_historicalData_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AsMaintainedStructure")

   virtual ~AsMaintainedStructure();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
