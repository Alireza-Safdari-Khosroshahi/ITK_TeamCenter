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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRFOLDER_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0BVRFOLDER_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/ImanItemBOPLine.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {


class TCSOACLIENTMNGD_API Mfg0BvrFolder : public Teamcenter::Soa::Client::Model::ImanItemBOPLine
{
public:
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0subFolders();
    const Teamcenter::Soa::Client::ModelObjectVector& get_Mfg0content();
    Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  get_Mfg0Parent();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0BvrFolder")

   virtual ~Mfg0BvrFolder();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
