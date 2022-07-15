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

#ifndef TEAMCENTER_SERVICES_CHANGEMANAGEMENT__2009_06_CHANGEMANAGEMENT_HXX
#define TEAMCENTER_SERVICES_CHANGEMANAGEMENT__2009_06_CHANGEMANAGEMENT_HXX

#include <teamcenter/soa/client/model/BOMEdit.hxx>
#include <teamcenter/soa/client/model/ChangeItemRevision.hxx>
#include <teamcenter/soa/client/model/PSBOMViewRevision.hxx>
#include <teamcenter/soa/client/ModelObject.hxx>


#include <teamcenter/soa/client/ModelObject.hxx>
#include <teamcenter/soa/client/ServiceData.hxx>
#include <teamcenter/soa/client/PartialErrors.hxx>
#include <teamcenter/soa/client/Preferences.hxx>

#include <teamcenter/services/changemanagement/ChangeManagement_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Changemanagement
        {
            namespace _2009_06
            {
                class Changemanagement;

class TCSOACHANGEMANAGEMENTSTRONGMNGD_API Changemanagement
{
public:

    struct GetNoteVariantOutput;
    struct GetNoteVariantResponse;
    struct GetNoteVariantsInput;

    /**
     * <code>GetNoteVariantOutput</code> structure contains object references to 1) the
     * BOMEdit, 2) the associated change revision, 3) the solution bvr, and 4) the impacted
     * bvr.  It also contains a list of details count and a list of strings representing
     * some textual details of the note or variant change.
     */
    struct GetNoteVariantOutput
    {
        /**
         * An object reference to a BOMEdit
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::BOMEdit>  bomChange;
        /**
         * An object reference to a change revision.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::ChangeItemRevision>  changeRev;
        /**
         * An object reference to the Solution bvr.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMViewRevision>  solutionBVR;
        /**
         * An object reference to the Impacted bvr.
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::Model::PSBOMViewRevision>  impactedBVR;
        /**
         * Count of note or variant change details
         */
        std::vector< int > vCount;
        /**
         * Note or variant change details.
         */
        std::vector< std::string > vBomChangeDetails;
    };

    /**
     * <code>GetNoteVariantResponse</code> structure contains a list of <code>GetNoteVariantOutput</code>
     * structures and a standard service data.
     */
    struct GetNoteVariantResponse
    {
        /**
         * A reference to the list of GetNoteVariantOutput
         */
        std::vector< Teamcenter::Services::Changemanagement::_2009_06::Changemanagement::GetNoteVariantOutput > output;
        /**
         * Standard Service data.
         */
        Teamcenter::Soa::Client::ServiceData serviceData;
    };

    /**
     * GetNoteVariantsInput structure contains an object reference to a BOMEdit whose integer
     * type is EITHER 6 (=Note Change) OR 7(=Variant Change) and a matching context string.
     */
    struct GetNoteVariantsInput
    {
        /**
         * An object reference to a BOMEdit
         */
        Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  bomChangeNode;
        /**
         * A context string of two possible values: CM_note_change_details or CM_variant_change_details.
         */
        std::string contextRelName;
    };




    /**
     * This operation is specifically designed to handle the retrieval of information for
     * Note or Variant changes to be consumed by the Teamcenter Structure Manager Rich Client
     * UI.  There are helper functions in the Rich Client to facilitate the consumption
     * and interpretation of the retrieved information.  In other words, this operation
     * may pose challenges to users of this operation who are unfamiliar with the intended
     * usage of the returned details.  For Rich Client developers, it is better to use the
     * helper functions instead.
     * <br>
     * The operation accepts as input a list of <code>GetNoteVariantsInput</code> structures,
     * each containing an object reference to a <code>BOMEdit</code> whose integer type
     * is EITHER 6 (=Note Change) OR 7(=Variant Change) and a matching context string of
     * one of the following two possible values:
     * <br>
     * <ul>
     * <li type="disc">CM_note_change_details
     * </li>
     * <li type="disc">CM_variant_change_details
     * </li>
     * </ul>
     * <br>
     * Based on the input structures, the operation will assemble the retrieved information
     * in a list of <code>GetNoteVariantOutput</code> structures, and package them together
     * with a standard service data in the returned <code>GetNoteVariantResponse</code>
     * structure.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * <b>Use Case 1: Getting the details for a note change</b>
     * <br>
     * This operation can be invoked via an instance of the <code>ChangeManagementService</code>.
     * The caller program will need to supply an object reference to a <code>BOMEdit</code>
     * whose integer type is 6 and a matching context string of CM_note_change_details in
     * the input structure <code>GetNoteVariantsInput</code>.  The corresponding output
     * structure <code>GetNoteVariantOutput</code> contains object references to 1) the
     * BOMEdit, 2) the associated change revision, 3) the solution bvr, and 4) the impacted
     * bvr.  It also contains a list of details count and a list of strings representing
     * some textual details of the note change.  The caller program will use the count to
     * read the strings for details.
     * <br>
     * <b>Use Case 2: Getting the details for a variant change</b>
     * <br>
     * This operation can be invoked via an instance of the <code>ChangeManagementService</code>.
     * The caller program will need to supply an object reference to a <code>BOMEdit</code>
     * whose integer type is 7 and a matching context string of CM_variant_change_details
     * in the input structure <code>GetNoteVariantsInput</code>.  The corresponding output
     * structure <code>GetNoteVariantOutput</code> contains object references to 1) the
     * BOMEdit, 2) the associated change revision, 3) the solution bvr, and 4) the impacted
     * bvr.  It also contains a list of details count and a list of strings representing
     * some textual details of the variant change.  The caller program will use the count
     * to read the strings for details.
     * <br>
     * <br>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Change Management - This Component is intended to identify all Operations and Services
     * under Change Management.
     *
     * @param getNoteVariantRequest
     *        A list of GetNoteVariantsInput structures, each containing an object reference to
     *        a BOMEdit whose integer type is EITHER 6 (=Note Change) OR 7(=Variant Change) and
     *        a matching context string.
     *        <br>
     *
     * @return
     *         <code>GetNoteVariantResponse</code> which contains a list of <code>GetNoteVariantOutput</code>
     *         structures and a standard service data. Following are some possible errors returned
     *         in <code>ServiceData</code>:
     *         <br>
     *         <ul>
     *         <li type="disc">233035&nbsp;&nbsp;&nbsp;&nbsp;CM_invalid_bomedit_form_prop
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Services::Changemanagement::_2009_06::Changemanagement::GetNoteVariantResponse getNoteVariantChanges ( const std::vector< Teamcenter::Services::Changemanagement::_2009_06::Changemanagement::GetNoteVariantsInput >& getNoteVariantRequest ) = 0;


protected:
    virtual ~Changemanagement() {}
};
            }
        }
    }
}

#include <teamcenter/services/changemanagement/ChangeManagement_undef.h>
#endif

