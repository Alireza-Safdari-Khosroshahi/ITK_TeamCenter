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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CLS0CLASSBASE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CLS0CLASSBASE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0ModelElement.hxx>

#include <teamcenter/soa/client/model/ClassificationMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLASSIFICATIONMODELMNGD_API Cls0ClassBase : public Teamcenter::Soa::Client::Model::Mdl0ModelElement
{
public:
    const std::string& get_cls0object_id();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cls0classified_object();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cls0ClassBase")

   virtual ~Cls0ClassBase();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/ClassificationMngd_undef.h>
#endif
