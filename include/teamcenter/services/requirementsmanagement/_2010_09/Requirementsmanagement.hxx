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

#ifndef TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2010_09_REQUIREMENTSMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_REQUIREMENTSMANAGEMENT__2010_09_REQUIREMENTSMANAGEMENT_HXX

#include <teamcenter/soa/client/model/Fnd0BuildingBlockBOMLine.hxx>


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
            namespace _2010_09
            {
                class Requirementsmanagement;

class TCSOAREQUIREMENTSMANAGEMENTSTRONGMNGD_API Requirementsmanagement
{
public:

    struct MoveLineInfo;
    struct MoveLineResponse;

    /**
     * <code>MoveLineInfo</code> structure represents the parameters required to re-sequence
     * the selected <b>Fnd0BuildingBlockBOMLine</b> object in the BOM structure.
     */
    struct MoveLineInfo
    {
        /**
         * A unique string supplied by the caller. This ID is used to identify return data elements
         * and partial errors associated with this input structure.
         */
        std::string clientId;
        /**
         * The operation integer value to decide the operation performed. Following operation
         * can be supported by <code>MoveLineInfo</code>.
         * <br>
         * <ul>
         * <li type="disc">Move Up
         * </li>
         * <li type="disc">Move Down
         * </li>
         * <li type="disc">Promote
         * </li>
         * <li type="disc">Demote
         * </li>
         * <li type="disc">Edit Number
         * </li>
         * </ul>
         */
        int operation;
        /**
         * The <b>Fnd0BuildingBlockBOMLine</b> object, on which operation will be performed.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Fnd0BuildingBlockBOMLine>  selectedLine;
        /**
         * The new Number property value, will be used when Edit Number operation will be performed.
         * Based on new property value selected BOM line will be moved in the BOM structure.
         */
        std::string newNumber;
    };

    /**
     * MoveLineResponse structure contains the ServiceData object.
     */
    struct MoveLineResponse
    {
        /**
         * The Service Data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This operation manipulates the <b>BOMLine</b> Structure (<b>Requirement</b>/ <b>Function</b>/
     * <b>SEBlock</b> structure) by moving the selected <b>BOMLine</b> object either Upwards,
     * Downwards or to a specific position. A <b>Number</b> property will be updated for
     * selected <b>Fnd0BuildingBlockBOMLine</b> object along with its children.
     * <br>
     * Following operation are supported by this service operation.
     * <br>
     * <ul>
     * <li type="disc">Move Up - To move up the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, if a requirement structure
     * "Req_01", we have two children "SubReq_01" and "SubReq_02". In move up structure
     * modification can be done with respect to the parent. Requirements "SubReq_01" and
     * "SubReq_02" can be move up in context of parent "Req_01".
     * </li>
     * <li type="disc">Move Down - To move down the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, if a requirement structure
     * "Req_01", we have two children "SubReq_01" and "SubReq_02". In move down structure
     * modification can be done with respect to the parent. Requirements "SubReq_01" and
     * "SubReq_02" can be move down in context of parent "Req_01".
     * </li>
     * <li type="disc">Promote - To indent the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, promote a requirement
     * previously occupying level 2, with number "1.1", moves to the level 1, with number
     * "2.0". Children previously occupying level 3 with number "1.1.1", moves to the level
     * 2, with number "2.1".
     * </li>
     * <li type="disc">Demote - To out-dent the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. For instance, demote a requirement
     * previously occupying level 2, with number "1.0", moves to the level 3, with number
     * "1.1.1". Children previously occupying level 3, with number "1.1.1", moves to the
     * level 4, with number "1.1.1.1".
     * </li>
     * <li type="disc">Edit Number - To move the selected BOM line (<b>Fnd0BuildingBlockBOMLine</b>)
     * up in the structure with respect to its sibling. You can able to move selected BOM
     * line object from one level to other and from one parent to other parent.  For instance,
     * if a requirement has number "1.1.1" which means it is under parent "1.1". If the
     * number changed to "1.1.3", the requirement is repositioned under the parent. If the
     * number is changed to "2.1", then requirement will be removed from the parent and
     * put under the sibling of the parent.
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * You can manipulate the hierarchy for a selected <b>Requirement</b> /<b>Function</b>/
     * <b>SEBlockBOMLine</b> object by using the moveLine operation. The given <b>Fnd0BuildingBlockBOMLine</b>
     * object will be moved as per the choice along with its children and the Number property
     * will be updated with new values.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Requirement Management - Application to manage Requirments in Tc
     *
     * @param input
     *        A list of <code>MoveLineInfo</code> structures which hold the required information
     *        to move selected <b>Fnd0BuildingBlockBOMLine</b> object along with its sibling.
     *
     * @return
     *         ServiceData object is returned. The updated <b>Fnd0BuildingBlockBOMLine</b> object
     *         is returned in the updated object list of ServiceData. Any failure will be returned
     *         with client id mapped to error message in the ServiceData list of partial errors.
     *         Following error codes are returned in the ServiceData.
     *         <br>
     *         <ul>
     *         <li type="disc">266001&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be Move Up in the BOM structure because it is the top children for
     *         parent object of selected object.
     *         </li>
     *         <li type="disc">266002&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be Move Down in the BOM structure because it is the last children
     *         for parent object of selected object.
     *         </li>
     *         <li type="disc">266003&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be promoted in the BOM structure because selected object could not
     *         be indent.
     *         </li>
     *         <li type="disc">266004&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         could not be demoted in the BOM structure because selected object could not be out-dented.
     *         </li>
     *         <li type="disc">266005&nbsp;&nbsp;&nbsp;&nbsp;If specified <b>Fnd0BuildingBlockBOMLine</b>
     *         object could not be Move to any level in the BOM structure as pre input number property
     *         value.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Requirementsmanagement::_2010_09::Requirementsmanagement::MoveLineResponse moveLine ( const std::vector< Teamcenter::Services::Requirementsmanagement::_2010_09::Requirementsmanagement::MoveLineInfo >& input ) = 0;


protected:
    virtual ~Requirementsmanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/requirementsmanagement/Requirementsmanagement_undef.h>
#endif

