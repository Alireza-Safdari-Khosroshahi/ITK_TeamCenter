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

#ifndef CPD0_SERVICES_CPDCORE_STRUCTUREEXPANDSERVICE_HXX
#define CPD0_SERVICES_CPDCORE_STRUCTUREEXPANDSERVICE_HXX

#include <cpd0/services/cpdcore/_2011_06/Structureexpand.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <cpd0/services/cpdcore/CpdCore_exports.h>

namespace Cpd0
{
    namespace Services
    {
        namespace Cpdcore
        {
            class StructureexpandService;

/**
 * This service handles expansion of worksets, their subsets, and <i>subordinate</i>
 * design elements.   This service is used mainly when opening a workset in a CAD tool
 * or displaying the content of a workset in the Teamcenter client.  The main operation
 * supported by this service is <code>startExpandStructure</code>. There are two supporting
 * operations <code>nextExpandStructure</code> and <code>stopExpandStructure</code>
 * which complement <code>startExpandStructure</code>.
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libcpd0soacpdcorestrongmngd.dll
 * </li>
 * <li type="disc">libcpd0soacpdcoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class CPD0SOACPDCORESTRONGMNGD_API StructureexpandService
    : public Cpd0::Services::Cpdcore::_2011_06::Structureexpand
{
public:
    static StructureexpandService* getService( Teamcenter::Soa::Client::Connection* );


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


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("StructureexpandService")

};
        }
    }
}


#pragma warning ( pop )

#include <cpd0/services/cpdcore/CpdCore_undef.h>
#endif

