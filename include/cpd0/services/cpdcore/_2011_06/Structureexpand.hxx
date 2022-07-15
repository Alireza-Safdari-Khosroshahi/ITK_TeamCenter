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

#ifndef CPD0_SERVICES_CPDCORE__2011_06_STRUCTUREEXPAND_HXX
#define CPD0_SERVICES_CPDCORE__2011_06_STRUCTUREEXPAND_HXX

#include <teamcenter/soa/client/model/BOMLine.hxx>
#include <teamcenter/soa/client/model/ConfigurationContext.hxx>
#include <teamcenter/soa/client/model/Cpd0DesignSubsetElement.hxx>
#include <teamcenter/soa/client/model/POM_object.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <cpd0/services/cpdcore/CpdCore_exports.h>

namespace Cpd0
{
    namespace Services
    {
        namespace Cpdcore
        {
            namespace _2011_06
            {
                class Structureexpand;

class CPD0SOACPDCORESTRONGMNGD_API Structureexpand
{
public:

    struct CopyStableIDData;
    struct ExpandStructureContent;
    struct ExpandStructureControls;
    struct ExpandStructureResponse;

    /**
     * BoToBoMap
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > BoToBoMap;

    /**
     * BoToStringMap
     */
    typedef std::map< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject> , std::string > BoToStringMap;

    /**
     * <code>CopyStableIDData</code> contains a map of <code>copy stable ID</code> values
     * for design elements within a subset.
     */
    struct CopyStableIDData
    {
        /**
         * The subset which is the context for the copy stable ID values.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::Cpd0DesignSubsetElement>  subset;
        /**
         * A map of design elements, design features and other members of a subset to their
         * copy stable ID within the subset.
         * <br>
         * <code>copyStableIDMap</code> is object of <code>BoToStringMap</code>.
         * <br>
         * <code>copyStableIDMap</code> parameter : Map of (<code>Teamcenter::BusinessObject,
         * std::string</code>)
         */
        BoToStringMap copyStableIDMap;
    };

    /**
     * <code>ExpandStructureContent</code> contains the expansion content for a given object
     * in the starting scope of a structure expands operation.  Resulting expansion content
     * can be of several possible types; <b>BOMLines</b> and presented parents are returned
     * in their own list, all other content is returned in the <code>elementContent</code>
     * list. <code> Copy stable ID</code> values are used to identify the relationship of
     * a design element to a subset or a subset to a workset revision; these values are
     * included if the caller requested it.
     */
    struct ExpandStructureContent
    {
        /**
         * The object from starting scope which resulted in the expansion of the returned content.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  startingObject;
        /**
         * Contains any <b>BOMLine</b> objects that resulted from the expansion.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  > bomLineContent;
        /**
         * Contains any model element content that resulted from the expansion.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  > elementContent;
        /**
         * Contains any presented parent content that were included because it was requested
         * (via <code>includePresentedParents</code>) in the expansion controls.
         */
        std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::POM_object>  > presentedParentContent;
        /**
         * A list of copy stable ID data (CopyStableIDData).
         * <br>
         * <code>copyStableIDMap</code> is object of <code>BoToStringMap</code>.
         * <br>
         * <code>copyStableIDMap</code> parameter : Map of (<code>Teamcenter::BusinessObject,
         * std::string</code>)
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Structureexpand::CopyStableIDData > copyStableIDData;
        /**
         * Reserved for future use.
         * <br>
         * <code>sourceTargetMap</code> id object of <code>BoToBoMap</code>.
         * <br>
         * <code>sourceTargetMap</code> parameter : Map of (<code>Teamcenter::BusinessObject,Teamcenter::BusinessObject</code>)
         */
        BoToBoMap sourceTargetMap;
    };

