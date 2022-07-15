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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPTECHNICALBRIEFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPTECHNICALBRIEFREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/CPBriefRevision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class UnitOfMeasure;
                class UnitOfMeasure;


class TCSOAPKGARTMODELMNGD_API CPTechnicalBriefRevision : public Teamcenter::Soa::Client::Model::CPBriefRevision
{
public:
    const std::string& get_packing_instructions();
    const std::string& get_substrate();
    const std::string& get_tests_to_perform();
    const std::string& get_manufacturing_process();
    const std::string& get_printing_technique();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_dimension_unit();
    double get_height();
    double get_width();
    double get_depth();
    double get_gross_weight();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_weight_unit();
    int get_case_count();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_Results_In_Package_Rough();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_marketing_briefs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPTechnicalBriefRevision")

   virtual ~CPTechnicalBriefRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
