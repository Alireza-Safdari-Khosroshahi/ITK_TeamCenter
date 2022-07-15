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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CIV0COM4REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CIV0COM4REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_TopicRevision.hxx>

#include <teamcenter/soa/client/model/Contmgmts1000d40Mngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTS1000D40MODELMNGD_API Civ0COM4Revision : public Teamcenter::Soa::Client::Model::DC_TopicRevision
{
public:
    const std::string& get_civ0inwork();
    const std::string& get_skdctitle();
    const std::string& get_skdctype();
    const std::string& get_skddispto_building();
    const std::string& get_skddispto_city();
    const std::string& get_skddispto_country();
    const std::string& get_skddispto_dept();
    const std::string& get_skddispto_email();
    const std::string& get_skddispto_fax();
    const std::string& get_skddispto_firstname();
    const std::string& get_skddispto_internet();
    const std::string& get_skddispto_jobtitle();
    const std::string& get_skddispto_lastname();
    const std::string& get_skddispto_phone();
    const std::string& get_skddispto_pobox();
    const std::string& get_skddispto_postcode();
    const std::string& get_skddispto_province();
    const std::string& get_skddispto_room();
    const std::string& get_skddispto_state();
    const std::string& get_skddispto_street();
    const std::string& get_skddispto_zip();
    const std::string& get_skddiyear();
    const std::string& get_skdiss_type();
    const std::string& get_skdissdate_day();
    const std::string& get_skdissdate_month();
    const std::string& get_skdissdate_year();
    const std::string& get_skdissno();
    const std::string& get_skdmodelic();
    const std::string& get_skdpriority();
    const std::string& get_skdremarks();
    const std::string& get_skdresponse();
    const std::string& get_skdsecurity_class();
    const std::string& get_skdsendid();
    const std::string& get_skdseqnum();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Civ0COM4Revision")

   virtual ~Civ0COM4Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Contmgmts1000d40Mngd_undef.h>
#endif
