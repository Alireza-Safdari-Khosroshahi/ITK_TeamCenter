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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ADSTECHDOCUMENT_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ADSTECHDOCUMENT_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DocumentRevision.hxx>

#include <teamcenter/soa/client/model/AdsfoundationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAADSFOUNDATIONMODELMNGD_API ADSTechDocument_Revision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    const std::string& get_adscustodial_org_name();
    bool get_adsundimensioned();
    const std::string& get_adsdesign_level();
    bool get_adsfind_nbr_parts_list();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ADS_Lists_Parts();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ADS_Lists_PartRevisions();
    const Teamcenter::Soa::Client::ModelObjectVector& get_ADS_Lists_DrawingRevisions();
    const std::string& get_ads0OriginalLocationCode();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ADSTechDocument_Revision")

   virtual ~ADSTechDocument_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AdsfoundationMngd_undef.h>
#endif
