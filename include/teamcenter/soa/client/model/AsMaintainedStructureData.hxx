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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ASMAINTAINEDSTRUCTUREDATA_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ASMAINTAINEDSTRUCTUREDATA_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PSOccurrence;


class TCSOAASMAINTAINEDMODELMNGD_API AsMaintainedStructureData : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const Teamcenter::Soa::Common::DateTime& get_installationTime();
    const Teamcenter::Soa::Common::DateTime& get_unInstallationTime();
    const std::string& get_partUsedIs();
    const std::string& get_usageName();
    bool get_isInstalled();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrence> get_alignedPSOccurence();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AsMaintainedStructureData")

   virtual ~AsMaintainedStructureData();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
