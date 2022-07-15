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

#ifndef TEAMCENTER_SERVICES_GLOBALMULTISITE_SITERESERVATIONSERVICE_HXX
#define TEAMCENTER_SERVICES_GLOBALMULTISITE_SITERESERVATIONSERVICE_HXX

#include <teamcenter/services/globalmultisite/_2007_06/Sitereservation.hxx>



#include <teamcenter/soa/client/Connection.hxx>
#include <new> // for size_t
#include <teamcenter/soa/common/MemoryManager.hxx>

#pragma warning ( push )
#pragma warning ( disable : 4996  )

#include <teamcenter/services/globalmultisite/GlobalMultiSite_exports.h>

namespace Teamcenter
{
    namespace Services
    {
        namespace Globalmultisite
        {
            class SitereservationService;

/**
 * This service provides operations to transfer modification privilege for offline use
 * cases. It is used for offline GMS using Briefcase as the data exchange mechanism.
 * In offline GMS, the ownership cannot be transferred. So only the source site holds
 * the objects ownership. This service provides the operations to allow the user to
 * modify the data at a remote site.
 * <br>
 * The SiteReservation service supports the following usecases for modification at remote
 * site.
 * <br>
 * <ul>
 * <li type="disc">Site check out the objects to a remote site.
 * </li>
 * <li type="disc">Site check in the objects at the remote site after modification.
 * </li>
 * <li type="disc">Cancel site check out if user will not do site check out.
 * </li>
 * </ul>
 * <br>
 * Only these six types and their sub types are supported to be site checked out: <b>Item</b>,
 * <b>ItemRevision</b>, <b>Form</b>, <b>Dataset</b>, <b>BOMView</b>, <b>BOMViewRevision</b>.
 * When site check out is performed on <b>Item</b>, <b>ItemRevision</b> or <b>Dataset</b>,
 * related objects will be site checked out also:
 * <br>
 * <ul>
 * <li type="disc">Item&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Related
 * Master Form(s).
 * </li>
 * <li type="disc">ItemRevision  Related Master Form(s).
 * </li>
 * <li type="disc">Dataset&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;All namedReference
 * objects which are <b>WorkspaceObject</b>.
 * </li>
 * </ul>
 * .
 * <br>
 * <br>
 * <b>Dependencies:</b>
 * <br>
 * Reservation, ImportExport
 * <br>
 * <br>
 * <br>
 * <b>Library Reference:</b>
 * <ul>
 * <li type="disc">libtcsoaglobalmultisitestrongmngd.dll
 * </li>
 * <li type="disc">libtcsoaglobalmultisitetypes.dll (runtime dependency)
 * </li>
 * </ul>
 */

class TCSOAGLOBALMULTISITESTRONGMNGD_API SitereservationService
    : public Teamcenter::Services::Globalmultisite::_2007_06::Sitereservation
{
public:
    static SitereservationService* getService( Teamcenter::Soa::Client::Connection* );


    /**
     * This operation is used in offline GMS. It is used to cancel site check out objects
     * which has been site checked out to another site and removes the reservation objects.
     * If errors occur, they are returned in the ServiceData structure.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can pass a list of objects which have been in site checked out status to do
     * cancel site check in.
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * siteCheckOut
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Briefcase - Offline GMS capabilitiy tailored to support the disconnected supplier
     * use case for data transfer and synchronization.
     *
     * @param objects
     *        The busincess objects to be site checked in. Since site checkout can only be performed
     *        on following list of objects and all it sub classes, cancel site check out also can
     *        only be performed on these objects.
     *        <br>
     *        <ul>
     *        <li type="disc"><b>Item</b>
     *        </li>
     *        <li type="disc"><b>ItemRevision</b>
     *        </li>
     *        <li type="disc"><b>PSBOMView</b>
     *        </li>
     *        <li type="disc"><b>PSBOMViewRevision</b>
     *        </li>
     *        <li type="disc"><b>Form</b>
     *        </li>
     *        <li type="disc"><b>Dataset</b>
     *        </li>
     *        </ul>
     *
     * @return
     *         ServiceData contains partial errors if the operation fails on any of the objects.
     *         Each partial error contains the tag of the object and error code. Updated objects
     *         are added to the updated object vector of the ServiceData. Possible errors are:
     *         <br>
     *         <ul>
     *         <li type="disc">32092&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The type of
     *         the object is not supported by site check out facility.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData cancelSiteCheckOut ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation is used in offline GMS. It is used to check in objects that were checked
     * out to another site and removes the reservation objects. If errors occur, they are
     * returned in the ServiceData structure.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can pass a list of objects which have been in site checked out status to do
     * site check in. A series of related objects will be site checked in along with the
     * input objects <b>Item</b>, <b>ItemRevision</b> or <b>Dataset</b>:
     * <br>
     * <ul>
     * <li type="disc">Item&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Related Master
     * <b>Form</b>(s)
     * </li>
     * <li type="disc">ItemRevision&nbsp;&nbsp;&nbsp;&nbsp;Related Master <b>Form</b>(s)
     * </li>
     * <li type="disc">Dataset&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;All namedReference
     * objects which are <b>WorkspaceObject</b>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Dependencies:</b>
     * <br>
     * siteCheckOut
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Briefcase - Offline GMS capabilitiy tailored to support the disconnected supplier
     * use case for data transfer and synchronization.
     *
     * @param objects
     *        The business objects to be site checked in. Since site checkout can only be performed
     *        on following list of objects and all it subtypes, site check in also can only be
     *        performed on these objects.
     *        <br>
     *        <ul>
     *        <li type="disc"><b>Item</b>
     *        </li>
     *        <li type="disc"><b>ItemRevision</b>
     *        </li>
     *        <li type="disc"><b>PSBOMView</b>
     *        </li>
     *        <li type="disc"><b>PSBOMViewRevision</b>
     *        </li>
     *        <li type="disc"><b>Form</b>
     *        </li>
     *        <li type="disc"><b>Dataset</b>
     *        </li>
     *        </ul>
     *
     * @return
     *         ServiceData contains partial errors if the operation fails on any objects, each partial
     *         error contains the tag of the object and error code. Updated objects are added to
     *         the updated object vector of the ServiceData. Possible errors are:
     *         <br>
     *         <ul>
     *         <li type="disc">32092&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The type of
     *         the object is not supported by site check out facility.
     *         </li>
     *         </ul>
     *
     */
    virtual Teamcenter::Soa::Client::ServiceData siteCheckIn ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects ) = 0;

