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

#ifndef TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_02_INCREMENTALCHANGE_HXX
#define TEAMCENTER_SERVICES_STRUCTUREMANAGEMENT__2012_02_INCREMENTALCHANGE_HXX

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
            namespace _2012_02
            {
                class Incrementalchange;

class TCSOASTRUCTUREMANAGEMENTSTRONGMNGD_API Incrementalchange
{
public:

    struct BomLineInfo;

    /**
     * This structure holds the source and the target <b>BOMLine</b> objects.
     */
    struct BomLineInfo
    {
        /**
         * The source <b>BOMLine</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  sourceLine;
        /**
         * The target <b>BOMLine</b>.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMLine>  targetLine;
    };




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


protected:
    virtual ~Incrementalchange() {}
};
            }
        }
    }
}

#include <teamcenter/services/structuremanagement/StructureManagement_undef.h>
#endif

