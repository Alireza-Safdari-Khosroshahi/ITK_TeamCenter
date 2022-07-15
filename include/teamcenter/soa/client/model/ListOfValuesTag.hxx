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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_LISTOFVALUESTAG_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_LISTOFVALUESTAG_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ListOfValues.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API ListOfValuesTag : public Teamcenter::Soa::Client::Model::ListOfValues
{
public:
    const std::string& get_lov_reference_class();
    const std::string& get_lov_reference_attr();
    const Teamcenter::Soa::Client::ModelObjectVector& get_lov_values();
    const Teamcenter::Soa::Client::StringVector& get_lov_value_descriptions();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ListOfValuesTag")

   virtual ~ListOfValuesTag();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
