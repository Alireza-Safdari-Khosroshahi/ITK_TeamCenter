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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_GMO0PHASERCONFIGFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_GMO0PHASERCONFIGFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/GmoMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAGMOMODELMNGD_API GMo0PhaserConfigForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    const std::string& get_GMo0active();
    const std::string& get_GMo0prepare();
    const std::string& get_GMo0check();
    const std::string& get_GMo0release();
    const std::string& get_GMo0release_procedure();
    const std::string& get_GMo0default_form();
    const std::string& get_GMo0update_structure();
    const std::string& get_GMo0parse_assembly();
    const std::string& get_GMo0dcs_required_categories();
    const std::string& get_GMo0prep_tool();
    const std::string& get_GMo0override_seed_file();
    const std::string& get_GMo0override_part_attribs();
    const std::string& get_GMo0revision_rule();
    const std::string& get_GMo0seed_file();
    const std::string& get_GMo0mode();
    const std::string& get_GMo0p_mass();
    const std::string& get_GMo0p_mat();
    const std::string& get_GMo0p_gauge();
    const std::string& get_GMo0vpps();
    const std::string& get_GMo0p_density();
    const std::string& get_GMo0p_volume();
    const std::string& get_GMo0p_area();
    const std::string& get_GMo0gqs();
    const std::string& get_GMo0gqs_plus();
    const std::string& get_GMo0gqs_gme();
    const std::string& get_GMo0design_log();
    bool get_GMo0Is_Default_Form();
    const std::string& get_GMo0dcs_file_org();
    const std::string& get_GMo0p_mat_tol();
    bool get_GMo0Is_BaselineRelease();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("GMo0PhaserConfigForm")

   virtual ~GMo0PhaserConfigForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/GmoMngd_undef.h>
#endif
