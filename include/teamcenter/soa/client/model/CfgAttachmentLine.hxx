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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CFGATTACHMENTLINE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CFGATTACHMENTLINE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/MECfgLine.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API CfgAttachmentLine : public Teamcenter::Soa::Client::Model::MECfgLine
{
public:
    int get_child_has_ice_types();
    bool get_child_removed_by_current_ic();
    bool get_child_added_by_current_ic();
    bool get_reln_added_by_current_ic();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_al_object();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_al_structure_line();
    const Teamcenter::Soa::Client::ModelObjectVector& get_al_ices_of_reln();
    const std::string& get_al_reln_ic_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_al_ices_of_child_edits();
    const Teamcenter::Soa::Client::ModelObjectVector& get_al_ices_of_child();
    const std::string& get_al_child_ic_list();
    const std::string& get_al_source_type();
    const std::string& get_al_source_class();
    const std::string& get_al_child_edits_ic_list();
    const std::string& get_al_context();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_al_absocc_rootline();
    int get_reln_has_ice_types();
    bool get_reln_removed_by_current_ic();
    const std::string& get_al_absocc_rootline_string();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CfgAttachmentLine")

   virtual ~CfgAttachmentLine();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
