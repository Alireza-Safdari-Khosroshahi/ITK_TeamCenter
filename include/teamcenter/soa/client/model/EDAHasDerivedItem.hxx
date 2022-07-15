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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EDAHASDERIVEDITEM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EDAHASDERIVEDITEM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanRelation.hxx>

#include <teamcenter/soa/client/model/EdaserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAEDASERVERMODELMNGD_API EDAHasDerivedItem : public Teamcenter::Soa::Client::Model::ImanRelation
{
public:
    const std::string& get_derived_data_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EDAHasDerivedItem")

   virtual ~EDAHasDerivedItem();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EdaserverMngd_undef.h>
#endif
