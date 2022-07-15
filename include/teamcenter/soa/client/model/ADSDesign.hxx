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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADSDESIGN_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADSDESIGN_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Design.hxx>

#include <teamcenter/soa/client/model/AdsfoundationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class ADSTechDocument;


class TCSOAADSFOUNDATIONMODELMNGD_API ADSDesign : public Teamcenter::Soa::Client::Model::Design
{
public:
    const std::string& get_adsdesign_category();
    const std::string& get_adsdistribution_code();
    const std::string& get_adsqualification_req();
    bool get_adsinstallation();
    const std::string& get_adsassembly_type();
    bool get_adsspecial_handling();
    const std::string& get_adssource_document();
    const std::string& get_adssource_doc_revision();
    const std::string& get_adssource_doc_category();
    const std::string& get_adssource_tdoc_category();
    const std::string& get_adssource_doc_org();
    Teamcenter::Soa::Common::AutoPtr<ADSTechDocument> get_ads0source_doc_ref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADSDesign")

   virtual ~ADSDesign();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AdsfoundationMngd_undef.h>
#endif
