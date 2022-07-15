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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISSPECSECTIONREVATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISSPECSECTIONREVATTR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/SpecmgrMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOASPECMGRMODELMNGD_API ISSpecSectionRevAttr : public Teamcenter::Soa::Client::Model::Form
{
public:
    int get_row_index();
    int get_parent_row_index();
    bool get_is_bom_section();
    bool get_is_process_section();
    bool get_is_included();
    bool get_is_editable();
    bool get_is_extendable();
    const std::string& get_name_mlt();
    int get_section_id();
    int get_subsection_id();
    short get_section_revision();
    short get_subsection_revision();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISSpecSectionRevAttr")

   virtual ~ISSpecSectionRevAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
