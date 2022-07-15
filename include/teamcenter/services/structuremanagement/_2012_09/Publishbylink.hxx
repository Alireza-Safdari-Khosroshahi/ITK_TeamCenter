/* 
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.
 ==================================================
 Copyright 2012
 Siemens Product Lifecycle Management Software Inc.
 All Rights Reserved.
 ==================================================
 Copyright 2012 Siemens Product Lifecycle Management Software Inc. All Rights Reserved.

 ==================================================

   Auto-generated source from service interface.
                 DO NOT EDIT

 ==================================================
*/

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_PUBLISHBYLINK_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_09_PUBLISHBYLINK_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            namespace _2012_09
            {
                class Publishbylink;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Publishbylink
{
public:





    /**
     * Finds and deletes <b>PublishLink</b> for input source <b>BOMLine</b> objects.
     * <br>
     * <br>
     * The <b>AbsOccXform</b> of the target <b>BOMLine</b> objects will be deleted if <code>dataToUnpublish</code>
     * is TRANSFORM. All in context JTs of the target <b>BOMLine</b> objects will be unattached
     * if <code>dataToUnpublish</code> is SHAPE. If all data(as of now TRANSFORM and SHAPE
     * only) needs to be removed then value of <code>dataToUnpublish</code> should be ALL.
     * None of the published data will be impacted when <code>dataToPublish</code> is empty
     * string.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Delete <b>PublishLink</b> and unpublish data from target <b>BOMLine</b>.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Part BOM independence - Teamcenter offers CAD and BOM independence through which
     * customer can have separation of design and part related information so that both
     * part and design structures can evolve at different pace.
     *
     * @param sourceBOMLines
     *        Source <b>BOMLine</b> objects for which  <b>PublishLink</b> to be deleted. The <b>PublishLink</b>
     *        found is used to find target <b>BOMLine</b> objects before <b>PublishLink</b>s are
     *        deleted.
     *
     * @param dataToUnpublish
     *        Data to unpublish. Valid values are TRANSFORM, SHAPRE, ALL or empty string. The value
     *        is case sensitive.
     *
     * @return
     *         <code>ServiceData</code> containing partial error information.
     *         <br>
     *         <br>
     *         46002 Invalid tag received by BOM Module.
     *         <br>
     *         43111 Invalid source as input.
     *
     *
     * @exception ServiceException
     *           
     */
    virtual Teamcenter::Soa::Client::ServiceData deleteLinksForSource2 ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& sourceBOMLines,
        const std::string&  dataToUnpublish ) = 0;


protected:
    virtual ~Publishbylink() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

