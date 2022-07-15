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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MES0PDFREPORTTEMPLATE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MES0PDFREPORTTEMPLATE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Dataset.hxx>

#include <teamcenter/soa/client/model/CmtmesMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACMTMESMODELMNGD_API Mes0PDFReportTemplate : public Teamcenter::Soa::Client::Model::Dataset
{
public:
    bool get_mes0DoesContain2D();
    bool get_mes0DoesContain3D();
    bool get_mes0DoesContainSimulation();
    const std::string& get_mes0DataSource();
    const Teamcenter::Soa::Client::StringVector& get_mes0TemplateSpecification();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mes0PDFReportInputRel();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mes0PDFReportTemplate")

   virtual ~Mes0PDFReportTemplate();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CmtmesMngd_undef.h>
#endif
