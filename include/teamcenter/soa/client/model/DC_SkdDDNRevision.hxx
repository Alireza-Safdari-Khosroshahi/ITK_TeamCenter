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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDDDNREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDDDNREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_TopicRevision.hxx>

#include <teamcenter/soa/client/model/Contmgmts1000dMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTS1000DMODELMNGD_API DC_SkdDDNRevision : public Teamcenter::Soa::Client::Model::DC_TopicRevision
{
public:
    const std::string& get_skdauthrtn();
    const std::string& get_skddispfrom_building();
    const std::string& get_skddispfrom_city();
    const std::string& get_skddispfrom_country();
    const std::string& get_skddispfrom_dept();
    const std::string& get_skddispfrom_email();
    const std::string& get_skddispfrom_fax();
    const std::string& get_skddispfrom_firstname();
    const std::string& get_skddispfrom_internet();
    const std::string& get_skddispfrom_jobtitle();
    const std::string& get_skddispfrom_lastname();
    const std::string& get_skddispfrom_phone();
    const std::string& get_skddispfrom_pobox();
    const std::string& get_skddispfrom_postcode();
    const std::string& get_skddispfrom_province();
    const std::string& get_skddispfrom_room();
    const std::string& get_skddispfrom_state();
    const std::string& get_skddispfrom_street();
    const std::string& get_skddispfrom_zip();
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
    const std::string& get_skdmediaid();
    const std::string& get_skdmodelic();
    const std::string& get_skdrecvid();
    const std::string& get_skdremarks();
    const std::string& get_skdsecurity_class();
    const std::string& get_skdsendid();
    const std::string& get_skdseqnum();
    const std::string& get_skddispto_div_name();
    const std::string& get_skddispto_ent_name();
    const std::string& get_skddispto_ent_unit();
    const std::string& get_skddispfrom_div_name();
    const std::string& get_skddispfrom_ent_name();
    const std::string& get_skddispfrom_ent_unit();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_SkdDDNRevision")

   virtual ~DC_SkdDDNRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Contmgmts1000dMngd_undef.h>
#endif
