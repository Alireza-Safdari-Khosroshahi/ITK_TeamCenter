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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFSEDREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFSEDREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ParmDefRevision.hxx>

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
                class TableDefinition;


class TCSOACCDMMODELMNGD_API ParmDefSEDRevision : public Teamcenter::Soa::Client::Model::ParmDefRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<Table> get_validValues();
    const std::string& get_initialValue();
    Teamcenter::Soa::Common::AutoPtr<TableDefinition> get_tableDefinition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmDefSEDRevision")

   virtual ~ParmDefSEDRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
