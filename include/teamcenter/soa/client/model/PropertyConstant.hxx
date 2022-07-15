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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_PROPERTYCONSTANT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_PROPERTYCONSTANT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Constant.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API PropertyConstant : public Teamcenter::Soa::Client::Model::Constant
{
public:
    const std::string& get_constant_name();
    const Teamcenter::Soa::Client::StringVector& get_scoped_type_name();
    const Teamcenter::Soa::Client::StringVector& get_scoped_property_name();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("PropertyConstant")

   virtual ~PropertyConstant();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
