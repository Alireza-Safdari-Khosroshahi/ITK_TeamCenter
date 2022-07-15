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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCGDEOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_ABSOCCGDEOBJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/AbsOccData.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class GeneralDesignElement;


class TCSOACLIENTMNGD_API AbsOccGdeObject : public Teamcenter::Soa::Client::Model::AbsOccData
{
public:
    Teamcenter::Soa::Common::AutoPtr<GeneralDesignElement> get_gde_object();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("AbsOccGdeObject")

   virtual ~AbsOccGdeObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
