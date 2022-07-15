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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPARTWORKREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPARTWORKREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Specification_Revision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAPKGARTMODELMNGD_API CPArtworkRevision : public Teamcenter::Soa::Client::Model::Specification_Revision
{
public:
    const std::string& get_currency();
    double get_cost();
    const std::string& get_design_agency();
    const std::string& get_production_process();
    const std::string& get_print_agency();
    const std::string& get_special_print_feature();
    int get_no_of_colors();
    const std::string& get_type_of_ink();
    const std::string& get_color_matching_info();
    bool get_is_lead_artwork();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_package_items();
    const std::string& get_artwork_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPArtworkRevision")

   virtual ~CPArtworkRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
