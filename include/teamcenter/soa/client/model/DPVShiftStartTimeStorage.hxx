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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DPVSHIFTSTARTTIMESTORAGE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DPVSHIFTSTARTTIMESTORAGE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/model/DpvMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOADPVMODELMNGD_API DPVShiftStartTimeStorage : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    const std::string& get_mon_1();
    const std::string& get_mon_2();
    const std::string& get_mon_3();
    const std::string& get_mon_4();
    const std::string& get_tue_1();
    const std::string& get_tue_2();
    const std::string& get_tue_3();
    const std::string& get_tue_4();
    const std::string& get_wed_1();
    const std::string& get_wed_2();
    const std::string& get_wed_3();
    const std::string& get_wed_4();
    const std::string& get_thu_1();
    const std::string& get_thu_2();
    const std::string& get_thu_3();
    const std::string& get_thu_4();
    const std::string& get_fri_1();
    const std::string& get_fri_2();
    const std::string& get_fri_3();
    const std::string& get_fri_4();
    const std::string& get_sat_1();
    const std::string& get_sat_2();
    const std::string& get_sat_3();
    const std::string& get_sat_4();
    const std::string& get_sun_1();
    const std::string& get_sun_2();
    const std::string& get_sun_3();
    const std::string& get_sun_4();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DPVShiftStartTimeStorage")

   virtual ~DPVShiftStartTimeStorage();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/DpvMngd_undef.h>
#endif
