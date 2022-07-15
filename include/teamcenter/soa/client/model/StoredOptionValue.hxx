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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_STOREDOPTIONVALUE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_STOREDOPTIONVALUE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/POM_object.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class PSOccurrenceThread;
                class Item;
                class StoredOptionSet;


class TCSOACLIENTMNGD_API StoredOptionValue : public Teamcenter::Soa::Client::Model::POM_object
{
public:
    size_t count_scope();
    Teamcenter::Soa::Common::AutoPtr<PSOccurrenceThread> get_scope_at( size_t inx );
    const std::string& get_option();
    int get_type_specifier();
    const std::string& get_string_value();
    int get_integer_value();
    double get_double_value();
    Teamcenter::Soa::Common::AutoPtr<Item> get_item();
    Teamcenter::Soa::Common::AutoPtr<StoredOptionSet> get_parent();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StoredOptionValue")

   virtual ~StoredOptionValue();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
