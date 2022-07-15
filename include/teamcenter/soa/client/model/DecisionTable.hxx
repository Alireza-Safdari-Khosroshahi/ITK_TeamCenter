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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DECISIONTABLE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DECISIONTABLE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/AppExtensionRuleType.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class RBFRow;
                class RBFTableColumn;


class TCSOACLIENTMNGD_API DecisionTable : public Teamcenter::Soa::Client::Model::AppExtensionRuleType
{
public:
    size_t count_rows();
    Teamcenter::Soa::Common::AutoPtr<RBFRow> get_rows_at( size_t inx );
    size_t count_table_columns();
    Teamcenter::Soa::Common::AutoPtr<RBFTableColumn> get_table_columns_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DecisionTable")

   virtual ~DecisionTable();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
