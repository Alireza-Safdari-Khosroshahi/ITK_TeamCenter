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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADSTECHDOCUMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADSTECHDOCUMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Document.hxx>

#include <teamcenter/soa/client/model/AdsfoundationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAADSFOUNDATIONMODELMNGD_API ADSTechDocument : public Teamcenter::Soa::Client::Model::Document
{
public:
    const std::string& get_adscategory();
    const std::string& get_adstech_doc_category();
    const std::string& get_adsdistribution_code();
    const std::string& get_adsgovt_data_right();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADSTechDocument")

   virtual ~ADSTechDocument();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AdsfoundationMngd_undef.h>
#endif
