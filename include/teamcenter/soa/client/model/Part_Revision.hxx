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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PART_REVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PART_REVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ItemRevision.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Part_Revision : public Teamcenter::Soa::Client::Model::ItemRevision
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Primary_Design_Representation();
    const Teamcenter::Soa::Client::ModelObjectVector& get_TC_Is_Represented_By();
    int get_source();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Part_Revision")

   virtual ~Part_Revision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
