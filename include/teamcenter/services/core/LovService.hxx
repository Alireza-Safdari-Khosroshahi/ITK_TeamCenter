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

#ifndef TEAMCENTER_SERVICES_CORE_LOVSERVICE_HXX
#define TEAMCENTER_SERVICES_CORE_LOVSERVICE_HXX

#include <teamcenter/services/core/_2007_06/Lov.hxx>
#include <teamcenter/services/core/_2011_06/Lov.hxx>
#include <teamcenter/services/core/_2013_05/Lov.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/core/Core_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Core
        {
            class LovService;

/**
 * This service exposes the operations to returns LOV attachments attached to properties
 * which are attached with <b>project based conditions</b>. This service can also be
 * used for properties attached with session based attachments. Please note following
 * points when using this service for efficient use:
 * <br>
 * <br>
 * a)&nbsp;&nbsp;&nbsp;&nbsp;This service need to be used for each object which has
 * properties attached with project based conditions.  To figure out whether a property
 * is attached with project based conditions or not look at the value of the lovAttachmentCategory
 * on respective property descriptor.
 * <br>
 * <br>
 * b)&nbsp;&nbsp;&nbsp;&nbsp;Project based conditions would come into picture when editing
 * an object. For create/save as/revise scenario's applications should display session
 * based attachments which would have been retrieved using property services.
 * <br>
 * <br>
 * c)&nbsp;&nbsp;&nbsp;&nbsp;This service also returns session based valid attachment.
 * If application codes deals with Property Descriptors, then properties may have already
 * holding valid session based attachment
 * <br>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * PropDescriptor
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoacorestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoacoretypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOACORESTRONGMNGD_API LovService
    : public Teamcenter::Services::Core::_2007_06::Lov,
             public Teamcenter::Services::Core::_2011_06::Lov,
             public Teamcenter::Services::Core::_2013_05::Lov
{
public:
    static LovService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * Get attached LOV based on input type name and property names structure. The LOV Tag
     * is returned in the response and service data.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param inputs
     *        - vector of structure of LOVInfo with type name and property names vector.
     *
     * @return
     *         AttachedLOVsResponse - Response structure with Map of input Index to LOV tag and
     *         serviceData
     *
     *
     * @exception ServiceException
     *           None
     * @deprecated
     *         As of tc2007.1, use the getAttachedPropDescs operation.
     *
     */
#ifdef WNT
__declspec(deprecated("Deprecated as of tc2007.1, use the getAttachedPropDescs operation."))
#endif
    virtual Teamcenter::Services::Core::_2007_06::Lov::AttachedLOVsResponse getAttachedLOVs ( const std::vector< Teamcenter::Services::Core::_2007_06::Lov::LOVInfo >& inputs ) = 0;

    /**
     * Returns valid LOV attachments for the properties of each object passed in as input.
     * It may return LOV or <b>null</b> based on condition validations. If none of the conditions
     * evaluated to be <b>True</b>, then no LOV attachment is returned for the property
     * of an instance.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param objectStructArray
     *        LOV attachments are evaluated for each property of the structure LOVAttachmentsInut
     *        based on each object in <code>objects</code> list.
     *
     * @return
     *         Returns LOV attachments currently attached to properties.
     *
     *
     * @exception ServiceException
     *           None
     */
    virtual Teamcenter::Services::Core::_2011_06::Lov::LOVAttachmentsResponse getLOVAttachments ( const std::vector< Teamcenter::Services::Core::_2011_06::Lov::LOVAttachmentsInput >& objectStructArray ) = 0;

    /**
     * This operation is invoked to query the data for a property having an LOV attachment.
     * The results returned from the server also take into consideration any filter string
     * that is in the input.  This operation returns both LOV meta data as necessary for
     * the client to render the LOV and partial LOV values list as specified.  The operation
     * will return the results in the LOVSearchResults data structure. Maximum number of
     * results to be returned are specified in the InitialLOVData data structure. If there
     * are more results, the moreValuesExist flag in the LOVSearchResults data structure
     * will be true. If the flag is true, more values can be retrieved with a call to the
     * getNextLOVValues operation.
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param initialData
     *        Input data to get LOV results for any LOV
     *
     * @return
     *         The LOV Search Results. This includes LOV metadata information (LOV usage, LOV style,
     *         etc.). It also contains the instance data (LOV values) that the client can use to
     *         render the LOV UI widget. The output also contains information as to whether there
     *         are more results to be processed in which case a user can page to get next set of
     *         values (this triggers a call to the getNextLOVValues operation).  The following partial
     *         errors are returned in the ServiceData:
     *         <br>
     *         -   54051 - The property  is not a valid sort property. Property must be one of the
     *         LOV Value or LOV Description or any of Filter Properties.
     *         <br>
     *         -   54052 - The Dynamic LOV  has an invalid configuration. It may be that Business
     *         Object Type this dynamic LOV may not exists in the system. Please contact your business
     *         modeler administrator with this information.
     *         <br>
     *         -   54053 - The Dynamic LOV  has an invalid configuration  with one of the filter
     *         property does not exists. Please contact your business modeler administrator with
     *         this information.
     *         <br>
     *         -   54055 - The Dynamic LOV  has an invalid configuration. The specified LOV value
     *         description property for the Dynamic LOV does not exist. Please contact your business
     *         modeler administrator with this information.
     *         <br>
     *         -   54058 - Sorting is not supported for columns representing array properties.
     *         <br>
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Lov::LOVSearchResults getInitialLOVValues ( const Teamcenter::Services::Core::_2013_05::Lov::InitialLovData&  initialData ) = 0;

    /**
     * This operation is invoked after a call to getInitialLOVValues if the moreValuesExist
     * flag is true in the LOVSearchResults output returned from a call to the getInitialLOVValues
     * operation. The operation will retrieve the next set of LOV values
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param lovData
     *        Input data to get next set of LOV results for Dynamic LOV. This is returned as part
     *        of the LOVSearchResults output from the call to getInitialLOVValues operation
     *
     * @return
     *         LOV Search Results (LOVSearchResults instance). The LOV Search Results contains LOV
     *         metadata information (LOV usage, LOV style, etc.). It also contains the instance
     *         data (LOV values) that the client can use to render the LOV UI widget. The output
     *         also contains information as to whether there are more results to be processed in
     *         which case a user can page to get next set of values (this triggers a call to the
     *         subsequent getNextLOVValues operation).  Partial errors are returned in the ServiceData
     *         field in the LOV Search Results. Possible errors are:
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Lov::LOVSearchResults getNextLOVValues ( const Teamcenter::Services::Core::_2013_05::Lov::LOVData&  lovData ) = 0;

    /**
     * This operation can be invoked after selecting a value from the LOV.  Use this operation
     * to do additional validation to be done on server such as validating Range value,
     * getting the dependent properties values in case of interdependent LOV (resetting
     * the dependendent property values), Coordinated LOVs ( populating dependent property
     * values )
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * List of Values (LOV) - Component to define lists of values and to associate them
     * with attributes and properties.  Associations can be stored in the database (persistent)
     * or independently associated for each Teamcenter session (run time).
     *
     * @param lovInput
     *        updated LOV input with new selection
     *
     * @param propName
     *        It is the name of the Property for which LOV is being evaluated
     *
     * @param uidOfSelectedRows
     *        Pass the uids from the selected rows. Every LovValueRow returned from server is designated
     *        with valid UID for dynamic LOV. That is the value need to be passed to the server
     *        for effective validation. For other LOVs it is empty
     *
     * @return
     *         The response data indicating validity of LOV value selections and containing updated
     *         property values and interdependent property values
     *
     */
    virtual Teamcenter::Services::Core::_2013_05::Lov::ValidateLOVValueSelectionsResponse validateLOVValueSelections ( const Teamcenter::Services::Core::_2013_05::Lov::LOVInput&  lovInput,
        const std::string&  propName,
        const std::vector< std::string >& uidOfSelectedRows ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("LovService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/core/Core_undef.h>
#endif

