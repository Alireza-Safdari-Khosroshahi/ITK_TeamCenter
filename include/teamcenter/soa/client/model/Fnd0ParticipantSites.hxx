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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0PARTICIPANTSITES_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0PARTICIPANTSITES_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Fnd0ParticipantSites : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Client::IntVector& get_fnd0SiteIdList();
    const std::string& get_fnd0ProjectId();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ParticipantSites")

   virtual ~Fnd0ParticipantSites();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
