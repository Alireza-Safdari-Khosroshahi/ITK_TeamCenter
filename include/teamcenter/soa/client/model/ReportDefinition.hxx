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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REPORTDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REPORTDEFINITION_HXX

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
                class PropertySet;
                class CrfQuerySource;
                class Dataset;


class TCSOACLIENTMNGD_API ReportDefinition : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_rd_id();
    const std::string& get_rd_name();
    const std::string& get_rd_description();
    const std::string& get_rd_class();
    const std::string& get_rd_source();
    const std::string& get_rd_folder_name();
    int get_rd_type();
    int get_rd_state();
    const Teamcenter::Soa::Client::StringVector& get_rd_parameters();
    const Teamcenter::Soa::Client::StringVector& get_rd_param_values();
    Teamcenter::Soa::Common::AutoPtr<PropertySet> get_rd_property_source();
    Teamcenter::Soa::Common::AutoPtr<CrfQuerySource> get_rd_query_source();
    size_t count_rd_style_sheets();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_rd_style_sheets_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ReportDefinition")

   virtual ~ReportDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
