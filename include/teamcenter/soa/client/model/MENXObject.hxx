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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MENXOBJECT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MENXOBJECT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/GeneralDesignElement.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API MENXObject : public Teamcenter::Soa::Client::Model::GeneralDesignElement
{
public:
    const std::string& get_sub_type();
    const Teamcenter::Soa::Client::IntVector& get_int_attrs();
    const Teamcenter::Soa::Client::DoubleVector& get_double_attrs();
    const Teamcenter::Soa::Client::StringVector& get_string_attrs();
    const Teamcenter::Soa::Client::StringVector& get_int_keys();
    const Teamcenter::Soa::Client::StringVector& get_double_keys();
    const Teamcenter::Soa::Client::StringVector& get_string_keys();
    const Teamcenter::Soa::Client::StringVector& get_menx_properties();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("MENXObject")

   virtual ~MENXObject();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
