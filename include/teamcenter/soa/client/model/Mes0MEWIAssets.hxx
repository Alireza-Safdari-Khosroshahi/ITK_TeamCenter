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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0MEWIASSETS_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0MEWIASSETS_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/FullText.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0MEWIAssets : public Teamcenter::Soa::Client::Model::FullText
{
public:
    const Teamcenter::Soa::Client::StringVector& get_mes0WIStringKeys();
    const Teamcenter::Soa::Client::StringVector& get_mes0WIStrings();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0MEWIAssets")

   virtual ~Mes0MEWIAssets();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
