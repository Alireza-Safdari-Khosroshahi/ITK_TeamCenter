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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_UGALTREP_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_UGALTREP_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Dataset.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API UGALTREP : public Teamcenter::Soa::Client::Model::Dataset
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_promotion();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_capture();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_wave_geometry();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_wave_part_link();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_wave_position();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_UG_expression();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_Drawing();
    const std::string& get_standard_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("UGALTREP")

   virtual ~UGALTREP();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
