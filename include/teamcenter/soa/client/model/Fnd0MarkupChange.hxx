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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0MARKUPCHANGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0MARKUPCHANGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_application_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0MarkupChange : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_fnd0property_to_edit();
    const std::string& get_fnd0property_value();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0input_object();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0context();
    int get_fnd0markup_type();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_fnd0modified_object();
    const std::string& get_fnd0note();
    int get_fnd0status();
    const std::string& get_bl_line_name();
    const std::string& get_bl_sequence_no();
    const std::string& get_bl_quantity();
    const std::string& get_bl_pack_count();
    const std::string& get_bl_occ_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0MarkupChange")

   virtual ~Fnd0MarkupChange();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
