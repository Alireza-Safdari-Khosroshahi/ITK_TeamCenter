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

#ifndef TEAMCENTER_SERVICES_CAD__2009_04_STRUCTUREMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CAD__2009_04_STRUCTUREMANAGEMENT_HXX

#include <teamcenter/services/cad/_2008_06/Structuremanagement.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


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
            namespace _2009_04
            {
                class Structuremanagement;

class TCSOACADSTRONGMNGD_API Structuremanagement
{
public:

    struct AttributesInfoForObject;
    struct AttributesInfos;
    struct RelativeStructureParentInfo;
    struct CreateOrUpdateRelativeStructureInfo;
    struct CreateOrUpdateRelativeStructurePref;
    struct CreateOrUpdateRelativeStructureResponse;
    struct MappedReturnData;

    /**
     * Map that maps from client Id to MappedReturnData
     */
    typedef std::map< std::string, MappedReturnData > ClientIdToOccurrenceMap;

    /**
     * Contains classname and vector of AttributesInfos structure
     */
    struct AttributesInfoForObject
    {
        /**
         * Name of the attribute that refers to the object
         */
        std::string topLineAttrThatRefersToObject;
        /**
         * List of AttributesInfos
         */
        std::vector< Teamcenter::Services::Cad::_2009_04::Structuremanagement::AttributesInfos > attrsToSet;
    };

    /**
     * Contains name/values pair data to be set as attributes on the related object.
     */
    struct AttributesInfos
    {
        /**
         * Attribute name
         */
        std::string name;
        /**
         * Attribute values
         */
        std::vector< std::string > values;
    };

    /**
     * Contains information about the parent BOM line representation.
     */
    struct RelativeStructureParentInfo
    {
        /**
         * A unique string supplied by the caller.  This ID is used to identify return data
         * elements and partial errors associated with this input structure.  If <code>clientId</code>
         * is not provided then it can be difficult to align the input with any returned errors.
         */
        std::string clientId;
        /**
         * Flag that if true signifies that the structure represented in the input is the full
         * representation of the structure under the input parent. Any other structure relations
         * that exist in Teamcenter but are not represented in the input will be removed.
         */
        bool complete;
        /**
         * The type of the BOM view to create under the parent <code>bomViewTypeName</code>
         * object.  If not specified, <code>CreateOrUpdateRelativeStructurePref</code> <code>bomViewTypeName</code>
         * will be used as the default.
         */
        std::string bomViewTypeName;
        /**
         * Object reference of the Item Revision context assembly object to create or update
         * the child occurrence.  This is a required input.  An error will be returned if a
         * valid parent is not specified.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  parent;
        /**
         * Designated for future implementation.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  changeContext;
        /**
         * Last modified date of BOM view revision (BVR) under the input <code>parent</code>.
         * This input is not required.  If this input date is different than the current last
         * modified date and the <code>overwriteForLastModDate</code> preference is false the
         * input will be ignored and processing will continue with the next input.  In this
         * scenario, error 215033 will be returned.  If the dates are different and the <code>overwriteForLastModDate</code>
         * preference is true, processing will continue with the current input.  In this scenario,
         * error 215034 will be returned.
         */
        Teamcenter::Soa::Common::DateTime lastModifiedOfBVR;
        /**
         * Flag for updating the BVR to precise (true) or imprecise (false).  Specifying precise
         * as true means the child occurrences reference item revisions, whereas specifying
         * precise as false (imprecise) means the child occurrences reference items.
         */
        bool precise;
        /**
         * A list of object property names for the parent BOM line and attributes to set on
         * the corresponding objects.  For example, <code>supportingClassAttrs</code> <code>topLineAttrThatRefersToObject</code>
         * could be set to the property name <i>bl_bomview_rev</i> and <code>attrsToSet</code>
         * could include the attribute <i>legacy_transform_factor</i> with a value of 0.5 to
         * set on the BOM view revision object.
         */
        std::vector< Teamcenter::Services::Cad::_2009_04::Structuremanagement::AttributesInfoForObject > supportingClassAttrs;
    };

    /**
     * Input structure for <code>createOrUpdateRelativeStructure</code>.
     */
    struct CreateOrUpdateRelativeStructureInfo
    {
        /**
         * Parent info structure containing information about the parent BOM line representation.
         */
        Teamcenter::Services::Cad::_2009_04::Structuremanagement::RelativeStructureParentInfo parentInfo;
        /**
         * Child info structure for creating the occurrence or updating the occurrence attributes.
         * If no child objects are specified and <code>RelativeStructureParentInfo</code> <code>complete</code>
         * is true, all existing child objects will be removed.  If no child objects are specified
         * and <code>RelativeStructureParentInfo</code> <code>complete</code> is false, the
         * input is ignored.
         */
        std::vector< Teamcenter::Services::Cad::_2008_06::Structuremanagement::RelativeStructureChildInfo2 > childInfo;
    };

    /**
     * Preference structure for <code>createOrUpdateRelativeStructure</code>.
     */
    struct CreateOrUpdateRelativeStructurePref
    {
        /**
         * Flag to check whether the structure needs to be updated if the input last modified
         * date is different from the current last modified date of the object in Teamcenter.
         * If false, but the <code>RelativeStructureParentInfo</code> <code>lastModifiedOfBVR</code>
         * input specified is different than the set modified date, partial error 215033 will
         * be returned.
         */
        bool overwriteForLastModDate;
        /**
         * Flag to indicate whether the operation should continue processing to the next input
         * when an error is encountered.
         */
        bool continueOnError;
        /**
         * The default BOM view type to create or the view type of the child to be added to
         * the parent <b>BOMViewRevision</b> This default value can be overridden for individual
         * parent by specifying the <code>bomViewTypeName</code> in  <code>RelativeStructureParentInfo</code>
         * <code>parentInfo</code> input. The default value can also be overridden for individual
         * children by specifying the <code>childBomViewType</code> in the <code>RelativeStructureChildInfo</code>
         * <code>childInfo</code> input.
         */
        std::string bomViewTypeName;
        /**
         * Represents the occurrence note type which holds the value for the CAD occurrence
         * ID or this can be the <b>PSOccurrenceThread</b> UID if the integration does not use
         * a note type.
         */
        std::string cadOccIdAttrName;
        /**
         * List of object types that the client is interested in.  If <code>complete</code>
         * is true, object types or subtypes that exist in the structure in Teamcenter but are
         * not in this list are removed.  If <code>complete</code> is true, but no <code>objectTypes</code>
         * are specified, then all objects types or subtypes are removed from the existing structure
         * in Teamcenter.  If <code>complete</code> is false, <code>objectTypes</code> is ignored.
         */
        std::vector< std::string > objectTypes;
    };

    /**
     * The response from the <code>createOrUpdateRelativeStructure</code> operation.
     */
    struct CreateOrUpdateRelativeStructureResponse
    {
        /**
         * Map of client IDs to <code>MappedReturnData</code>.
         */
        ClientIdToOccurrenceMap output;
        /**
         * The <code>ServiceData</code>.  This operation will populate the <code>ServiceData</code>
         * with created occurrences, BOM views and BOM view revisions, updated occurrences and
         * BOM view revisions, and any implicitly deleted occurrences.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * Map of returned data that is relevant to the created or updated occurrence for the
     * given client ID.
     */
    struct MappedReturnData
    {
        /**
         * The occurrence thread for tracking the created or updated occurrence.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  occThread;
        /**
         * The occurrence object that was created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  occurrence;
        /**
         * The BOM view revision that was created or updated.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bvr;
    };




    /**
     * This operation creates or updates the relative structure for the input parent assembly
     * and child components.  The objects created or updated by this operation include a
     * BOM view (BV), BOM view revision (BVR) and occurrence data (<b>PSOccurrence</b>,
     * <b>PSOccurrenceThread</b>).
     * <br>
     * 
     * <br>
     * Before creating the relative structure objects and relations, this operation will
     * check that the structure to be created does not already exist.  If the occurrence
     * exists but the input attribute values differ from those already set, an attempt is
     * made to update the values.
     * <br>
     * <br>
     * This operation assumes the input is in a bottom up format such that if any failures
     * occur, the structure that is created will still be consumable.  For example:
     * <br>
     * <br>
     * Parent assembly A, subassembly B and child C are input into this operation.  If the
     * relative structure for subassembly B and child C is created successfully but an error
     * occurs during the creation of the structure for assembly A and subassembly B, the
     * client can still access the subassembly B, child C relative structure.
     * <br>
     * <br>
     * No attempt is made in the operation to rearrange the input and process it in the
     * correct order. One parent context object is processed at one time and it is assumed
     * that all edits for a given parent context come in as one set of input.
     * <br>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * Use Case 1:
     * <br>
     * <br>
     * User adds an existing component to an existing assembly to create a relative occurrence.
     * <br>
     * For this operation, the assembly is passed in as the parent and the component is
     * passed in as the child.  The relative occurrence is created and a map of the input
     * <code>clientID</code> to <code>MappedReturnData</code> is returned in <code>output</code>
     * and the occurrence, BOM view and BOM view revision are returned as created objects
     * in <code>ServiceData</code>.
     * <br>
     * <br>
     * Use Case 2:
     * <br>
     * <br>
     * User wants to update the position of the child component relative to the parent assembly.
     * <br>
     * For this operation, the transform on the child occurrence information is updated
     * with the new position relative to the parent.  The assembly is passed in as the parent
     * and the component is passed in as the child.  The relative occurrence is updated
     * and a map of the <code>clientID</code> to <code>MappedReturnData</code> is returned
     * in <code>output</code> and the occurrence and BOM view revision are returned as updated
     * objects in <code>ServiceData</code>.
     * <br>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * createOrUpdateParts, createObjects
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * MCAD Integration - The set of capabilities that allow MCAD applications to integrate
     * with the Tc server.
     *
     * @param inputs
     *        List of input structures that specify all the children to be added to the specified
     *        parent assembly.
     *
     * @param pref
     *        The structure for setting specific preference input used by this operation.
     *
     * @return
     *         A map of input clientIds to <code>MappedReturnData</code>.
     *         <br>
     *         <br>
     *         The following warning and errors originate from this operation:
     *         <br>
     *         <br>
     *         <ul>
     *         <li type="disc">215000 (error): An invalid BOM view type name was specified with
     *         the parent input.
     *         </li>
     *         <li type="disc">215005 (error): The BOM view revision (BVR) is not checked out by
     *         the current user.
     *         </li>
     *         <li type="disc">215006 (error): The BOM view revision is checked out by another user.
     *         </li>
     *         <li type="disc">215008 (error): A duplicate parent for the relative structure parent
     *         input already exists.
     *         </li>
     *         <li type="disc">215009 (error): The object type name specified in the input preference
     *         does not exist.
     *         </li>
     *         <li type="disc">215010 (warning): The input CAD occurrence identifier does not correspond
     *         to a valid BOM line.  This is a warning when the complete input is true.
     *         </li>
     *         <li type="disc">215010 (error): The input CAD occurrence identifier does not correspond
     *         to a valid BOM line.  This is an error when the complete input is false.
     *         </li>
     *         <li type="disc">215033 (error): The input last modified date differs from actual.
     *         </li>
     *         <li type="disc">215034 (error): The dataset or BVR was modified even when the input
     *         last modified dates was different than the current last modified data.
     *         </li>
     *         </ul>
     *
     * @deprecated
     *         As of Teamcenter 10.1, this version of createOrUpdateRelativeStructure is replaced
     *         by the _2013_05 version.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of Teamcenter 10.1, this version of createOrUpdateRelativeStructure is replaced by the _2013_05 version."))
#endif
    virtual Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructureResponse createOrUpdateRelativeStructure ( const std::vector< Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructureInfo >& inputs,
        const Teamcenter::Services::Cad::_2009_04::Structuremanagement::CreateOrUpdateRelativeStructurePref&  pref ) = 0;


protected:
    virtual ~Structuremanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/cad/Cad_undef.h>
#endif

