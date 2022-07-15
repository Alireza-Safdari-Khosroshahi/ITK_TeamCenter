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

#ifndef TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEPOSITIONDIAGRAM_HXX
#define TEAMCENTER_SOA_CLIENT_MODEL_MFG0MEPOSITIONDIAGRAM_HXX

#include <new>
#include <teamcenter/soa/common/MemoryManager.hxx>
#include <teamcenter/soa/common/DateTime.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>

#include <teamcenter/soa/client/model/WorkspaceObject.hxx>

#include <teamcenter/soa/client/SoaClientMngdExports.h>

namespace Teamcenter
{
    namespace Soa
    {
        namespace Client
        {
            namespace Model
            {
                class Mfg0MEExecutionPosnStorage;
                class Dataset;


class TCSOACLIENTMNGD_API Mfg0MEPositionDiagram : public Teamcenter::Soa::Client::Model::WorkspaceObject
{
public:
    size_t count_Mfg0ExecutionPositions();
    Teamcenter::Soa::Common::AutoPtr<Mfg0MEExecutionPosnStorage> get_Mfg0ExecutionPositions_at( size_t inx );
    Teamcenter::Soa::Common::AutoPtr<Dataset> get_Mfg0DiagramPicture();
    const Teamcenter::Soa::Client::IntVector& get_Mfg0MatrixSize();


   SOA_CLASS_NEW_OPERATORS_WITH_IMPL("Mfg0MEPositionDiagram")

   virtual ~Mfg0MEPositionDiagram();
};
            }
        }
    }
}
#include <teamcenter/soa/client/SoaClientMngdUndef.h>
#endif
