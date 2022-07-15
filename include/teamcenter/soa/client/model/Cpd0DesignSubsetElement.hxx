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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNSUBSETELEMENT_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CPD0DESIGNSUBSETELEMENT_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Mdl0PositionedModelElement.hxx>

#include <teamcenter/soa/client/model/CpdMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Cpd0CollaborativeDesign;
                class PSBOMViewRevision;


class TCSOACPDMODELMNGD_API Cpd0DesignSubsetElement : public Teamcenter::Soa::Client::Model::Mdl0PositionedModelElement
{
public:
    Teamcenter::Soa::Common::AutoPtr<Cpd0CollaborativeDesign> get_cpd0source_object();
    const std::string& get_cpd0cs_id();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cpd0instance();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cpd0workset_revision();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_cpd0reuseInput();
    Teamcenter::Soa::Common::AutoPtr<PSBOMViewRevision> get_cpd0bvr();
    const std::string& get_cpd0source_object_id();
    const std::string& get_cpd0source_object_name();
    const std::string& get_cpd0source_object_type();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Cpd0DesignSubsetElement")

   virtual ~Cpd0DesignSubsetElement();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CpdMngd_undef.h>
#endif
