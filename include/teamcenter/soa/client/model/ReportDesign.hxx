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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_REPORTDESIGN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_REPORTDESIGN_HXX

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
                class ImanPFF;
                class ImanQuery;
                class Dataset;


class TCSOACLIENTMNGD_API ReportDesign : public Teamcenter::Soa::Client::Model::POM_application_object
{
public:
    const std::string& get_design_name();
    const std::string& get_design_desc();
    Teamcenter::Soa::Common::AutoPtr<ImanPFF> get_data_formatter();
    Teamcenter::Soa::Common::AutoPtr<ImanQuery> get_iman_query();
    size_t count_report_formatters();
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_report_formatters_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ReportDesign")

   virtual ~ReportDesign();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
