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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MDL0SEARCHCURSOR_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MDL0SEARCHCURSOR_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/RuntimeBusinessObject.hxx>

#include <teamcenter/soa/client/model/AppmodelMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAAPPMODELMODELMNGD_API Mdl0SearchCursor : public Teamcenter::Soa::Client::Model::RuntimeBusinessObject
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_mdl0elements();
    int get_mdl0index();
    int get_mdl0count();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mdl0SearchCursor")

   virtual ~Mdl0SearchCursor();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/AppmodelMngd_undef.h>
#endif
