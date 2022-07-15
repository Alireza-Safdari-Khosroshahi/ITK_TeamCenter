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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_RBFROW_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_RBFROW_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/BusinessElement.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class RBFCell;


class TCSOACLIENTMNGD_API RBFRow : public Teamcenter::Soa::Client::Model::BusinessElement
{
public:
    size_t count_cells();
    Teamcenter::Soa::Common::AutoPtr<RBFCell> get_cells_at( size_t inx );


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("RBFRow")

   virtual ~RBFRow();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
