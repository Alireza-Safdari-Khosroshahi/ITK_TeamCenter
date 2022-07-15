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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TCCALENDAR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TCCALENDAR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Range;
                class Range;
                class Range;
                class Range;
                class Range;
                class Range;
                class Range;


class TCSOACLIENTMNGD_API TCCalendar : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_tccal_name();
    const std::string& get_tccal_desc();
    Teamcenter::Soa::Common::AutoPtr<TCCalendar> get_base_calendar_tag();
    int get_tccal_type();
    const std::string& get_time_zone();
    size_t count_sun_ranges();
    Teamcenter::Soa::Common::AutoPtr<Range> get_sun_ranges_at( size_t inx );
    size_t count_mon_ranges();
    Teamcenter::Soa::Common::AutoPtr<Range> get_mon_ranges_at( size_t inx );
    size_t count_tue_ranges();
    Teamcenter::Soa::Common::AutoPtr<Range> get_tue_ranges_at( size_t inx );
    size_t count_wed_ranges();
    Teamcenter::Soa::Common::AutoPtr<Range> get_wed_ranges_at( size_t inx );
    size_t count_thu_ranges();
    Teamcenter::Soa::Common::AutoPtr<Range> get_thu_ranges_at( size_t inx );
    size_t count_fri_ranges();
    Teamcenter::Soa::Common::AutoPtr<Range> get_fri_ranges_at( size_t inx );
    size_t count_sat_ranges();
    Teamcenter::Soa::Common::AutoPtr<Range> get_sat_ranges_at( size_t inx );
    const Teamcenter::Soa::Client::ModelObjectVector& get_fnd0OrganizationAuditLogs();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TCCalendar")

   virtual ~TCCalendar();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
