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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0SEARCHSLCTCONTENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0SEARCHSLCTCONTENT_HXX

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


class TCSOAAPPMODELMODELMNGD_API Mdl0SearchSlctContent : public Teamcenter::Soa::Client::Model::Mdl0SearchDef
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_mdl0selectedcontents();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mdl0unselectedcontents();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0SearchSlctContent")

   virtual ~Mdl0SearchSlctContent();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
