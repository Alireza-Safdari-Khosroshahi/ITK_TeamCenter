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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CLS0OBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CLS0OBJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Cls0ClassBase.hxx>

#include <teamcenter/soa/client/model/ClassificationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Icm0;


class TCSOACLASSIFICATIONMODELMNGD_API Cls0Object : public Teamcenter::Soa::Client::Model::Cls0ClassBase
{
public:
    Teamcenter::Soa::Common::AutoPtr<Icm0> get_cls0properties();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cls0Object")

   virtual ~Cls0Object();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ClassificationMngd_undef.h>
#endif
