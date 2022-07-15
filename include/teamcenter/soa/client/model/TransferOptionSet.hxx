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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TRANSFEROPTIONSET_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TRANSFEROPTIONSET_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class POMImc;
                class TransferMode;


class TCSOACLIENTMNGD_API TransferOptionSet : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    int get_scope();
    Teamcenter::Soa::Common::AutoPtr<POMImc> get_site();
    Teamcenter::Soa::Common::AutoPtr<TransferMode> get_transfermode();
    const Teamcenter::Soa::Client::StringVector& get_option_realnames();
    const Teamcenter::Soa::Client::StringVector& get_option_displaynames();
    const Teamcenter::Soa::Client::StringVector& get_option_descriptions();
    const Teamcenter::Soa::Client::StringVector& get_option_initialvalues();
    const Teamcenter::Soa::Client::StringVector& get_option_groupnames();
    const Teamcenter::Soa::Client::BoolVector& get_option_readonlyflags();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TransferOptionSet")

   virtual ~TransferOptionSet();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
