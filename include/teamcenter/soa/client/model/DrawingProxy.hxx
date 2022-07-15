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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_DRAWINGPROXY_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_DRAWINGPROXY_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/TcUsageProxy.hxx>

#include <teamcenter/soa/client/model/CbaMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACBAMODELMNGD_API DrawingProxy : public Teamcenter::Soa::Client::Model::TcUsageProxy
{
public:
    const std::string& get_cba0DRAWINGBASE_UDrawingNomenclature();
    const std::string& get_cba0ALTERNATEREPRESENTATION_UDrawingNomenclature();
    const Teamcenter::Soa::Client::ModelObjectVector& get_drawing_sheets();
    const std::string& get_cba0NUMBERNAMESPACE_UDrawingNomenclature();
    const std::string& get_cba0DRAWINGSOURCETUID_UDrawingSource();
    const std::string& get_cba0SLOC_UDrawingNomenclature();
    const std::string& get_cba0SLOC_UDrawingNomenclatureTUID();
    const std::string& get_cba0DRAWINGREVISION_UDrawingNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UDrawingSource();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UDrawingSource();
    const std::string& get_cba0DRAWINGTYPE_UDrawingSource();
    const std::string& get_cba0RECORDSTATE_UDrawingNomenclature();
    const Teamcenter::Soa::Client::ModelObjectVector& get_representation_for();
    const std::string& get_object_desc();
    const std::string& get_object_name();
    const std::string& get_cba0RECORDSTATE_UDrawingNomenclatureTUID();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UDrawingNomenclatureText();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UDrawingNomenclatureText();
    const std::string& get_cba0DRAWINGMATURITY_UDrawingSource();
    const std::string& get_cba0NOMENCLATURETUID_UDrawingNomenclatureTUID();
    const std::string& get_checked_out();
    bool get_is_modifiable();
    const std::string& get_last_mod_date();
    const std::string& get_cba0NOMENCLATURETUID_UDrawingNomenclature();
    const std::string& get_cba0DRAWINGKEY02_UDrawingNomenclature();
    const std::string& get_cba0DEFAULTSORTCRITERA_UDrawingNomenclature();
    const std::string& get_cba0DRAWINGUID_UDrawingSource();
    const std::string& get_cba0LASTMODIFIEDUSER_UDrawingNomenclature();
    const std::string& get_cba0CREATIONUSER_UDrawingNomenclature();
    const std::string& get_cba0CREATIONUSER_UDrawingNomenclatureTUID();
    const std::string& get_cba0LASTMODIFIEDUSER_UDrawingNomenclatureTUID();
    const std::string& get_cba0NUMBERNAMESPACE_UDrawingNomenclatureText();
    const std::string& get_cba0DRAWINGNOMENCLATURETEXTTUID_UDrawingNomenclatureText();
    const std::string& get_cba0DRAWINGNOMENCLATURETUID_UDrawingSource();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UDrawingNomenclature();
    const std::string& get_cba0SLOC_UDrawingNomenclatureText();
    const std::string& get_cba0LNG_UDrawingNomenclatureText();
    const std::string& get_cba0RECORDSTATE_UDrawingSource();
    const std::string& get_cba0RECORDSTATE_UDrawingNomenclatureText();
    const std::string& get_object_type();
    const std::string& get_owning_user();
    const std::string& get_owning_group();
    const std::string& get_cba0NOMENCLATURETUID_UDrawingNomenclatureText();
    const std::string& get_cba0LASTMODIFIEDUSER_UDrawingSource();
    const std::string& get_cba0CREATIONUSER_UDrawingSource();
    const std::string& get_relation();
    const std::string& get_release_status_list();
    const std::string& get_cba0LASTMODIFIEDUSER_UDrawingNomenclatureText();
    const std::string& get_cba0CREATIONUSER_UDrawingNomenclatureText();
    const std::string& get_cba0DRAWINGNOMENCLATURETUID_UDrawingNomenclature();
    const std::string& get_cba0DEFAULTREASONFORASSIGNMENT_UDrawingNomenclatureText();
    const std::string& get_cba0DRAWINGNAME_UDrawingNomenclatureText();
    const std::string& get_cba0SYSTEMGENERATED_UDrawingNomenclature();
    const std::string& get_cba0DEFAULTLNG_UDrawingNomenclature();
    const std::string& get_cba0SLOC_UDrawingSource();
    const std::string& get_cba0DRAWINGUIDNAMESPACE_UDrawingSource();
    const std::string& get_cba0DRAWINGSYSTEMTUID_UDrawingSource();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UDrawingNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UDrawingNomenclature();
    const Teamcenter::Soa::Common::DateTime& get_cba0CREATIONTIME_UDrawingNomenclatureTUID();
    const Teamcenter::Soa::Common::DateTime& get_cba0LASTMODIFIEDTIME_UDrawingNomenclatureTUID();
    const std::string& get_cba0DRAWINGKEY03_UDrawingNomenclature();
    const std::string& get_cba0DEFAULTDRAWINGNAME_UDrawingNomenclature();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("DrawingProxy")

   virtual ~DrawingProxy();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CbaMngd_undef.h>
#endif
