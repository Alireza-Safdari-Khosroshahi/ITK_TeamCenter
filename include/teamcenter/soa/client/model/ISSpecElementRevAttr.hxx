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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ISSPECELEMENTREVATTR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ISSPECELEMENTREVATTR_HXX

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


class TCSOASPECMGRMODELMNGD_API ISSpecElementRevAttr : public Teamcenter::Soa::Client::Model::Form
{
public:
    short get_is_item_revision();
    short get_is_item_type();
    int get_is_item_id();
    bool get_display_header();
    bool get_is_optional();
    bool get_is_editable();
    bool get_is_included();
    bool get_is_extended();
    int get_display_format_id();
    short get_display_format_revision();
    int get_row_index();
    const std::string& get_name_mlt();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ISSpecElementRevAttr")

   virtual ~ISSpecElementRevAttr();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/SpecmgrMngd_undef.h>
#endif
