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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TMXVARIANTSET_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TMXVARIANTSET_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Form.hxx>

#include <teamcenter/soa/client/model/CmtemserverMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTEMSERVERMODELMNGD_API TMXVariantSet : public Teamcenter::Soa::Client::Model::Form
{
public:
    const Teamcenter::Soa::Client::StringVector& get_VariantSetExpression();
    const std::string& get_VariantSetID();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TMXVariantSet")

   virtual ~TMXVariantSet();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtemserverMngd_undef.h>
#endif
