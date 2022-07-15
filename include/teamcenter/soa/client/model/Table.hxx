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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TABLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TABLE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class TableCell;
                class TableDefinition;


class TCSOACLIENTMNGD_API Table : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_cells();
    Teamcenter::Soa::Common::AutoPtr<TableCell> get_cells_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<TableDefinition> get_definition();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Table")

   virtual ~Table();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