    /**
     * This operation is used in offline GMS. It is used to checkout objects to another
     * site, so that after the objects are imported into that site, they are modifiable.
     * If errors occur, they are returned in the ServiceData structure.
     * <br>
     * <br>
     * <b>Use Cases:</b>
     * <br>
     * User can pass a list of objects (only these six types and their sub types are supported:
     * <b>Item</b>, <b>ItemRevision</b>, <b>Form</b>, <b>Dataset</b>, <b>BOMView</b>, <b>BOMViewRevision</b>)
     * to do site check out. A series of related objects will be site checked out along
     * with the input objects <b>Item</b>, <b>ItemRevision</b> or <b>Dataset</b>:
     * <br>
     * <ul>
     * <li type="disc">Item&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Related Master
     * Form(s)
     * </li>
     * <li type="disc">ItemRevision&nbsp;&nbsp;&nbsp;&nbsp;Related Master Form(s)
     * </li>
     * <li type="disc">Dataset&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;All namedReference
     * objects which are <b>WorkspaceObject</b>
     * </li>
     * </ul>
     * <br>
     * <br>
     * <b>Teamcenter Component:</b>
     * <br>
     * Briefcase - Offline GMS capabilitiy tailored to support the disconnected supplier
     * use case for data transfer and synchronization.
     *
     * @param objects
     *        The business objects to be site checked out. Site checkout can only be performed
     *        on following list of objects and all their sub classes:
     *        <br>
     *        <ul>
     *        <li type="disc"><b>Item</b>
     *        </li>
     *        <li type="disc"><b>ItemRevision</b>
     *        </li>
     *        <li type="disc"><b>PSBOMView</b>
     *        </li>
     *        <li type="disc"><b>PSBOMViewRevision</b>
     *        </li>
     *        <li type="disc"><b>Form</b>
     *        </li>
     *        <li type="disc"><b>Dataset</b>
     *        </li>
     *        </ul>
     *
     * @param siteId
     *        Id of the site that the objects are to be checked out to.
     *
     * @param comment
     *        Check out comment, the reason for the site check out.
     *
     * @param changeId
     *        The mark for this site check out process.
     *
     * @return
     *         ServiceData contains partial errors if the operation fails on any of the objects.
     *         Each partial error contains the tag of the object and error code. Updated objects
     *         are added to the updated object vector of the ServiceData. Possible errors are:
     *         <br>
     *         <ul>
     *         <li type="disc">10017&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Unable to find
     *         site %1$
     *         </li>
     *         <li type="disc">32092&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The type of
     *         the object is not supported by site check out facility.
     *         </li>
     *         </ul>
     *
     *
     * @exception ServiceException
     *           .
     */
    virtual Teamcenter::Soa::Client::ServiceData siteCheckOut ( const std::vector< Teamcenter::Soa::Common::AutoPtr<Teamcenter::Soa::Client::ModelObject>  >& objects,
        int siteId,
        const std::string&  comment,
        const std::string&  changeId ) = 0;


    SOA_CLASS_NEW_OPERATORS_WITH_IMPL("SitereservationService")

};
        }
    }
}


#pragma warning ( pop )

#include <teamcenter/services/globalmultisite/GlobalMultiSite_undef.h>
#endif

