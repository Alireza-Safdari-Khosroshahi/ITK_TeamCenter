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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_VISUALREPORTDEFINITION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_VISUALREPORTDEFINITION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Dataset.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API VisualReportDefinition : public Teamcenter::Soa::Client::Model::Dataset
{
public:
    const std::string& get_full_name();
    const std::string& get_full_description();
    const std::string& get_application();
    const std::string& get_xml_schema_version();
    const Teamcenter::Soa::Client::StringVector& get_reporting_property_list();
    const Teamcenter::Soa::Client::StringVector& get_keyword_list();
    const std::string& get_category();
    const std::string& get_language();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("VisualReportDefinition")

   virtual ~VisualReportDefinition();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
