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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_TCPUBLISHINGTECHNICALPORTFOLIO_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_TCPUBLISHINGTECHNICALPORTFOLIO_HXX

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


class TCSOACLIENTMNGD_API TCPublishingTechnicalPortfolio : public Teamcenter::Soa::Client::Model::Dataset
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_TCPublishedPortfolio();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_PortfolioConfiguredPage();
    const Teamcenter::Soa::Client::ModelObjectVector& get_IMAN_PortfolioPage();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("TCPublishingTechnicalPortfolio")

   virtual ~TCPublishingTechnicalPortfolio();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
