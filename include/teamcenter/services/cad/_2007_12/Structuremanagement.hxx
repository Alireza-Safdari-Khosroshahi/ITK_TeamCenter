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

#ifndef TEAMCENTER_SERVICES_CAD__2007_12_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2007_12_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/services/cad/_2007_01/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2007_06/Structuremanagement.hxx>
#include <teamcenter/services/cad/_2007_09/Structuremanagement.hxx>
#include <teamcenter/soa/client/model/AssemblyArrangement.hxx>
#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/ItemRevision.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/cad/Cad_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Cad
        {
            namespace _2007_12
            {
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct BomLineVariantCondition;
    struct ClassicOptionData;
    struct ClassicOptionsResponse;
    struct CreateOrUpdateAbsoluteStructureInfo2;
    struct CreateOrUpdateAbsoluteStructurePref2;
    struct CreateOrUpdateRelativeStructureInfo2;
    struct CreateOrUpdateRelativeStructurePref2;
    struct DeleteAssemblyArrangementsInfo2;
    struct DeleteAssemblyArrangementsPref;
    struct DeleteRelativeStructureInfo2;
    struct DeleteRelativeStructurePref2;
    struct VariantConditionResponse;

    /**
     * This contains the variant condition information for a given <b>BOMLine</b> object.
     */
    struct BomLineVariantCondition
    {
        /**
         * Refers to <b>BOMLine</b> object on which variant condition are defined.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  bomLine;
        /**
         * Refers to a list of <b>VariantCondInfo</b> struct objects which has classic variant
         * condition information.
         */
        std::vector< Teamcenter::Services::Cad::_2007_09::Structuremanagement::VariantCondInfo > conditionClauses;
    };

    /**
     * Contains the option information for a single item revision.
     */
    struct ClassicOptionData
    {
        /**
         * itemRevision
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRevision;
        /**
         * optionData
         */
        std::vector< Teamcenter::Services::Cad::_2007_06::Structuremanagement::ClassicOptionInfo > optionData;
    };

    /**
     * Contains the option information for a set of <b>ItemRevision</b> objects.
     */
    struct ClassicOptionsResponse
    {
        /**
         * Refers to a list of <code>ClassicOptionData</code> struct, which has <b>ItemRevision</b>
         * and corresponding classic variant option list.
         */
        std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::ClassicOptionData > itemRevisionOptionData;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the service operation, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Contains Last Modified Date of BVR, contextItemRev, List of AbsOccInfo for bvr qualified
     * overrides and a list of AssemblyArrangementInfo for bvr/arrangement qualified overrides.
     */
    struct CreateOrUpdateAbsoluteStructureInfo2
    {
        /**
         * Last Modified Date of BVR
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * ItemRevision object reference of the context assembly to create/validate the occurrence,
         * required reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  contextItemRev;
        /**
         * List of AbsOccInfo for bvr qualified overrides
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AbsOccInfo > bvrAbsOccInfo;
        /**
         * List of AssemblyArrangementInfo for bvr/arrangement qualified overrides, may be null
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::AssemblyArrangementInfo > arrAbsOccInfo;
    };

    /**
     * Contains a flag to check whether BVR needs to be modified, if input last modified
     * date is different from actual and a cadOccIdAttrName which identifies the BOMLine
     * attribute that is used to identify relative occurrences to update.
     */
    struct CreateOrUpdateAbsoluteStructurePref2
    {
        /**
         * Flag to check whether BVR needs to be modified, if input last modified date is different
         * from actual.
         */
        bool overwriteForLastModDate;
        /**
         * Identifies the BOMLine attribute that is used to identify relative occurrences to
         * update.
         */
        std::string cadOccIdAttrName;
    };

    /**
     * Contains lastModifiedOfBVR, a parent ItemRevision object, list of type RelativeStructureChildInfo
     * and a  boolean value to convey precision of the BVR.
     */
    struct CreateOrUpdateRelativeStructureInfo2
    {
        /**
         * Last Modified Date of BVR
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * ItemRevision object reference for which the context assembly is created or updated,
         * required reference
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  parent;
        /**
         * List of type RelativeStructureChildInfo
         */
        std::vector< Teamcenter::Services::Cad::_2007_01::Structuremanagement::RelativeStructureChildInfo > childInfo;
        /**
         * Flag for updating the BVR to precise(true)/imprecise(false)
         */
        bool precise;
    };

    /**
     * Contains overwriteForLastModDate, cadOccIdAttrName and a list of item types.
     */
    struct CreateOrUpdateRelativeStructurePref2
    {
        /**
         * Flag to check whether BVR needs to be modified, if input last modified date is different
         * from actual.
         */
        bool overwriteForLastModDate;
        /**
         * String representing the occurrence note type which holds the value for the CAD occurrence
         * id or PSOccurrenceThread uid
         */
        std::string cadOccIdAttrName;
        /**
         * List of item types that the client is interested in, such that if the overall structure
         * in Teamcenter contains structure relating to other item types or subtypes not in
         * this list, that structure will not be deleted if this operation is complete.
         */
        std::vector< std::string > itemTypes;
    };

    /**
     * Information to delete assembly arrangements.
     */
    struct DeleteAssemblyArrangementsInfo2
    {
        /**
         * Last modified date of BOM view revision object under the input <code>itemRev</code>.
         * This input is not required.  If this input date is different than the current last
         * modified date and the <code>overwriteForLastModDate</code> preference is false the
         * input will be ignored and processing will continue with the next input.  In this
         * scenario, error 215033 will be returned.  If the dates are different and the <code>overwriteForLastModDate</code>
         * preference is true, processing will continue with the current input, the BVR will
         * be modified and the arrangements deleted.  In this scenario, error 215034 will be
         * returned.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * Object reference of the item revision context assembly from which the assembly arrangements
         * are to be removed.  This is a required input.  An error will be returned if a valid
         * <code>itemRev</code> is not specified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  itemRev;
        /**
         * List of assembly arrangement object references to be deleted.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::AssemblyArrangement>  > arrangements;
    };

    /**
     * Preference structure for <code>deleteAssemblyArrangements</code>.
     */
    struct DeleteAssemblyArrangementsPref
    {
        /**
         * Flag to check whether the structure needs to be updated if the input last modified
         * date is different from the current last modified date of the object in Teamcenter.
         * If false, but the <code>DeleteAssemblyArrangementsInfo2</code> <code>lastModifiedOfBVR</code>
         * input specified is different than the set modified date, partial error 215033 will
         * be returned.
         */
        bool overwriteForLastModDate;
    };

    /**
     * Contains lastModifiedOfBVR, parent itemRevision and childInfo.
     */
    struct DeleteRelativeStructureInfo2
    {
        /**
         * Last Modified Date of BVR
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * ItemRevision object reference for the context assembly from which children are to
         * be removed
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  parent;
        /**
         * List of identifiers of the relative occurrences to be deleted. This is the CAD occurrence
         * id or PSOccurrenceThread uid to uniquely identify the occurrence under a particular
         * context Item Revision.
         */
        std::vector< std::string > childInfo;
    };

    /**
     * Preference structure for <code>deleteRelativeStructure</code>.
     */
    struct DeleteRelativeStructurePref2
    {
        /**
         * Flag to check whether the structure needs to be updated if the input last modified
         * date is different from the current last modified date of the object in Teamcenter.
         * If false, but the <code>DeleteRelativeStructureInfo3</code> <code>lastModifiedOfBVR</code>
         * input specified is different than the set modified date, partial error 215033 will
         * be returned.
         */
        bool overwriteForLastModDate;
        /**
         * The <b>BOMLine</b> attribute that contains the CAD occurrence identifier.
         */
        std::string cadOccIdAttrName;
    };

    /**
     * This contains the variant condition information for a set of <b>BOMLine</b> objects.
     */
    struct VariantConditionResponse
    {
        /**
         * Refers to a list of <code>BomLineVariantCondition</code> struct objects, contains
         * the variant condition on <b>BOMLine</b> object.
         */
        std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::BomLineVariantCondition > variantConditions;
        /**
         * The SOA framework object containing objects that were created, deleted, or updated
         * by the Service, plain objects, and error information.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * This is the overloaded function of Cad::_2007_01::StructureManagement::createOrUpdateAbsoluteStructure.
     * It takes an additional variable into the CreateOrUpdateAbsoluteStructurePref2 structure
     * to hold the last modified date of the BVR with an extra preference value to check
     * it with server modifed date to make a decision whether we want to make modification
     * on BVR. CreateOrUpdateAbsoluteStucture allows the user to find or create the absolute
     * structure network of objects and relations for the input model. The service first
     * attempts to check for the presence of duplicate context objects and then validate
     * the existence of the structure to be created. If any of the objects exist and the
     * input attribute values differ from those already set, an attempt is made to update
     * the values. Note: The following AbsOccData attributes are not supported for arrangement
     * qualified overrides. These attributes can only be overridden at the bvr level (which
     * applies to all arrangements). If these attributes are overridden in the AssemblyArrangementInfo,
     * they will be ignored. 1.child item 2.GDE object 3.instance number 4.occurrence name
     * 5.note 6.occurrence type 7.Variant instance As we process one contextItemRev object
     * at one time, it is assumed that all edits for a given contextItemRev come in as one
     * set of input.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        List of input structures that defines all the occurrence for a given parent
     *
     * @param bomViewTypeName
     *        Type of BOMView
     *
     * @param complete
     *        flag that if true signifies that the structure represented in the input is the full
     *        representation of the structure under the input parent. Any other structure relations
     *        that exist in Teamcenter but are not represented here will be removed. Upper and
     *        lower qualified (including arrangements) absolute occurrence overrides will not be
     *        implicitly deleted or removed.  Please use the deleteAssemblyArrangements operation.
     *
     * @param pref
     *        preference structure specific for this service
     *
     * @return
     *         Output is an explicit response consisting of a map of input clientId for the absolute
     *         occurrence to created/updated/ found absolute occurrence and map of input client
     *         id to created/updated/found AssemblyArrangement.
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if an invalid BOM view type is specified in bomViewTypeName.
     *           <br>
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateAbsoluteStructureResponse createOrUpdateAbsoluteStructure ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateAbsoluteStructureInfo2 >& info,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateAbsoluteStructurePref2&  pref ) = 0;

    /**
     * This is the overloaded function of Cad::_2007_01::StructureManagement::createOrUpdateRelativeStructure.
     * It takes an additional variable into the CreateOrUpdateRelativeStructureInfo2 structure
     * to hold the last modified date of the BVR with an extra preference value to check
     * it with server modifed date to make a decision whether we want to make modification
     * on BVR. Create or update the relative structure objects and relations for the input
     * model. The service first attempts to check for the presence of duplicate context
     * objects and then validate the existence of the structure to be created. If any of
     * the objects exist but the input attribute values that differ from those already set,
     * an attempt is made to update the values if possible. This service assumes the input
     * is in a bottom-up format such that if any failures occur, the structure that is created
     * will be consistent. No attempt is made in the service to rearrange the input and
     * process it in the correct order. As we process one parent context Object at one time,
     * it is assumed that all edits for a given parent context come in as one set of input.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        List of input structures that defines all the occurrence for a given parent
     *
     * @param bomViewTypeName
     *        Type of BOMView to create
     *
     * @param complete
     *        Flag that if true signifies that the structure represented in the input is the full
     *        representation of the structure under the input parent.  Any other structure relations
     *        that exist in Teamcenter but are not represented here will be removed.
     *
     * @param pref
     *        Preference structure specific for this service
     *
     * @return
     *         Output is an explicit response consisting of a map of input clientId string to created/updated/found
     *         occurrence thread reference.
     *
     *
     * @exception ServiceException
     *           Service exceptions are thrown for the following error situations:
     *           <br>
     *           <br>
     *           215005: The BOM view revision (BVR) is not checked out by the current user.
     *           <br>
     *           215006: The BOM view revision is checked out by another user.
     *           <br>
     *           215009: The object type name specified in the input preference does not exist.
     *           <br>
     *           215010: The input CAD occurrence identifier does not correspond to a valid BOM line.
     *           This is an error when the complete input is false.
     *           <br>
     *           215033: The input last modified date differs from actual.
     *           <br>
     *           215034: The dataset or BVR was modified even when the input last modified dates was
     *           different than the current last modified data.
     *           <br>
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::CreateOrUpdateRelativeStructureResponse createOrUpdateRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateRelativeStructureInfo2 >& inputs,
        const std::string&  bomViewTypeName,
        bool complete,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::CreateOrUpdateRelativeStructurePref2&  pref ) = 0;

    /**
     * This operation deletes assembly arrangements and all the absolute occurrence data
     * associated with the assembly arrangements.  It also deletes the relation between
     * assembly arrangements and the BOM view revision object. The last modified date of
     * the BVR can be specified for comparison against the last modified date in Teamcenter
     * to ensure the BVR that contains the arrangement has not changed outside of this client
     * context.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User deletes an existing assembly arrangement from an existing assembly.
     * <br>
     * <br>
     * For this operation, the assembly is passed in as the <code>itemRev</code> and the
     * assembly arrangement is passed in through <code>arrangements</code>.  The assembly
     * arrangement is removed from the assembly, as well as the relation between the arrangement
     * and the BVR, and the UID of the deleted arrangement is added to the <b>ServiceData</b>
     * list of deleted objects.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateAbsoluteStructure
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param info
     *        List of item revisions and the assembly arrangements to delete from the found BOM
     *        view revision.
     *
     * @param bomViewTypeName
     *        The BOM view type used to find the existing BOM view object.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         <code>ServiceData</code><b> </b>which<b> </b>contains<b> </b>the UIDs of any deleted
     *         assembly arrangements.
     *         <br>
     *         <br>
     *         The following errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215005: The BOM view revision is not checked out by the current user.
     *         </li>
     *         <li type="disc">215006: The BOM view revision is checked out by another user.
     *         </li>
     *         <li type="disc">215033: The input last modified date differs from actual.
     *         </li>
     *         <li type="disc">215034: The dataset or BOM view revision was modified even when the
     *         input last modified dates was different than the current last modified data.
     *         </li>
     *         <li type="disc">215042: The Item was not found for the input itemRev.
     *         </li>
     *         <li type="disc">215043: The BOM view revision was not found for the input itemRev.
     *         </li>
     *         <li type="disc">215044: The BOM view was not found for the item.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           Service Exception&nbsp;&nbsp;&nbsp;&nbsp;Thrown if an invalid BOM view type is
     *           specified in <code>bomViewTypeName</code>.
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteAssemblyArrangementsResponse deleteAssemblyArrangements ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteAssemblyArrangementsInfo2 >& info,
        const std::string&  bomViewTypeName,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteAssemblyArrangementsPref&  pref ) = 0;

    /**
     * Deletes one or more first level children of a parent assembly.  This is the overloaded
     * function of Cad::_2007_01::StructureManagement::deleteRelativeStructure. It takes
     * an additional variable into the DeleteRelativeStructureInfo2 structure to hold the
     * last modified date of the BVR with an extra preference value to check it with server
     * modifed date to make a decision whether we want to make modification on BVR.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        List input of structures that defines the parent and first level children to be deleted.
     *
     * @param bomViewTypeName
     *        Qualifies the specified parent item revision(s) to identify a unique BOM   view revision.
     *
     * @param pref
     *        Preference structure specific for this service
     *
     * @return
     *         The ServiceData contains the UIDs of any deleted occurrences
     *
     *
     * @exception ServiceException
     *           Service Exception    Thrown if an invalid BOM view type is specified in bomViewTypeName.
     *           <br>
     */
    virtual Teamcenter::Services::Cad::_2007_01::Structuremanagement::DeleteRelativeStructureResponse deleteRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteRelativeStructureInfo2 >& inputs,
        const std::string&  bomViewTypeName,
        const Teamcenter::Services::Cad::_2007_12::Structuremanagement::DeleteRelativeStructurePref2&  pref ) = 0;

    /**
     * This operation is to find classic variant options defined on an <b>ItemRevision</b>
     * object(s).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user can use this operation to find all the classic variant options defined on
     * given <b>ItemRevision</b> object. The option and values can be used for configuration
     * or creating other related objects like variant conditions, constraint (defaults,
     * derived defaults and rule checks) rules or <b>VariantRule</b> objects.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputRevisions
     *        This is list of <b>ItemRevision</b> object on which variant options are to be queried.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *
     */
    virtual Teamcenter::Services::Cad::_2007_12::Structuremanagement::ClassicOptionsResponse queryClassicOptions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ItemRevision>  >& inputRevisions ) = 0;

    /**
     * This operation is to find a variant condition value ( load if - this is a type of
     * variant expression represents variant condition) for a <b>BOMLine</b> object.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * The user needs variant condition defined on the <b>BOMLine</b> object, for display
     * or editing purpose.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Product Structure Authoring - The application that allows people to create and manage
     * product structure using the various components such as configuration management;
     * option and variants etc.
     *
     * @param inputBomLines
     *        This has the list of <b>BOMLine</b> objects, on which variant condition are defined.
     *
     * @return
     *         The <code>serviceData</code> returned with objects in case of success scenario. In
     *         case of failure scenario, this will return partial errors with <code>serviceData</code>
     *         with original input object(s) if any.
     *         <br>
     *         <br>
     *         Some of the application level errors codes are listed as below.
     *         <br>
     *         <ul>
     *         <li type="disc">46001 Invalid tag received by BOM Module
     *         </li>
     *         <li type="disc">46067 Invalid variant condition clause.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Cad::_2007_12::Structuremanagement::VariantConditionResponse queryVariantConditions ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  >& inputBomLines ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

