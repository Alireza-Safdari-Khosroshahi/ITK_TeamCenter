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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_FND0RECORDCOLCONVERSION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_FND0RECORDCOLCONVERSION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Fnd0GenericConversionRule.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Fnd0RecordConversion;


class TCSOACLIENTMNGD_API Fnd0RecordColConversion : public Teamcenter::Soa::Client::Model::Fnd0GenericConversionRule
{
public:
    const std::string& get_fnd0DefaultValue();
    size_t count_fnd0RecordConversions();
    Teamcenter::Soa::Common::AutoPtr<Fnd0RecordConversion> get_fnd0RecordConversions_at( size_t inx );
    bool get_fnd0WithInterpolation();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Fnd0RecordColConversion")

   virtual ~Fnd0RecordColConversion();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
