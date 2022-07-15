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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PARTLOGISTICSFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PARTLOGISTICSFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/MrocoreMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAMROCOREMODELMNGD_API PartLogisticsForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    bool get_isSerialized();
    bool get_isLot();
    bool get_isTraceable();
    bool get_isConsumable();
    bool get_isRotable();
    bool get_preserveQuantity();
    bool get_lifeLimited();
    int get_propertyMask();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PartLogisticsForm")

   virtual ~PartLogisticsForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/MrocoreMngd_undef.h>
#endif
