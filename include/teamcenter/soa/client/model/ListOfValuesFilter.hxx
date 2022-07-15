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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_LISTOFVALUESFILTER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_LISTOFVALUESFILTER_HXX

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
                class ListOfValues;


class TCSOACLIENTMNGD_API ListOfValuesFilter : public Teamcenter::Soa::Client::Model::ListOfValues
{
public:
    Teamcenter::Soa::Common::AutoPtr<ListOfValues> get_based_on_lov();
    const Teamcenter::Soa::Client::IntVector& get_shown_value_indexes();
    bool get_shown_base_all();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("ListOfValuesFilter")

   virtual ~ListOfValuesFilter();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