    /**
     * A set of controls for clients to stipulate the output of the expand processing.
     * These controls can be set at the start of the expand, and remain constant for the
     * duration of the expand, including any subsequent calls to <code>nextExpandStructure</code>.
     */
    struct ExpandStructureControls
    {
        /**
         * The number of levels to expand, where 0 signifies to expand all levels, 1 signifies
         * to expand the next level only.  Values other than 0 or 1 are not supported.
         */
        int levelsToExpand;
        /**
         * If true, presented parents of design elements will be added to the expand results.
         */
        bool includePresentedParents;
        /**
         * If true, <code>copy stable ID</code> maps will be returned in the response.
         */
        bool includeCopyStableIDMaps;
        /**
         * Reserved for future use.
         */
        bool includeSourceObjectForSubsets;
        /**
         * Controls the average number of objects to return per call (to <code>startExpandStructure</code>
         * and <code>nextExpandStructure</code>); if the value is out of bounds of the <code>DefaultMaximumLoadSize</code>
         * site preference, then the closest bound of the site preference setting will be used.
         * <br>
         * <b>Note</b>: Returned <b>BOMLines</b> and element content are both considered to
         * consume the page size, while presented parent content, copy stable ID map content
         * and source to target map content do not.
         * <br>
         * <b>Note</b>: Calls to <code>nextStructureExpand</code> will increment the page size
         * on subsequent calls by the value specified in the <code>DefaultLoadCountIncreateRate</code>
         * site preference.
         * <br>
         * <b>Note</b>: A current internal maximum page size limit is set to 2000 objects and
         * will override <code>DefaultMaximumLoadSize</code> preference if its value exceeds
         * 2000 objects.
         * <br>
         */
        int suggestedPageSize;
        /**
         * Reserved for future use.
         */
        bool expandSubsetAsSaved;
        /**
         * Pre load datasets used by visualization into the server so that they may be returned
         * via property references on any <b>Mdl0PositionedModelElement</b> object. The default
         * value is set to false. It is strongly recommended to set this value to true, if dataset
         * references are put into the property policy for <b>Mdl0PositionedModelElement</b>
         * objects.
         */
        bool preLoadVisualizationDatasets;
        /**
         * A reference to a configuration context object.  It is used in limited circumstances
         * within the expand; specifically it is used configure the children of expanded <b>Cpd0DesignElements</b>
         * by effectivity only.The configuration context is ignored for other input types, and
         * may be omitted if the starting scope contains only object of the other input types.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ConfigurationContext>  configurationContext;
    };

    /**
     * This is the response for <code>startExpandStructure</code> and <code>nextExpandStructure</code>;
     * it contains the result of the expansion for the input starting scope.  If the expansion
     * is only partially complete, the finished flag will be set to false and an expand
     * cursor (<code>expandCursor</code>) is returned for input into a subsequent call to
     * <code>nextExpandStructure</code>; otherwise, the finished flag will be set to true.
     * The service data contains any errors that occurred during the expansion.
     */
    struct ExpandStructureResponse
    {
        /**
         * expanded content
         */
        std::vector< Cpd0::Services::Cpdcore::_2011_06::Structureexpand::ExpandStructureContent > content;
        /**
         * Cursor object to pass to subsquent call to <code>nextExpandStructure</code> or <code>stopExpandStructure</code>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  expandCursor;
        /**
         * Set to <b>true</b> when there is no more content to return; <b>false</b>, otherwise.
         */
        bool finished;
        /**
         * Returns any errors which occurred during expansion.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };




    /**
     * Continues the expansion of one or more worksets, subsets, or design elements using
     * an expand cursor initially returned from <code>startExpandStructure</code>.   Results
     * are paged back to the client, and subsequent calls to <code>nextExpandStructure</code>
     * may be required to get the entire set of expanded results.  Note: Applications should
     * call <code>stopExpandStructure</code> if they wish to no longer fetch additional
     * remaining expand results (e.g. after user termination of expand).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * See SOA documentation for startExpandStructure for details about ExpandStructureResponse.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * startExpandStructure
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param expandCursor
     *        An expand cursor returns from <code>startExpandStructure</code>
     *
     * @return
     *         <code>ExpandStructureResponse</code> contains the results of the expansion; the <code>finished</code>
     *         flag is set to true when there is no more content to return. The input expand cursor
     *         is returned if there are additional content to retrieve from the server (and should
     *         be used in subsequent calls to <code>nextExpandStructure</code>) until all content
     *         is retrieved or <code>stopExpandStructure</code> is called.
     *         <br>
     *         <br>
     *         Note: See SOA documentation for <code>startExpandStructure</code> for details about
     *         <code>ExpandStructureResponse</code>.
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Structureexpand::ExpandStructureResponse nextExpandStructure ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  expandCursor ) = 0;

    /**
     * Start an expansion of one or more worksets, subsets, or design elements.   Objects
     * are expanded in the order listed.  Results are paged back to the client and subsequent
     * calls to <code>nextExpandStructure</code> may be required to get the entire set of
     * expanded results.  Note: Applications should call <code>stopExpandStructure</code>
     * if they wish to no longer fetch additional remaining expand results (e.g. after user
     * termination of expand).
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * This API supports the navigation of workset content and presented children of design
     * elements. Expanded workset content includes item sub structure, subsets, and subset
     * content. Subset content is made up of design elements and design features previously
     * configured and selected from a collaborative design by execution of the subsets search
     * recipe. Presented children of design elements (<b>Cpd0DesignElement</b>) are found
     * by reverse navigation of their presented parent (<code>cpd0presented_parent</code>)
     * property.
     * <br>
     * <br>
     * <b>Use Case 1: Expand Workset One Level </b>
     * <br>
     * Get the first level children of a workset. The results include any immediate occurrences
     * of items in the workset and any subsets in the workset. All results are returned
     * as BOMLine objects (note: subsets are returned via <b>Cpd0SubsetLine</b> objects).
     * <br>
     * <br>
     * Get the configuration to be used on the workset. This is accomplished by the following
     * steps::
     * <br>
     * <ul>
     * <li type="disc">Open a BOM window (<b>BOMWindow</b>);
     * </li>
     * <li type="disc">Apply a revision rule to the window
     * </li>
     * <li type="disc">Set the workset or workset revision as the top line in the window
     * </li>
     * <li type="disc">Use the top line as a starting scope of <code>startStructureExpand</code>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Set the number of levels to expand (<code>levelsToExpand</code>)
     * to 1
     * </li>
     * <li type="disc">Set other expansion control flags, as needed
     * </li>
     * <li type="disc">Initiate the expand using the <code>startStructureExpand</code> operation
     * </li>
     * <li type="disc">Determine if the expansion is complete by testing the finished flag
     * in the response.
     * </li>
     * <li type="disc">If the expansion is not complete, use the <code>nextStructureExpand</code>
     * operation to retrieve the next batch of expansion results from the Teamcenter; or
     * use the <code>stopStructureExpand</code> operation if no more results of the expand
     * are desired (e.g. user initiated abort).
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Case 2: Get Presented Children of a Design Element </b>
     * <br>
     * <br>
     * Get the first level presented children of a design element. The results include all
     * design elements that reference the input design elements as their presented parent.
     * All results are returned as design element objects.
     * <br>
     * <ul>
     * <li type="disc">Set the design elements of interest as the starting scope of the
     * expand
     * </li>
     * <li type="disc">Set any expansion control flags, as needed
     * </li>
     * <li type="disc">Initiate the expand using the <code>startStructureExpand</code> operation
     * </li>
     * <li type="disc">Determine if the expansion is complete by testing the finished flag
     * in the response.
     * </li>
     * <li type="disc">If the expansion is not complete, use the <code>nextStructureExpand</code>
     * operation to retrieve the next batch of expansion results from the Teamcenter; or
     * use the <code>stopStructureExpand</code> operation if no more results of the expand
     * are desired (e.g. user initiated abort).
     * </li>
     * </ul>
     * <br>
     * <br>
     * <br>
     * <b>Use Case 3: Expand a Subset to get its Design Elements and Design Features</b>
     * <br>
     * <br>
     * Get the content of a subset. The results include all design elements and design features
     * that were configured and selected last time the subset recipe was executed (replayed).
     * All results are returned as design element or design feature objects.
     * <br>
     * Set the subset(s) of interest as the starting scope of the expand; this can be done
     * in two ways
     * <br>
     * <br>
     * <i>Method 1: via a subset line</i> (<b>Cpd0SubsetLine</b>)
     * <br>
     * <ul>
     * <li type="disc">Get a Cpd0SubsetLine object from a previous expansion.
     * </li>
     * <li type="disc">Set it as a starting scope for an expand.
     * </li>
     * </ul>
     * <br>
     * <i>Method 2: via a direct reference</i>
     * <br>
     * <ul>
     * <li type="disc">Get a reference to a subset (<b>Cpd0DesignSubsetElement</b>)
     * </li>
     * <li type="disc">Set it as a starting scope for an expand.
     * </li>
     * </ul>
     * <br>
     * Note: Method 1 is the more commonly used scenario.
     * <br>
     * <br>
     * <ul>
     * <li type="disc">Set any expansion control flags, as needed
     * </li>
     * <li type="disc">Initiate the expand using the <code>startStructureExpand</code> operation
     * </li>
     * <li type="disc">Determine if the expansion is complete by testing the finished flag
     * in the response.
     * </li>
     * <li type="disc">If the expansion is not complete, use the <code>nextStructureExpand</code>
     * operation to retrieve the next batch of expansion results from the Teamcenter; or
     * use the <code>stopStructureExpand</code> operation if no more results of the expand
     * are desired (e.g. user initiated abort).
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param startingScope
     *        A list of objects to expand. The valid types of input objects are:
     *        <br>
     *        <b>Cpd0Workset
     *        <br>
     *        Cpd0WorksetRevision
     *        <br>
     *        Cpd0DesignSubsetElement
     *        <br>
     *        Cpd0DesignElement
     *        <br>
     *        Cpd0WorksetLine
     *        <br>
     *        Cpd0SubsetLine
     *        <br>
     *        </b>
     *        <br>
     *        Note: <b>ImanItemLine</b> objects (other than <b>Cpd0WorksetLine</b>) are not a supported
     *        type for starting scope.  Application should use normal BOM expand API to process
     *        ImanItemLines.
     *        <br>
     *
     * @param controls
     *        A set of controls (<code>ExpandStructureControls</code>) which govern the expansion
     *        of objects.
     *
     * @return
     *         <code>ExpandStructureResponse</code> contains the results of the expansion; the finished
     *         flag is set to true when there is no more content to return. An expand cursor is
     *         returned if there are additional content to retrieve from the server (used in subsequent
     *         calls to <code>nextExpandStructure</code>).
     *
     */
    virtual Cpd0::Services::Cpdcore::_2011_06::Structureexpand::ExpandStructureResponse startExpandStructure ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& startingScope,
        const Cpd0::Services::Cpdcore::_2011_06::Structureexpand::ExpandStructureControls&  controls ) = 0;

    /**
     * Terminates an expansion initially started by a call to <code>startExpandStructure</code>.
     * Clients should only call this operation when there are still results to return, as
     * indicated by the <code>finished</code> flag being set to false in the last response
     * from either startExpandStructure or <code>nextExpandStructure</code> operations.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * See SOA documentation for <b>startExpandStructure</b> for use cases involving this
     * operation.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * startExpandStructure
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Collaborative Product Development - Defines data management of 4GD application objects
     * (Design Elements,Design Features,Design Control Elements),defines operations to create
     * and manage Subsets from Collaborative Design and navigation operations for Workset
     * and Subset content.
     *
     * @param expandCursor
     *        An expand cursor initially returned from <code>startExpandStructure</code>
     *
     * @return
     *         Return value is always false.
     *
     */
    virtual bool stopExpandStructure ( Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  expandCursor ) = 0;


protected:
    virtual ~Structureexpand() {}
};
            }
        }
    }
}

#include <cpd0/services/cpdcore/CpdCore_undef.h>
#endif

