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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFDBLREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARMDEFDBLREVISION_HXX

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
                class Table;
                class Table;
                class TableDefinition;


class TCSOACCDMMODELMNGD_API ParmDefDblRevision : public Teamcenter::Soa::Client::Model::ParmDefRevision
{
public:
    Teamcenter::Soa::Common::AutoPtr<Table> get_maxValues();
    Teamcenter::Soa::Common::AutoPtr<Table> get_minValues();
    double get_resolution_numerator();
    double get_resolution_denominator();
    double get_tolerance();
    int get_precision();
    bool get_isSigned();
    Teamcenter::Soa::Common::AutoPtr<Table> get_initialValues();
    Teamcenter::Soa::Common::AutoPtr<TableDefinition> get_tableDefinition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ParmDefDblRevision")

   virtual ~ParmDefDblRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
