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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0TWIREFINFOFORM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0TWIREFINFOFORM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0TWIRefInfoForm : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Client::StringVector& get_mes0TWIRefIDs();
    const Teamcenter::Soa::Client::ModelObjectVector& get_mes0ReferencedObjects();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0TWIRefInfoForm")

   virtual ~Mes0TWIRefInfoForm();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
