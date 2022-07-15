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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_INCREMENTALCHANGESERVICE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT_INCREMENTALCHANGESERVICE_HXX

#include <teamcenter/services/structuremanagement/_2012_02/Incrementalchange.hxx>
#include <teamcenter/services/structuremanagement/_2013_05/Incrementalchange.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/structuremanagement/StructureManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Structuremanagement
        {
            class IncrementalchangeService;

/**
 * SOAs for select ICE calls
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoastructuremanagementstrongmngd.dll
 * </li>
 * <li type="disc">libtcsoastructuremanagementtypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API IncrementalchangeService
    : public Teamcenter::Services::Structuremanagement::_2012_02::Incrementalchange,
             public Teamcenter::Services::Structuremanagement::_2013_05::Incrementalchange
{
public:
    static IncrementalchangeService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation carries the <b>IncrementalChangeElement</b> (ICE) object(s) from the
     * source line to the corresponding target line by cloning them.
     * <br>
     * There are two BMIDE constants that were introduced for this functionality
     * <br>
     * 
     * <br>
     * Type Constant <b>Fnd0EnableIceCarryOver</b>
     * <br>
     * Property Constant <b>Fnd0AttrIcesToExclude</b>
     * <br>
     * <br>
     * - New <b>IncrementalChangeElement</b> object(s) are attached to the original incremental
     * change revision.
     * <br>
     * <br>
     * - Add changes on the occurrence are ignored - It does not make sense to have two
     * occurrences appearing at the same time at different locations.<b>
     * <br>
     * <br>
     * - GDELine</b> objects are not supported.
     * <br>
     * <br>
     * - For attribute changes the context of the absolute occurrence data is the new parent
     * <b>BOMView Revision</b>.
     * <br>
     * <br>
     * - If there is no write access on incremental change revision, the carryover is allowed
     * with a programmatic bypass.
     * <br>
     * - If there is any failure while cloning any <b>IncrementalChangeElement</b> object
     * that is being carried over, the entire operation will rollback.
     * <br>
     * <br>
     * - Carryover is not possible if we have the following two conditions:
     * <br>
     * <ul>
     * <li type="disc">Both source and target <b>BomView Revision</b> item type are not
     * available in the BMIDE Type Constant <b>Fnd0EnableIceCarryOver</b>.
     * </li>
     * <li type="disc">BOM-BOP case - If the source line is a <b>BOMLine</b> and the target
     * line is a BOP (Bill of Process) line or vice versa
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User wants to carry over <b>IncrementalChangeElement</b> object(s) when doing a Copy-Paste
     * or a Cut-Paste of a <b>BOMLine</b> having <b>IncrementalChangeElement</b> object(s),
     * from one structure partition to another partition within the Plant BOP.
     * <br>
     * User wants to carry over <b>IncrementalChangeElement</b> object(s) when doing a Copy-Paste
     * or a Cut-Paste of a <b>BOMLine</b> having <b>IncrementalChangeElement</b> object(s),
     * from Product BOP and to another partition in the Plant BOP.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Incremental Change - An incremental change collects a number of structure changes
     * to a component such as add or remove of components or changes to attachments (data).
     * Incremental change is an alternative to revision-based effectivity configuration.
     *
     * @param bomLineInfos
     *        A list of source and their corresponding target <b>BOMLine</b> objects
     *
     * @return
     *         A <code>Service Data</code> object will be returned which may contain the following
     *         partial errors:
     *         <br>
     *         
     *         <br>
     *         <ul>
     *         <li type="disc">201003 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;An internal
     *         error occurred in Incremental Change module.
     *         </li>
     *         <li type="disc">201007 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Carrying forward
     *         of changes was blocked because creation of duplicate changes is not allowed
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData carryOver ( const std::vector< Teamcenter::Services::Structuremanagement::_2012_02::Incrementalchange::BomLineInfo >& bomLineInfos ) = 0;

    /**
     * This operation deletes the list of Incremental Change Elements (ICE) on the given
     * BOMLine or the MECfgLine.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Incremental Change - An incremental change collects a number of structure changes
     * to a component such as add or remove of components or changes to attachments (data).
     * Incremental change is an alternative to revision-based effectivity configuration.
     *
     * @param listOfObjects
     *        A list of BOMLine or the MECfgLine component and their corresponding ICE.
     *
     * @return
     *         For successfully deleted ICEs, corresponding business object will be sent back in
     *         the ServiceData lists of updated object. If an invalid business object is detected,
     *         72035 is returned as a partial error with the corresponding business object. If an
     *         ICE does not affect the corresponding BOMLine, 46000 is returned as a partial error.
     *         Similarly, if an ICE does not affect the corresponding MECfgLine, 200165 is returned
     *         as a partial error.
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData removeIncrementalChanges ( const std::vector< Teamcenter::Services::Structuremanagement::_2013_05::Incrementalchange::ObjectsICEInfo >& listOfObjects ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("IncrementalchangeService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

