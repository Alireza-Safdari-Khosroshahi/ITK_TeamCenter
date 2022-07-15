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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADSDRAWING_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADSDRAWING_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Drawing.hxx>

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


class TCSOAADSFOUNDATIONMODELMNGD_API ADSDrawing : public Teamcenter::Soa::Client::Model::Drawing
{
public:
    const std::string& get_adsdistribution_code();
    bool get_adsqualification_req();
    const std::string& get_adssource_document();
    const std::string& get_adssource_doc_revision();
    const std::string& get_adssource_doc_category();
    const std::string& get_adssource_tdoc_category();
    const std::string& get_adssource_doc_org();
    Teamcenter::Soa::Common::AutoPtr<ADSTechDocument> get_ads0source_doc_ref();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADSDrawing")

   virtual ~ADSDrawing();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AdsfoundationMngd_undef.h>
#endif
