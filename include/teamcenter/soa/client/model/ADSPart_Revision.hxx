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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADSPART_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADSPART_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Part_Revision.hxx>

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


class TCSOAADSFOUNDATIONMODELMNGD_API ADSPart_Revision : public Teamcenter::Soa::Client::Model::Part_Revision
{
public:
    Teamcenter::Soa::Common::AutoPtr<ADSTechDocument> get_ads0source_doc_ref();
    const std::string& get_adssource_doc_category();
    const std::string& get_adssource_tdoc_category();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADSPart_Revision")

   virtual ~ADSPart_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AdsfoundationMngd_undef.h>
#endif
