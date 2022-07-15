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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALLOCATION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PHYSICALLOCATION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/PhysicalElement.hxx>

#include <teamcenter/soa/client/model/AsmaintainedMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class CompanyLocation;


class TCSOAASMAINTAINEDMODELMNGD_API PhysicalLocation : public Teamcenter::Soa::Client::Model::PhysicalElement
{
public:
    const std::string& get_locationType();
    Teamcenter::Soa::Common::AutoPtr<CompanyLocation> get_locationInfo();
    const Teamcenter::Soa::Client::ModelObjectVector& get_PhysicalLocationDetails();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PhysicalLocation")

   virtual ~PhysicalLocation();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AsmaintainedMngd_undef.h>
#endif
