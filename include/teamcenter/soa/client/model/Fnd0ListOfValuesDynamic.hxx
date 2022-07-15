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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0LISTOFVALUESDYNAMIC_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0LISTOFVALUESDYNAMIC_HXX

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


class TCSOACLIENTMNGD_API Fnd0ListOfValuesDynamic : public Teamcenter::Soa::Client::Model::ListOfValues
{
public:
    const Teamcenter::Soa::Client::StringVector& get_fnd0query_clause();
    const Teamcenter::Soa::Client::StringVector& get_fnd0filter_attributes();
    const std::string& get_fnd0lov_value();
    const std::string& get_fnd0lov_desc();
    const std::string& get_fnd0query_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0ListOfValuesDynamic")

   virtual ~Fnd0ListOfValuesDynamic();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
