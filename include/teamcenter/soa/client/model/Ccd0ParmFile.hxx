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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_CCD0PARMFILE_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_CCD0PARMFILE_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/Dataset.hxx>

#include <teamcenter/soa/client/model/CcdmMngd_exports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACCDMMODELMNGD_API Ccd0ParmFile : public Teamcenter::Soa::Client::Model::Dataset
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasInputSource();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Ccd0HasOutputFiles();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Ccd0ParmFile")

   virtual ~Ccd0ParmFile();
};
            }
        }
    }
}
#include <teamcenter/soa/client/model/CcdmMngd_undef.h>
#endif
