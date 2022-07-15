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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMVALBOOL_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMVALBOOL_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ParmVal.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Table;


class TCSOACCDMMODELMNGD_API ParmValBool : public Teamcenter::Soa::Client::Model::ParmVal
{
public:
    Teamcenter::Soa::Common::AutoPtr<Table> get_values();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmValBool")

   virtual ~ParmValBool();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
