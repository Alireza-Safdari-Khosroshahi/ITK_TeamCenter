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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CIV0PM4REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CIV0PM4REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DC_SkdPMRevision.hxx>

#include <teamcenter/soa/client/model/Contmgmts1000d40Mngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACONTMGMTS1000D40MODELMNGD_API Civ0PM4Revision : public Teamcenter::Soa::Client::Model::DC_SkdPMRevision
{
public:
    const std::string& get_civ0inwork();
    const std::string& get_civ0country();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Civ0PM4Revision")

   virtual ~Civ0PM4Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/Contmgmts1000d40Mngd_undef.h>
#endif
