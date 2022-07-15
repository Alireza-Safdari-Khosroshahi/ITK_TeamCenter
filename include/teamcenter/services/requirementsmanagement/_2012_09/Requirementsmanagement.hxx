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

#ifndef TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2012_09_REQUIREMENTSMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2012_09_REQUIREMENTSMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Requirementsmanagement
        {
            namespace _2012_09
            {
                class Requirementsmanagement;

class TCSOAREQUIREMENTSMANAGEMENTSTRONGMNGD_API Requirementsmanagement
{
public:

    struct GetBOMLineInfo;

    /**
     * Structure represents the parameters required to get BOMLine after create.
     */
    struct GetBOMLineInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * Parent BOMLine under which newly created BOMLine will be attached.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  selectedBomLine;
        /**
         * Item for which BOMLine needs to be created.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  newComp;
    };




    /**
     * This operation creates a BOMLine for a newly created  Item and adds it to the selected
     * parent BOMLine and checks out the latest revision of newly created Item based on
     * a check-out preference. The inputs structure for this operation contains selected
     * parent BOMLine and newly created Item (e.g. Functionality or Logical Block).
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param inputs
     *        This argument contains parent BOMLine and newly created business object of the Item.
     *        The newly created Item is used to create the BOMLine and to get the latest ItemRevision
     *        for the checkout. The parent BOMLine in the input list is used to attach the newly
     *        created BOMLine.
     *
     * @return
     *         A GetBOMLineResponse with ServiceData element containing the newly created BOMLine.
     *         The following partial error may be returned: 515024  Specified object tag is not
     *         a valid.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData getBomlineAfterCreate ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2012_09::Requirementsmanagement::GetBOMLineInfo >& inputs ) = 0;


protected:
    virtual ~Requirementsmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_undef.h>
#endif

