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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDIPRFREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDIPRFREVISION_HXX

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


class TCSOACONTMGMTS1000DMODELMNGD_API DC_SkdIPRFRevision : public Teamcenter::Soa::Client::Model::DC_TopicRevision
{
public:
    const std::string& get_skdcage();
    const std::string& get_skddiyear();
    const std::string& get_skdiprdate_day();
    const std::string& get_skdiprdate_month();
    const std::string& get_skdiprdate_year();
    const std::string& get_skdiprfrm_name();
    const std::string& get_skdiprfrm_oraniz();
    const std::string& get_skdiprtitle();
    const std::string& get_skdiprto_name();
    const std::string& get_skdiprto_oraniz();
    const std::string& get_skdiss_type();
    const std::string& get_skdissdate_day();
    const std::string& get_skdissdate_month();
    const std::string& get_skdissdate_year();
    const std::string& get_skdissno();
    const std::string& get_skdmodelic();
    const std::string& get_skdremarks();
    const std::string& get_skdsecurity_class();
    const std::string& get_skdsendid();
    const std::string& get_skdseqnum();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_SkdIPRFRevision")

   virtual ~DC_SkdIPRFRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Contmgmts1000dMngd_undef.h>
#endif
