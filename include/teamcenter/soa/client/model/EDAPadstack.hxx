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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_EDAPADSTACK_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_EDAPADSTACK_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GeneralDesignElement.hxx>

#include <teamcenter/soa/client/model/EdalibraryMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOAEDALIBRARYMODELMNGD_API EDAPadstack : public Teamcenter::Soa::Client::Model::GeneralDesignElement
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_reference();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("EDAPadstack")

   virtual ~EDAPadstack();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/EdalibraryMngd_undef.h>
#endif
