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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPDIELINEREVISION_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPDIELINEREVISION_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/DocumentRevision.hxx>

#include <teamcenter/soa/client/model/PkgartMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class UnitOfMeasure;


class TCSOAPKGARTMODELMNGD_API CPDieLineRevision : public Teamcenter::Soa::Client::Model::DocumentRevision
{
public:
    double get_dieline_length();
    double get_width();
    Teamcenter::Soa::Common::AutoPtr<UnitOfMeasure> get_unit_of_measure();
    const Teamcenter::Soa::Client::ModelObjectVector& get_CP_package_items();
    const Teamcenter::Soa::Client::ModelObjectVector& get_pka0CP_has_artworks();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("CPDieLineRevision")

   virtual ~CPDieLineRevision();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/PkgartMngd_undef.h>
#endif
