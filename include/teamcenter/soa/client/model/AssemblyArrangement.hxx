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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ASSEMBLYARRANGEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ASSEMBLYARRANGEMENT_HXX

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
                class AssemblyArrangementAnchor;


class TCSOACLIENTMNGD_API AssemblyArrangement : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    const std::string& get_external_uid();
    Teamcenter::Soa::Common::AutoPtr<AssemblyArrangementAnchor> get_arrangement_anchor();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AssemblyArrangement")

   virtual ~AssemblyArrangement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
