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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CIV0SCOENTRYREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CIV0SCOENTRYREVISION_HXX

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


class TCSOACONTMGMTS1000D40MODELMNGD_API Civ0SCOEntryRevision : public Teamcenter::Soa::Client::Model::DC_TopicRevision
{
public:
    const std::string& get_skdmodelic();
    const std::string& get_skdpmissuer();
    const std::string& get_skdpmnumber();
    const std::string& get_skdpmvolume();
    const std::string& get_skdqa();
    const std::string& get_skdiss_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Civ0SCOEntryRevision")

   virtual ~Civ0SCOEntryRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Contmgmts1000d40Mngd_undef.h>
#endif
