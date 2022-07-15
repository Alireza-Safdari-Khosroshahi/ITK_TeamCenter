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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CCD0CONVOVERRIDERECORD_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CCD0CONVOVERRIDERECORD_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Ccd0ParmDefOverrideRecord.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Fnd0GenericConversionRule;


class TCSOACCDMMODELMNGD_API Ccd0ConvOverrideRecord : public Teamcenter::Soa::Client::Model::Ccd0ParmDefOverrideRecord
{
public:
    Teamcenter::Soa::Common::AutoPtr<Fnd0GenericConversionRule> get_ccd0ConversionRule();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ccd0ConvOverrideRecord")

   virtual ~Ccd0ConvOverrideRecord();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
