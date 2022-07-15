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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0SEARCHPLANEZONE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0SEARCHPLANEZONE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0SearchDef.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAAPPMODELMODELMNGD_API Mdl0SearchPlaneZone : public Teamcenter::Soa::Client::Model::Mdl0SearchDef
{
public:
    int get_mdl0operator();
    const Teamcenter::Soa::Client::DoubleVector& get_mdl0coordinates();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0SearchPlaneZone")

   virtual ~Mdl0SearchPlaneZone();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
