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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDDMREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DC_SKDDMREVISION_HXX

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


class TCSOACONTMGMTS1000DMODELMNGD_API DC_SkdDMRevision : public Teamcenter::Soa::Client::Model::DC_TopicRevision
{
public:
    const std::string& get_skddiscodev();
    const std::string& get_skdiss_type();
    const std::string& get_skdissdate_year();
    const std::string& get_skdissdate_month();
    const std::string& get_skdissdate_day();
    const std::string& get_skdissno();
    const std::string& get_skdmodelic();
    const std::string& get_skdremarks();
    const std::string& get_skdsecurity_class();
    const std::string& get_skdlanguage();
    const std::string& get_skdorig();
    const std::string& get_skdqa();
    const std::string& get_skdrfu();
    const std::string& get_skdrpc();
    const std::string& get_skdsbc();
    const std::string& get_skdapplic_model();
    const std::string& get_skdapplic_type();
    const std::string& get_skddiscode();
    const std::string& get_skddmsize();
    const std::string& get_skdincode();
    const std::string& get_skdincodev();
    const std::string& get_skditemloc();
    const std::string& get_skdlevel();
    const std::string& get_skdskill();
    const std::string& get_skdchapnum();
    const std::string& get_skdsection();
    const std::string& get_skdsdc();
    const std::string& get_skdcidc();
    const std::string& get_skdecscs();
    const std::string& get_skdtechname();
    const std::string& get_skdsubsection();
    const std::string& get_skdinfoname();
    const std::string& get_skdsubject();
    const std::string& get_skdsupeqvc();
    const std::string& get_skdeidc();
    bool get_simulatedTopic();
    const std::string& get_c1k0dmecode();
    const std::string& get_c1k0dmeproducer();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DC_SkdDMRevision")

   virtual ~DC_SkdDMRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Contmgmts1000dMngd_undef.h>
#endif
